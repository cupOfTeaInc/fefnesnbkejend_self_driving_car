//master
#include <Wire.h>

#define SENSORHUBADDR 9
#define MOVEMENTHUBADDR 10
#define FWDBLOCKEDREVMS 2000

void setup() {
  // put your setup code here, to run once:
  Wire.begin();        
  Serial.begin(9600);
}

int sensorData[4];
char l = 0;
char r = 0;
bool fwdBeenBlocked = false;
int msFwdLastBlocked = 0;
void loop() {
  updateSensorData();

  if(sensorData[0] <= 20 or (fwdBeenBlocked and millis()-msFwdLastBlocked <= FWDBLOCKEDREVMS)){
    if(msFwdLastBlocked >= FWDBLOCKEDREVMS){
      msFwdLastBlocked = millis();
    }
    if(sensorData[2] >= 50){
      l = 127;
      r = 50;
    }else if(sensorData[3] >= 50){
      r = 127;
      l = 50;
    }else {
      r = -100;
      l = -100;
    }
    
  }
  
  changeMovement(l, r);
}

//acess and refresh sensor values

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
