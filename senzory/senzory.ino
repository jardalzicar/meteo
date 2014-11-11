
#include <SFE_BMP180.h>
#include <Wire.h>
#include <DHT.h>

#define ALTITUDE 275
#define INTERVAL 2000
#define DHTPIN 2

SFE_BMP180 pressure;
DHT dht(DHTPIN, DHT22);

char status;
double T,P;
float temp, pres, hum;
  
void setup(){
 
  Serial.begin(9600);
  pressure.begin();
  dht.begin();  
 
  delay(2000);
}

void loop(){
  
  temp=-999;
  pres=-999;
  
  // Humidity measurement
  hum = dht.readHumidity();
  if(isnan(hum)){ 
    hum = -999;
    Serial.println("error retrieving pressure measurement");
  }
  
  // Temperature measurement
  status = pressure.startTemperature();
  if (status != 0){
    delay(status);
    status = pressure.getTemperature(T);
    
    if (status != 0){  
      temp = (float)T;
    }
    else Serial.println("error retrieving temperature measurement");  
  }
  else Serial.println("error starting temperature measurement");
  
  // Pressure measurement
  status = pressure.startPressure(3);
  if (status != 0 && temp != -999){      
    delay(status);
    status = pressure.getPressure(P,T);
    
    if (status != 0){
      pres = (float)pressure.sealevel(P,ALTITUDE); 
    }
    else Serial.println("error retrieving pressure measurement");   
  }
  else Serial.println("error starting pressure measurement");

  // Print values via serial (debugging only)     
  Serial.print("temperature: ");
  Serial.print(temp);
  Serial.print(" C <> ");  
  Serial.print("pressure: ");
  Serial.print(pres);
  Serial.print(" HPa <> ");
  Serial.print("humidity: ");
  Serial.print(hum);
  Serial.println(" % ");
  
  //Wait between measurements
  delay(INTERVAL); 
}
