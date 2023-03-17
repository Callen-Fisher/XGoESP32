#include <Arduino.h>
#include "Dog.h"
#include <Adafruit_NeoPixel.h>
#define PIN 2
//Ground pin 9 to programme 




// modify Dog.h and Controller.h to have all the required functions from the register table
// Add functions for reading all servo positions
// Add functions for reading all foot positions
// TEST sending foot positions
// Need to calibrate the servos 



// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, PIN, NEO_GRB + NEO_KHZ800);

Dog* dog = new Dog();

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}



void setup() {
  delay(1000);
  pinMode(10,OUTPUT);

  strip.begin();
  strip.setBrightness(50);
  strip.show();

  //colorWipe(strip.Color(0, 0, 255), 50); // Blue
  rainbowCycle(20);

  digitalWrite(10,HIGH);
  dog->setup();
  digitalWrite(10,LOW);
  
  //delay(10000);
  //dog->controller->setBodyHeight(80);
  //delay(1000);
  //dog->controller->walk(Axis::X,Direction::FORWARD, 80); //speed of 0 to 100
  //delay(10000);
  //dog->controller->walk(Axis::X,Direction::FORWARD, 0); //speed of 0 to 100
  //delay(1000);

}

void loop() {
  digitalWrite(10,HIGH);
  delay(1000);
  digitalWrite(10,LOW);
  delay(1000);
}













