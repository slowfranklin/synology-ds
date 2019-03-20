#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef	_SYNO_AVAHI_H
#define _SYNO_AVAHI_H

/**
 * Add a loglevel option in avahi-daemon.conf
 */

/**
 * Add option to set service need to resolve
 */

/**
 * Bug #22321(2011Q2), #22608
 * - allow '_' in avahi host name
 */

/**
 * Bug #44964, 43704
 * - Wrong format from other device
 */
#define SYHO_AVAHI_WRONG_FORMAT

/**
* Avahi-browse may have chance to set poll fd timeout to -1,
* which means an infinite timeout.
*/
#ifdef MY_ABC_HERE
#define SYNO_AVAHI_BROWSE_TIMEOUT		100
#define SYNO_AVAHI_BROWSE_MAX_RETRY	100

/**
* Avahi broadcast cname
*/

/**
* Avahi Interface check
* DSM B#93505 - Some interface cannot connect by other client (ex: docker*).
* Therefore, we should not broadcast these interface information.
*/

/**
* FOR Fix resource leak
*/

#endif
#endif
