

#include <Wire.h>
#include <BMP085.h>
#include <DHT.h>

#define DHTPIN 2

BMP085 dps = BMP085();   
DHT dht(DHTPIN, DHT22);

long temp0 = 0, pres0 = 0; 
float temp, pres;
float hum; 
//float temp2;

void setup(void) {
  
  Serial.begin(9600);
  Wire.begin();
  dht.begin();
  delay(1000);
  dps.init(MODE_ULTRA_HIGHRES, 27500, true); 

}            

void loop(void) { 
 
  dps.getPressure(&pres0);
  dps.getTemperature(&temp0);
  pres = (float) pres0/100;
  temp = (float)temp0/10;
  
  hum = dht.readHumidity();
  //temp2 = dht.readTemperature();

  
  Serial.print("Teplota: ");
  Serial.print(temp);
  //Serial.print(" Teplota 2: ");
  //Serial.print(temp2);
  Serial.print(" C --- Vlhkost: ");
  Serial.print(hum);
  Serial.print("% --- Tlak : ");
  Serial.print(pres);
  Serial.println(" HPa");
  delay(2000);
}
