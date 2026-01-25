// gpio.c - FIXED (Pure numbers, no GPIO_Pin_TypeDef)
#include "gpio.h"

void gpio_init(void) {
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin  = (1 << LED_PIN);  // 1<<6 = GPIO_Pin_6
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
}

void gpio_set(int pin) {
    GPIO_SetBits(GPIOD, (1 << pin));  // Direct bit position
}

void gpio_clear(int pin) {
    GPIO_ResetBits(GPIOD, (1 << pin));
}

void gpio_toggle(int pin) {
    uint8_t state = GPIO_ReadOutputDataBit(GPIOD, (1 << pin));
    if (state) {
        gpio_clear(pin);
    } else {
        gpio_set(pin);
    }
}
