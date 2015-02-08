#ifndef DFRobotL298PShield_H
#define DFRobotL298PShield_H

#include <Arduino.h>

// Pins are fixed since it is a shield
#define LEFT_PWM  7
#define LEFT_EN   6
#define RIGHT_PWM 4
#define RIGHT_EN  5

class DFRobotL298PShield
{
  public:
    // Constructor
    DFRobotL298PShield();
    // Public functions
    void init();  // Initializes the pins
    void left_set_pwm(int16_t desired_pwm);  // Sets the desired PWM value
    void right_set_pwm(int16_t desired_pwm);
    void flip_left_motor_direction();
    void flip_right_motor_direction();

  private:
    // Private variables
    int8_t left_invert_direction_;
    int8_t right_invert_direction_;
};

#endif  // DFRobotL298PShield_H
