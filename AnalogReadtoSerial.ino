/*
Using a potentiometer, read the value from an analog input and display it on the serial monitor.
It can be used as a voltmeter
*/

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  // Set the Baud rate to 9600
}

void loop() {
  // put your main code here, to run repeatedly:
int State = digitalRead(inpin);   // Reads the value of inpin

int in = analogRead(A0);        // The analog input is stored as an integer
Serial.print("raw input= ");    // Display the raw input directly from the analog input, to the serial monitor
Serial.println(in);               

int in = analogRead(A0);        // The analog input is stored as an integer
float volt = in*5.0/1023.0;     // Using y=mx+b, the input from the analog input is used to find the voltage going into the analog input
Serial.print("\t");             
Serial.print("Voltage= ");      // The voltage found is displayed on the serial monitor
Serial.println(volt);
}
