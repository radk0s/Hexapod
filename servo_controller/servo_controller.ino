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
// 180 w pione - gora
// 180 poziom - w przod
// 180 w kolanie - zgiete
void setup(){
//  pinMode(LED_PIN, OUTPUT);
//  pinMode(SRF_ECHO_1, INPUT);
//  pinMode(SRF_TRIG_1, OUTPUT);
  leg1.initPosition(90,90,90);
  leg2.initPosition(90,90,90);
  leg3.initPosition(90,90,90);
  leg3.initPosition(90,90,90);
  leg4.initPosition(90,90,90);
  leg5.initPosition(90,90,90);
  leg6.initPosition(90,90,90);
  delay(2000);
}

int i= 0;
void loop(){
//  if( getFrontDistance() < 30) {
//    obrot(20);
//  }  
  if(i < 6) {
    krok2();
    i++;
  }
}

int getFrontDistance(){
  digitalWrite(SRF_TRIG_1, LOW);                   // Set the trigger pin to low for 2uS
  delayMicroseconds(2);
  digitalWrite(SRF_TRIG_1, HIGH);                  // Send a 10uS high to trigger ranging
  delayMicroseconds(10);
  digitalWrite(SRF_TRIG_1, LOW);                   // Send pin low again
  int distance = pulseIn(SRF_ECHO_1, HIGH);        // Read in times pulse
  return distance/58;                              // Calculate distance from time of pulse in cm
}
void step(int sleep){  
  for(int i = 0; i<40; i ++){ // zmiana o 40 stopni // podnoszenie nog 1 3 5
   leg1.incVertical();
   leg3.incVertical();
   leg5.incVertical();
   leg1.incKnee();
   leg3.incKnee();
   leg5.incKnee();
   if( i % 2 == 0){
     leg2.decVertical();
     leg4.decVertical();
     leg6.decVertical();
     leg2.decKnee();
     leg4.decKnee();
     leg6.decKnee();
   }
   delay(sleep);
  } 
  
  for(int i = 0; i<40; i ++){ // zmiana o 40 stopni // opadanie nog 1 3 5
   leg1.decVertical();
   leg3.decVertical();
   leg5.decVertical();
   leg1.decKnee();
   leg3.decKnee();
   leg5.decKnee();
   if( i % 2 == 0){
     leg2.incVertical();
     leg4.incVertical();
     leg6.incVertical();
     leg2.incKnee();
     leg4.incKnee();
     leg6.incKnee();
   }
   delay(sleep);
  }  
  
  for(int i = 0; i<40; i ++){ // zmiana o 40 stopni // podnoszenie nog 2 4 6
   leg2.incVertical();
   leg4.incVertical();
   leg6.incVertical();
   leg2.incKnee();
   leg4.incKnee();
   leg6.incKnee();
   if( i % 2 == 0){
     leg1.decVertical();
     leg3.decVertical();
     leg5.decVertical();
     leg1.decKnee();
     leg3.decKnee();
     leg5.decKnee();
   }
   delay(sleep);
  } 
  
  for(int i = 0; i<40; i ++){ // zmiana o 40 stopni // opadanie nog 2 4 6
   leg2.decVertical();
   leg4.decVertical();
   leg6.decVertical();
   leg2.decKnee();
   leg4.decKnee();
   leg6.decKnee();
   if( i % 2 == 0){
     leg1.incVertical();
     leg3.incVertical();
     leg5.incVertical();
     leg1.incKnee();
     leg3.incKnee();
     leg5.incKnee();
   }
   delay(sleep);
  }    
}

