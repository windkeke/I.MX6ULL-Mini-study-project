#include"bsp_clk.h"
#include"bsp_delay.h"
#include"bsp_beep.h"
#include"bsp_led.h"


/*
 * @description	: beep闪烁程序
 * @param 		: 无
 * @return 		: 无
 */
int main(void)
{
    clk_enable();
    beep_init();
    led_init();
    while(1)
    {
        Led_on();
        delay_ms(1000);
        beep_on();
        delay_ms(500);
        Led_off();
        beep_off();
        delay_ms(500);
    }
    return 0;
}