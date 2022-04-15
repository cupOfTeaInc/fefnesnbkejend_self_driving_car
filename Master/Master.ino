//master
#include <Wire.h>

#define SENSORHUBADDR 9
#define MOVEMENTHUBADDR 10


void setup() {
  // put your setup code here, to run once:
  Wire.begin();        
  Serial.begin(9600);
}


char l = 0;
char r = 0;
void loop() {
  updateSensorData();
  
  changeMovement(l, r);
}

//acess and refresh sensor values
int sensorData[3];
void updateSensorData() {
  Wire.requestFrom(SENSORHUBADDR, 4);
  int i = 0;
  while (Wire.available()) { 
    sensorData[i] = Wire.read(); 
    i++;
  }
}
//control movement
void changeMovement(char l, char r) { //speed can be negative, char is a signed byte
  Wire.beginTransmission(MOVEMENTHUBADDR);
  Wire.write(l);
  Wire.write(r);
  Wire.endTransmission();
}
