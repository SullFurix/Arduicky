//Windows files General Availability by SullFurix: 12/06/2019
#include <HIDKeyboard.h>

HIDKeyboard keyboard; 

  void setup() {
    keyboard.begin();
  } 

  void loop() {
    keyboard.pressKey(GUI, 'r'); // Press Windows+R
    delay(2000); // Wait 2 secondes
    keyboard.println("notepad"); // Types 'notepad'
    keyboard.releaseKey(); // Releases keys
    delay(2000); // Wait 2 secondes
    keyboard.pressSpecialKey(ENTER); // Sends an "Enter" keypress
    keyboard.releaseKey(); // Releases "Enter"
    delay(2000); // Wait 2 secondes
    keyboard.println("Hello Word"); // Types "Hello World!" followed by a carriage return
    while(1); // Hold forever
  }
