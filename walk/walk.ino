#include <Servo.h>
#include "Leg.h"
#include "pins_config.h"

#define LED_PIN 13

Leg leg1(LEFT_FRONT_KNEE, LEFT_FRONT_HORI, LEFT_FRONT_VERT);
Leg leg2(LEFT_MIDDLE_KNEE, LEFT_MIDDLE_HORI, LEFT_MIDDLE_VERT);
Leg leg3(LEFT_REAR_KNEE, LEFT_REAR_HORI, LEFT_REAR_VERT);
Leg leg4(RIGHT_FRONT_KNEE, RIGHT_FRONT_HORI, RIGHT_FRONT_VERT);
Leg leg5(RIGHT_MIDDLE_KNEE, RIGHT_MIDDLE_HORI, RIGHT_MIDDLE_VERT);
Leg leg6(RIGHT_REAR_KNEE, RIGHT_REAR_HORI, RIGHT_REAR_VERT);

void setup(){
  pinMode(LED_PIN, OUTPUT);
  leg1.initPosition(90,90,90);
  leg2.initPosition(90,90,90);
  leg3.initPosition(90,90,90);
  leg4.initPosition(90,90,90);
  leg5.initPosition(90,90,90);
  leg6.initPosition(90,90,90);
  delay(1000);
}

int i= 0;
void loop(){
  if(i < 1){
    test();
    i++;
  }

}

void pompka(){
    leg1.kneeMovement(150);
    leg1.verticalMovement(150);
//    leg2.kneeMovement(150);
//    leg2.verticalMovement(150);
//    leg3.kneeMovement(150);
//    leg3.verticalMovement(150);
//    leg4.kneeMovement(150);
//    leg4.verticalMovement(150);
//    leg5.kneeMovement(150);
//    leg5.verticalMovement(150);
//    leg6.kneeMovement(150);
//    leg6.verticalMovement(150);
    delay(1000);
    leg1.kneeMovement(30); 
    leg1.verticalMovement(30);
//    leg2.kneeMovement(30); 
//    leg2.verticalMovement(30); 
//    leg3.kneeMovement(30); 
//    leg3.verticalMovement(30); 
//    leg4.kneeMovement(30); 
//    leg4.verticalMovement(30); 
//    leg5.kneeMovement(30); 
//    leg5.verticalMovement(30); 
//    leg6.kneeMovement(30); 
    delay(1000);   
}

void krok(){
  	leg1.verticalMovement(130);
	leg2.verticalMovement(130);
	leg5.verticalMovement(130);
  if(i < 3) {		
    
	delay(1000);
    leg1.kneeMovement(130);
	leg2.horizontalMovement(130);
	leg5.horizontalMovement(130); 
    delay(1000); 
	leg1.verticalMovement(90);
	leg2.verticalMovement(90);
	leg5.verticalMovement(90);
	delay(1000);
	leg6.verticalMovement(130);
	leg3.verticalMovement(130);
	leg4.verticalMovement(130);
    leg1.kneeMovement(90);
	leg2.horizontalMovement(50);
	leg5.horizontalMovement(50); 
	delay(1000);
	leg6.kneeMovement(90);
	leg3.horizontalMovement(130);
	leg4.horizontalMovement(130); 
    delay(1000); 
	leg6.verticalMovement(90);
	leg3.verticalMovement(90);
	leg4.verticalMovement(90);
	delay(1000);
	leg1.verticalMovement(130);
	leg2.verticalMovement(130);
	leg5.verticalMovement(130);
	leg1.kneeMovement(130);
	leg2.horizontalMovement(50);
	leg5.horizontalMovement(50); 
	delay(1000);
    i++;
  }
  digitalWrite(LED_PIN, LOW);
  delay(300);
  digitalWrite(LED_PIN, HIGH); 
  delay(300);

}

void test(){
    leg1.kneeMovement(180);
    leg1.horizontalMovement(180);
    leg1.verticalMovement(180);
    leg2.kneeMovement(180);
    leg2.horizontalMovement(180);
    leg2.verticalMovement(180);
    leg3.kneeMovement(180);
    leg3.horizontalMovement(180);
    leg3.verticalMovement(180);
    leg4.kneeMovement(180);
    leg4.horizontalMovement(180);
    leg4.verticalMovement(180);
    leg5.kneeMovement(180);
    leg5.horizontalMovement(180);
    leg5.verticalMovement(180);
    leg6.kneeMovement(180);
    leg6.horizontalMovement(180);
    leg6.verticalMovement(180);
}




