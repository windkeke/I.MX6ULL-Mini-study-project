#include "GPIO.h"

/*Init all clock*/
void Clock_Init(void)
{

    CCM_CCGR0 = 0xffffffff;
    CCM_CCGR1 = 0xffffffff;
    CCM_CCGR2 = 0xffffffff;
    CCM_CCGR3 = 0xffffffff;
    CCM_CCGR4 = 0xffffffff;
    CCM_CCGR5 = 0xffffffff;
    CCM_CCGR6 = 0xffffffff;
}
/*Config GPIO*/
void Gpio_Init(void)
{
    SW_MUX_GPIO1_IO03 = 0x5;
    SW_PAD_GPIO1_IO03 = 0x10b0;
    GPIO1_GDIR = 0x00000008;
    GPIO1_DR = 0x0;
}

void Led_on(void)
{
    GPIO1_DR &= ~(1<<3);    //BIT3 = 0
}

void Led_off(void)
{
    GPIO1_DR |= (1<<3);   //BIT3 = 1
}
void delay_short(volatile unsigned int i)
{
    while(i--){}
}
void delay_ms(volatile unsigned int i)
{
    while(i--)
    {
        delay_short(0x7ff);
    }
}
int main(void)
{
    Clock_Init();
    Gpio_Init();
    while(1)
    {
        Led_on();
        delay_ms(500);
        Led_off();
        delay_ms(500);
    }
    return 0;
}