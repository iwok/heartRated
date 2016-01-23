//////////
/////////  All Serial Handling Code
/////////

void serialOutput(){   // Decide How To Output Serial. 
      sendDataToSerial('S', Signal);     // goes to sendDataToSerial function
}

//  Decides How To OutPut BPM and SKIN Data
void serialOutputWhenBeatHappens(){    
        sendDataToSerial('B',BPM);   // send heart rate with a 'B' prefix
}

//  Sends Data to Pulse Sensor Processing App, Native Mac App, or Third-party Serial Readers. 
void sendDataToSerial(char symbol, int data ){
    Serial.print(symbol);
    Serial.println(data);
    softSerial.print(symbol);
    softSerial.println(data);                     
  }
