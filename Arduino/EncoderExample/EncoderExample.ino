#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Encoders encoders;
Zumo32U4LCD lcd;
Zumo32U4Buzzer buzzer;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonA buttonB;
Zumo32U4ButtonC buttonC;

const char encoderErrorLeft[] PROGMEM = "!<c2";
const char encoderErrorRight[] PROGMEM = "!<e2";

char report[80];

bool MOVING_FORWARD = true;
bool TURN = false;
bool BACKWARD = false;

void setup()
{

}

void loop()
{
  static uint8_t lastDisplayTime;
  static uint8_t displayErrorLeftCountdown = 0;
  static uint8_t displayErrorRightCountdown = 0;

  int16_t countsLeft = encoders.getCountsLeft();
  int16_t countsRight = encoders.getCountsRight();

  if (MOVING_FORWARD) { 
    int16_t forwardDistance = 3400;
    
    if (countsLeft <= forwardDistance) {
      motors.setLeftSpeed(200);
    }
  
    if (countsRight <= forwardDistance) {
      motors.setRightSpeed(200);
    }

    if (countsLeft >= forwardDistance && countsRight >= forwardDistance) {
      MOVING_FORWARD = false;
      TURN = true;
    }
  }

  if (TURN) {
    int16_t rotation = 4700;

    if (countsLeft <= rotation) {
      motors.setLeftSpeed(200);
    }

    if (countsLeft > rotation) {
      TURN = false;
      BACKWARD = true;
    }
  }

  if (BACKWARD) {
    motors.setSpeeds(-200, -200);
  }

  if ((uint8_t)(millis() - lastDisplayTime) >= 100)
  {
    lastDisplayTime = millis();
    lcd.clear();
    lcd.print(countsLeft);
    lcd.gotoXY(0,1);
    lcd.print(countsRight);
  }

  if (buttonA.isPressed())
  {
    motors.setSpeeds(400, 400);
  }
  else if (buttonC.isPressed())
  {
    motors.setSpeeds(-400, -400);
  }
  else
  {
    motors.setSpeeds(0, 0);
  }
}
