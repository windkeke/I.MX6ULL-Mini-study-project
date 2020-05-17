obj = start.o main.o 

ledc.bin : $(obj)
	arm-linux-gnueabihf-ld -Timx6ull.dls $^ -o led.elf
	arm-linux-gnueabihf-objcopy -O binary -S -g led.elf $@
	arm-linux-gnueabihf-objdump -D led.elf > led.dis

%.o : %.c
	arm-linux-gnueabihf-gcc -g -c -o $@ $<

%.o : %.s
	arm-linux-gnueabihf-gcc -g -c -o $@ $<

clean:
	rm -rf *.o *.bin *.elf *.dis


	