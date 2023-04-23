#include <Arduino.h>
#include <NewPing.h>
 
#define TRIGGER_PIN  8
#define ECHO_PIN     7
#define rung  5
#define MAX_DISTANCE 450
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
    
void setup() {
  pinMode(rung, OUTPUT);
  Serial.begin(9600);
}
    
void loop() {
  delay(200);
  int distance = sonar.ping_cm();
  Serial.print("Khoang cach: ");
  Serial.print(distance);
  Serial.println(" cm");
    
  if (distance <= 10 && distance > 0) {
    analogWrite(rung, 64);
  }
  else if (distance <= 7 && distance > 0) {
    analogWrite(rung, 127);
  }
  else if (distance <= 5 && distance > 0) {
    analogWrite(rung, 191);
  }
  else if (distance <= 2 && distance > 0) {
    analogWrite(rung, 255);
  }
  else{
    analogWrite(rung,0);
  }
}
