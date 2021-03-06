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
    led_init();
    beep_init();
    while(1)
    {
        beep_on();
        Led_on();
        delay_ms(500);
        beep_off();
        Led_off();
        delay_ms(500);
    }
    return 0;
}