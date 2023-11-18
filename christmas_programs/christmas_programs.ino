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
  groupedGreenRed(3);
  }


void groupedGreenRed(uint16_t group_size) {
  
  String color = "GREEN";

  for (uint16_t i = 0; i < strip.numPixels(); i += group_size) {

    // Swap colors
    if (color.equals("GREEN")) {
      color = "RED";
    } else if (color.equals("RED")) {
      color = "GREEN";
    }

    // Loop through lights in groups the size of group_size
    for (uint16_t j = i; j < i + group_size && j < strip.numPixels(); j++) {

      // Assign group colors based on the color variable
      if (color.equals("RED")) {
         strip.setPixelColor(j, 255, 255, 255);  // Red color for "RED"
      } else if (color.equals("GREEN")) {
        strip.setPixelColor(j, 255, 0, 0);  // Green color for "GREEN"
      }
    }
  }
  strip.show(); // Show the changes after updating colors
}


//    }
//    
//    }
//}
