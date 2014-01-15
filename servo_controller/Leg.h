#ifndef Leg_h
#define Leg_h

#include <Arduino.h>
#include <Servo.h>

class Leg {
private:
  int knee_pin;
  int horizontal_pin;
  int vertical_pin;
  boolean is_right_leg;

  Servo servo_knee;
  Servo servo_horizontal;
  Servo servo_vertical;

public:
  int knee_current_pos;
  int horizontal_current_pos;
  int vertical_current_pos;
  Leg(int knee_pin, int horizontal_pin, int vertical_pin, boolean is_right_leg);
  void initPosition(int knee, int horizontal, int vertical);
  int kneeMovement(int degrees);
  int horizontalMovement(int degrees);
  int verticalMovement(int degrees);
  int reverseDegreesIfLeft(int degree);
  void incKnee();
  void decKnee();
  void incHorizontal();
  void decHorizontal();
  void incVertical();
  void decVertical();
};

#endif
