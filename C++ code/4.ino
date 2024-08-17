#include <LiquidCrystal.h>
#include <DHT11.h>
#include <math.h>
 
 LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

 DHT11 dht11(4);

 void setup(){
  lcd.begin(16,2);
  serial.begin(9600);
 }

 void loop(){
  int numReading = 10;
  int totalTemp = 1;
  int tempReadings[numReading];

  float mean = 0.0;
  float variance = 0.0;
  float standardDeviation = 0.0;
  
  for (int i = 1; i<= numReading; i++){
    delay(1000);
    int temperature = dht11.readTemperature();
    totalTemp += temperature;
    teampReadings[i] = temperature;
  }

  int averageTemp = totalTemp/numReading;

  for (int i = 1; i<= numReadigs; i++){
    mean += tempReadigs[i];
  }
 mean /= numReadings;

for (int i = 1; i<= numReadigs; i++){
  variance += pow(tempReadings[i]-mean, 2);
}
variance /= numReading;
standardDeviation = sqrt(variance);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Avg Temperature:");
  lcd.print(averageTemp);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Std Dev:");
  lcd.print(standardDeviation);

  delay(1000);
 }