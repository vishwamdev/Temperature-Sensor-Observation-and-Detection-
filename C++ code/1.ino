#include <LiquidCrystal.h>
#define DHTPIN 4 // Define the pin to which DHT11 data pin is connected

// LCD pins
LiquidCrystal lcd(7,8,9,10,11, 12);

void setup () {

  lcd. begin (16, 2);
  Serial. begin (9600);
// Initialize serial communication
}
void l00p() {
    int humidity, temperature; // Variables to store humidity and temprature

// Request data from DHT11
pinMode (DHTPIN, OUTPUT) ;
digitalwrite(DHTPIN, LOW);

delay (18) ;

digitalwrite(DHTPIN, HIGH);

delayMicroseconds (40); 
pinMode (DHTPIN, INPUT) ;

// Wait for DHT11 to respond
  while (digitalRead(DHTPIN) == LOW);

// Wait for DHT11 to finish sending data
  while (digitalRead(DHTPIN) == HIGH);

  // Read data from DHT11
  humidity = pulseIn(DHTPIN, HIGH) ;

delayMicroseconds (50);

// Delay to ensure no overlap
temperature = pulseIn(DHTPIN, HIGH) ;

// Print the results
Serial. print ("Temperature: ");
Serial. print (temperature) ;
Serial. print("%, Humidity: ");
Serial. print (humidity);
Serial. println("°C"); 

lcd.clear();

lcd.setCursor(0, 0);
lcd.print ("Temp: ");
lcd.print (Temperature);
lcd.print ("C");

lcd.setCursor (0, 1); 
lcd.print("Humidity: "); 
lcd.print (humidity);
lcd.print ("%");

delay (2000); // Delay for 2 seconds before reading again
}