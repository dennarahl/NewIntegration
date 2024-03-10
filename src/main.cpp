#include <Arduino.h>
#include <NewPing.h>
#include "NostromoPinsAndGlobals.h"
#include "SGUltrasonic.h"

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(9600);
}

void loop()
{
  delay(2500);
  unsigned int stop_or_go = is_to_close();
  if (stop_or_go == 1)
  {
    Serial.println("STOP");
  }
  else
  {
    Serial.println("Go");
  }
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}