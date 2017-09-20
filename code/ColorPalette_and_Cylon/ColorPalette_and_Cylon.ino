#include <FastLED.h>
#include <Adafruit_NeoPixel.h>

// using a state machine to drive two patterns on two strings at the same time
// By Mike Cook July 2017

#define PIN_FOR_1   13 // pin connected to the Larger strip
#define PIN_FOR_2   12 // pin connected to the smaller strip
#define NUMPIXELS1      140 // number of LEDs on first (larger) strip
#define NUMPIXELS2      82 // number of LEDs on second (smaller) strip
#define BRIGHTNESS  70
#define COLOR_ORDER GRB
CRGB leds[NUMPIXELS1];

// how often each pattern updates
unsigned long pattern1Interval  = 400;
unsigned long pattern2Interval  = 900;

// for millis() when last update occurred
long lastUpdateP1 = 0;
long lastUpdateP2 = 0;  

// state variables for patterns
int p1State = 0 ; 
int p2State = 0 ; 

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS1, PIN_FOR_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS2, PIN_FOR_2, NEO_GRB + NEO_KHZ800);

void setup() {
   
   strip1.begin() { // This initializes the NeoPixel library for pattern 1.
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, PIN_FOR_1, COLOR_ORDER>(leds, NUMPIXELS1).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
    
    void fadeall() { for(int i = 0; i < NUMPIXELS1; i++) { leds[i].nscale8(250); } }   //this can't be in the right spot....
   }
   
   strip2.begin(){ // This initializes the NeoPixel library for pattern 2.
    delay( 3000 ); // power-up safety delay
    Serial.println("resetting");
    LEDS.addLeds<WS2812,PIN_FOR_2,RGB>(leds,NUMPIXELS2);
    FastLED.setBrightness(  BRIGHTNESS );

    void fadeall() { for(int i = 0; i < NUMPIXELS2; i++) { leds[i].nscale8(250); } }  //this can't be in the right spot....
   }
   // wipes the LED buffers
   wipe1(0,0,0); 
   wipe2(0,0,0);
}

void loop(){
if(millis() - lastUpdateP1 > pattern1Interval) updatePattern1();   //Add anything here?
if(millis() - lastUpdateP2 > pattern2Interval) updatePattern2();   //or here?
}

void updatePattern1(){ // update pattern 1 a walking red led
    ChangePalettePeriodically();
    
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors( startIndex);
    
    FastLED.update(1000 / UPDATES_PER_SECOND);
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUMPIXELS1; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}
   
   
   int lastLed = p1State -1;
   if (lastLed < 0) { // wrap round count
      lastLed = NUMPIXELS1 -1;
   }
   strip1.setPixelColor(lastLed, strip1.Color(0,0,0)); // turn off last LED
   p1State ++; // move on state variable for the next time we enter this
   if(p1State >= NUMPIXELS1){ // wrap round the state
    p1State = 0;
   }
   strip1.show(); // update display
   lastUpdateP1 = millis(); // time for next update
}

void updatePattern2(){ // update pattern 2 a walking green LED
   static uint8_t hue = 0;
   Serial.print("x");
   // First slide the led in one direction
   for(int i = 0; i < NUMPIXELS2; i++) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.update(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);   
   
   int lastLed = p2State -1;
   if (lastLed < 0) { // wrap round count
      lastLed = NUMPIXELS2 -1;
   }
   
   strip2.setPixelColor(lastLed, strip2.Color(0,0,0)); // turn off last LED
   p2State ++; // move on state variable for the next time we enter this
   if(p2State >= NUMPIXELS2){ // wrap round the state
    p2State = 0;
   }
   strip2.show(); // update display
   lastUpdateP2 = millis(); // time for next update
}

void wipe1(byte r,byte g, byte b){
     for(int i=0;i<NUMPIXELS1;i++){
       strip1.setPixelColor(i, strip1.Color(r,g,b)); 
       }
}

void wipe2(byte r,byte g, byte b){
     for(int i=0;i<NUMPIXELS2;i++){
       strip2.setPixelColor(i, strip2.Color(r,g,b)); 
       }
}
