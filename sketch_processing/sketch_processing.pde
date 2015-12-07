 import processing.serial.*;

 Serial myPort;        // The serial port
 int xPos = 1;         // horizontal position of the graph
 Table table;          // Table for Sensor values
 
void setup () {
  // set the window size:
  size(1200, 300);
   
  // Set FrameRate to 1 for better 
  frameRate(1);
  // create new Table
  table = new Table();
  // Add colums for sensor values
  table.addColumn("time");
  table.addColumn("pulseSensorVal");
  table.addColumn("moistureSensorVal");
  table.addColumn("breathSensorVal");

 // List all the available serial ports
 // if using Processing 2.1 or later, use Serial.printArray()
 println(Serial.list());
 //println(Serial.printArray());

 // I know that the first port in the serial list on my mac
 // is always my  Arduino, so I open Serial.list()[0].
 // Open whatever port is the one you're using.
 myPort = new Serial(this, Serial.list()[2], 9600);

 // don't generate a serialEvent() unless you get a newline character:
 myPort.bufferUntil('\n');

 // set inital background:
 background(255);
 }

void draw () {
 // everything happens in the serialEvent()
 }

 void serialEvent (Serial myPort) {
 // get the ASCII string:
 String inString = myPort.readStringUntil('\n');

 if (inString != null) {
 // trim off any whitespace:
 inString = trim(inString);
 // convert to an int and map to the screen height:
 float inByte = float(inString);
 inByte = map(inByte, 0, 1023, 0, height);
  
 exportSensorVal(int(inByte),0,0);
 
 // draw the line:
 stroke(255,50,15,90);
 line(xPos, height, xPos, height - inByte);

 // at the edge of the screen, go back to the beginning:
 if (xPos >= width) {
 xPos = 0;
 background(255);
 }
 else {
 // increment the horizontal position:
 xPos++;
 }
 }
 }
 
 void exportSensorVal(int pulse, int moisture, int breath){
  
  TableRow newRow = table.addRow();
  newRow.setInt("time", table.getRowCount() - 1);
  newRow.setInt("pulseSensorVal", pulse);
  newRow.setInt("moistureSensorVal", moisture);
  newRow.setInt("breathSensorVal", breath);
  
  saveTable(table, "data/data.csv"); 
   
 }
