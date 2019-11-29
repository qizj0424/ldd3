#obj-m:=hello.o
#
#KERNELDIR:=/lib/modules/`uname -r`/build
#PWD :=$(shell pwd)
#
#modules:
#	$(MAKE)  -C  $(KERNELDIR)  M=$(PWD)  modules
#clean:
#	rm -rf *o *.mod.c *.order *.symver *.symvers



obj-m:=hello.o

CURRENT_PATH        :=$(shell pwd)

LINUX_KERNEL        :=$(shell uname -r)

LINUX_KERNEL_PATH   :=/lib/modules/$(LINUX_KERNEL)/build

all:

	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules

clean:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean
