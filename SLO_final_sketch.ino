#include <Servo.h> 
 
Servo myservoL;
Servo myservoR;
long timeInMillis = 0;
int LEFTPIN = 2;
int RIGHTPIN = 8;
int DANCEPIN = 13;

void setup() {
  pinMode(LEFTPIN,INPUT);
  pinMode(RIGHTPIN,INPUT);
  pinMode(DANCEPIN,INPUT);
  myservoL.attach(9);
  myservoR.attach(10);
  myservoL.write(10);
  myservoR.write(10);
  delay(3000);
  Serial.begin(9600);
}

void loop() {
  
  if(digitalRead(LEFTPIN) != LOW) {
    Serial.println("Press 2!!");
  } else if (digitalRead(RIGHTPIN) != LOW) {
    Serial.println("Press 8!!");
  } else if (digitalRead(DANCEPIN) != LOW) {
    Serial.println("Press 13!!");
  }

  if(digitalRead(LEFTPIN) != LOW) {
    myservoL.write(170);
  } else {
    myservoL.write(10);
  }

  if(digitalRead(RIGHTPIN) != LOW) {
    myservoR.write(170);
  } else {
    myservoR.write(10);
  }

  if(digitalRead(DANCEPIN) != LOW) {
    doTheDance();
  }
}

void doTheDance() {
  rotateRight();
  center();
  rotateLeft();
  center();
  listenUp();
  center();
}

void rotateRight() {
  myservoL.write(20);
  myservoR.write(170);
  delay(700);
}

void rotateLeft() {
  myservoL.write(170);
  myservoR.write(20);
  delay(700);
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
  delay(700);
}
