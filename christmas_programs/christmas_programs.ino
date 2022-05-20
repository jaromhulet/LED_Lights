#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


#define PIN 7

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(600, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:

  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'

}


void loop() {
  // Some example procedures showing how to display to the pixels:
  alternateChristmasRed();
  delay(250);
  alternateChristmasGreen();
  delay(250);
  allred();
  //groupedGreenRed(3);
  }

void alternateChristmasRed() {

   for(uint16_t i=0; i<strip.numPixels(); i++) {
      if (i % 2 == 0) {
          strip.setPixelColor(i, 255, 0, 0);
      }
      else {
        strip.setPixelColor(i, 0, 255, 0);
      }
  }
  strip.show();
};


void alternateChristmasGreen() {

   for(uint16_t i=0; i<strip.numPixels(); i++) {
      if (i % 2 == 0) {
          strip.setPixelColor(i, 0, 255, 0);
      }
      else {
        strip.setPixelColor(i, 255, 0, 0);
      }
  } 
  strip.show();
};

void allred(){

  for (uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, 0, 255, 0);
  }
}

//
//void groupedGreenRed(group_size) {
//
//  for (uint16_t i=0; i<strip.numPixels(); i+= group_size) {
//
//    //set initial color to green to instantiate color variable
//    if (i == 0){
//      string color = 'GREEN';
//    }
//
//    //swap colors
//    if (color == 'GREEN'){
//      color = 'RED';
//    }
//  
//    if (color == 'RED'){
//      color = GREEN;
//    }
//
//    //Loop through lights in groups the size of group_size
//    for (uint16_t j=i; j<group_size; i++) {
//
//      //assign group colors based on the color variable
//      if (color == 'RED'){
//         strip.setPixelColor(j+i, 255, 0, 0)
//      }
//  
//      if (color == 'GREEN'){
//        strip.setPixelColor(j+i,0, 255,0)
//      }
//    }
//    
//    }
//}
