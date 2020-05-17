.global _start

_start:
    /*设置CPU处于SVC模式*/
    /*配置CPSR状态寄存器M[4:0]=10011*/
    mrs r0, cpsr        @读取cpsr状态寄存器
    bic r0, r0, #0x1f    @清除M[4:0]
    orr r0, r0, #0x13    @M[4:0]=10011
    msr cpsr, r0

    /*设置sp指针*/
    /*2MB堆栈即sp->0x80000000 + 0x200000*/
    ldr sp, =0x80200000

    /*跳转到c->main函数*/
    b main
    