//sensors
#include <Wire.h>

#define ADDR 9

#define FWDPINGPIN 2
#define BCKPINGPIN 3
#define LFTPINGPIN 4
#define RGTPINGPIN 5
#define MAXDISTANCE 250

NewPing FWD(FWDPINGPIN, FWDPINGPIN, MAXDISTANCE);
NewPing BCK(BCKPINGPIN, BCKPINGPIN, MAXDISTANCE);
NewPing LFT(LFTPINGPIN, LFTPINGPIN, MAXDISTANCE);
NewPing RGT(RGTPINGPIN, RGTPINGPIN, MAXDISTANCE);

byte fwdDistance = 0;
byte bckDistance = 0;
byte lftDistance = 0;
byte rgtDistance = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(ADDR);
  Wire.onRequest(requestEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
  fwdDistance = FWD.ping_cm();
  delay(20);
  bckDistance = BCK.ping_cm();
  delay(20);
  lftDistance = LFT.ping_cm();
  delay(20);
  rgtDistance = RGT.ping_cm();
  delay(100);
}
void requestEvent(){
  Wire.write(fwdDistance);
  Wire.write(bckDistance);
  Wire.write(lftDistance);
  Wire.write(rgtDistance);
}
