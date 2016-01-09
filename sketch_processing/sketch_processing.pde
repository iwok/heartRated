 import processing.serial.*;

 Serial myPort;        // The serial port
 int xPos = 1;         // horizontal position of the graph
 Table table;          // Table for Sensor values
 
 int Sensor;      // HOLDS PULSE SENSOR DATA FROM ARDUINO
 int BPM;         // HOLDS HEART RATE VALUE FROM ARDUINO
 int SKIN;        // HOLDS SKIN CONDUCTIVITY VALUE FROM ARDUINO
 

void setup () {
  // set the window size:
  size(200, 300);
   
  // Set FrameRate to 1 for better 
  //frameRate(1);
  // create new Table
  table = new Table();
  // Add colums for sensor values
  table.addColumn("TIME");
  table.addColumn("BPM");
  table.addColumn("SKIN");
  //table.addColumn("breathSensorVal");

 // List all the available serial ports
 // if using Processing 2.1 or later, use Serial.printArray()
 println(Serial.list());
 //println(Serial.printArray());

 // I know that the first port in the serial list on my mac
 // is always my  Arduino, so I open Serial.list()[0].
 // Open whatever port is the one you're using.
 myPort = new Serial(this, Serial.list()[1], 115200);

 // don't generate a serialEvent() unless you get a newline character:
 myPort.bufferUntil('\n');
 myPort.clear();            // flush buffer
 // set inital background:
 background(255);
 }

void draw () {
 // everything happens in the serialEvent()
 
  TableRow newRow = table.addRow();
   
 }
