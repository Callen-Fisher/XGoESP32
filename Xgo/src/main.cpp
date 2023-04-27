#include <Arduino.h>
#include "xGo.h"
#include "Neo.h"

#define LED 10
//Ground pin 9 to programme 
int arrX[]={200,200,150,100,50,0,0,0,50,100,150,200};
int arrZ[]={25,50,50,50,50,50,25,0,0,0,0,0};
int arrY[]={100,100,100,100,100,100,100,100,100,100,100,100};
Dog* dog = new Dog();

void setup() {
  delay(100);
  pinMode(LED,OUTPUT);

  setup_neo();

  digitalWrite(LED,HIGH);
  dog->setup();
  digitalWrite(LED,LOW);
  


  colorWipe(strip.Color(0, 0, 255), 1); 
  delay(100);
  


  //dog->setBodyHeight(20);
  //
  //delay(1000);


  //dog->IMU_stabilize(1);
  //dog->walk(Direction::FORWARD, 50);
  //delay(1000);

  //dog->IMU_stabilize(1);
  //dog->walk(Direction::FORWARD, 50);
  //delay(1000);

  //dog->IMU_stabilize(1);
  //dog->walk(Direction::FORWARD, 50);
  //delay(1000);

  //dog->IMU_stabilize(1);
  //dog->walk(Direction::FORWARD, 50);
  //delay(1000);

  dog->stop_robot();
}

void loop() {
  
  int temp=dog->getBatteryLevel();
  colorWipe(strip.Color(temp, 0, 0), 1); 



  dog->customGait(80,12,arrX,arrY,arrZ);

    
  
  
  
  
  
  
}













