////////////
///////////  AllSDOutputs 
///////////   
//   
//  // make a string for assembling the data to log:
//  String dataString = "";
//
//
//// read two sensors and append to the string:
////  for (int analogPin = 0; analogPin < 1; analogPin++) {
////    int sensor = analogRead(analogPin);
////    dataString += String(sensor);
////    if (analogPin < 2) {
////      dataString += ",";
////    }
////  }
//  
//
//  // open the file. note that only one file can be open at a time,
//  // so you have to close this one before opening another.
//  File dataFile = SD.open("datalog.txt", FILE_WRITE);
//
//  // if the file is available, write to it:
//  if (dataFile) {
//    dataFile.println(dataString);
//    dataFile.close();
//    // print to the serial port too:
//    Serial.println(dataString);
//  }
//  // if the file isn't open, pop up an error:
//  else {
//    Serial.println("error opening datalog.txt");
//  }