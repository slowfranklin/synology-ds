cmd_/source/linux-3.10.x-virtual-headers/usr/include/linux/byteorder/.install := /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/byteorder /source/linux-3.10.x-virtual-headers/include/uapi/linux/byteorder big_endian.h little_endian.h; /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/byteorder /source/linux-3.10.x-virtual-headers/include/linux/byteorder ; /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/byteorder /source/linux-3.10.x-virtual-headers/include/generated/uapi/linux/byteorder ; for F in ; do echo "\#include <asm-generic/$$F>" > /source/linux-3.10.x-virtual-headers/usr/include/linux/byteorder/$$F; done; touch /source/linux-3.10.x-virtual-headers/usr/include/linux/byteorder/.install
