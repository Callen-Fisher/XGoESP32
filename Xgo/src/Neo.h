#pragma once
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define PIN 2

Adafruit_NeoPixel strip;


 //colorWipe(strip.Color(255, 0, 0), 1); // Red
 //colorWipe(strip.Color(0, 255, 0), 1); // Green
 //colorWipe(strip.Color(0, 0, 255), 1); // Blue




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

void setup_neo()
{
    // Parameter 1 = number of pixels in strip
    // Parameter 2 = pin number
    // Parameter 3 = pixel type flags
    strip = Adafruit_NeoPixel(4, PIN, NEO_GRB + NEO_KHZ800);

    strip.begin();
    strip.setBrightness(50);
    strip.show();

    //colorWipe(strip.Color(0, 0, 255), 50); // Blue
    rainbowCycle(20);
}