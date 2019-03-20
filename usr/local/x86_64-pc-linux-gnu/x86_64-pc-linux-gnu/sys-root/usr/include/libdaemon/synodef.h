#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
#ifndef _SYNO_HEADER_LIBDAEMON_SYNODEF_
#define _SYNO_HEADER_LIBDAEMON_SYNODEF_

/**
 * Fix Bug #19937:
 * Handle empty pid file as corrupted pid file.
 * (To prevent sending kill(0))
 */

/**
 * Fix Bug #30747:
 * fix priority checking for prio not eq LOG_DEBUG
 */

#endif
