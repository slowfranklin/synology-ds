cmd_/source/linux-3.10.x-virtual-headers/usr/include/linux/tc_act/.install := /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/tc_act /source/linux-3.10.x-virtual-headers/include/uapi/linux/tc_act tc_csum.h tc_gact.h tc_ipt.h tc_mirred.h tc_nat.h tc_pedit.h tc_skbedit.h; /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/tc_act /source/linux-3.10.x-virtual-headers/include/linux/tc_act ; /bin/sh scripts/headers_install.sh /source/linux-3.10.x-virtual-headers/usr/include/linux/tc_act /source/linux-3.10.x-virtual-headers/include/generated/uapi/linux/tc_act ; for F in ; do echo "\#include <asm-generic/$$F>" > /source/linux-3.10.x-virtual-headers/usr/include/linux/tc_act/$$F; done; touch /source/linux-3.10.x-virtual-headers/usr/include/linux/tc_act/.install