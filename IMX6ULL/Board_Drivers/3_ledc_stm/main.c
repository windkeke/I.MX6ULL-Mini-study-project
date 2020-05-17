#include"imx6ull.h"

/*Init all clock*/
void Clock_Init(void)
{
    CCM->CCGR0 = 0xffffffff;
    CCM->CCGR1 = 0xffffffff;
    CCM->CCGR2 = 0xffffffff;
    CCM->CCGR3 = 0xffffffff;
    CCM->CCGR4 = 0xffffffff;
    CCM->CCGR5 = 0xffffffff;
    CCM->CCGR6 = 0xffffffff;

}
/*Config GPIO*/
void Gpio_Init(void)
{
    IOMUX_SW_MUX->GPIO1_IO03 = 0x5;
    IOMUX_SW_PAD->GPIO1_IO03 = 0X10B0;
    GPIO1->GDIR = 0x00000008;
}

void Led_on(void)
{
    GPIO1->DR &= ~(1<<3);    //BIT3 = 0
}

void Led_off(void)
{
    GPIO1->DR |= (1<<3);   //BIT3 = 1
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