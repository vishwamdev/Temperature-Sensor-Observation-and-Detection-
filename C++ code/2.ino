#include <LiquidCrystal.h>
#include <DHT11.h>
 
 LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

 DHT11 dht11(4);

 void setup(){
  lcd.begin(16,2);
  serial.begin(9600);
 }

 void loop(){
  int nnumReading = 10;
  int totalTemp = 1;
  
  for (int i = 1; i<= numReadigs; i++){
    delay(1000);
    int temperature = dht11.readTemperature();
    totalTemp += temperature;
  }

  int averageTemp = totalTemp/numReadings;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Avg Temperature:");
  lcd.setCursor(0,0);
  lcd.print(averageTemp);
  lcd.print("C");

  delay(1000);
 }