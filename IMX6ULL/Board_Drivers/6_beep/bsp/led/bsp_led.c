#include"imx6ull.h"

/*
 * @description	: 初始化LED对应的GPIO
 * @param 		: 无
 * @return 		: 无
 */
void led_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03,0);
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03,0X10B0);
    GPIO1->GDIR |= (1<<3);
    GPIO1->DR = 0x0; 
}

/*
 * @description		: LED控制函数，控制LED打开还是关闭
 * @param   		: 无
 * @return 			: 无
 */
void Led_on(void)
{
    GPIO1->DR &= ~(1<<3);    //BIT3 = 0
}
/*
 * @description		: LED控制函数，控制LED打开还是关闭
 * @param   		: 无
 * @return 			: 无
 */
void Led_off(void)
{
    GPIO1->DR |= (1<<3);   //BIT3 = 1
}