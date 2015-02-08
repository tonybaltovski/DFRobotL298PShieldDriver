#include "DFRobotL298PShield.h"


// Constructor
DFRobotL298PShield::DFRobotL298PShield()
{
  left_invert_direction_ = 1;
  right_invert_direction_ = 1;
}


void DFRobotL298PShield::init()
{
  // Initializes the pins
  pinMode(LEFT_PWM, OUTPUT);
  pinMode(LEFT_EN, OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);
  pinMode(RIGHT_EN, OUTPUT);
}

void DFRobotL298PShield::flip_left_motor_direction()
{
  left_invert_direction_ *= -1;
}

void DFRobotL298PShield::flip_right_motor_direction()
{
  right_invert_direction_ *= -1;
}

void DFRobotL298PShield::left_set_pwm(int16_t desired_pwm)
{
  // Sets the pwm value.  Will take negative pwm values.
  if (desired_pwm < 0)
  {
    digitalWrite(LEFT_EN, LOW);
    if (desired_pwm < -255)
      desired_pwm = -255;
    analogWrite(LEFT_PWM, left_invert_direction_ * -1 * desired_pwm);
  }
  else
  {
    digitalWrite(LEFT_EN, HIGH);
    if (desired_pwm > 255)
      desired_pwm = 255;
    analogWrite(LEFT_PWM, left_invert_direction_ * desired_pwm);
  }
}

void DFRobotL298PShield::right_set_pwm(int16_t desired_pwm)
{
  // Sets the pwm value.  Will take negative pwm values.
  if (desired_pwm < 0)
  {
    digitalWrite(RIGHT_EN, LOW);
    if (desired_pwm < -255)
      desired_pwm = -255;
    analogWrite(RIGHT_PWM, right_invert_direction_ * -1 * desired_pwm);
  }
  else
  {
    digitalWrite(RIGHT_EN, HIGH);
    if (desired_pwm > 255)
      desired_pwm = 255;
    analogWrite(RIGHT_PWM, right_invert_direction_ * desired_pwm);
  }
}
