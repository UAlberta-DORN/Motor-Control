int x = 0;

#include <AccelStepper.h>
#define dirPin 15
#define stepPin 2
#define motorInterfaceType 1

// Define a stepper and the pins it will use
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);


void setup() {
 Serial.begin(115200);
 Serial.setTimeout(1);
 stepper.setMaxSpeed(500);
 stepper.setAcceleration(1000);
}

void loop() {
  stepper.run();
  if (Serial.available() > 0) {
    delay(100);
    x = Serial.readString().toInt();
    Serial.print(x);
    stepper.move(x);
  }
  if (stepper.distanceToGo() == 0){
    stepper.setCurrentPosition(0);
  }
}
