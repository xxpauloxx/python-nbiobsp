#!/bin/bash
KER_VER=`uname -r`
DRIVER_PATH="/lib/modules/$KER_VER/kernel/drivers/usb/misc/"
device="ngstar"
major=180
minor=246

echo "NITGEN USB Finkey HAMSTER II Driver Install "

  if [ -d $DRIVER_PATH ]; then
  # Do nothing
      echo
  else
    echo Driver Path does not exist , will create
    mkdir $DRIVER_PATH
   fi
	if [ -f $DRIVER_PATH/ngstardrv.ko  ]; then
		echo $DRIVER_PATH"ngstardrv.ko already exists"
    echo run uninstaller  to uninstall drive 
		exit 1
	fi
    if [ -f ngstardrv.ko  -a  -f ngstardrv.h  ]; then
     drvkernel=`/sbin/modinfo ngstardrv.ko | grep vermagic | cut -f8 -d " "`
     # checking for kernel version with driver compiled version .
    if [ $drvkernel == $KER_VER ]; then
        #echo "copying ----- driver DUMMY  "
		    cp -v ngstardrv.ko $DRIVER_PATH
    else
      echo your kernel version $KER_VER does not match with NITGEN USB Driver compiled kernel verion  $drvkernel
      echo you can compile NITGEN USB Finkey HAMSTER II driver source
      echo and run this script or Get $KER_VER driver binary from vendor.
      exit 1
    fi
	else
		echo "ngstardrv.ko or ngstardrv.h  file not found in current dir ....."
		exit 1;
	fi
			if [ -f /usr/include/linux/ngstardrv.h ]; then
			echo "ngstardrv.h already exists"
			exit 1
		fi
	cp -v ngstardrv.h /usr/include/linux/

#remove stale node
rm -f /dev/${device}[0-7]

# check dynamic devicefile scheme
is_dyn_usb_devfile_use=`cat /lib/modules/$KER_VER/build/include/generated/autoconf.h | grep CONFIG_USB_DYNAMIC_MINORS`
if [ -z "${is_dyn_usb_devfile_use}" ] ; then
    # static device file use...
    #create 8 nodes for the device
    mknod /dev/${device}0 c $major `expr $minor + 0`
    mknod /dev/${device}1 c $major `expr $minor + 1`
    mknod /dev/${device}2 c $major `expr $minor + 2`
    mknod /dev/${device}3 c $major `expr $minor + 3`
    mknod /dev/${device}4 c $major `expr $minor + 4`
    mknod /dev/${device}5 c $major `expr $minor + 5`
    mknod /dev/${device}6 c $major `expr $minor + 6`
    mknod /dev/${device}7 c $major `expr $minor + 7`
else
    # dynamic device file use...
    cp -av ./99-Nitgen-ngstardrv.rules /etc/udev/rules.d
fi

#move  to driver detination directory
cd $DRIVER_PATH

#install the driver module into kernel
/sbin/insmod ngstardrv.ko

# driver dependacy update
/sbin/depmod

echo "NITGEN USB Finkey HAMSTER II Driver sucessfully installed "
echo "Disconnect the Device and Plug it back "
