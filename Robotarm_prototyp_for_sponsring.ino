#include <Stepper.h>

#include<
int stepsPerRevolution = 2048;
int rpm = 10;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11)

int trigPin = 2;
int echoPin = 4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myStepper.setSpeed(10); // Sätt hastighet i RPM (max ca 15 för denna motor)

}

void loop() {
  // put your main code here, to run repeatedly:
  // Skicka ut ultraljudspuls
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Läs av svarstiden
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; // Beräkna avstånd i cm

  Serial.print("Avstånd: ");
  Serial.print(distance);
  Serial.println(" cm");


  delay(500);
}
