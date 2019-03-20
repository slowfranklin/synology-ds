#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
#ifndef SYNOHA_NODE_H
#define SYNOHA_NODE_H

#include <sys/cdefs.h>

#ifdef MY_ABC_HERE
#include <synocore/synotype.h>
#endif /* MY_ABC_HERE */

typedef enum {
	HA_ROLE_HA_NOT_RUNNING,
	HA_ROLE_ACTIVE,
	HA_ROLE_PASSIVE,
	HA_ROLE_PREPARE, // special type, when ha initialization (or crm not ready), the role is ambiguous
	HA_ROLE_PREACTIVE, // Get DUMMY_START, but no DUMMY_END
	HA_ROLE_SPLIT_BRAIN,
	HA_ROLE_MAX,
} HA_ROLE_TYPE;

typedef enum _tag_NODE_TYPE_ {
	NODE_TYPE_UNKNOWN,
	NODE_LOCAL,
	NODE_REMOTE,
	NODE_LEFT,
	NODE_RIGHT,
} NODE_TYPE;

__BEGIN_DECLS

/**
 * Get role of local node
 *
 * @return local node role
 * @see HA_ROLE_TYPE
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
HA_ROLE_TYPE SYNOHANodeRoleGet(void);

__END_DECLS

#ifdef MY_ABC_HERE

typedef enum _tag_NODE_STATUS_ {
	NODE_STATUS_UNKNOWN,
	NODE_STANDALONE,
	NODE_NONE,
	NODE_ONLINE,
	NODE_WARNING_ONLINE,
	NODE_WARNING_OFFLINE,
	NODE_OFFLINE,
	NODE_ERROR,
} NODE_STATUS;

NODE_STATUS HANodeStatusGet(const NODE_TYPE);
const char* HANodeStatusStr(const NODE_STATUS);
HA_ROLE_TYPE HANodeRoleTypeGet(const NODE_TYPE);
BOOL HAGetNodeHostName(NODE_TYPE type, char *szHost, int length);

#endif /* MY_ABC_HERE */

#endif
