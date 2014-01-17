
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
    knee_current_pos = degrees;
    servo_knee.write(reverseDegreesIfLeft(degrees)); 
}

void Leg::incKnee()
{ 
    ++knee_current_pos;
    servo_knee.write(reverseDegreesIfLeft(knee_current_pos)); 
}

void Leg::decKnee()
{ 
    --knee_current_pos;
    servo_knee.write(reverseDegreesIfLeft(knee_current_pos)); 
}

int Leg::horizontalMovement(int degrees)
{ 
    horizontal_current_pos = degrees;  
    servo_horizontal.write(reverseDegreesIfLeft(degrees));
}

void Leg::incHorizontal()
{ 
    ++horizontal_current_pos;
    servo_horizontal.write(reverseDegreesIfLeft(horizontal_current_pos)); 
}

void Leg::decHorizontal()
{ 
    --horizontal_current_pos;
    servo_horizontal.write(reverseDegreesIfLeft(horizontal_current_pos)); 
}

int Leg::verticalMovement(int degrees)
{ 
    vertical_current_pos = degrees;  
    servo_vertical.write(reverseDegreesIfLeft(degrees));
}

void Leg::incVertical()
{ 
    ++vertical_current_pos;
    servo_vertical.write(reverseDegreesIfLeft(vertical_current_pos)); 
}

void Leg::decVertical()
{ 
    --vertical_current_pos;
    servo_vertical.write(reverseDegreesIfLeft(vertical_current_pos)); 
}

int Leg::reverseDegreesIfLeft(int degree){
  if(is_right_leg)  
    return degree;
  else
    return 180-degree; 
}










