REM Windows files General Availability by SullFurix: 12/06/2019

@echo off
echo ==========================
echo =       SullFurix        =
echo ==========================

echo  ________________________
echo (                        )
echo ( Reset the aurdino...   )
echo (________________________)

pause

echo  ________________________
echo (                        )
echo ( Loading...             )______________________________
echo (                                                       )
.\bin\windows\dfu-programmer.exe atmega16u2 erase
.\bin\windows\dfu-programmer.exe atmega16u2 flash --debug 1 "lib\Arduino-usbserial-uno.hex"
.\bin\windows\dfu-programmer.exe atmega16u2 reset
echo (_______________________________________________________)
echo (                        )
echo ( Plug cycle and program )
echo (________________________)

pause

echo  ________________________
echo (                        )
echo ( Reset the aurdino...   )
echo (________________________)

pause

echo  ________________________
echo (                        )
echo ( Loading...             )______________________________
echo (                                                       )
.\bin\windows\dfu-programmer.exe atmega16u2 erase
.\bin\windows\dfu-programmer.exe atmega16u2 flash --debug 1 "lib\Arduino-keyboard-0.3.hex"
.\bin\windows\dfu-programmer.exe atmega16u2 reset
echo (_______________________________________________________)
echo (                        )
echo ( End... Have Fun!!      )
echo (________________________)

pause