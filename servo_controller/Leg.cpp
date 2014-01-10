
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
  servo_knee.write(reverseDegreesIfLeft(init_knee_pos));
  servo_horizontal.write(reverseDegreesIfLeft(init_horiz_pos));
  servo_vertical.write(reverseDegreesIfLeft(init_vert_pos));
  knee_current_pos = init_knee_pos;
  horizontal_current_pos = init_horiz_pos;
  vertical_current_pos = init_vert_pos;
}

int Leg::kneeMovement(int degrees)
{ 
    int pos;
    if (degrees > knee_current_pos)
      for(pos = knee_current_pos; pos <= degrees; pos += 1)  
      {                                  
          servo_knee.write(reverseDegreesIfLeft(pos));
          knee_current_pos = pos;      
          delay(20);                       
      }
    else
      for(pos = knee_current_pos; pos >= degrees; pos -= 1)  
      {                                  
          servo_knee.write(reverseDegreesIfLeft(pos));
          knee_current_pos = pos;      
          delay(20);                       
      };
  
    
}

int Leg::horizontalMovement(int degrees)
{                                  
    servo_horizontal.write(reverseDegreesIfLeft(degrees));
}

int Leg::verticalMovement(int degrees)
{                                
    servo_vertical.write(reverseDegreesIfLeft(degrees));
}

int Leg::reverseDegreesIfLeft(int degree){
  if(is_right_leg)  
    return degree;
  else
    return 180-degree; 
}










