/*
 Button withh blink and delay
 
 Designed for Arduno MEGA
 
 The circuit:
 * LED attached from pin 32 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 

 Originally created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 Modified Feb 1, 2014
 by Mike Dillion and Chase Southard
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
*/


// array of LED pins:
const int ledPins[] = {32,33,34,35,36,37,38,39};

// array of arcade button pins:
const int buttonPins[] = {2,3,4,5,6,7,8,9};

// variables will change:
// variable for reading the pushbutton status
int buttonState = 0;         

void setupButtonPins() {
  for (int thisPin = 0; thisPin <= 8; thisPin++)  {
    pinMode(buttonPins[thisPin], INPUT);      
  }
}

void setupLEDPins() {
  for (int thisPin = 0; thisPin <= 8; thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);      
  }
}

void setup() {
  // initialize the LED pin as an output:
  //pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  //pinMode(buttonPin, INPUT);     
  setupButtonPins();
  setupLEDPins();
}

void loop(){
  for (int thisPin = 2; thisPin <= 9; thisPin++){
    detect_and_burn(thisPin);
  }
}

void detect_and_burn(int buttonPin){
  buttonState = digitalRead(buttonPin);
  
  // no hashes. buttons on 2 - 9; LEDs on 32 - 39; just add 30 to button pin
  // wire up the leds to pins in the 30 range
  int ledPin = buttonPin + 30;
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
 if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);
    // wait 50 seconds
    delay(50000);
    // blink for 10 seconds
    blink(ledPin);
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
}

// flash for 10 seconds
void blink(int led){
  for(int i=0; i<10; i++) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);               // wait for a 0.5 second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(500);               // wait for a 0.5 second 
  }
}
