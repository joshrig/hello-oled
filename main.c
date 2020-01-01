#include <inttypes.h>
#include <string.h>
#include <stdio.h>

#include <atmel_start.h>

#include "led.h"
#include "display.h"




int main(void)
{
        /* Initializes MCU, drivers and middleware */
        atmel_start_init();


        led_init();

        display_init(
            &SPI_0,
            GPIO(GPIO_PORTC, 31), // display reset
            GPIO(GPIO_PORTC,  1), // data/command select
            GPIO(GPIO_PORTC, 14)  // spi slave select
            );

        
        // systick interrupts every ~500ms (for a 12MHz clock)
        SysTick_Config(6000000);


        // wait for an interrupt.
        while (1)
            __WFI();
}


void SysTick_Handler(void)
{
    static uint32_t tick = 0;
    char buf[50];


    led_update();


    sprintf(buf, "Hello, World!\ntick: %ld", tick++);
    display_clear();
    display_write_string((const char *)buf, 1, 1);
}
