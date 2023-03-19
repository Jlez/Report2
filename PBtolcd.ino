/*
Using a potentiometer, read the value from an analog input and display it on the serial monitor.
Then, display it on the LCD display.
If a PB is pressed, display Voltage.
If a PB is not pressed, display Bit value.
*/
#include <LiquidCrystal.h>          // Allows the lcd library to be referenced for new functions

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int inpin = 8;                  // Name pin 8 "inpin"

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  // Set the Baud rate to 9600
lcd.begin(15, 1);    // Declare the amount of colums and rows needed
pinMode(inpin, INPUT_PULLUP);    // This will be used to set the input as a pullup resistor
}

void loop() {
  // put your main code here, to run repeatedly:
int State = digitalRead(inpin);   // Reads the value of inpin



if (State == HIGH ) {           // because of the Pull Up resistor, the state is inverted so when it is not pressed, it is HIGH
int in = analogRead(A0);        // The analog input is stored as an integer
Serial.print("raw input= ");    // Display the raw input directly from the analog input, to the serial monitor
Serial.println(in);               
lcd.setCursor(0,0);             // Start the line at the first column and first row of the lcd
lcd.print("raw input= ");       // Display the raw input directly from the analog input, to the lcd
lcd.print(in);
}

else {
int in = analogRead(A0);        // The analog input is stored as an integer
float volt = in*5.0/1023.0;     // Using y=mx+b, the input from the analog input is used to find the voltage going into the analog input
Serial.print("\t");             
Serial.print("Voltage= ");      // The voltage found is displayed on the serial monitor
Serial.println(volt);
lcd.setCursor(0,0);             // Start the line at the first column and second row of the lcd
lcd.print("Voltage= ");         // Display the Voltage directly from the analog input, to the lcd
lcd.print(volt);
}

delay(30);                   // Clears the display every 30 milliseconds
lcd.clear();                 // Use the delay to make the lcd flicker less





}
