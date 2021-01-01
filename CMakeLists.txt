cmake_minimum_required(VERSION 3.2)
project(WeatherStation C)

SET(MCU "atmega328p")
SET(F_CPU "16000000")

#-fpack-struct option is mandatory for compiler (pragma pack analog)
SET(CMAKE_C_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -DNDEBUG -Os -fno-move-loop-invariants -fno-tree-scev-cprop -fno-inline-small-functions -funsigned-char -funsigned-bitfields -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -Wno-unknown-pragmas -std=gnu99")
SET(CMAKE_C_LINK_FLAGS "-mmcu=${MCU} -Wl,--relax,--gc-sections")

include_directories(.)

add_executable(WeatherStation main.c i2c/i2c.c i2c/i2c.h bme280/bme280.c bme280/bme280.h bme280/bme280_defs.h bme280/bme280_user.c bme280/bme280_user.h spi/spi.c spi/spi.h common/definitions.h common/runtime_info.h common/settings.h lcd/lcd.h lcd/lcd.c)