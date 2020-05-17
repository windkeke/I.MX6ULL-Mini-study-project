.global _start

.global _bss_start
_bss_start:
    .word __bss_start

.global _bss_end
_bss_end:
    .word __bss_end


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

    /*清除BSS段*/
    ldr r0, = __bss_start
    ldr r1, = __bss_end
    mov r2, #0
    bss_loop:
        stmia r0!, {r2}
        cmp r0, r1      @比较r0 r1里值的大小
        ble bss_loop    @如果r0里值小于等于r1，跳转到bss_loop继续执行

    /*跳转到c->main函数*/
    b main
    