// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_WIRELESS_SEMAPHORE_HPP_
#define _SYNO_WIRELESS_SEMAPHORE_HPP_

namespace synowireless {
namespace semaphore {

class Semaphore {
public:
	Semaphore(unsigned int iNewKey);
	~Semaphore();

	int Enter();
	int Release();
private:
	int Get(int *piSemid);

	unsigned int iKey;
};

} /* namespace semaphore */
} /* namespace synowireless */

#endif /* _SYNO_WIRELESS_SEMAPHORE_HPP_ */
