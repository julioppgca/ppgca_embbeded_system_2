/*
  Analog input, serial output (use plot serial to view).
 
 created 18 Aug. 2017
 by julio
 
 This example code is in the public domain.
 
 */

// Analog pin used
const int analogInPin = A0; 

int sensorValue = 0;

void setup() {
  // initialize serial communications at 115200 bps:
  Serial.begin(115200); 

  // set analog converter to 12 bits (max) resolution
  analogReadResolution(12);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);            

  // print the results to the serial monitor:  
  Serial.println(sensorValue); 
  //Serial.println(0); 
  
  // wait 833 micro seconds before the next loop    
  delayMicroseconds(833);
}
