#include <SoftwareSerial.h>

char a = 'a';
void setup(){
  Serial.begin(115200); //115200
  Serial3.begin(115200);
}

void loop(){
  // Calculate distance from time of pulse
  if (Serial.available()){
    Serial3.write(a);
    Serial.write(a);
  } 
    if (Serial3.available()){
    char b = Serial3.read();
    Serial.write(b);
  } 
  delay(100);                                    // Wait 50mS before next ranging
}


