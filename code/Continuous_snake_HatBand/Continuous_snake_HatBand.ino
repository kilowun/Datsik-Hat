//Figure-Eight animation for Neopixel Ring Bangle Bracelet
//By Dano Wall and Becky Stern for Adafruit Industries
#include <Adafruit_NeoPixel.h>

#define PIN 0 //marked D1 on GEMMA

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, PIN, NEO_GRB + NEO_KHZ800);

//Array of pixels in order of animation - 70 in total
int sine[] = {0, 1, 2, 3, 4};
void setup() {
  strip.begin();
  strip.setBrightness(30); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {


for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){ 
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(255, 255, 255)); //change RGB color value here        WHITE
    }
  strip.show();
  delay(20);
  }

// ---------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(180, 0, 255)); //change RGB color value here                                PURPLE
    }
  strip.show();
  delay(20);
  }

//----------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){ 
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(0, 255, 0)); //change RGB color value here        GREEN
    }
  strip.show();
  delay(20);
  }

// ---------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(180, 0, 255)); //change RGB color value here                                PURPLE
    }
  strip.show();
  delay(20);
  }
  
//----------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){ 
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(0, 255, 0)); //change RGB color value here        GREEN
    }
  strip.show();
  delay(20);
  }

//----------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(15, 0, 230)); //change RGB color value here                       BLUE
    }
  strip.show();
  delay(20);
  }
  
//----------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(255, 255, 0)); //change RGB color value here                       YELLOW
    }
  strip.show();
  delay(20);
  }
//----------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(15, 0, 2300)); //change RGB color value here                       BLUE
    }
  strip.show();
  delay(20);
  }
  
  //----------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(255, 255, 0)); //change RGB color value here                       YELLOW
    }
  strip.show();
  delay(20);
  }
  //----------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(0, 0, 255)); //change RGB color value here                       BLUE
    }
  strip.show();
  delay(20);
  }
  
// ---------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(15, 180, 220)); //change RGB color value here                   CYAN
    }
  strip.show();
  delay(20);
  }
//---------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(15, 0, 230)); //change RGB color value here                       BLUE
    }
  strip.show();
  delay(20);
  }


// ---------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(255, 255, 255)); //change RGB color value here                   WHITE
    }
  strip.show();
  delay(20);
  }
//---------------------------------------------------------------------------------------------------------------------------
for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){ 
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(255, 0, 255)); //change RGB color value here        MAGENTA
    }
  strip.show();
  delay(20);
  }

// ---------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(180, 0, 255)); //change RGB color value here                                PURPLE
    }
  strip.show();
  delay(20);
  }

//----------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(255, 0, 0)); //change RGB color value here        RED
    }
  strip.show();
  delay(20);
  }

//-----------------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(255, 90, 0)); //change RGB color value here              ORANGE
    }
  strip.show();
  delay(20);
  }

//-------------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(255, 255, 0)); //change RGB color value here           YELLOW       
    }
  strip.show();
  delay(20);
  }

  //-------------------------------------------------------------------------------------------------------------------------

for(int i=0; i<5; i++) { 
  strip.setPixelColor(sine[i], strip.Color(0, 0, 0));
      
  for (int j=0; j<13; j++){
    strip.setPixelColor(sine[(j+i+1)%80], strip.Color(0, 255, 0)); //change RGB color value here                  GREEN
    }
  strip.show();
  delay(20);
  }

}




