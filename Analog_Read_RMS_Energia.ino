/*
  Analog input, serial output rms current value.
 
 created 18 Aug. 2017
 by julio
 
 This example code is in the public domain.
 
*/

// Analog pin used
const int analogInPin = A0;
// Analog channel offset
const int adcOffset = 2058;
// Analog channel scale
const float adcScale = (3.3/4095);
// Sensor scale
const float sensorScale = 5.33;
// Number of samples 
const int sampleNum = 40;

// sample window vector
int sensorValue[sampleNum] = {};
// to get rms value
float rms = 0;

void setup() {
  // initialize serial communications at 115200 bps:
  Serial.begin(115200); 

  // set analog converter to 12 bits (max) resolution
  analogReadResolution(12);
}

void loop() {
  // read the analog in value:
  for(int i=0;i<sampleNum;i++)
  {
    sensorValue[i] = analogRead(analogInPin); 
    delayMicroseconds(833); // Fs=1200Hz
  }

  for(int i=0;i<sampleNum;i++)
  {
    sensorValue[i]-=adcOffset;      // apply adc offset
    sensorValue[i]*=sensorValue[i]; // sensorValue^2
    rms+=sensorValue[i];            // sum
  }
  // average value
  rms/=sampleNum;

  // square root
  rms=sqrt(rms);         

  // normalize value
  rms*=(adcScale*sensorScale);

  // print the results to the serial monitor:  
  Serial.print("Load Current: ");
  Serial.print(rms); 
  Serial.println(" Arms");
  
  // wait 1 second before the next loop    
  delay(1000);
}
