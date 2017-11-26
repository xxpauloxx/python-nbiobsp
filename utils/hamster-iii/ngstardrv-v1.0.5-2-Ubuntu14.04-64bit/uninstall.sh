#!/bin/sh

# first uninstall driver
./uninstall-driver.sh

#remove user module
echo "uninstalling library........."
if [ -f /lib/ngstarlib.so ]; then
	rm -f /lib/ngstarlib.so
fi
#remove Device conf. file
if [ -f /etc/ngstardrv.conf ]; then
	rm -f /etc/ngstardrv.conf
fi
echo "driver un-installed successfully"
