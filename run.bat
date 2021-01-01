::cd cmake-build-release
::"C:/Program Files/Atmel/Studio/7.0/toolchain/avr8/avr8-gnu-toolchain/bin/avr-size.exe" -C --mcu=atmega328p WeatherStation
::"C:/Program Files/Atmel/Studio/7.0/toolchain/avr8/avr8-gnu-toolchain/bin/avr-objcopy.exe" -j .text -j .data -O ihex WeatherStation WeatherStation.hex
::"F:/Programs/avrdudeprog33/avrdude.exe" -p m328p -c usbasp -P usb -U flash:w:WeatherStation.hex:i
::cd ..

D:\Programs\avr8-gnu-toolchain-win32_x86\bin\avr-size.exe -C --mcu=atmega328p %1
D:\Programs\avr8-gnu-toolchain-win32_x86\bin\avr-objcopy.exe -j .text -j .data -O ihex %1 %1.hex
D:\Programs\avrdude\avrdude.exe -p m328p -c usbasp -P usb -U flash:w:%1.hex:i