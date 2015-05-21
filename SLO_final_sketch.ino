#include <Servo.h> 
 
Servo myservoL;
Servo myservoR;
long timeInMillis = 0;

void setup() {
  // put your setup code here, to run once:
  myservoL.attach(9);
  myservoR.attach(10);
  myservoL.write(10);
  myservoR.write(10);
  delay(3000);
  Serial.begin(9600);
}

void loop() {

  long mils = millis();

  if(mils%4000 >= 0 && mils%4000 < 700) {
    rotateRight();
  } else if (mils%4000 >= 2000 && mils%4000 < 2700) {
    rotateLeft();
  } else if(mils%4000 >= 700 && mils%4000 < 1000 || mils%4000 >= 2700 && mils%4000 < 3000) {
    center();
  } else if (mils%4000 >= 1000 && mils%4000 <= 1300) {
    listenUp();
  }
  
}

void rotateRight() {
  myservoL.write(20);
  myservoR.write(170);
}

void rotateLeft() {
  myservoL.write(170);
  myservoR.write(20);
}

void listenUp() {
  myservoL.write(120);
  myservoR.write(60);
  delay(125);
  myservoL.write(60);
  myservoR.write(120);
  delay(125);
}

void center() {
  myservoL.write(10);
  myservoR.write(10);
}
