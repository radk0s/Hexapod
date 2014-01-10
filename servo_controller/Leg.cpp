
#include <Arduino.h>
#include "Leg.h"
#include <Servo.h>

Leg::Leg( int knee_pin, int horizontal_pin, int vertical_pin, boolean is_right_leg){
  this -> knee_pin = knee_pin;
  this -> horizontal_pin = horizontal_pin; 
  this -> vertical_pin = vertical_pin;  
  this -> is_right_leg = is_right_leg; 
}

void Leg::initPosition( int init_knee_pos, int init_horiz_pos, int init_vert_pos)
{
  servo_knee.attach(knee_pin);
  servo_horizontal.attach(horizontal_pin);
  servo_vertical.attach(vertical_pin);
  servo_knee.write(init_knee_pos);
  servo_horizontal.write(init_horiz_pos);
  servo_vertical.write(init_vert_pos);
  knee_current_pos = init_knee_pos;
  horizontal_current_pos = init_horiz_pos;
  vertical_current_pos = init_vert_pos;
}

int Leg::kneeMovement(int degrees)
{ 
  if(is_right_leg)  
    servo_knee.write(degrees);
  else
    servo_knee.write(180-degrees);  
}

int Leg::horizontalMovement(int degrees)
{                                
  if(is_right_leg)  
    servo_horizontal.write(degrees);
  else
    servo_horizontal.write(180-degrees); 
}

int Leg::verticalMovement(int degrees)
{                                
  if(is_right_leg)  
    servo_vertical.write(degrees);
  else
    servo_vertical.write(180-degrees); 
}










