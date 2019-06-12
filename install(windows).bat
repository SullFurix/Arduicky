REM Windows files General Availability by SullFurix: 12/06/2019

@echo off
echo ================================
echo =          SullFurix           =
echo ================================

SET rootArduino=
echo  ______________________________
echo (                              )
SET /p rootArduino="( Root of the arduino software:  "
echo (______________________________)

echo  ______________________________
echo (                              )
echo ( Loading...                   )
echo (                              )
copy ".\lib\HIDKeyboard.cpp" "%rootArduino%\hardware\arduino\avr\cores\arduino"
copy ".\lib\HIDKeyboard.h" "%rootArduino%\hardware\arduino\avr\cores\arduino"
echo (                              )
echo ( End... Have Fun!!            )
echo (______________________________)

pause