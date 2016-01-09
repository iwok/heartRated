//////////
/////////  moviEmotions 
/////////

//  Variables
int pulsePin = A0; // Pulse Sensor purple wire connected to analog pin 0
int skinPin  = A1; // Skin Sensor 

// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int SKIN;
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

void setup() {
 Serial.begin(115200);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  interruptSetup(); // sets up to read Pulse Sensor signal every 2mS 
  Serial.println("Waiting for Values ...");
}

void loop() { 


  //serialOutput() ;  
  getMittelwertSkin();
  
  if (QS == true){     // A Heartbeat Was Found
                       // BPM and IBI have been Determined
                       // Quantified Self "QS" true when arduino finds a heartbeat
        
        serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.     
        QS = false;                      // reset the Quantified Self flag for next time    
  }
     
  delay(1000);                            //  take a break

}
