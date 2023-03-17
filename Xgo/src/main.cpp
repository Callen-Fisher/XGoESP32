#include <Arduino.h>
#include "Dog.h"


//Ground pin 9 to programme 

Dog* dog = new Dog();

void setup() {
  
  pinMode(10,OUTPUT);

  digitalWrite(10,HIGH);
  dog->setup();
  digitalWrite(10,LOW);
  
  dog->controller->setBodyHeight(80);
}

void loop() {
  digitalWrite(10,HIGH);
  



  
  dog->controller->walk(Axis::X, 255);
  delay(1);
  dog->controller->walk(Axis::X, 0);
  delay(1);
  dog->controller->walk(Axis::X, 255);
  delay(1);
  dog->controller->walk(Axis::X, 0);
  delay(1);
  
}