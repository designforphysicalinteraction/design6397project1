# Physical Joystick

## 1. Download Arduino IDE

Arduino is the microcontroller platform you will use to create your joystick. You can download the Arduino IDE here: https://www.arduino.cc/en/Main/Software which is where you will write your software, compile, and flash it into the Arduino. If you've never used an Arduino before, this page has all the info you need to get started: https://www.arduino.cc/en/Tutorial/HomePage

## 2. Program Arduino

We are using a clone of the Arduino Pro Micro (https://www.sparkfun.com/products/12640). Plug your Arduino into your computer and you should see a small red LED for power. If you don't, it could be because your Arduino is not properly connected to your computer or your computer might be having some driver issues recognizing the board.

Now let's make sure you can program your board.

First you need tell the Arduino IDE what port your board is connected to and make sure you've selected the right board.

Go to **Tools > Boards** and select **Arduino Micro**. **Arduino Leonardo** uses the same microcontroller and will also work.

Then select the port the Arduino is connected to.

Go to **Tools > Port** and then **/dev/cu.usbmodemHIDPC1 (Arduino Micro)**. <-- this is what it is called on my computer. Yours might be different.

Then run a simple example to make sure your Arduino programs correctly.

Go to **File > New Sketch**. This will open a blank sketch.

Click the Upload arrow. And you should get a **Done Uploading** message.

## 2.5 Reset

Because the keyboard functionality uses the serial port, which is also how we program the Arduino, you might get into a situation where the serial port is outputting numbers and doesn't let you reprogram the Arduino.

If this happens, connect a wire from the **RST (reset)** pin to ground. Then start upload and disconnect the reset wire. You might need to do this a few times to get the timing right. This video walks you through resetting the Arduino Pro Micro: https://youtu.be/K2G2ryJa-c8

**The Short Story: when using a Leonardo (or Pro Micro), only have it output serial commands when the user does something like press a button. If you have it output all the time by default, you will get into this situation.**

## 3. Add a Button

Follow the example on the Sparkfun website to add a button and output a keyboard command when pressing it. Make sure that you change pin numbers to reflect the pins you are connecting your button to to:

https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/example-2-hid-mouse-and-keyboard

## 4. Add a Joystick and Run A_Joystick

Connect a joystick to your Arduino Pro Micro with jumper wires. In the example code, we use Analog Pins A0 and A1 for the movement (analog potentiometers), and digital input 2 to register press (switch):
![Hookup Guide](https://raw.githubusercontent.com/designforphysicalinteraction/design6397project1/refs/heads/main/figures/arduino_pro_micro_joystick_hookup.png)

## 5. Add a Rotary Encoder

Use the example included wih the Github repo. This example also requires a library that you will need to install by going to Tools > Manage Libraries and search for rotaryencoder. Look for the library by Matthias Hertel.

CLK and DT are the pins on the rotary encoder that you need to connect to Arduino to detect rotation.

SW works like a regular button if you press down the rotary encoder. Code is not included in the example for the switch but it's similar to the button sketch above.

This video has a good explanation of how the encoder works if you are curious:
https://www.youtube.com/watch?v=v4BbSzJ-hz4&ab_channel=HowToMechatronics

## 6. Run A_Rotary

Now adapt your electronics to run the A_Joystick code provided. You will need an encoder and 4 buttons. But you can start with just a button and see if you can get it to control your game similar to how your keyboard does.

## 7. Now Design your own Controller

Once you can fully control your game using only your own joystick, it's time to think about what the most appropriate joystick should be. Here are a few questions to help you think through the problem:

- What sensors should you use? How does the choice of sensor inform its behavior?
- Where should they be located? Are they close together or far apart? At the top, bottom or sides?
- Do you need one hand or both to control your joystick?
- How about multiple players?
