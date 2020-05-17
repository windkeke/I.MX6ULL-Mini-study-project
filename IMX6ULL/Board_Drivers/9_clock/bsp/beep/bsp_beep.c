#include"imx6ull.h"
#include"bsp_gpio.h"

/*
 * @description	: 初始化BEEP对应的GPIO
 * BEEP -> GPIO5_IO1
 * 
 * @param 		: 无
 * @return 		: 无
 */
void beep_init(void)
{
    gpio_pin_config_t beep_config;
    beep_config.direction = kGPIO_DigitalOutput;
    beep_config.outputLogic = 1;
    gpio_init(GPIO5,1, &beep_config);

}

/*
 * @description		: beep控制函数，控制beep打开
 * @param   		: 无
 * @return 			: 无
 */
void beep_on(void)
{
    gpio_pinwrite(GPIO5, 1, 0);    //BIT1 = 0
}
/*
 * @description		: beep控制函数，控制beep关闭
 * @param   		: 无
 * @return 			: 无
 */
void beep_off(void)
{
    gpio_pinwrite(GPIO5, 1, 1);   //BIT1 = 1
}