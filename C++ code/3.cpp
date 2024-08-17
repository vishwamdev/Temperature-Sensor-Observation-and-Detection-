#include "mbed.h" 
#include "C12832A1Z.h" 
#include "DHT.h"

C12832A1Z lcd(p15, p16, p17, p18, p19, p20);

DHT dht(p10 DHT11);

int main(){
    lcd.cls();
    lcd.printf("Initializing...");

    while(1){
        int numReadings = 10;
        int totalTemp = 0;

        for (int i = 0; i<numReadings; i++){
            wait(1.0);
            int temperature = dht.readTeamperature();
            totalTemp += temperature;
        }
        int averageTemp = totalTemp/numReadings;

        lcd.cls();
        lcd.locate(o,o);
        lcd.printf("Avg Temperature:");
        lcd.locate(0,1);
        lcd.printf("%d c", averageTemp);

        wait(10.0);
    }
}