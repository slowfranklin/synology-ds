cmd_/source/linux-3.10.x-virtual-headers/usr/include/linux/nfsd/.install := /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/nfsd /source/linux-3.10.x-virtual-headers/include/uapi/linux/nfsd cld.h debug.h export.h nfsfh.h stats.h; /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/nfsd /source/linux-3.10.x-virtual-headers/include/linux/nfsd ; /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/nfsd /source/linux-3.10.x-virtual-headers/include/generated/uapi/linux/nfsd ; for F in ; do echo "\#include <asm-generic/$$F>" > /source/linux-3.10.x-virtual-headers/usr/include/linux/nfsd/$$F; done; touch /source/linux-3.10.x-virtual-headers/usr/include/linux/nfsd/.install
