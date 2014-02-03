#include <Servo.h>
#include "Leg.h"
#include "Configuration.h"
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
  pinMode(LED_PIN, OUTPUT);
  pinMode(SRF_ECHO_1, INPUT);
  pinMode(SRF_TRIG_1, OUTPUT);
  leg1.initPosition(90,90,90);
  leg2.initPosition(90,90,90);
  leg3.initPosition(90,90,90);
  leg3.initPosition(90,90,90);
  leg4.initPosition(90,90,90);
  leg5.initPosition(90,90,90);
  leg6.initPosition(90,90,90);
  delay(2000);
}

int distance = 0;
boolean freeze = true;
int i = 0;
struct configuration simple_move_conf = {
  14, -15, 0, 
  -26, 45, 0,
  -30, -15, 0,
  -30, 15, 0,
  14, -45, 0,
  22, 15, 0
};
void loop(){
  distance = getFrontDistance();
  if( freeze ) {
    flushLed();
  }
  if( distance < 60 && !freeze ) {
    resetToDefaultPosition(15);
    sayHello(5);
    resetToDefaultPosition(15);
    rotate(6, 30);
    rotate(6, 30);
    rotate(6, 30);
    initMove(simple_move_conf, 15);
  }
  if( distance < 30) {
    if ( !freeze) {
      resetToDefaultPosition(15);
    } 
    else {
      initMove(simple_move_conf, 15);
    }
    freeze = !freeze;
  } 
  if( !freeze ) {
    simpleMove(7);  
  }
//  if(i==0){
//    i++;
//    initKrok2();
//    krok2(3);
//  }

}

