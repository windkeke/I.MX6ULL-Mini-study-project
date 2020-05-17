#include<stdio.h>

int add(int a, int b)
{
    return(a+b);
}

int main(void)
{

    int value = 0;
    value = add(5,6);
    printf("5 + 6 = %d\n",value);
}