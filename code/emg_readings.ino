#include <Servo.h>

const int emgPin = A0;
const int threshold = 500;

Servo thumb;
Servo indexFinger;
Servo middleFinger;
Servo ringFinger;
Servo littleFinger;

void setup() {
  Serial.begin(9600);

  thumb.attach(6);
  indexFinger.attach(7);
  middleFinger.attach(8);
  ringFinger.attach(9);
  littleFinger.attach(10);
}

void loop() {
  int emgValue = analogRead(emgPin);

  Serial.print("EMG Value: ");
  Serial.println(emgValue);

  if (emgValue > threshold) {
    closeHand();
  } else {
    openHand();
  }

  delay(100);
}

void closeHand() {
  thumb.write(90);
  indexFinger.write(90);
  middleFinger.write(90);
  ringFinger.write(90);
  littleFinger.write(90);
}

void openHand() {
  thumb.write(0);
  indexFinger.write(0);
  middleFinger.write(0);
  ringFinger.write(0);
  littleFinger.write(0);
}
