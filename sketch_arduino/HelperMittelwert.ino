int getMittelwertSkin(){

  int mittelWertSkin,sensorValSkin = 0;

    for(int i=1; i<= 10; i++){
       // mittelWertSkin = map(analogRead(skinPin), 0, 1023, 0, 500);
        mittelWertSkin = analogRead(skinPin);
        sensorValSkin += mittelWertSkin;
        mittelWertSkin = sensorValSkin/i;
    }
  sendDataToSerial('S',mittelWertSkin);
  //Serial.println(mittelWertSkin);
  return mittelWertSkin;  
  
}
