// Copyright (c) 2000-2016 Synology Inc. All rights reserved.
#ifndef __SYNOLOCALACCOUNT_USER_H__
#define __SYNOLOCALACCOUNT_USER_H__

#include <synosdk/user.h>

__BEGIN_DECLS;

#define SZD_HOME_NOEXIST        "/nonexist"

/**
 * @brief Local user password policy.
 *
 * Rules of strong password. For boolean fields, 0 means false and 1 means true.
 */
typedef struct {
	/** @brief Whether strong password enabled. */
	int strong_password_enable;
	/** @breif Exclude user name and description, caseless. */
	int exclude_username;
	/** @brief Whether minimum password length enabled, see also `min_length`. */
	int min_length_enable;
	/** @brief Mix alphabets and digits. */
	int included_numeric_char;
	/** @brief Mix upper and lower cases. */
	int mixed_case;
	/** @brief Include special characters. */
	int included_special_char;
	/** @brief Minimum password length, see also `min_length_enable`. */
	int min_length;
	/** @brief Exclude common passwords. */
	int exclude_common_password;
	/** @brief Exclude passwords in history, see also `history_num`. */
	int exclude_history;
	/** @brief Number of history to remember, see also `exclude_history`. */
	int history_num;
} SYNOPASSWDRULE;

/**
 * @brief Password status according to its age, read man pages of shadow
 *        and getspnam for more details.
 *
 * @note "Disallow change password" (i.e. sp_min > sp_max) is NOT included.
 */
typedef enum {
	/** @brief Unknown. */
	PASSWORD_STATUS_UNKNOWN = -1,
	/** @brief Normal. */
	PASSWORD_IS_NORMAL,
	/** @brief Password expired, i.e. age>sp_max. */
	PASSWORD_EXPIRED,
	/** @brief Password is too young for change, i.e. age<sp_min. */
	PASSWORD_TOO_YOUNG,
	/** @brief Password must be changed now, i.e. sp_lstchg=0. */
	PASSWORD_MUST_CHANGE,
	/** @brief Password change time, i.e. sp_lstchg, is from future. */
	PASSWORD_FROM_FUTURE,
} SYNO_PASSWORD_STATUS;

__END_DECLS;

#ifdef __cplusplus
#include <iostream>

/**
 * @brief Local user password expiry settings.
 */
struct SYNOPASSWORDEXPIRY {
	bool enable_max_age;
	long max_age_days;
	bool enable_min_age;
	long min_age_days;
	bool enable_login_prompt;
	long login_prompt_days;
	bool enable_reset_on_expired;
	bool enable_mail_notify;
	long mail_task_id;
	long mail_notify_hour;
	long mail_notify_minute;
	std::string mail_check_points;
	SYNOPASSWORDEXPIRY();
};

#endif  // __cplusplus

#ifndef NO_PROTO
#include "user_p.h"
#endif // NO_PROTO

#endif // __SYNOLOCALACCOUNT_USER_H__
