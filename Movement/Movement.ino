//movement
#include <Wire.h>

#define LEFTMOTORPINEN 3//pwm
#define LEFTMOTORPINFWD 4
#define LEFTMOTORPINREV 5

#define RIGHTMOTORPINEN 6//pwm
#define RIGHTMOTORPINFWD 7
#define RIGHTMOTORPINREV 8

#define ADDR 10
char l = 0;//motor speeds 
char r = 0;


void setup() {
  // put your setup code here, to run once:
  Wire.begin(ADDR);
  Wire.onReceive(receiveEvent);

  pinMode(LEFTMOTORPINEN, OUTPUT);
  pinMode(RIGHTMOTORPINEN, OUTPUT);
  
  pinMode(LEFTMOTORPINFWD, OUTPUT);
  pinMode(LEFTMOTORPINREV, OUTPUT);
  pinMode(RIGHTMOTORPINFWD, OUTPUT);
  pinMode(RIGHTMOTORPINREV, OUTPUT);
}

void loop() {
  if(l > 0){
    digitalWrite(LEFTMOTORPINFWD, HIGH);
    digitalWrite(LEFTMOTORPINREV, LOW);
  } else if(l < 0){
    digitalWrite(LEFTMOTORPINFWD, LOW);
    digitalWrite(LEFTMOTORPINREV, HIGH);
  }
  analogWrite(LEFTMOTORPINEN, abs(l));

  if(r > 0){
    digitalWrite(RIGHTMOTORPINFWD, HIGH);
    digitalWrite(RIGHTMOTORPINREV, LOW);
  } else if(r < 0){
    digitalWrite(RIGHTMOTORPINFWD, LOW);
    digitalWrite(RIGHTMOTORPINREV, HIGH);
  }
  analogWrite(RIGHTMOTORPINEN, abs(r));
}

void receiveEvent(int byteCount) {
  l = Wire.read();
  r = Wire.read();
}
