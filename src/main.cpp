#include <Arduino.h>
#include <Servo.h>

Servo myservo;

int servoSpeedCoeff = 720;
int servoSpeedAngle = 60;
int servoVoltage = 5;
int servoButtonPin = 2;
float servoSpeed = servoSpeedCoeff / servoVoltage / servoSpeedAngle;

int servoAngle = 60;

float getServoRotateTime(int rotateAngle) {
  Serial.println(rotateAngle);
  Serial.println(servoSpeed);
  return rotateAngle * servoSpeed;
}


int rotateTime = getServoRotateTime(servoAngle);

void setup() {
  myservo.attach(3);
  myservo.write(0);
  pinMode(servoButtonPin, INPUT_PULLUP);

  Serial.begin(9600);

  Serial.println("Begin");
  Serial.println(rotateTime);
  
}

void loop() {
  int value = !digitalRead(servoButtonPin);

  if (value) {
    myservo.write(servoAngle);
    delay(rotateTime);
    myservo.write(0);
    delay(rotateTime);
  }
  
}
