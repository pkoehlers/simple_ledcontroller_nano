/* 
  Simple program for a arduino nano driven LED strip.

  The LED strip is dimmable and warm white, so only brightness can be adjusted via PWM through a MOSFET. (connected to ledPin)

  The brightness will be controlled by a potentiometer.

  Additional logic is needed to stabilize the potentiometer values. Adding a capacitor did not eliminate all flickering, especially when the poti
  is turned to 0 and the light should be off...
*/

int potPin = A0;    // select the input pin for the potentiometer
int ledPin = 5;   // select the pin for the LED

int steps = 64; // in how many steps the light should be dimmable

int val = 0;       // variable to store the value coming from the potentiometer
int lastVal = 0;   // variable to store the last parsed value from the potentiometer
int counter = 0;   // counts how often the same value has been seen

void setup() {
  //Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(13, OUTPUT);  
  digitalWrite(13, LOW);   
}

void loop() {
  val = analogRead(potPin);    // read the value from the sensor
  
  int rest = val % steps;

  if (rest > 0) {
    val = val + steps - rest;
    val = val / 4 - 1;
  }

  if (counter < 3) {
    if (val == lastVal) {
      counter += counter;
    }
    
  } else {
    analogWrite(ledPin, val);
  }

  lastVal = val;
  //Serial.println(val);
  delay(200);
}
