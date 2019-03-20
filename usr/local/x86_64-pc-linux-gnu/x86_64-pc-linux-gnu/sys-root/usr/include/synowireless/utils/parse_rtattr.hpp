/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */

#ifndef _SYNO_WIRELESS_UTILS_PARSE_RTATTR_HPP_
#define _SYNO_WIRELESS_UTILS_PARSE_RTATTR_HPP_

#include <string>
extern "C" {
#include <sys/socket.h>
#include <linux/rtnetlink.h>
}

namespace synowireless {
namespace utils {

int parse_rtattr(struct rtattr *tb[], int max, struct rtattr *rta, int len);

} /* namespace utils */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_UTILS_PARSE_RTATTR_HPP_ */