void flushLed(){
  digitalWrite(LED_PIN , HIGH);
  delay(500); 
  digitalWrite(LED_PIN , LOW);
  delay(500); 
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

void applyConf(struct configuration conf,int sleep){
  for(int i = 0; i < 90; i++){
    if(conf.left_front_knee_pos !=0 && conf.left_front_knee_pos>0){
      conf.left_front_knee_pos--;
      leg1.incKnee();
    } 
    else if ( conf.left_front_knee_pos !=0 && conf.left_front_knee_pos<0 ){
      conf.left_front_knee_pos++;
      leg1.decKnee();
    } 
    if(conf.left_front_hori_pos !=0 && conf.left_front_hori_pos>0){
      conf.left_front_hori_pos--;
      leg1.incHorizontal();
    } 
    else if ( conf.left_front_hori_pos !=0 && conf.left_front_hori_pos<0 ){
      conf.left_front_hori_pos++;
      leg1.decHorizontal();
    } 
    if(conf.left_front_vert_pos !=0 && conf.left_front_vert_pos>0){
      conf.left_front_vert_pos--;
      leg1.incVertical();
    } 
    else if ( conf.left_front_vert_pos !=0 && conf.left_front_vert_pos<0 ){
      conf.left_front_vert_pos++;
      leg1.decVertical();
    }
    //left_middle
    if(conf.left_middle_knee_pos !=0 && conf.left_middle_knee_pos>0){
      conf.left_middle_knee_pos--;
      leg2.incKnee();
    } 
    else if ( conf.left_middle_knee_pos !=0 && conf.left_middle_knee_pos<0 ){
      conf.left_middle_knee_pos++;
      leg2.decKnee();
    } 
    if(conf.left_middle_hori_pos !=0 && conf.left_middle_hori_pos>0){
      conf.left_middle_hori_pos--;
      leg2.incHorizontal();
    } 
    else if ( conf.left_middle_hori_pos !=0 && conf.left_middle_hori_pos<0 ){
      conf.left_middle_hori_pos++;
      leg2.decHorizontal();
    } 
    if(conf.left_middle_vert_pos !=0 && conf.left_middle_vert_pos>0){
      conf.left_middle_vert_pos--;
      leg2.incVertical();
    } 
    else if ( conf.left_middle_vert_pos !=0 && conf.left_middle_vert_pos<0 ){
      conf.left_middle_vert_pos++;
      leg2.decVertical();
    }
    //left_rear
    if(conf.left_rear_knee_pos !=0 && conf.left_rear_knee_pos>0){
      conf.left_rear_knee_pos--;
      leg3.incKnee();
    } 
    else if ( conf.left_rear_knee_pos !=0 && conf.left_rear_knee_pos<0 ){
      conf.left_rear_knee_pos++;
      leg3.decKnee();
    } 
    if(conf.left_rear_hori_pos !=0 && conf.left_rear_hori_pos>0){
      conf.left_rear_hori_pos--;
      leg3.incHorizontal();
    } 
    else if ( conf.left_rear_hori_pos !=0 && conf.left_rear_hori_pos<0 ){
      conf.left_rear_hori_pos++;
      leg3.decHorizontal();
    } 
    if(conf.left_rear_vert_pos !=0 && conf.left_rear_vert_pos>0){
      conf.left_rear_vert_pos--;
      leg3.incVertical();
    } 
    else if ( conf.left_rear_vert_pos !=0 && conf.left_rear_vert_pos<0 ){
      conf.left_rear_vert_pos++;
      leg3.decVertical();
    }
    //right_front_
    if(conf.right_front_knee_pos !=0 && conf.right_front_knee_pos>0){
      conf.right_front_knee_pos--;
      leg4.incKnee();
    } 
    else if ( conf.right_front_knee_pos !=0 && conf.right_front_knee_pos<0 ){
      conf.right_front_knee_pos++;
      leg4.decKnee();
    } 
    if(conf.right_front_hori_pos !=0 && conf.right_front_hori_pos>0){
      conf.right_front_hori_pos--;
      leg4.incHorizontal();
    } 
    else if ( conf.right_front_hori_pos !=0 && conf.right_front_hori_pos<0 ){
      conf.right_front_hori_pos++;
      leg4.decHorizontal();
    } 
    if(conf.right_front_vert_pos !=0 && conf.right_front_vert_pos>0){
      conf.right_front_vert_pos--;
      leg4.incVertical();
    } 
    else if ( conf.right_front_vert_pos !=0 && conf.right_front_vert_pos<0 ){
      conf.right_front_vert_pos++;
      leg4.decVertical();
    }
    //right_middle_
    if(conf.right_middle_knee_pos !=0 && conf.right_middle_knee_pos>0){
      conf.right_middle_knee_pos--;
      leg5.incKnee();
    } 
    else if ( conf.right_middle_knee_pos !=0 && conf.right_middle_knee_pos<0 ){
      conf.right_middle_knee_pos++;
      leg5.decKnee();
    } 
    if(conf.right_middle_hori_pos !=0 && conf.right_middle_hori_pos>0){
      conf.right_middle_hori_pos--;
      leg5.incHorizontal();
    } 
    else if ( conf.right_middle_hori_pos !=0 && conf.right_middle_hori_pos<0 ){
      conf.right_middle_hori_pos++;
      leg5.decHorizontal();
    } 
    if(conf.right_middle_vert_pos !=0 && conf.right_middle_vert_pos>0){
      conf.right_middle_vert_pos--;
      leg5.incVertical();
    } 
    else if ( conf.right_middle_vert_pos !=0 && conf.right_middle_vert_pos<0 ){
      conf.right_middle_vert_pos++;
      leg5.decVertical();
    }
    //right_rear_
    if(conf.right_rear_knee_pos !=0 && conf.right_rear_knee_pos>0){
      conf.right_rear_knee_pos--;
      leg6.incKnee();
    } 
    else if ( conf.right_rear_knee_pos !=0 && conf.right_rear_knee_pos<0 ){
      conf.right_rear_knee_pos++;
      leg6.decKnee();
    } 
    if(conf.right_rear_hori_pos !=0 && conf.right_rear_hori_pos>0){
      conf.right_rear_hori_pos--;
      leg6.incHorizontal();
    } 
    else if ( conf.right_rear_hori_pos !=0 && conf.right_rear_hori_pos<0 ){
      conf.right_rear_hori_pos++;
      leg6.decHorizontal();
    } 
    if(conf.right_rear_vert_pos !=0 && conf.right_rear_vert_pos>0){
      conf.right_rear_vert_pos--;
      leg6.incVertical();
    } 
    else if ( conf.right_rear_vert_pos !=0 && conf.right_rear_vert_pos<0 ){
      conf.right_rear_vert_pos++;
      leg6.decVertical();
    }
    delay(sleep);
  }  
}
void initMove(struct configuration conf, int sleep){     
  resetToDefaultPosition(sleep);
  applyConf(conf,sleep);
  //    leg1.horizontalMovement(75);
  //    leg2.horizontalMovement(135);
  //    leg3.horizontalMovement(75);
  //    leg4.horizontalMovement(105);
  //    leg5.horizontalMovement(45);
  //    leg6.horizontalMovement(105);
  //    leg1.verticalMovement(90);
  //    leg2.verticalMovement(90);
  //    leg3.verticalMovement(90);
  //    leg4.verticalMovement(90);
  //    leg5.verticalMovement(90);
  //    leg6.verticalMovement(90);
  //    leg1.kneeMovement(104);
  //    leg2.kneeMovement(64);
  //    //leg2.kneeMovement(90);
  //    leg3.kneeMovement(60);
  //    leg4.kneeMovement(60);
  //    leg5.kneeMovement(104);
  //    //leg5.kneeMovement(90);
  //    leg6.kneeMovement(112);
  //    delay(60);
}

void resetToDefaultPosition( int sleep){
  boolean any_change = true;
  for(int i = 0; i < 90 && any_change; i++){
    any_change = false;
    if(leg1.knee_current_pos < 90){
      leg1.incKnee();
      any_change = true;
    }
    if ( leg1.knee_current_pos > 90){
      leg1.decKnee();
      any_change = true;
    }   
    if(leg1.horizontal_current_pos < 90){
      leg1.incHorizontal();
      any_change = true;
    }
    if ( leg1.horizontal_current_pos > 90){
      leg1.decHorizontal();
      any_change = true;
    } 
    if(leg1.vertical_current_pos < 90){
      leg1.incVertical();
      any_change = true;
    }
    if ( leg1.vertical_current_pos > 90){
      leg1.decVertical();
      any_change = true;
    }

    if(leg2.knee_current_pos < 90){
      leg2.incKnee();
      any_change = true;
    }
    if ( leg2.knee_current_pos > 90){
      leg2.decKnee();
    }   
    if(leg2.horizontal_current_pos < 90){
      leg2.incHorizontal();
      any_change = true;
    }
    if ( leg2.horizontal_current_pos > 90){
      leg2.decHorizontal();
      any_change = true;
    } 
    if(leg2.vertical_current_pos < 90){
      leg2.incVertical();
      any_change = true;
    }
    if ( leg2.vertical_current_pos > 90){
      leg2.decVertical();
      any_change = true;
    }

    if(leg3.knee_current_pos < 90){
      leg3.incKnee();
      any_change = true;
    }
    if ( leg3.knee_current_pos > 90){
      leg3.decKnee();
      any_change = true;
    }   
    if(leg3.horizontal_current_pos < 90){
      leg3.incHorizontal();
      any_change = true;
    }
    if ( leg3.horizontal_current_pos > 90){
      leg3.decHorizontal();
      any_change = true;
    } 
    if(leg3.vertical_current_pos < 90){
      leg3.incVertical();
      any_change = true;
    }
    if ( leg3.vertical_current_pos > 90){
      leg3.decVertical();
      any_change = true;
    }

    if(leg4.knee_current_pos < 90){
      leg4.incKnee();
      any_change = true;
    }
    if ( leg4.knee_current_pos > 90){
      leg4.decKnee();
      any_change = true;
    }   
    if(leg4.horizontal_current_pos < 90){
      leg4.incHorizontal();
      any_change = true;
    }
    if ( leg4.horizontal_current_pos > 90){
      leg4.decHorizontal();
      any_change = true;
    } 
    if(leg4.vertical_current_pos < 90){
      leg4.incVertical();
      any_change = true;
    }
    if ( leg4.vertical_current_pos > 90){
      leg4.decVertical();
      any_change = true;
    }

    if(leg5.knee_current_pos < 90){
      leg5.incKnee();
      any_change = true;
    }
    if ( leg5.knee_current_pos > 90){
      leg5.decKnee();
      any_change = true;
    }   
    if(leg5.horizontal_current_pos < 90){
      leg5.incHorizontal();
      any_change = true;
    }
    if ( leg5.horizontal_current_pos > 90){
      leg5.decHorizontal();
      any_change = true;
    } 
    if(leg5.vertical_current_pos < 90){
      leg5.incVertical();
      any_change = true;
    }
    if ( leg5.vertical_current_pos > 90){
      leg5.decVertical();
      any_change = true;
    }

    if(leg6.knee_current_pos < 90){
      leg6.incKnee();
      any_change = true;
    }
    if ( leg6.knee_current_pos > 90){
      leg6.decKnee();
      any_change = true;
    }   
    if(leg6.horizontal_current_pos < 90){
      leg6.incHorizontal();
      any_change = true;
    }
    if ( leg6.horizontal_current_pos > 90){
      leg6.decHorizontal();
      any_change = true;
    } 
    if(leg6.vertical_current_pos < 90){
      leg6.incVertical();
      any_change = true;
    }
    if ( leg6.vertical_current_pos > 90){
      leg6.decVertical();
      any_change = true;
    }    
    delay(sleep);
  } 
}

void initKrok2(){
  leg1.horizontalMovement(75);
  leg2.horizontalMovement(135);
  leg3.horizontalMovement(75);
  leg4.horizontalMovement(105);
  leg5.horizontalMovement(45);
  leg6.horizontalMovement(105);
  leg1.verticalMovement(90);
  leg2.verticalMovement(90);
  leg3.verticalMovement(90);
  leg4.verticalMovement(90);
  leg5.verticalMovement(90);
  leg6.verticalMovement(90);
  leg1.kneeMovement(90);
  leg2.kneeMovement(90);
  leg3.kneeMovement(90);
  leg4.kneeMovement(90);
  leg5.kneeMovement(90);
  leg6.kneeMovement(90);
  delay(60);
}

void sayHello(int sleep){
  for(int i = 0; i < 80; i++){
    if( i % 2 == 0){
      leg1.incHorizontal();
      leg4.incHorizontal();
      leg2.incHorizontal();
      leg5.incHorizontal();
      leg3.decHorizontal();
      leg6.decHorizontal();
    }
    if( i % 3 == 0){
      leg4.incHorizontal();
      leg2.decVertical();
      leg5.decVertical();
      leg2.decKnee();
      leg5.decKnee();
      leg3.incVertical();
      leg6.incVertical();
      leg3.incKnee();
      leg6.incKnee();
    }
    leg1.incVertical();
    leg1.decKnee();
    leg4.incVertical();
    leg4.decKnee();    
    delay(sleep);
  }

  for( int j= 0; j < 5; j++){
    for(int i = 0; i < 20; i++){
      leg1.incVertical();
      leg1.decKnee();
      leg4.decVertical();
      leg4.incKnee();
      delay(sleep);
    }
    for(int i = 0; i < 40; i++){
      leg1.decVertical();
      leg1.incKnee();
      leg4.incVertical();
      leg4.decKnee();
      delay(sleep);
    }
    for(int i = 0; i < 20; i++){
      leg1.incVertical();
      leg1.decKnee();
      leg4.decVertical();
      leg4.incKnee();
      delay(sleep);
    }
  } 

  for(int i = 0; i < 80; i++){
    if( i % 2 == 0){
      leg1.decHorizontal();
      leg4.decHorizontal();
      leg2.decHorizontal();
      leg5.decHorizontal();
      leg3.incHorizontal();
      leg6.incHorizontal();
    }
    if( i % 3 == 0){
      leg4.decHorizontal();
      leg2.incVertical();
      leg5.incVertical();
      leg2.incKnee();
      leg5.incKnee();
      leg3.decVertical();
      leg6.decVertical();
      leg3.decKnee();
      leg6.decKnee();
    }
    leg1.decVertical();
    leg1.incKnee();
    leg4.decVertical();
    leg4.incKnee();    
    delay(sleep);
  }
}

void simpleMove(int sleep){
  for(int i = 0; i<45; i ++){
    leg1.incVertical();
    leg3.incVertical();
    leg5.incVertical();
    leg2.decHorizontal();
    leg5.incHorizontal();
    if ( i %3 == 0 ) {
      leg1.incHorizontal();
      leg3.incHorizontal();
      leg4.decHorizontal();
      leg6.decHorizontal(); 
    } 
    if( i % 2 == 0){
      leg1.decKnee();
      leg3.incKnee();
      leg4.incKnee();
      leg6.decKnee();
      leg2.incKnee();
      leg5.decKnee();
    }
    delay(sleep);
  } 
  for(int i = 0; i<45; i ++){
    leg1.decVertical();
    leg3.decVertical();
    leg5.decVertical();
    leg2.decHorizontal();
    leg5.incHorizontal();
    if ( i %3 == 0 ) {
      leg1.incHorizontal();
      leg3.incHorizontal();
      leg4.decHorizontal();
      leg6.decHorizontal(); 
    } 
    if( i % 2 == 0){
      leg1.decKnee();
      leg3.incKnee();
      leg4.incKnee();
      leg6.decKnee();
      leg2.incKnee();
      leg5.decKnee();
    }
    delay(sleep);
  }
  for(int i = 0; i<45; i ++){
    leg2.incVertical();
    leg4.incVertical();
    leg6.incVertical();
    leg2.incHorizontal();
    leg5.decHorizontal();
    if ( i %3 == 0 ) {
      leg1.decHorizontal();
      leg3.decHorizontal();
      leg4.incHorizontal();
      leg6.incHorizontal(); 
    } 
    if( i % 2 == 0){
      leg1.incKnee();
      leg3.decKnee();
      leg4.decKnee();
      leg6.incKnee();
      leg2.decKnee();
      leg5.incKnee();
    }
    delay(sleep);
  }  
  for(int i = 0; i<45; i ++){
    leg2.decVertical();
    leg4.decVertical();
    leg6.decVertical();
    leg2.incHorizontal();
    leg5.decHorizontal();
    if ( i %3 == 0 ) {
      leg1.decHorizontal();
      leg3.decHorizontal();
      leg4.incHorizontal();
      leg6.incHorizontal(); 
    } 
    if( i % 2 == 0){
      leg1.incKnee();
      leg3.decKnee();
      leg4.decKnee();
      leg6.incKnee();
      leg2.decKnee();
      leg5.incKnee();
    }
    delay(sleep);
  }
}

void rotate(int sleep, int degrees){

  for(int i = 0; i<degrees; i ++){ // zmiana o 40 stopni // podnoszenie nog 1 3 5
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

  for(int i = 0; i<degrees; i ++){ // zmiana o 40 stopni // opadanie nog 1 3 5
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

  for(int i = 0; i<degrees; i ++){ // zmiana o 40 stopni // podnoszenie nog 2 4 6
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

  for(int i = 0; i<degrees; i ++){ // zmiana o 40 stopni // opadanie nog 2 4 6
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

void step(int sleep, int degrees){  
  for(int i = 0; i<degrees; i ++){ // zmiana o 40 stopni // podnoszenie nog 1 3 5
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

  for(int i = 0; i<degrees; i ++){ // zmiana o 40 stopni // opadanie nog 1 3 5
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

  for(int i = 0; i<degrees; i ++){ // zmiana o 40 stopni // podnoszenie nog 2 4 6
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

  for(int i = 0; i<degrees; i ++){ // zmiana o 40 stopni // opadanie nog 2 4 6
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

void krok(int sleep){      
  for(int i = 0; i<40; i ++){ //nogi 1,3,5 do gory i w przod
    leg1.incVertical();
    leg3.incVertical();
    leg5.incVertical();
    leg1.decKnee();
    if(i%2==0){
      leg3.incHorizontal();
      leg5.incHorizontal();
    }
    delay(sleep);
  }


  for(int i = 0; i<40; i ++){  //nogi 1,3,5 w dol
    leg1.decVertical();
    leg3.decVertical();
    leg5.decVertical();
    delay(sleep);
  }

  for(int i = 0; i<40; i ++){  //zobaczyc jak bedzie wygladalo polaczone z poprzednia petla ; nogi 2,4,6 w gore, 1,3,5 w tyl
    leg6.incVertical();
    leg2.incVertical();
    leg4.incVertical();
    leg1.incKnee(); 
    leg3.decHorizontal();
    leg5.decHorizontal();
    leg6.incKnee();
    leg2.incHorizontal();
    leg4.incHorizontal();
    delay(sleep);
  }

  for(int i = 0; i<40; i ++){
    leg6.decVertical();
    leg2.decVertical();
    leg4.decVertical();
    delay(sleep);
  }

  for(int i = 0; i<40; i ++){ //tu też sprobowac polaczyc
    leg1.incVertical();
    leg3.incVertical();
    leg5.incVertical();
    leg2.decHorizontal();
    leg4.decHorizontal(); 
    leg6.decKnee();
    if(i%2==0){
      leg3.incHorizontal();
      leg5.incHorizontal();
    }
    delay(sleep);
  }

  delay(sleep);
}

void krok2(int sleep){
  leg1.initPosition(90,10,90); //1
  leg5.initPosition(90,75,90); //2
  leg3.initPosition(90,140,90); //3
  leg4.initPosition(90,40,90); //4
  leg2.initPosition(90,105,90); //5
  leg6.initPosition(90,170,90); //6
  delay(500);

  for(int i = 0; i<40; i ++){
    if(i<20){
      leg1.incVertical();           //20
    }
    leg1.incHorizontal(); //6			//40

    if(i%5==0){
      leg5.decHorizontal(); //1
      leg3.decHorizontal(); //2
      leg4.decHorizontal(); //3
      leg2.decHorizontal(); //4
      leg6.decHorizontal(); //5
    }
    if(i>=20){
      leg1.decVertical();
    }
    delay(sleep);
  }

  for(int i = 0; i<40; i ++){
    if(i<20){
      leg5.incVertical();           //20
    }
    leg5.incHorizontal(); //6			//40

    if(i%5==0){
      leg3.decHorizontal(); //1
      leg4.decHorizontal(); //2
      leg2.decHorizontal(); //3
      leg6.decHorizontal(); //4
      leg1.decHorizontal(); //5
    }
    if(i>=20){
      leg5.decVertical();
    }
    delay(sleep);
  }

  for(int i = 0; i<40; i ++){
    if(i<20){
      leg3.incVertical();           //20
    }
    leg3.incHorizontal(); //6			//40

    if(i%5==0){
      leg4.decHorizontal(); //1
      leg2.decHorizontal(); //2
      leg6.decHorizontal(); //3
      leg1.decHorizontal(); //4
      leg5.decHorizontal(); //5
    }
    if(i>=20){
      leg3.decVertical();
    }
    delay(sleep);
  }

  for(int i = 0; i<40; i ++){
    if(i<20){
      leg4.incVertical();           //20
    }
    leg4.incHorizontal(); //6			//40

    if(i%5==0){
      leg2.decHorizontal(); //1
      leg6.decHorizontal(); //2
      leg1.decHorizontal(); //3
      leg5.decHorizontal(); //4
      leg3.decHorizontal(); //5
    }
    if(i>=20){
      leg4.decVertical();
    }
    delay(sleep);
  }

  for(int i = 0; i<40; i ++){
    if(i<20){
      leg2.incVertical();           //20
    }
    leg2.incHorizontal(); //6			//40

    if(i%5==0){
      leg6.decHorizontal(); //1
      leg1.decHorizontal(); //2
      leg5.decHorizontal(); //3
      leg3.decHorizontal(); //4
      leg4.decHorizontal(); //5
    }
    if(i>=20){
      leg2.decVertical();
    }
    delay(sleep);
  }	

  for(int i = 0; i<40; i ++){
    if(i<20){
      leg6.incVertical();           //20
    }
    leg6.incHorizontal(); //6			//40

    if(i%5==0){
      leg1.decHorizontal(); //1
      leg5.decHorizontal(); //2
      leg3.decHorizontal(); //3
      leg4.decHorizontal(); //4
      leg2.decHorizontal(); //5
    }
    if(i>=20){
      leg6.decVertical();
    }
    delay(sleep);
  }	

}








