#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


#define PIN 8

// 8 is domino
// 7 is sprinkle

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(556, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:

  strip.begin();
  strip.setBrightness(10);
  strip.show(); // Initialize all pixels to 'off'

}


void loop() {
  // Some example procedures showing how to display to the pixels:
 //  mavSprinkle();
 // mavsWhiteBlue();
  // spookyEyes();
   mavsDomino();

  //testcount();
  }



void testcount(){

  strip.fill(strip.Color(255, 255, 255), 0, 556);
  strip.show();

  
}


void mavsDomino() {

  // Make white first
   for(uint16_t i=0; i<strip.numPixels(); i++) {
       
       strip.setPixelColor(i, 255, 255, 255);
       strip.show();

       delay(10);

    }

  // Make Blue
   for(uint16_t i=0; i<strip.numPixels(); i++) {
       
       strip.setPixelColor(i, 0, 0, 255);
       strip.show();

       delay(10);

    }  
  
  
  }

void mavsWhiteBlue() {

   for(uint16_t i=0; i<strip.numPixels(); i++) {
      if (i % 2 == 0) {
          strip.setPixelColor(i, 255, 255, 255);
      }
      else {
        strip.setPixelColor(i, 0, 0, 255);
      }
  }
  strip.show();
};




void mavSprinkle() {

  long randNumber = random(0, strip.numPixels());
  long randBinary = random(0, 10);

  if (randBinary > 6) {
          strip.setPixelColor(randNumber, 0, 0, 255);
          strip.show();
      }
  else {
    strip.setPixelColor(randNumber, 255, 255, 255);
    strip.show();
  }

  //delay(50);

  
}

void lightning(){

  long randNumber = random(70, 150);
  
  strip.fill(strip.Color(255, 255, 255), 0, 600);
  delay(randNumber);
  strip.show();

  randNumber = random(150, 400);
  strip.fill(strip.Color(0, 0, 0), 0, 600);
  delay(randNumber);
  strip.show(); 
}


void spookyEyes() {
  
  long randNBR = random(0,49);

  strip.setPixelColor(randNBR, 255, 25, 0);
  strip.setPixelColor(randNBR + 1, 255, 25, 0);
  strip.show();

  long stareLength = random(1000, 1500);
  delay(stareLength);

  strip.setPixelColor(randNBR, 0, 0, 0);
  strip.setPixelColor(randNBR + 1, 0, 0, 0);
  strip.show();

  long blinkLength = random(100, 300);
  delay(blinkLength);
  
  strip.setPixelColor(randNBR, 255, 25, 0);
  strip.setPixelColor(randNBR + 1, 255, 25, 0);
  strip.show();
  
  stareLength = random(1000, 1500);
  delay(stareLength);

  strip.setPixelColor(randNBR, 0, 0, 0);
  strip.setPixelColor(randNBR + 1, 0, 0, 0);
  strip.show();


  blinkLength = random(100, 300);
  delay(blinkLength);
  
  strip.setPixelColor(randNBR, 255, 25, 0);
  strip.setPixelColor(randNBR + 1, 255, 25, 0);
  strip.show();

  stareLength = random(1000, 1500);
  delay(stareLength);

  strip.setPixelColor(randNBR, 0, 0, 0);
  strip.setPixelColor(randNBR + 1, 0, 0, 0);
  strip.show(); 

  delay(1400);
  
  
  }
