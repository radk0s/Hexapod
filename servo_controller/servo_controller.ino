#include <Servo.h>
#include "Leg.h"
#include "pins_config.h"

#define LED_PIN 13

Leg rightLeg(LEFT_FRONT_KNEE, LEFT_FRONT_HORI, LEFT_FRONT_VERT);

void setup(){
  pinMode(LED_PIN, OUTPUT);
  rightLeg.initPosition(30,30,30);
}

int i= 0;
void loop(){
  if(i == 0) {
    rightLeg.kneeMovement(150);
    rightLeg.horizontalMovement(150);
    rightLeg.verticalMovement(150);
    delay(1000);
    rightLeg.horizontalMovement(30);
    rightLeg.kneeMovement(30); 
    rightLeg.verticalMovement(30); 
    i++;
  }
  digitalWrite(LED_PIN, LOW);
  delay(300);
  digitalWrite(LED_PIN, HIGH); 
  delay(300);


}


