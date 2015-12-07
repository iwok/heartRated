#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      8

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // delay for tenth of a second

// Sensor values for our Project
// Skin 
#define SKINPIN        A0
int i = 0;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  int sensorValSkin = getMittelwertSkin();

  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(sensorValSkin,sensorValSkin,sensorValSkin*3)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
}

int getMittelwertSkin(){

int mittelWertSkin,sensorValSkin = 0;

  for(int i=1; i<= 15; i++){
      
      mittelWertSkin = map(analogRead(A0), 0, 1023, 0, 255);
      sensorValSkin += mittelWertSkin;
      mittelWertSkin = sensorValSkin/i;
      Serial.println(mittelWertSkin);
     
  }

return mittelWertSkin;  
}
