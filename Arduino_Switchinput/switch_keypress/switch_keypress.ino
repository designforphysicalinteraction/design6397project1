#include <Keyboard.h>      // include library that let's Arduino act as a keyboard

// some useful values
#define OFF 0
#define ON 1

// start by assuming no buttons are pressed
bool keyA = OFF;

void setup() {
  // put your setup code here, to run once:

  // make pin 2 an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  // All the key presses happen here
  //////////////////////////////////////////////

  if ((digitalRead(2) == HIGH) && keyA == OFF)
  {
    keyA = ON;
    Keyboard.write(65); // A
  }
  if (digitalRead(2) == LOW)
  {
    keyA = OFF;
  }
}
