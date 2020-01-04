# hello-oled

This is just an example of how to use the Atmel START+ASF4 synchronous
drivers to control the OLED display and the on-board LEDs.

The SPI driver is configured to use SERCOM6. The OLED board is plugged
into EXT3 and the pin assignments to drive the display are as follows:

- PC04 MOSI
- PC05 SCLK
- PC07 MISO
- PC14 Slave Select
- PC31 Display Reset
- PC01 Data/Command Select

For the LEDs, they are:

- PC18 LED0
- PC10 LED1
- PD11 LED2
- PD10 LED3


**NOTES**

- The display code for the OLED is utter garbage. It effectively
  turns the bit-addressable display into a 16x2 display.

