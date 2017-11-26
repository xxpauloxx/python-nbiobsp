#!/bin/sh
KER_VER=`uname -r`
DRIVER_PATH="/lib/modules/$KER_VER/kernel/drivers/usb/misc/"
device="ngstar"
echo "uninstalling driver......."

#remove stale node
   rm -f /dev/${device}[0-7]

# uninstall driver from kernel space
   /sbin/rmmod ngstardrv.ko
  
#delete module from source
	if [ -f $DRIVER_PATH/ngstardrv.ko ]; then
		rm -f $DRIVER_PATH/ngstardrv.ko
	fi
#remove headerfile
	if [ -f /usr/include/linux/ngstardrv.h ]; then
		rm -f /usr/include/linux/ngstardrv.h
	fi
        if [ -f /etc/udev/rules.d/99-Nitgen-ngstardrv.rules ] ; then
                rm -f /etc/udev/rules.d/99-Nitgen-ngstardrv.rules
        fi

/sbin/depmod

echo "driver un-installed successfully"
