#include "DFRobotL298PShield.h"

DFRobotL298PShield motors;

void setup()
{
  motors.init();
}

void loop()
{
  for (int x = 0; x < 256;x++)
  {
    motors.left_set_pwm(x);
    motors.right_set_pwm(-x);
    delay(25);
  }
}

