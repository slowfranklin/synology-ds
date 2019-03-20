#ifndef __SYNO_SDUTILS_H__
#define __SYNO_SDUTILS_H__

#include <stdint.h>
#include <synocore/synotype.h>
#include <synocore/list.h>
#include <synocredentials/synocredentials.h>

__BEGIN_DECLS;

#define SZK_TIME_MACHINE_SHARES         "time_machine_shares"
#define SZK_TIME_MACHINE_DISABLE_SHARES "time_machine_disable_shares"
#define SZK_AFP_TIME_MACHINE_ENABLE     "enable_afp_time_machine"
#define SZK_SMB_TIME_MACHINE_ENABLE     "enable_smb_time_machine"
#define SZF_BONJOUR_TIME_MACHINE_CONF   "/usr/syno/etc/time_machine.conf"
#define SZF_AVAHI_TIME_MACHINE_CONF     "/etc/avahi/services/tm.service"
#define AFP_TIME_MACHINE                0x0001
#define SMB_TIME_MACHINE                0x0002

#define SZK_ADISK_TYPE                  "_adisk._tcp"

#ifndef MAXHOSTNAMELEN
#define MAXHOSTNAMELEN                  256
#endif

#ifndef INIT_NUM_SHARES
#define INIT_NUM_SHARES 512
#endif

#ifndef TXT_RECORD_LEN
#define TXT_RECORD_LEN 256
#endif

typedef enum {
    TMTYPE_AFP = 1,
    TMTYPE_SMB = 2
}TMTYPE;

typedef struct _syno_tmconf {
    uint16_t adVFFlags;
    /**
     * Broadcast TimeMachine share lists
     */
    PSLIBSZLIST pListShareName;
    /**
     * Share should not broadcast sometimes. For example:
     * Encrpyt share should not broacast when encrypt unmount.
     */
    PSLIBSZLIST pListDisableShareName;
}SYNO_TMCONF;

#include <availability.h>
#include "synosdutils_p.h"

__END_DECLS;
#endif // __SYNO_SDUTILS_H__
