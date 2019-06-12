
#include <HIDKeyboard.h>

HIDKeyboard Keyboard; 

  void setup() {
    Keyboard.begin();
  } 

  void loop() {
    Keyboard.pressKey(GUI, 'r'); // Types 'A'
    delay(2000);
    Keyboard.println("notepqd");
    Keyboard.releaseKey();
    delay(2000);
    Keyboard.pressSpecialKey(ENTER); // Sends an "Enter" keypress
    Keyboard.releaseKey(); // Releases "Enter"
    delay(2000);
    Keyboard.println("HelloWorld"); // Types "Hello World!" followed by a carriage return
    while(1); // Hold forever
  }
