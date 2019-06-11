
#include <HIDKeyboard.h>

HIDKeyboard Keyboard; 

  void setup() {
    Keyboard.begin();
  } 

  void loop() {
    Keyboard.println("Hello World!"); // Types "Hello World!" followed by a carriage return
    Keyboard.pressSpecialKey(ENTER); // Sends an "Enter" keypress
    Keyboard.releaseKey(); // Releases "Enter"
    Keyboard.pressKey('a'); // Types 'a'
    Keyboard.releaseKey(); // Releases the 'a' key
    Keyboard.pressKey(SHIFT, 'a'); // Types 'A'
    Keyboard.releaseKey(); // Releases 'a' and SHIFT
    while(1); // Hold forever
  }
