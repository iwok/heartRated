#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif




}

void loop() {







  }
}

int getMittelwertSkin(){

int mittelWertSkin,sensorValSkin = 0;

  for(int i=1; i<= 15; i++){
      
      
      mittelWertSkin = map(analogRead(A0), 0, 1023, 255, 0);
      sensorValSkin += mittelWertSkin;
      mittelWertSkin = sensorValSkin/i;
      Serial.println(mittelWertSkin);
      
      
  }
return mittelWertSkin;  
}
