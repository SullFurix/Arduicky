#include <HIDKeyboard.h>

HIDKeyboard keyboard; // Initialize HIDKeyboard object

void setup() {
  keyboard.begin(); // Start communication
  delay(2000); // Wait for device to be found as a keyboard
}

void loop() {
  
  // Send first Hello World using the println() function
  keyboard.println("SullFurix");
  
  while(1);
}
