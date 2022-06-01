#include <Arduino.h>
// #include <GyverOS.h>
#include "Motor.h"
#include "PWMRead.h"

  PWMRead motionRead(
    11
    ,2000
    ,1000
    ,1500
  );
  PWMRead turnRead(
    10
    ,1180
    ,1830
    ,1500
  );

  Motor leftTop(3, 2);
  Motor rightTop(5, 4);
  Motor leftBottom(6, 7);
  Motor rightBottom(9, 8);
  
  // GyverOS<2> OS;
  
void setup() {
  Serial.begin(9600);
  // pinMode(12, OUTPUT);
  // pinMode(11, OUTPUT);
  // OS.attach(0, Serial.println("L"+read1.getPWM()), 200);
}

void loop() {
  char leftMotion;
  char rightMotion;
  char sideShiftFactor = turnRead.getPWM();
  if (sideShiftFactor > 0){
    leftMotion = ( (motionRead.getPWM() + sideShiftFactor) / 2 );
    rightMotion = motionRead.getPWM();
  } 
  else if (sideShiftFactor < 0) {
    leftMotion = motionRead.getPWM();
    rightMotion = ( (motionRead.getPWM() - sideShiftFactor) / 2 );
  }
  
  
  leftTop.go(leftMotion);
  leftBottom.go(leftMotion);
  rightTop.go(rightMotion);
  rightBottom.go(rightMotion);

  // leftTop.go( motionRead.getPWM() + turnRead.getPWM() );
}