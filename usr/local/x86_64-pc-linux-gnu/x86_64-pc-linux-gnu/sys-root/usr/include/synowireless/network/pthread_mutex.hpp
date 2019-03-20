/* Copyright (c) 2000-2014 Synology Inc. All rights reserved. */
#ifndef _SYNO_NETWORK_PTHREAD_MUTEX_HPP_
#define _SYNO_NETWORK_PTHREAD_MUTEX_HPP_

#include <pthread.h>

namespace synonetwork {
namespace network {

class PthreadMutex {
public:
	PthreadMutex();
	~PthreadMutex();

	bool Lock();    // blocked
	bool TryLock(); // not blocked
	bool Unlock();
private:
	pthread_mutex_t mutex_;
};
} /* namespace network */
} /* namespace synonetwork */
#endif /* _SYNO_NETWORK_PTHREAD_MUTEX_HPP_ */
