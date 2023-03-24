#include <Arduino.h>
//#include "Dog.h"
#include "xGo.h"
#include "Neo.h"


#define LED 10
//Ground pin 9 to programme 





// TEST sending foot positions
// Need to calibrate the servos 
// playstation remote
// add acknowledgements to code I used 
// compare to Python code



















Dog* dog = new Dog();
//Leg* left_fore_leg = new Leg(Limb::LEFT_FORE);
//Leg* right_fore_leg = new Leg(Limb::RIGHT_FORE);
//Leg* right_rear_leg = new Leg(Limb::RIGHT_REAR);
//Leg* left_rear_leg = new Leg(Limb::LEFT_REAR);

void setup() {
  delay(1000);
  pinMode(LED,OUTPUT);



 

  






  setup_neo();

  digitalWrite(LED,HIGH);
  dog->setup();
  digitalWrite(LED,LOW);
  
  //delay(10000);
  //dog->controller->setBodyHeight(80);
  //delay(1000);
  //dog->controller->walk(Axis::X,Direction::FORWARD, 80); //speed of 0 to 100
  //delay(10000);
  //dog->controller->walk(Axis::X,Direction::FORWARD, 0); //speed of 0 to 100
  //delay(1000);

}

void loop() {
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);

  

}













