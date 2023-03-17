#include <Arduino.h>
#include "Dog.h"
//Ground pin 9 to programme 

Dog* dog = new Dog();

void setup() {
  delay(10000);
  pinMode(10,OUTPUT);

  digitalWrite(10,HIGH);
  dog->setup();
  digitalWrite(10,LOW);
  
  delay(10000);
  dog->controller->setBodyHeight(80);
  delay(1000);
  dog->controller->walk(Axis::X,Direction::FORWARD, 80); //speed of 0 to 100
  delay(10000);
  dog->controller->walk(Axis::X,Direction::FORWARD, 0); //speed of 0 to 100
  delay(1000);

}

void loop() {
  digitalWrite(10,HIGH);
  delay(1000);
  digitalWrite(10,LOW);
  delay(1000);
}