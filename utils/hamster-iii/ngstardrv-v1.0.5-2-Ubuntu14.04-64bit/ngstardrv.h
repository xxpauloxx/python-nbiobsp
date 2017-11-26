/* NITGEN USB Fingkey Hamster II (hfdu14) driver  - 1.0
 * Copyright(C) 2009 NITGEN&COMPANY CO., Ltd.
 * History: 
 *	21/05/2009 : first release  
 */

#ifndef __LINUX_HFDU14__
#define __LINUX_HFDU14__

#include <asm/ioctl.h>
#include <asm/types.h>

#define _BULK_DATA_LEN 64
typedef struct
{
        unsigned char data[_BULK_DATA_LEN];
        unsigned int size;
        unsigned int pipe;
}bulk_transfer_t,*pbulk_transfer_t;
/* I/O Control macros */

#define FDU14_IOCTL_BULK_READ  	_IOW('E',   0x01, bulk_transfer_t)
#define FDU14_IOCTL_BULK_WRITE  	_IOR('E',   0x02, bulk_transfer_t)
#define FDU14_IOCTL_RESETPIPE  	_IO('E',    0x03)

#define FDU14_IOCTL_INIT_DEVICE              0x04
#define FDU14_IOCTL_GET_DUMP_IMAGE           0x05
#define FDU14_IOCTL_GET_IMAGE_DATA           0x06
#define FDU14_IOCTL_GET_LIVE_IMAGE           0x07
#define FDU14_IOCTL_GET_VISIBLE_IMAGE        0x08
#define FDU14_IOCTL_SENSOR_LED               0x09
#define FDU14_IOCTL_SET_SENSOR_OPTION        0x0a
#define FDU14_IOCTL_GET_SENSOR_OPTION        0x0b
#define FDU14_IOCTL_GET_SENSOR_INFORMATION   0x0c
#define FDU14_IOCTL_GET_ID                   0x0d
#define FDU14_IOCTL_SET_ID                   0x0e
#define FDU14_IOCTL_GET_E2PROM_DATA          0x0f
#define FDU14_IOCTL_SET_E2PROM_DATA          0x10
#define FDU14_IOCTL_GET_VALUE                0x11
#define FDU14_IOCTL_SET_VALUE                0x12
#define FDU14_IOCTL_GET_DEVICE_DESC          0x13
#define FDU14_IOCTL_GET_AUTOON_STATUS        0x14
#define FDU14_IOCTL_LOCK_DEVICE              0x15
#define FDU14_IOCTL_UNLOCK_DEVICE            0x16

#define FDU14_IOCTL_USB_CYCLE_PORT           0x17
#define FDU14_IOCTL_SET_LATENT               0x18

#define FDU06_IOCTL_GET_TOUCH_STATUS         0x19
#define FDU06_IOCTL_GET_SENSOR_SETTING       0x1a
#define FDU06_IOCTL_SET_SENSOR_SETTING       0x1b

#define FDU06_IOCTL_START_CONT_IMAGE_DATA    0x1c
#define FDU06_IOCTL_IR_START_CONT_IMAGE_DATA 0x1d
#define FDU06_IOCTL_STOP_CONT_IMAGE_DATA     0x1e

#endif /*  __LINUX_HFDU14__ */ 
