// EXCERCISE
// Can we light up another led?

// HINT
// We can reuse the pinMode and digitalWrite functions, but modify them slightly 

// This code runs before code that runs in the loop function below
void setup() {
  // This begins the serial monitor on the computer programming the Arduino.
  // We can use this to write text from the arduino back to the host computer.
  // The 9600 is the transmission rate in bits per second (baud)
  Serial.begin(9600);
  Serial.println("Greetings Programs!");
}

void loop() {
  // The loop is intentionally left blank.
  // What would happen if we printed something in here?
}