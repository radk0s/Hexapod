#include <Servo.h>
#include "Leg.h"
#include "pins_config.h"

#define LED_PIN 13

Leg leg1(LEFT_FRONT_KNEE, LEFT_FRONT_HORI, LEFT_FRONT_VERT, false);
Leg leg2(LEFT_MIDDLE_KNEE, LEFT_MIDDLE_HORI, LEFT_MIDDLE_VERT, false);
Leg leg3(LEFT_REAR_KNEE, LEFT_REAR_HORI, LEFT_REAR_VERT, false);
Leg leg4(RIGHT_FRONT_KNEE, RIGHT_FRONT_HORI, RIGHT_FRONT_VERT, true);
Leg leg5(RIGHT_MIDDLE_KNEE, RIGHT_MIDDLE_HORI, RIGHT_MIDDLE_VERT, true);
Leg leg6(RIGHT_REAR_KNEE, RIGHT_REAR_HORI, RIGHT_REAR_VERT, true);

void setup(){
  pinMode(LED_PIN, OUTPUT);
  leg1.initPosition(90,90,90);
  leg2.initPosition(90,90,90);
  leg3.initPosition(90,90,90);
  leg4.initPosition(90,90,90);
  leg5.initPosition(90,90,90);
  leg6.initPosition(90,90,90);
//	leg1.verticalMovement(130);
//	leg2.verticalMovement(130);
//	leg5.verticalMovement(130);
}

int i= 0;
void loop(){
  
  if(i < 6) {
    twist();
    i++;
  }
  digitalWrite(LED_PIN, LOW);
  delay(300);
  digitalWrite(LED_PIN, HIGH); 
  delay(300);


}

void pompka(){
    leg1.kneeMovement(90);
    leg1.verticalMovement(90);
    leg2.kneeMovement(90);
    leg2.verticalMovement(90);
    leg3.kneeMovement(90);
    leg3.verticalMovement(90);
    leg4.kneeMovement(90);
    leg4.verticalMovement(90);
    leg5.kneeMovement(90);
    leg5.verticalMovement(90);
    leg6.kneeMovement(90);
    leg6.verticalMovement(90);
    delay(1000);
    leg1.kneeMovement(130); 
    leg1.verticalMovement(130);
    leg2.kneeMovement(130); 
    leg2.verticalMovement(130); 
    leg3.kneeMovement(130); 
    leg3.verticalMovement(130); 
    leg4.kneeMovement(130); 
    leg4.verticalMovement(130); 
    leg5.kneeMovement(130); 
    leg5.verticalMovement(130); 
    leg6.kneeMovement(130); 
    leg6.verticalMovement(130);
    delay(1000);   
}

void twist(){
    leg1.horizontalMovement(90);

    leg2.horizontalMovement(90);

    leg3.horizontalMovement(90);

    leg4.horizontalMovement(90);

    leg5.horizontalMovement(90);

    leg6.horizontalMovement(90);

    delay(1000);
    leg1.horizontalMovement(130); 

    leg2.horizontalMovement(130); 

    leg3.horizontalMovement(130); 

    leg4.horizontalMovement(130); 

    leg5.horizontalMovement(130); 

    leg6.horizontalMovement(130); 
    delay(1000);   
}


void krok(){
      
	delay(1000);
        leg1.kneeMovement(50);
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
	leg1.kneeMovement(50);
	leg2.horizontalMovement(50);
	leg5.horizontalMovement(50); 
	delay(1000);
}






