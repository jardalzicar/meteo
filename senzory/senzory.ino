
#include <SFE_BMP180.h>
#include <Wire.h>
#include <DHT.h>
#include <Ethernet.h>
#include <SPI.h>
#include <math.h>

#define ALTITUDE 275
#define INTERVAL 30000
#define DHTPIN 2

EthernetClient client;
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0F, 0x4B, 0x5F }; 
char server[] = "192.168.1.111";

SFE_BMP180 pressure;
DHT dht(DHTPIN, DHT22);
String data;
int temp, hum, pres;
  
void setup(){
 
  Serial.begin(9600);
  pressure.begin();
  dht.begin(); 
  Ethernet.begin(mac); 
 
  delay(2000);
}

void loop(){

  hum=measureHumidity();
  temp=measureTemperature();
  pres=measurePressure(temp);
  
  printValues();
  
  data =(String)"temp=" + temp + "&pres=" + pres + "&hum=" + hum;
  
  sendToServer(server, 80, data);
      
  //Wait between measurements
  delay(INTERVAL); 
}

//===========================================================================================

int measureHumidity(){
  int value;
  value =(int) (dht.readHumidity()*10);
  if(isnan(value)){ 
    value = -999;
    Serial.println("error retrieving pressure measurement");
  }
  return value; 
}

int measureTemperature(){
  int value = -999;
  char status;
  double T;
  status = pressure.startTemperature();
  if (status != 0){
    delay(status);
    status = pressure.getTemperature(T);
    
    if (status != 0){  
      value = (int)(T*100);
    }
    else Serial.println("error retrieving temperature measurement");  
  }
  else Serial.println("error starting temperature measurement");
  return value;
}

int measurePressure(int temperature){
  int value = -999;
  char status;
  double P;
  double T= (double)temperature/100.0;
  status = pressure.startPressure(3);
  if (status != 0 && temperature != -999){      
    delay(status);
    status = pressure.getPressure(P,T);
    
    if (status != 0){
      value = (int)(round(pressure.sealevel(P,ALTITUDE)*10.0)); 
    }
    else Serial.println("error retrieving pressure measurement");   
  }
  else Serial.println("error starting pressure measurement");
  return value;
}

void sendToServer(char server[], int port, String data){
  if (client.connect(server,port)) {
                Serial.println("-> Connected");
		client.println("POST /arduino/add.php HTTP/1.1"); 
		client.print("Host: "); 
                client.println(server);
		client.println("Content-Type: application/x-www-form-urlencoded"); 
		client.print("Content-Length: "); 
		client.println(data.length()); 
		client.println(); 
		client.print(data); 
                Serial.println(data);
                Serial.println();
  } 
  else Serial.println("Connection failed");

  if (client.connected()) { 
    client.stop();	
  }
}

// Print values via serial (debugging only) 
void printValues(){
  Serial.print("temperature: ");
  Serial.print(temp/100.0);
  Serial.print(" C || ");  
  Serial.print("pressure: ");
  Serial.print(pres/10.0);
  Serial.print(" HPa || ");
  Serial.print("humidity: ");
  Serial.print(hum/10.0);
  Serial.println(" % ");
}
