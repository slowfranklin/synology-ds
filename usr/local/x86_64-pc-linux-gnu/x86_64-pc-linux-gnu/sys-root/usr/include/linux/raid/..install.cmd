cmd_/source/linux-3.10.x-virtual-headers/usr/include/linux/raid/.install := /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/raid /source/linux-3.10.x-virtual-headers/include/uapi/linux/raid md_p.h md_u.h; /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/raid /source/linux-3.10.x-virtual-headers/include/linux/raid ; /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/raid /source/linux-3.10.x-virtual-headers/include/generated/uapi/linux/raid ; for F in ; do echo "\#include <asm-generic/$$F>" > /source/linux-3.10.x-virtual-headers/usr/include/linux/raid/$$F; done; touch /source/linux-3.10.x-virtual-headers/usr/include/linux/raid/.install