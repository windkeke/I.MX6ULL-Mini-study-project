CROSS_COMPILE	?=	arm-linux-gnueabihf-
NAME			:=	ledc

CC				:=	$(CROSS_COMPILE)gcc
LD           	:=	$(CROSS_COMPILE)ld
OBJCOPY			:= 	$(CROSS_COMPILE)objcopy
OBJDUMP			:= 	$(CROSS_COMPILE)objdump

OBJS			:=  Start.o main.o

$(NAME).bin : $(OBJS)
	$(LD) -Timx6ull.lds -o $(NAME).elf $^
	$(OBJCOPY) -O binary -S $(NAME).elf $@
	$(OBJDUMP) -D -m arm $(NAME).elf > $(NAME).dis

%.o : %.s
	$(CC) -Wall -nostdlib -c -o $@ $< 

%.o : %.S
	$(CC) -Wall -nostdlib -c -o $@ $<

%.o : %.c
	$(CC) -Wall -nostdlib -c -o $@ $<

clean:
	rm -rf *.o $(NAME).bin $(NAME).elf $(NAME).dis