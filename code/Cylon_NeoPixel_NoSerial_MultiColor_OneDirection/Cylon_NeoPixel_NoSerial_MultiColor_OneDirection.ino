//NeoPixel LED Digital Strip Cylon Eye v1.10 Created by EternalCore
#include <Adafruit_NeoPixel.h>

//Settings:
#define PIN 0 //The Pin out your Neopixel DIN strip/stick is connected to (Default is 6)
#define TPIXEL 300 //The total amount of pixel's/led's in your connected strip/stick (Default is 60)
//To change the timing of between pulses change the number in int 'refresh', to change the speed of it scrolling change the number in int 'wait_T' and 1000 is equal to 1second. 
int wait_T=50; //This is the delay between moving back and forth and per pixel
int refresh=1;
int PixelCount=300; //Set this to the AMOUNT of Led's/Pixels you have or want to use on your strip And It can be used to tell where to Stop then return the eye at in the strip
int Pixel_Start_End=0; //Set this to where you want it to Start/End at
boolean UsingBar = false; //Set this to true If you are using the 8x1 Neopixel Bar Or you want to only use 3 leds for the scanner. 

Adafruit_NeoPixel strip = Adafruit_NeoPixel(TPIXEL, PIN, NEO_GRB + NEO_KHZ800); //Standard Strip function

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  //Serial.begin(9600); //Used For pixel Count Debugging
}
void loop() {
  //Example: CylonEyeUp(Center_Dot_Color, Second_Dot_color, Third_Dot_color, wait_T, PixelCount, Pixel_Start_End);
  CylonEyeUp(strip.Color(0,255,50), strip.Color(0,230,45), strip.Color(0,200,40), strip.Color(0,180,36), strip.Color(0,162,32), strip.Color(0,145,29), strip.Color(0,131,26), wait_T, PixelCount, Pixel_Start_End);
  delay(wait_T);                               //GREEN

  CylonEyeClear(wait_T, PixelCount, Pixel_Start_End);
  delay(refresh);
  
  CylonEyeUp(strip.Color(180,0,255), strip.Color(162,0,230), strip.Color(145,0,200), strip.Color(131,0,180), strip.Color(118,0,162), strip.Color(106,0,145), strip.Color(95,0,131), wait_T, PixelCount, Pixel_Start_End);
  delay(wait_T);                              //PURPLE

  CylonEyeClear(wait_T, PixelCount, Pixel_Start_End);
  delay(refresh);

  CylonEyeUp(strip.Color(35,200,255), strip.Color(32,180,230), strip.Color(28,162,200), strip.Color(25,145,180), strip.Color(23,131,162), strip.Color(21,118,145), strip.Color(19,106,131), wait_T, PixelCount, Pixel_Start_End);
  delay(wait_T);                              //DARK CYAN

  CylonEyeClear(wait_T, PixelCount, Pixel_Start_End);
  delay(refresh);

  CylonEyeUp(strip.Color(255,255,0), strip.Color(230,230,0), strip.Color(200,200,0), strip.Color(180,180,0), strip.Color(162,162,0), strip.Color(145,145,0), strip.Color(131,131,0), wait_T, PixelCount, Pixel_Start_End);
  delay(wait_T);                              //YELLOW

  CylonEyeClear(wait_T, PixelCount, Pixel_Start_End);
  delay(refresh);

  CylonEyeUp(strip.Color(40,40,255), strip.Color(36,36,230), strip.Color(32,32,200),  strip.Color(29,29,180), strip.Color(26,26,162), strip.Color(23,23,145), strip.Color(21,21,131), wait_T, PixelCount, Pixel_Start_End);
  delay(wait_T);                              //DARK BLUE

  CylonEyeClear(wait_T, PixelCount, Pixel_Start_End);
  delay(refresh);

  CylonEyeUp(strip.Color(255,0,255), strip.Color(230,0,230), strip.Color(200,0,200),  strip.Color(180,0,180), strip.Color(162,0,162), strip.Color(145,0,145), strip.Color(131,0,131), wait_T, PixelCount, Pixel_Start_End);
  delay(wait_T);                              //PINK

  CylonEyeClear(wait_T, PixelCount, Pixel_Start_End);
  delay(refresh);

  CylonEyeUp(strip.Color(255,0,0), strip.Color(230,0,0), strip.Color(200,0,0),  strip.Color(180,0,0), strip.Color(162,0,0), strip.Color(145,0,0), strip.Color(131,0,0), wait_T, PixelCount, Pixel_Start_End);
  delay(wait_T);                              //RED
  
 
  //Example: CylonEyeDown(Center_Dot_Color, Second_Dot_color, Third_Dot_color, wait_T, PixelCount, Pixel_Start_End);
  //CylonEyeDown(strip.Color(175,0,0), strip.Color(25,0,0), strip.Color(10,0,0), wait_T, PixelCount, Pixel_Start_End);
  //delay(wait_T);
  //Example: CylonEyeClear(wait_T, PixelCount, Pixel_Start_End);
  
  CylonEyeClear(wait_T, PixelCount, Pixel_Start_End);
  delay(refresh);
}




