// EXCERCISE
// What do we need to do to run the blink code when BOTH buttons are pressed?

// HINT
// If you want to compare two things, separate them by using &&

// This code runs before code that runs in the loop function below
void setup() {
  // pinMode tells the arduino that the entered pin number (12) is sending data (OUTPUT) 
  pinMode(12, OUTPUT);
  // We'll set up the gpio pin the button is connected to (13) for reading data (INPUT)
  pinMode(13, INPUT);
}

// This code runs repeatedly
void loop() {
  int input = digitalRead(13);
  // If the button is pressed, we'll run the blink code from the last example
  if (input == HIGH) {
    //You can write HIGH or LOW to a pin
    digitalWrite(12, HIGH);
    //Pause for a thousand milliseconds (1 second)
    delay(1000); 
    // Writing low onto a pin will turn send no current through the pin 
    digitalWrite(12, LOW);
    //Pause for another second
    delay(1000);
  } else {
    // If the button is not pressed, we'll turn off the light
    digitalWrite(12, LOW);
  }
}