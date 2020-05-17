#include"imx6ull.h"

/*
 * @description	: 初始化BEEP对应的GPIO
 * BEEP -> GPIO5_IO1
 * 
 * @param 		: 无
 * @return 		: 无
 */
void beep_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0);
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0X10B0);
    GPIO5->GDIR |= (1<<1);  //IO01设置为输出
    GPIO5->DR |= (1<<1);    //默认关闭 
}

/*
 * @description		: beep控制函数，控制beep打开还是关闭
 * @param   		: 无
 * @return 			: 无
 */
void beep_on(void)
{
    GPIO5->DR &= ~(1<<1);    //BIT3 = 0
}
/*
 * @description		: beep控制函数，控制beep打开还是关闭
 * @param   		: 无
 * @return 			: 无
 */
void beep_off(void)
{
    GPIO5->DR |= (1<<1);   //BIT3 = 1
}