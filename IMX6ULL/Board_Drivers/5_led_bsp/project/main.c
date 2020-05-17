#include"bsp_clk.h"
#include"bsp_delay.h"
#include"bsp_led.h"

/*
 * @description	: LED闪烁程序
 * @param 		: 无
 * @return 		: 无
 */
int main(void)
{
    clk_enable();
    led_init();
    while(1)
    {
        Led_on();
        delay_ms(500);
        Led_off();
        delay_ms(500);
    }
    return 0;
}