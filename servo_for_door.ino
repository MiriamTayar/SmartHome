

#include <ESP32Servo.h>

const int servoPin = 18;

Servo servo;

void setup_servo() {
  servo.attach(servoPin, 500, 2400);
}


void servo_for_door(){
  int pos = 0;
for (pos = 0; pos <= 100; pos += 1) {
    servo.write(pos);
    delay(10);
  }
  delay(1000);
  for (pos = 100; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(50);
  }
}

