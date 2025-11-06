#include <Keyboard.h> // include the keyboard library, which outputs native key commands on the Arduino

const int joyX = A0;   // Joystick X-axis input pin
const int joyY = A1;   // Joystick Y-axis input pin
const int joyBtn = 2;  // Joystick button input pin

// To understand how the joystick works
const int threshold = 300;  // Deadzone threshold around center (adjust as needed)
int centerX = 512;          // Default center value for X (approx)
int centerY = 512;          // Default center value for Y (approx)

bool keyA = false;
bool keyD = false;
bool keyJ = false;
bool keyL = false;
bool btnPressed = false;

void setup() {
  pinMode(joyBtn, INPUT_PULLUP);  // Joystick button usually active LOW
  Keyboard.begin();
}

void loop() {
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);
  int buttonState = digitalRead(joyBtn);

  // ----- LEFT / RIGHT -----
  if (xValue < centerX - threshold) {
    if (!keyA) {
      Keyboard.press('a');
      keyA = true;
    }
  } else {
    if (keyA) {
      Keyboard.release('a');
      keyA = false;
    }
  }

  if (xValue > centerX + threshold) {
    if (!keyD) {
      Keyboard.press('d');
      keyD = true;
    }
  } else {
    if (keyD) {
      Keyboard.release('d');
      keyD = false;
    }
  }

  // ----- UP / DOWN -----
  if (yValue < centerY - threshold) {
    if (!keyJ) {
      Keyboard.press('j');
      keyJ = true;
    }
  } else {
    if (keyJ) {
      Keyboard.release('j');
      keyJ = false;
    }
  }
  if (yValue > centerY + threshold) {
    if (!keyL) {
      Keyboard.press('l');
      keyL = true;
    }
  } else {
    if (keyL) {
      Keyboard.release('l');
      keyL = false;
    }
  }

  // ----- BUTTON PRESS -----
  if (buttonState == LOW && !btnPressed) {
    Keyboard.write('r');
    btnPressed = true;
  } else if (buttonState == HIGH) {
    btnPressed = false;
  }

  delay(50);  // Small debounce delay
}
