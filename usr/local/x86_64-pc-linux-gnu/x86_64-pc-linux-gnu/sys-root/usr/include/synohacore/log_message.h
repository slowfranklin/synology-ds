// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef SYNOHA_LOG_MESSAGE_H
#define SYNOHA_LOG_MESSAGE_H

#include <sys/cdefs.h>

__BEGIN_DECLS

/**
 * Send log message information to remote node
 *
 * This function should be called by passive node
 *
 * @param [in] logClass       LOG1_SYS, LOG1_MAN, LOG1_CON, LOG1_BAK, or LOG1_COPY....etc
 * @param [in] eventType      LOG1_INFO, LOG1_WARN or LOG1_ERR
 * @param [in] szEventContent The log message that had been converted from eventID
 * @param [in] szUserID       User ID
 * @retval 0 success
 * @retval -1 error
 * @grantable Y
 * @user root
 * @apparmor abstractions/libsynohacore
 */
int SYNOHALogMessageSend(int logClass, int eventType, const char *szEventContent, const char *szUserID);

__END_DECLS

#endif
