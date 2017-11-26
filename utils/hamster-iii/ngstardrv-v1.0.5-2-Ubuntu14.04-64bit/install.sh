#!/bin/bash

# make kernel driver
./CreateModule

# first driver install
./install-driver.sh

# second library install
if [ -f /lib/ngstarlib.so ]; then
	echo "ngstarlib.so already exists"
	exit 1
fi

if [ -f ngstarlib.so ]; then
	cp -v ngstarlib.so /lib/
else
	echo "ngstarlib.so not exist"
	exit 1
fi

if [ -f ngstardrv.conf ]; then
	cp -f ngstardrv.conf /etc/
else
	echo "ngstardrv.conf not exist"
	exit 1
fi

echo "NITGEN USB Fingkey Hamster II Library sucessfully installed "
