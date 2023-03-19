/*
Making a N/O push-button connect to the Arduino Using the built in pull up resistors. 
Display 0 ,if the push-button is pressed, on the serial monitor. 
Display 1 ,if the push-button is not pressed, on the serial monitor
Green LED blinks all the time
*/
// constants won't change. Used here to set a pin number:
const int Green = LED_BUILTIN;  // the number of the LED pin

// Variables will change:
int ledState = LOW;  // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated

// constants won't change:
const long interval = 5000;  // interval at which to blink (milliseconds)
int inpin = 12;                  // Name pin 12 "inpin"
int Green = 2;                    // Name pin 2 "blue" because it is connected to the blue LED



void setup() {
  // put your setup code here, to run once:
pinMode(inpin, INPUT_PULLUP);    // This will be used to set the input as a pullup resistor
pinMode(Blue, OUTPUT);
pinMode(Green, OUTPUT);
Serial.begin(9600);              // Set Baud rate to 9600
}

void loop() {
  // put your main code here, to run repeatedly:
int State = digitalRead(inpin);   // Reads the value of inpin
Serial.print("ThePBvalue=");      // Displays the value in the quotation mark
Serial.print("\t");               // Displays a tab space
Serial.println(!State);           // Displays the value on the serial monitor inverted because of the "!"


unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(Green, ledState);
  }






}
