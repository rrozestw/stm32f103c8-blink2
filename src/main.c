#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
/* Infinite loop /
/ Use GDB to find out why we're here */
while (1);
}
#endif

void delay(int time)
{
    int i;
    for (i = 0; i < time * 4000; i++) {}
}

int main(void)
{
    GPIO_InitTypeDef gpio; // obiekt gpio z konfiguracja portow GPIO

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // uruchomienie zegara modulu GPIO

    GPIO_StructInit(&gpio); // domyslna konfiguracja
    gpio.GPIO_Pin = GPIO_Pin_0; // konfigurujemy pin 5
    gpio.GPIO_Mode = GPIO_Mode_Out_PP; // jako wyjscie
    GPIO_Init(GPIOB, &gpio); // inicjalizacja modulu GPIOA

    while (1) {
        GPIO_SetBits(GPIOB, GPIO_Pin_0); // zapalenie diody
        delay(100);
        GPIO_ResetBits(GPIOB, GPIO_Pin_0); // zgaszenie diody
        delay(400);
    }
}

