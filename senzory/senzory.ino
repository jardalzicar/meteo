

#include <Wire.h>
#include <BMP085.h>
#include <DHT.h>

#define DHTPIN 2
#define VYSKA 275

BMP085 dps = BMP085();   
DHT dht(DHTPIN, DHT22);

long temp0, pres0; 
float temp, pres;
float hum; 
//float temp2;

void setup(void) {
  
  Serial.begin(9600);
  Wire.begin();
  dht.begin();
  dps.init(MODE_ULTRA_HIGHRES, VYSKA*100, true); 
  delay(1000);

}            

void loop(void) { 
  temp0 = NULL;
  pres0 = NULL;
 
  dps.getPressure(&pres0);
  dps.getTemperature(&temp0);
  
  if(pres0 != NULL){
    pres = (float) pres0/100;
  }
  else{
    Serial.println("Error reading pressure");
    pres = NULL;
  }
  
  if(temp0 != NULL){
    temp = (float) temp0/10;
  }
  else{
    Serial.println("Error reading temperature");
    temp = NULL;
  }
  
  


  
  hum = dht.readHumidity();
  //temp2 = dht.readTemperature();

  
  Serial.print("Teplota: ");
  Serial.print(temp);
  Serial.print(" C --- Vlhkost: ");
  Serial.print(hum);
  Serial.print("% --- Tlak : ");
  Serial.print(pres);
  Serial.println(" HPa");
  delay(2000);
}
