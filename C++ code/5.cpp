#include "mbed.h" 
#include "C12832A1Z.h" 
#include "DHT.h"
#include <cmath>

#define DHTTYPE DHT11
#define DHTPIN 4
 
C12832A1Z lcd(p15, p16, p17, p18, p19, p20);

DHT dht11(DHTPIN, DHTTYPE);

int main(){
    lcd.cls();
    lcd.printf("Initializing...");

dht11.begin();

while(1){

  int numReading = 10;
  int totalTemp = 0;
  int tempReading[numReading];

  float mean = 0.0;
  float variance = 0.0;
  float standardDeviation = 0.0;
  
  for (int i = 1; i<= numReading; i++){
    delay(1000);
    int temperature = dht11.readTemperature();
    totalTemp += temperature;
    tempReading[i] = temperature;
  }

  int averageTemp = totalTemp/numReading;

  for (int i = 1; i<= numReading; i++){
    mean += tempReading[i];
  }
 mean /= numReading;

for (int i = 1; i<= numReading; i++){
  variance += pow(tempReading[i]-mean, 2);
}
variance /= numReading;
standardDeviation = sqrt(variance);

  lcd.cls();
  lcd.setCursor(0,0);
  lcd.print("Avg Temp: %d c", averageTemp);

  lcd.locate(0,1);
  lcd.printf("std Dev: %.2f c", standardDeviation);

  wait(10);
 }
}