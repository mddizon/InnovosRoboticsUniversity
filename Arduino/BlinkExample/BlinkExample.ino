// This code runs before code that runs in the loop function below
void setup() {
  // pinMode tells the arduino that the entered pin number (12) is sending data (OUTPUT) 
  pinMode(12, OUTPUT);
}

// This code runs repeatedly
void loop() {
  //You can write HIGH or LOW to a pin
  digitalWrite(12, HIGH);
  //Pause for a thousand milliseconds (1 second)
  delay(1000); 
  // Writing low onto a pin will turn send no current through the pin 
  digitalWrite(12, LOW);
  //Pause for another second
  delay(1000);
}