// array of LED pins:
const int ledPins[] = {10,11,12,13};
const int ledPinCount = 4;

// array of momentary buttons on pins:
const int buttonPins[] = {2};

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
  setupButtonPins();
  setupLEDPins();
}

void loop(){
  for (int thisPin = 2; thisPin <= 9; thisPin++){
    detect_and_countdown(thisPin);
  }
}

void detect_and_countdown(int buttonPin){
  buttonState = digitalRead(buttonPin);
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
 if (buttonState == HIGH) {     
    // turn LEDs on:
    for(int i=0; i <= ledPinCount; i++){
      digitalWrite(ledPins[i], HIGH);
    }
    
    delay(1000);
    
    for(int i=0; i <= ledPinCount; i++){
      blink(ledPins[i], 3);
      digitalWrite(ledPins[i], LOW);
    }
  }
}

void blink(int led, int repeats){
  for(int i=0; i < repeats; i++) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(300);               // wait for a 0.5 second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(300);               // wait for a 0.5 second 
  }
}
