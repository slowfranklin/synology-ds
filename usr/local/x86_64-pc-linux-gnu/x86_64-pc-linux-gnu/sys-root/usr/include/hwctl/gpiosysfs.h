// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef __SYNO_HWCTL_GPIOSYSFS_H_
#define __SYNO_HWCTL_GPIOSYSFS_H_

#include <syslog.h>

#define SZ_GPIO_SYSFS_PATH "/sys/class/gpio"
#define SZ_GPIO_SYSFS_EXPORT_PATH SZ_GPIO_SYSFS_PATH"/export"
#define SZ_GPIO_SYSFS_UNEXPORT_PATH SZ_GPIO_SYSFS_PATH"/unexport"
#define SZ_GPIO_DIRECTION_IN "in"
#define SZ_GPIO_DIRECTION_OUT "out"
#define SZ_GPIO_EDGE_BOTH "both"
#define SZ_GPIO_EDGE_RISING "rising"
#define SZ_GPIO_EDGE_FALLING "falling"
#define SZ_GPIO_EDGE_NONE "none"

int SYNOGpioGetValue(unsigned int gpio_num, unsigned int *pValue);
int SYNOGpioSetDirection(unsigned int gpio_num, int direction);
int SYNOGpioExport(unsigned int gpio_num, int export);

#endif /* __SYNO_HWCTL_GPIOSYSFS_H_ */
