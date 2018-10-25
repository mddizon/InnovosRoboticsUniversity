// EXCERCISE
// Can we light up another led?

// HINT
// We can reuse the pinMode and digitalWrite functions, but modify them slightly 

// This code runs before code that runs in the loop function below
void setup() {
  // pinMode tells the arduino that the entered pin number (12) is sending data (OUTPUT) 
  pinMode(7, OUTPUT);
}

// This code runs repeatedly
void loop() {
  //You can write HIGH or LOW to a pin
  digitalWrite(7, HIGH);
}