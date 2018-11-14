#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LCD lcd;
Zumo32U4Motors motors;
Zumo32U4ProximitySensors proxSensors;
Zumo32U4ButtonA buttonA;

const uint8_t sensorThreshold = 2;
const uint16_t turnSpeedMax = 400;
const uint16_t turnSpeedMin = 100;
const uint16_t deceleration = 10;
const uint16_t acceleration = 10;
uint16_t turnSpeed = turnSpeedMax;

void setup() {
  proxSensors.initThreeSensors();
  lcd.clear();
  lcd.print(F("Press A"));
  buttonA.waitForButton();
  lcd.clear();
}

void turnRight() {
  motors.setSpeeds(turnSpeed, -turnSpeed);
}

void turnLeft() {
  motors.setSpeeds(-turnSpeed, turnSpeed);
}

void chargeForward() {
  motors.setSpeeds(turnSpeed, turnSpeed);
}

void loop() {
  proxSensors.read();
  uint8_t FLValue = proxSensors.countsFrontWithLeftLeds();
  uint8_t FRValue = proxSensors.countsFrontWithRightLeds();

  uint8_t LLValue = proxSensors.countsLeftWithLeftLeds();

  uint8_t RRValue = proxSensors.countsRightWithRightLeds();

  bool left = LLValue > sensorThreshold;
  bool right = RRValue > sensorThreshold;

  if (FLValue >= LLValue && FRValue >= RRValue) {
    chargeForward();
  } else if (LLValue >= RRValue && LLValue >= FRValue && LLValue >= FLValue) {
    turnLeft();
  } else if (RRValue >= LLValue && RRValue >= FRValue && RRValue >= FLValue) {
    turnRight();
  }

  lcd.clear();
  lcd.print(LLValue);
  lcd.print(' ');
  lcd.print(RRValue);

  lcd.gotoXY(0,1);
  lcd.print(FLValue);
  lcd.print(' ');
  lcd.print(FRValue);  
}