void CylonEyeClear(uint8_t Delay, int TotalPixels, int pStart) {
  for(int i=pStart; i<TotalPixels+2; i++) {
    strip.setPixelColor(i, strip.Color(0,0,0)); //Clears the dots
     strip.show();
    //Serial.println(i); //Used For pixel Count Debugging
    //delay(Delay);
  }
}
void CylonEyeUp(uint32_t Co, uint32_t Ct, uint32_t Ctt, uint32_t Cttt, uint32_t Ctttt, uint32_t Cttttt, uint32_t Ctttttt, uint8_t Delay, int TotalPixels, int pStart) {
  for(int i=pStart; i<TotalPixels; i++) {
       if(!UsingBar) { strip.setPixelColor(i+6, Ctttttt); } //Seventh Dot Color
    strip.setPixelColor(i+5, Cttttt);   //Sixth Dot Color
    strip.setPixelColor(i+4, Ctttt);   //Fifth Dot Color
    strip.setPixelColor(i+3, Cttt);   //Fourth Dot Color
    strip.setPixelColor(i+2, Ctt);   //Third Dot Color   
    strip.setPixelColor(i+1, Ct);   //Second Dot Color
    strip.setPixelColor(i, Co);     //Center Dot Color
    strip.setPixelColor(i-1, Ct);   //Second Dot Color
    strip.setPixelColor(i-2, Ctt);   //Third Dot Color
    strip.setPixelColor(i-3, Cttt);   //Fourth Dot Color
    strip.setPixelColor(i-4, Ctttt);   //Fifth Dot Color
    strip.setPixelColor(i-5, Cttttt);   //Sixth Dot Color
    if(!UsingBar) { strip.setPixelColor(i-6, Ctttttt); } //Seventh Dot Color

    if(!UsingBar) {
      strip.setPixelColor(i-6, strip.Color(0,0,0)); //Clears the dots after the 3rd color
    } else {
      strip.setPixelColor(i-0, strip.Color(0,0,0)); //Clears the dots after the 2nd color
    }
    strip.show();
    //Serial.println(i); //Used For pixel Count Debugging
    delay(Delay);

  }
}
void CylonEyeDown(uint32_t Co, uint32_t Ct, uint32_t Ctt, uint8_t Delay, int TotalPixels, int pEnd) {
  for(int i=TotalPixels-1; i>pEnd; i--) {
    if(!UsingBar) { strip.setPixelColor(i-2, Ctt); } //Third Dot Color
    strip.setPixelColor(i-1, Ct);   //Second Dot Color
    strip.setPixelColor(i, Co);    //Center Dot Color
    strip.setPixelColor(i+1, Ct);  //Second Dot Color
    if(!UsingBar) { strip.setPixelColor(i+2, Ctt); } //Third Dot Color

    if(!UsingBar) { 
      strip.setPixelColor(i+3, strip.Color(0,0,0)); //Clears the dots after the 3rd color
    } else {
      strip.setPixelColor(i+2, strip.Color(0,0,0)); //Clears the dots after the 2rd color
    }
    strip.show();
    //Serial.println(i); //Used For pixel Count Debugging
    delay(Delay);
  }
}


