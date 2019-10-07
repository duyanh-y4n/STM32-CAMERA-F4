target remote :2338
mon reset
mon halt
load build/STM32-ESP-SPI.elf
symbol-file build/STM32-ESP-SPI.elf
b main
