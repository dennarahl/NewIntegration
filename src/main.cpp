#include <Arduino.h>
#include <NewPing.h>
#include "NostromoPinsAndGlobals.h"
#include "SGUltrasonic.h"

// Right motor side
#define motor1Pin1 32
#define motor1Pin2 33
#define enable1Pin 35

// Left motor side
#define Lmotor1Pin1 26
#define Lmotor1Pin2 25
#define Lenable1Pin 34

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int LpwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);

  // start serial communication for debugging/testing
  Serial.begin(9600);

  // set pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(Lmotor1Pin1, OUTPUT);
  pinMode(Lmotor1Pin2, OUTPUT);
  pinMode(Lenable1Pin, OUTPUT);

  // configure LED PWM functionalities
  ledcSetup(pwmChannel, freq, resolution);
  ledcSetup(LpwmChannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);
  ledcAttachPin(Lenable1Pin, LpwmChannel);

  // Testing
  Serial.println("Testing DC Motor...");
}

void loop()
{
  // delay(2500);
  unsigned int stop_or_go = is_to_close();
  if (stop_or_go == 1)
  {
    Serial.println("STOP");
    Serial.println("Motor stopped");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(Lmotor1Pin1, LOW);
    digitalWrite(Lmotor1Pin2, LOW);
    delay(1000);
  }
  else
  {
    Serial.println("Go");
    Serial.println("Moving Forward");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(Lmotor1Pin1, LOW);
    digitalWrite(Lmotor1Pin2, HIGH);
    delay(1000);
  }
  Serial.println("loop end");
  Serial.println("");
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}