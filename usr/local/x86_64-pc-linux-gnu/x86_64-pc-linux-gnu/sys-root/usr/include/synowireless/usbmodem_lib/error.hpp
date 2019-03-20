/* Copyright (c) 2000-2013 Synology Inc. All rights reserved. */
#ifndef _SYNO_WIRELESS_ERROR_HPP_
#define _SYNO_WIRELESS_ERROR_HPP_

namespace synowireless {
namespace usbmodem_lib {

enum ERROR_CODE {
	// Errors
	CONNECTION_FAILED	= -3,
	BAD_PIN				= -2,
	OTHER_ERROR			= -1,

	// Successes
	NO_ERROR			= 0,
	PROCESS_FINISH		= 1,
	PROCESS_BUSY		= 2
};

} /* namespace usbmodem_lib */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_ERROR_HPP_ */
