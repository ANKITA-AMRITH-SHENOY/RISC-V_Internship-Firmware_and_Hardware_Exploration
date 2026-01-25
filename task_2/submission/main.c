// main.c - Updated to demonstrate all required functions
#include "ch32v00x.h"
#include "gpio.h"
#include "uart.h"

void delay_ms(uint32_t ms) {
    uint32_t i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 6000; j++);  // Calibrated for ~24MHz CH32V003
}

int main(void) {
    SystemCoreClockUpdate();
    
    gpio_init();
    uart_init(115200);
    
    uart_send_string("GPIO Demo - set/clear/toggle cycle\r\n");
    
    int state = 0;
    while (1) {
        if (state == 0) {
            gpio_set(6);  // gpio_set(LED_PIN)
            uart_send_string("LED SET (ON)\r\n");
        } else if (state == 1) {
            gpio_clear(6);  // gpio_clear(LED_PIN)
            uart_send_string("LED CLEAR (OFF)\r\n");
        } else {
            gpio_toggle(6);  // gpio_toggle(LED_PIN)
            uart_send_string("LED TOGGLE\r\n");
            state = -1;  // Reset cycle
        }
        state++;
        delay_ms(1000);
    }
    
    return 0;
}
