// Constants for defining pin numbers
const int pirPin1 = 2;    // PIR sensor 1 connected to digital pin 7
const int pirPin2 = 3;    // PIR sensor 2 connected to digital pin 6
const int redPin1 = 13;   // Red LED 1 connected to digital pin 13
const int redPin2 = 9;    // Red LED 2 connected to digital pin 9
const int greenPin1 = 10; // Green LED 1 connected to digital pin 10
const int greenPin2 = 8;  // Green LED 2 connected to digital pin 8

// Variable to store PIR sensor values
int pirValue1 = 0;
int pirValue2 = 0;

void setup() {
  // Initialize the digital pins
  pinMode(pirPin1, INPUT);
  pinMode(pirPin2, INPUT);
  pinMode(redPin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(greenPin2, OUTPUT);
}

void loop() {
  // Read the value from PIR sensor 1
  pirValue1 = digitalRead(pirPin1);

  // Read the value from PIR sensor 2
  pirValue2 = digitalRead(pirPin2);

  // If motion is detected by PIR sensor 1
  if (pirValue1 == HIGH) {
    // Blink red light 2 and turn off red light 1
    blinkRed(redPin2);
    digitalWrite(redPin1, LOW);
  } 
  // If motion is detected by PIR sensor 2
  else if (pirValue2 == HIGH) {
    // Blink red light 1 and turn off red light 2
    blinkRed(redPin1);
    digitalWrite(redPin2, LOW);
  } 
  else {
    // If no motion detected, blink both green lights
    blinkGreen();
  }
}

// Function to blink a red light
void blinkRed(int redPin) {
  // Blink the red light 3 times
  for (int i = 0; i < 3; i++) {
    digitalWrite(redPin, HIGH);  // Turn on the red light
    delay(300);                   // Wait for 500 milliseconds
    digitalWrite(redPin, LOW);   // Turn off the red light
    delay(300);                   // Wait for 500 milliseconds

  }
}

// Function to blink both green lights
void blinkGreen() {
  // Blink both green lights 3 times
  for (int i = 0; i < 3; i++) {
    digitalWrite(greenPin1, HIGH);  // Turn on green light 1
    digitalWrite(greenPin2, HIGH);  // Turn on green light 2
    delay(300);                     // Wait for 500 milliseconds
    digitalWrite(greenPin1, LOW);   // Turn off green light 1
    digitalWrite(greenPin2, LOW);   // Turn off green light 2
    delay(300);                     // Wait for 500 milliseconds
  }
}