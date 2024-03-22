#include <Arduino.h>
#include <NewPing.h>
#include "NostromoPinsAndGlobals.h"
#include "SGUltrasonic.h"

// Right motor side
#define RSmotorPin1 32 // Riv: IN1_PIN
#define RSmotorPin2 33 // Riv: IN2_PIN
#define RSenablePin 35 // Riv: ENA_PIN

// Left motor side
#define LSmotorPin1 26 // Riv: IN3_PIN
#define LSmotorPin2 25 // Riv: IN4_PIN
#define LSenablePin 34 // Riv: ENB_PIN

// Setting PWM properties
const int freq = 30000;
const int RSpwmChannel = 0;
const int LSpwmChannel = 0;
const int resolution = 8;
const int run_time = 2000; // Riv: Duration
int Lspeed = 255;          // Riv: straight_A
int Rspeed = 255;          // Riv: straight_B

// put function declarations here:
void Forward();
void Reverse(int Duration);
void Stop();
void RotateRight(int Duration);
void RotateLeft(int Duration);

void setup()
{
  // put your setup code here, to run once:

  // start serial communication for debugging/testing
  Serial.begin(9600);

  // set pins as outputs
  pinMode(RSmotorPin1, OUTPUT);
  pinMode(RSmotorPin2, OUTPUT);
  pinMode(RSenablePin, OUTPUT);
  pinMode(LSmotorPin1, OUTPUT);
  pinMode(LSmotorPin2, OUTPUT);
  pinMode(LSenablePin, OUTPUT);

  // configure LED PWM functionalities
  ledcSetup(RSpwmChannel, freq, resolution);
  ledcSetup(LSpwmChannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(RSenablePin, RSpwmChannel);
  ledcAttachPin(LSenablePin, LSpwmChannel);

  // Testing
  Serial.println("Testing DC Motor...");
}

//
//
//
//
//

void loop()
{
  // delay(2500);
  unsigned int stop_or_go = is_to_close();
  if (stop_or_go == 1)
  {
    Serial.println("STOP");
    Serial.println("Motor stopped");
    Stop();
    // delay(100);        //only for testing
  }
  else
  {
    Serial.println("Go");
    Serial.println("Moving Forward");
    Forward();
    // delay(100);        //only for testing
  }
  Serial.println("loop end");
  Serial.println("");
}

//
//
//
//
//

// put function definitions here:
void Forward()
{
  // Function to drive forward for amount of time Duration
  Serial.print("Forward function ");
  // Side A spins clockwise
  digitalWrite(RSmotorPin1, LOW);
  digitalWrite(RSmotorPin2, HIGH);
  // Side B spins clockwise
  digitalWrite(LSmotorPin1, LOW);
  digitalWrite(LSmotorPin2, HIGH);
  // pwm yippee (S: not needed because of the way I setup)
  // analogWrite(RSenablePin, pwm_R);
  // analogWrite(LSenablePin, pwm_L);
}

//
//
//
//
//

void Reverse(int Duration)
{
  // Function to drive reverse for amount of time Duration

  Serial.print("Reverse for ");
  Serial.print(Duration / 1000);
  Serial.println(" seconds");
  // Side A spins counterclockwise
  digitalWrite(RSmotorPin1, HIGH);
  digitalWrite(RSmotorPin2, LOW);
  // Side B spins counterclockwise
  digitalWrite(LSmotorPin1, HIGH);
  digitalWrite(LSmotorPin2, LOW);
  delay(Duration);
}

//
//
//
//
//

void Stop()
{
  Serial.println("Stop function");
  // Side A spins clockwise
  digitalWrite(RSmotorPin1, LOW);
  digitalWrite(RSmotorPin2, LOW);
  // Side B spins clockwise
  digitalWrite(LSmotorPin1, LOW);
  digitalWrite(LSmotorPin2, LOW);
}

//
//
//
//
//

void RotateRight(int Duration)
{
  // Function to drive right rotation for amount of time Duration
  Serial.print("RotateRight for ");
  Serial.print(Duration / 1000);
  Serial.println(" seconds");
  // Side A spins counterclockwise
  digitalWrite(RSmotorPin1, HIGH);
  digitalWrite(RSmotorPin2, LOW);
  // Side B spins clockwise
  digitalWrite(LSmotorPin1, LOW);
  digitalWrite(LSmotorPin2, HIGH);
  delay(Duration);
}

//
//
//
//
//

void RotateLeft(int Duration)
{
  // Function to drive left rotation for amount of time Duration

  Serial.print("RotateLeft for ");
  Serial.print(Duration / 1000);
  Serial.println(" seconds");
  // Side A spins clockwise
  digitalWrite(RSmotorPin1, LOW);
  digitalWrite(RSmotorPin2, HIGH);
  // Side B spins counterclockwise
  digitalWrite(LSmotorPin1, HIGH);
  digitalWrite(LSmotorPin2, LOW);
  delay(Duration);
}
