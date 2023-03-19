/*
Manually select the color for the RGB LED.
A value between 0 and 255 must be selected with 255 being the brightest and 0 being the dimest.
*/
int Red = 3;                       // pin 3 is labeled Red
int Green = 5;                     // pin 5 is labeled Green
int Blue = 6;                      // pin 6 is labeled Blue
void setup() {
  // put your setup code here, to run once:

pinMode(3, OUTPUT);                // set pin 3 as OUTPUT
pinMode(5, OUTPUT);                // set pin 5 as OUTPUT
pinMode(6, OUTPUT);                // set pin 6 as OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
 
  analogWrite(Red, 15);            // set the value of the Red color here
  analogWrite(Green, 161);         // set the value of the Green color here
  analogWrite(Blue, 43);           // set the color of the Blue color here

}