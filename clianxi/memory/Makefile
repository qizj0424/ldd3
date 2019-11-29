obj-m := memory.o

KERNELDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

modules:
	make -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *o *.mod.c *.order *.symver *.symvers
