cmd_/source/linux-3.10.x-virtual-headers/usr/include/linux/can/.install := /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/can /source/linux-3.10.x-virtual-headers/include/uapi/linux/can bcm.h error.h gw.h netlink.h raw.h; /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/can /source/linux-3.10.x-virtual-headers/include/linux/can ; /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/can /source/linux-3.10.x-virtual-headers/include/generated/uapi/linux/can ; for F in ; do echo "\#include <asm-generic/$$F>" > /source/linux-3.10.x-virtual-headers/usr/include/linux/can/$$F; done; touch /source/linux-3.10.x-virtual-headers/usr/include/linux/can/.install
