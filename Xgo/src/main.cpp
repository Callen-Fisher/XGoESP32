#include <Arduino.h>
#include "xGo.h"
#include "Neo.h"

#define LED 10
//Ground pin 9 to programme 

Dog* dog = new Dog();

void setup() {
  delay(100);
  pinMode(LED,OUTPUT);

  setup_neo();

  digitalWrite(LED,HIGH);
  dog->setup();
  digitalWrite(LED,LOW);
  
  dog->setBodyHeight(20);
  colorWipe(strip.Color(0, 0, 255), 1); 
  delay(1000);

  
  dog->setPerformanceMode(Mode::NORMAL);

  dog->IMU_stabilize(1);
  dog->walk(Direction::FORWARD, 50);
  delay(1000);

  dog->IMU_stabilize(1);
  dog->walk(Direction::FORWARD, 50);
  delay(1000);

  dog->IMU_stabilize(1);
  dog->walk(Direction::FORWARD, 50);
  delay(1000);

  dog->IMU_stabilize(1);
  dog->walk(Direction::FORWARD, 50);
  delay(1000);

  dog->stop_robot();
}

void loop() {
  
  
  //dog->walk(Direction::BACKWARD,50);
  //delay(1000);
  //dog->walk(Direction::LEFT,50);
  //delay(1000);
  //dog->walk(Direction::RIGHT,50);
  //delay(1000);
  //dog->stop_robot();
  //delay(1000);
}