void obrot(int sleep){
  
  for(int i = 0; i<40; i ++){ // zmiana o 40 stopni // podnoszenie nog 1 3 5
   leg1.incVertical();
   leg3.incVertical();
   leg5.incVertical();
   leg1.incKnee();
   leg3.incKnee();
   leg5.incKnee();
   leg1.incHorizontal();
   leg2.decHorizontal();
   leg3.incHorizontal();
   leg4.incHorizontal();
   leg5.decHorizontal();
   leg6.incHorizontal();
   
   if( i % 2 == 0){
     leg2.decVertical();
     leg4.decVertical();
     leg6.decVertical();
     leg2.decKnee();
     leg4.decKnee();
     leg6.decKnee();
   }
   delay(sleep);
  } 
  
  for(int i = 0; i<40; i ++){ // zmiana o 40 stopni // opadanie nog 1 3 5
   leg1.decVertical();
   leg3.decVertical();
   leg5.decVertical();
   leg1.decKnee();
   leg3.decKnee();
   leg5.decKnee();
   if( i % 2 == 0){
     leg2.incVertical();
     leg4.incVertical();
     leg6.incVertical();
     leg2.incKnee();
     leg4.incKnee();
     leg6.incKnee();
   }
   delay(sleep);
  }  
  
  for(int i = 0; i<40; i ++){ // zmiana o 40 stopni // podnoszenie nog 2 4 6
   leg2.incVertical();
   leg4.incVertical();
   leg6.incVertical();
   leg2.incKnee();
   leg4.incKnee();
   leg6.incKnee();
   leg1.decHorizontal();
   leg2.incHorizontal();
   leg3.decHorizontal();
   leg4.decHorizontal();
   leg5.incHorizontal();
   leg6.decHorizontal();
   if( i % 2 == 0){
     leg1.decVertical();
     leg3.decVertical();
     leg5.decVertical();
     leg1.decKnee();
     leg3.decKnee();
     leg5.decKnee();
   }
   delay(sleep);
  } 
  
  for(int i = 0; i<40; i ++){ // zmiana o 40 stopni // opadanie nog 2 4 6
   leg2.decVertical();
   leg4.decVertical();
   leg6.decVertical();
   leg2.decKnee();
   leg4.decKnee();
   leg6.decKnee();
   if( i % 2 == 0){
     leg1.incVertical();
     leg3.incVertical();
     leg5.incVertical();
     leg1.incKnee();
     leg3.incKnee();
     leg5.incKnee();
   }
   delay(sleep);
  }    
}

  
void pompka(){
    leg1.kneeMovement(60);
    leg1.verticalMovement(60);
    leg2.kneeMovement(60);
    leg2.verticalMovement(60);
    leg3.kneeMovement(60);
    leg3.verticalMovement(60);
    leg4.kneeMovement(60);
    leg4.verticalMovement(60);
    leg5.kneeMovement(60);
    leg5.verticalMovement(60);
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

void kneeTest(){
    leg1.kneeMovement(90);
    leg2.kneeMovement(90);
    leg3.kneeMovement(90);
    leg4.kneeMovement(90);
    leg5.kneeMovement(90);
    leg6.kneeMovement(90);
    delay(1000);
    leg1.kneeMovement(130); 
    leg2.kneeMovement(130); 
    leg3.kneeMovement(130); 
    leg4.kneeMovement(130); 
    leg5.kneeMovement(130); 
    leg6.kneeMovement(130); 
    delay(1000);   
}

void krok(){      
      leg1.verticalMovement(130);
	  leg3.verticalMovement(130);
      leg5.verticalMovement(130);
  
        delay(1000);
        leg1.kneeMovement(50);
        leg3.horizontalMovement(110);
        leg5.horizontalMovement(110);
        delay(1000);
        leg1.verticalMovement(90);
        leg3.verticalMovement(90);
        leg5.verticalMovement(90);
        delay(1000);
        leg6.verticalMovement(130);
        leg2.verticalMovement(130);
        leg4.verticalMovement(130);
        leg1.kneeMovement(90); 
        leg3.horizontalMovement(70);
        leg5.horizontalMovement(70);
        delay(1000);

        leg6.kneeMovement(110);
        leg2.horizontalMovement(110);
        leg4.horizontalMovement(110);
        delay(1000);
        leg6.verticalMovement(90);
        leg2.verticalMovement(90);
        leg4.verticalMovement(90);
        delay(1000);
		leg1.verticalMovement(130);
		leg3.verticalMovement(130);
		leg5.verticalMovement(130);
		leg2.horizontalMovement(50);
		leg4.horizontalMovement(50); 
        leg6.kneeMovement(90);
        delay(1000);
        
  delay(2000);
}

void krok2(){
  
  leg1.initPosition(90,10,90); //1
  leg2.initPosition(90,75,90); //2
  leg3.initPosition(90,140,90); //3
  leg4.initPosition(90,40,90); //4
  leg5.initPosition(90,105,90); //5
  leg6.initPosition(90,170,90); //6
  delay(500);
  
  leg1.verticalMovement(110);
  leg1.horizontalMovement(60); //6
  delay(500);
  
  leg2.horizontalMovement(65); //1
  leg3.horizontalMovement(130); //2
  leg4.horizontalMovement(30); //3
  leg5.horizontalMovement(95); //4
  leg6.horizontalMovement(160); //5
  leg1.verticalMovement(90);
 delay(500);
 
  leg2.verticalMovement(110);
  leg2.horizontalMovement(115); //6
  delay(500);
  
  leg3.horizontalMovement(120); //1
  leg4.horizontalMovement(20); //2
  leg5.horizontalMovement(85); //3
  leg6.horizontalMovement(170); //4
  leg1.horizontalMovement(50); //5
  leg2.verticalMovement(90);
  delay(500);
  
  leg3.verticalMovement(110);
  leg3.horizontalMovement(170); //6
  delay(500);
  
  leg4.horizontalMovement(10); //1
  leg5.horizontalMovement(75); //2
  leg6.horizontalMovement(160); //3
  leg1.horizontalMovement(40); //4
  leg2.horizontalMovement(105); //5
  leg3.verticalMovement(90);
  delay(500);
  
  leg4.verticalMovement(110);
  leg4.horizontalMovement(60); //6
  delay(500);
  
  leg5.horizontalMovement(65); //1
  leg6.horizontalMovement(150); //2
  leg1.horizontalMovement(30); //3
  leg2.horizontalMovement(95); //4
  leg3.horizontalMovement(160); //5
  leg4.verticalMovement(90);
  delay(500);
  
  leg5.verticalMovement(110);
  leg5.horizontalMovement(115); //6
  delay(500);
  
  leg6.horizontalMovement(140); //1
  leg1.horizontalMovement(20); //2
  leg2.horizontalMovement(85); //3
  leg3.horizontalMovement(150); //4
  leg4.horizontalMovement(50); //5
  leg5.verticalMovement(90);
  delay(500);
  
  leg6.verticalMovement(110);
  leg6.horizontalMovement(170); //6
  delay(500);
  
  leg1.horizontalMovement(10); //1
  leg2.horizontalMovement(75); //2
  leg3.horizontalMovement(140); //3
  leg4.horizontalMovement(40); //4
  leg5.horizontalMovement(105); //5
  leg6.verticalMovement(90);
  delay(500);
  
}






