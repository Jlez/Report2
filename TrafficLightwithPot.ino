/*
Using a potentiometer, read the value from an analog input and connect it to an analog output. 
The output will change the color of an RGB LED depending on the input.
*/
int Red = 3;
int Green = 5;
int Blue = 6;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  // Set the Baud rate to 9600
pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int in = analogRead(A0);        // The analog input is stored as an integer
Serial.print("raw input= ");    // Displaying the raw input directly from the analog input
Serial.print(in);               
float volt = in*5.0/1023.0;     // Using y=mx+b, the input from the analog input is used to find the voltage going into the analog input
Serial.print("\t");             
Serial.print("Voltage= ");      // The voltage found is displayed on the serial monitor
Serial.print(volt);

if (in <= 341) {                                  // If the potentiometer value is <= 341, LED becomes green
  // The first third of the possible input
  Serial.println("     Go!")  ;                   // display this on serial monitor
  analogWrite(Red, 15);                           // this combination makes green
  analogWrite(Green, 161);
  analogWrite(Blue, 43);
}
else if (in > 341 && in < 682) {                  // If the potentiometer value is >341 and < 682, LED becomes orange
  // The Second third of the possible input
  Serial.println("     Wait...");                 // display this on serial monitor
  analogWrite(Red, 245);                          // this combination makes orange
  analogWrite(Green, 234);
  analogWrite(Blue, 19);
}
else {                                           // otherwise, LED becomes red
  // The third third of the possible input
  Serial.println("     STOP!!!");                // display this on serial monitor
  analogWrite(Red, 249);                         // this combination makes red
  analogWrite(Green, 32);
  analogWrite(Blue, 15);
}

}


