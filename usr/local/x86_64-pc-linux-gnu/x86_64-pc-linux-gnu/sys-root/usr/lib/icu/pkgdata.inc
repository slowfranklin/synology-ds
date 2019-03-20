GENCCODE_ASSEMBLY_TYPE=-a gcc
SO=so
SOBJ=so
A=a
LIBPREFIX=lib
LIB_EXT_ORDER=.56.1
COMPILE=/usr/local/x86_64-pc-linux-gnu/bin/x86_64-pc-linux-gnu-ccache-gcc -DSYNOPLAT_F_X86_64 -O2 -include /usr/syno/include/platformconfig.h -DSYNO_ENVIRONMENT -DBUILD_ARCH=64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DSYNO_RUNNING_DSM_BUILD_SYSTEM -g -pipe -fstack-protector --param=ssp-buffer-size=4 -Wformat -Wformat-security -D_FORTIFY_SOURCE=2 -O2 -Wno-unused-result -D_REENTRANT  -DU_HAVE_ELF_H=1 -DU_HAVE_ATOMIC=1  -DU_DISABLE_RENAMING=1 -DU_ATTRIBUTE_DEPRECATED= -DSYNOPLAT_F_X86_64 -O2 -include /usr/syno/include/platformconfig.h -DSYNO_ENVIRONMENT -DBUILD_ARCH=64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DSYNO_RUNNING_DSM_BUILD_SYSTEM -g -pipe -fstack-protector --param=ssp-buffer-size=4 -Wformat -Wformat-security -D_FORTIFY_SOURCE=2 -O2 -Wno-unused-result -std=c99 -Wall -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings   -c
LIBFLAGS=-I/usr/include -DPIC -fPIC
GENLIB=/usr/local/x86_64-pc-linux-gnu/bin/x86_64-pc-linux-gnu-ccache-gcc -DSYNOPLAT_F_X86_64 -O2 -include /usr/syno/include/platformconfig.h -DSYNO_ENVIRONMENT -DBUILD_ARCH=64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DSYNO_RUNNING_DSM_BUILD_SYSTEM -g -pipe -fstack-protector --param=ssp-buffer-size=4 -Wformat -Wformat-security -D_FORTIFY_SOURCE=2 -O2 -Wno-unused-result -std=c99 -Wall -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings   -Wl,-z,relro -Wl,--as-needed -Wl,--no-undefined  -shared -Wl,-Bsymbolic
LDICUDTFLAGS=-nodefaultlibs -nostdlib
LD_SONAME=-Wl,-soname -Wl,
RPATH_FLAGS=
BIR_LDFLAGS=-Wl,-Bsymbolic
AR=/usr/local/x86_64-pc-linux-gnu/bin/x86_64-pc-linux-gnu-ar
ARFLAGS=r
RANLIB=/usr/local/x86_64-pc-linux-gnu/bin/x86_64-pc-linux-gnu-ranlib
INSTALL_CMD=/bin/install -c
