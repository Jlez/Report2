/*
Using a potentiometer, read the value from an analog input and display it on the serial monitor.
Then, display it on the LCD display.
If a PB is pressed, display Voltage.
If a PB is not pressed, display Bit value.
*/
#include <LiquidCrystal.h>          // Allows the lcd library to be referenced for new functions

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte customChar[8] = {             // template for the Ohm symbol
	0b00000,
	0b00000,
	0b01110,
	0b10001,
	0b10001,
	0b01010,
	0b11011,
	0b00000
};

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  // Set the Baud rate to 9600
lcd.createChar(0, customChar);
lcd.begin(15, 1);    // Declare the amount of colums and rows needed
lcd.write((uint8_t)0);

}

void loop() {
  // put your main code here, to run repeatedly:


int in = analogRead(A0);         // The analog input is stored as an integer
float Res = in*5.0/1023.0;       // find resistance based on input voltage           
Serial.print("Resistor= ");      // The voltage found is displayed on the serial monitor
Serial.print(Res);
Serial.println("Ohms");
lcd.setCursor(0,0);             // Start the line at the first column and first row of the lcd
lcd.print("Voltage= ");         // Display the Voltage directly from the analog input, to the lcd
lcd.print(volt);


delay(30);                   // Clears the display every 30 milliseconds
lcd.clear();                 // Use the delay to make the lcd flicker less


}
