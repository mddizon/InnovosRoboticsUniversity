#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

void setup() {
  // put your setup code here, to run once:
  motors.flipLeftMotor(true);
  motors.flipRightMotor(true);
  buttonA.waitForButton();
}

void loop() {
  // put your main code here, to run repeatedly:
  motors.setSpeeds(-399.999999, -400);
}
