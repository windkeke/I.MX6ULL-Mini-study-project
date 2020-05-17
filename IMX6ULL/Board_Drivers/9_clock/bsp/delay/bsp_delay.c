
void delay_short(volatile unsigned int i)
{
    while(i--){}
}


/*delayh ms*/
void delay_ms(volatile unsigned int i)
{
    while(i--)
    {
        delay_short(0x7ff);
    }
}