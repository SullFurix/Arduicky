### HIDKeyboard (https://github.com/SFE-Chris/UNO-HIDKeyboard-Library)

Written by Chris Taylor for SparkFun Electronics, 10/15/12

This is an Arduino library written to simpify the use of the Arduino UNO as an HID device. It can NOT be used on its own. It must be used in conjunction with the arduino-keyboard firmware written by Darran, found here:

http://hunt.net.nz/users/darran/weblog/b3029/Arduino_UNO_Keyboard_HID_version_03.html

This firmware is meant to be installed on the ATMega8U2 on the UNO. I would attempt to write full installation instructions in this README, but Michael did a much more thorough and colorful job here:

http://mitchtech.net/arduino-usb-hid-keyboard/

NOTE that the ATMega328 cannot be programmed over USB when the arduino-keyboard firmware is installed on the ATMega8U2, you must flash the arduino-serial firmware again using FLIP, as explained in the above link.

ON TO THE LIBRARY:

The library defines a series of functions that make sending HID codes intuitive. Rather than having to look up and send HID codes for every character, the library takes care of it for you. Here's the jist:

Each HID report is sent as a key plus a modifier. The modifiers are CTRL, ALT, SHIFT, and GUI. By default each key is sent with a modifier of zero. The modifiers can be masked together to send more complex commands. The function pressKey() is overloaded to do this. For example:

To send the keypress 'k', use
		
	pressKey('k');
	
To send the keypress CTRL+ALT+k, use

	pressKey((CTRL | ALT), 'k');

There are similar functions for "Special Keys" like F1 that do not appear in the ASCII table. The values for these keys are defined in HIDKeyboard.h and are sent using the pressSpecialKey() function. For example:

To send the keypress TAB, use
		
	pressSpecialKey(TAB);
	
To send the keypress CTRL+ALT+TAB, use

	pressSpecialKey((CTRL | ALT), TAB);

There are also functions for printing ASCII strings, similar to the Serial.print() and println() functions. All of the functions are listed below:

	begin()
		
Initializes the HIDKeyboard object by ending any Serial communication and resetting it to 9600 baud

	pressKey(modifier, key)
	pressKey(key)

	pressSpecialKey(modifier, key)
	pressSpecialKey(key)

	releaseKey()

Releases any keys and modifiers that are currently down. NOTE: the pressKey and pressSpecialKey functions DO NOT release the key. releaseKey must be used to release the key. 

	print()
	
Sends keypresses for a full string. For example print("Hello World!");

	println()
		
Sends keypresses for a full string, followed by a carriage return. 

EXAMPLE:
	
	HIDKeyboard Keyboard; 

	void setup() {
		Keyboard.begin(); // Initializes keyboard
	}	

	void loop() {
		Keyboard.println("Hello World!");	// Types "Hello World!" followed by a carriage return
		Keyboard.pressSpecialKey(ENTER); // Sends an "Enter" keypress
		Keyboard.releaseKey(); // Releases "Enter"
		Keyboard.pressKey('a'); // Types 'a'
		Keyboard.releaseKey(); // Releases the 'a' key
		Keyboard.pressKey(SHIFT, 'a'); // Types 'A'
		Keyboard.releaseKey(); // Releases 'a' and SHIFT
		while(1); // Hold forever
	}

OUTPUT:

	Hello World!

	aA

For more examples, please see the included examples folder. 

### Arduino-keyboard-0.3 (https://github.com/coopermaa/USBKeyboard)

USBKeyboard is simple library for darran's Arduino UNO Keyboard HID.

darran's Arduino UNO Keyboard HID:
http://hunt.net.nz/users/darran/weblog/a6d52/Arduino_UNO_Keyboard_HID_version_02.html

### Arduino-usbserial-uno (https://github.com/arduino/ArduinoCore-avr/tree/master/firmwares/atmegaxxu2/arduino-usbserial)

To setup the project and upload the Arduino usbserial application firmware to an ATMEGA8U2 using the Arduino USB DFU bootloader:
1. unpack the source into LUFA's Projects directory
2. set ARDUINO_MODEL_PID in the makefile as appropriate
3. do "make clean; make"
4. put the 8U2 into USB DFU mode:
4.a. assert and hold the 8U2's RESET line
4.b. assert and hold the 8U2's HWB line
4.c. release the 8U2's RESET line
4.d. release the 8U2's HWB line
5. confirm that the board enumerates as either "Arduino Uno DFU" or "Arduino Mega 2560 DFU"
6. do "make dfu" (OS X or Linux - dfu-programmer must be installed first) or "make flip" (Windows - Flip must be installed first)

Check that the board enumerates as either "Arduino Uno" or "Arduino Mega 2560".  Test by uploading a new Arduino sketch from the Arduino IDE.

