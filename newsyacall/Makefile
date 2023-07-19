ifneq ($(KERNELRELEASE),)
	obj-m := newsyscall.o
else
	KERNELDIR ?= /home/loongkernel/linux-4.19-ls2k1000la
	PWD  := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions
endif