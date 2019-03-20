/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef LIBSYNORANDOM_INCLUDE_SYNORANDOM_H_
#define LIBSYNORANDOM_INCLUDE_SYNORANDOM_H_

#include <string>
#include <pcg_variants.h>
#include "char_pools.h"

namespace SYNO {
namespace RANDOM {

/**
 * @brief SYNORandomBase provide a basic random number generator, use /dev/urandom as seeds.
 */
class SYNORandomBase {
public:
	/**
	 * Initialize with a seed.
	 * @apparmor abstractions/libsynorandom
	 */
	SYNORandomBase ();

	virtual ~SYNORandomBase ();

	/**
	 * Reseed by using /dev/urandom as random source
	 * @apparmor abstractions/libsynorandom
	 */
	void reseed ();

	/**
	 * Reseed manually, we use 16 bytes as seed.
	 * @param seed1 first 8 bytes
	 * @param seed2 last 8 bytes
	 */
	void reseed (uint64_t seed1, uint64_t seed2);

	/**
	 * Get a random number 0 <= x <= UINT32_MAX
	 * @return random number
	 */
	uint32_t urandom ();

	/**
	 * Get a random number start <= x <= end
	 * @param  start start number
	 * @param  end   end number
	 * @return random number
	 */
	uint32_t urandom (uint32_t start, uint32_t end);

	/**
	 * Get a random number INT32_MIN <= x <= INT32_MAX
	 * @return random number
	 */
	int32_t random ();

	/**
	 * Get a random number start <= x <= end
	 * @param  start start number
	 * @param  end   end number
	 * @return       random number
	 */
	int32_t random (int32_t start, int32_t end);

protected:
	pcg32_random_t *rng;
};

/**
 * @brief SYNORandom provide a random generator with getString and choice
 */
class SYNORandom : public SYNORandomBase {
public:
	/**
	 * Get a random string, use charPool as character pool
	 * @param  strCharPool character pool
	 * @param  length      string length
	 * @param  strOutput   output string
	 * @return             success or not
	 */
	bool getString (const std::string &strCharPool, size_t length, std::string &strOutput);

	/**
	 * Get a random string, use POOL_ALPHA_NUMERIC as character pool
	 * @param  length      string length
	 * @param  strOutput   output string
	 * @return             success or not
	 */
	bool getString (size_t length, std::string &strOutput) { return getString(POOL_ALPHA_NUMERIC, length, strOutput); }

	/**
	 * Choice a element between two iterators
	 * @code{.cpp}
	 * vector<int> myList = {1,2,3};
	 * int randomNum = SYNORandom().choice(myList.begin(), myList.end());
	 * @endcode
	 * @param start        Start Iterator
	 * @param end          End Iterator
	 * @return             random picked value
	 */
	template <typename Iter>
	const typename Iter::value_type& choice (Iter start, Iter end)
	{
		size_t count = 0;
		Iter it = start;
		for (; it != end; ++it, ++count) {
			// pass
		}
		uint32_t yield = urandom(0, count);
		it = start;
		for (size_t i = 0; it != end; ++it, ++i) {
			if (i == yield) {
				return *it;
			}
		}
		return *end;
	}
protected:
	/**
	 *@deprecated need to hide in implement, please remove me in DSM 6.1.
	 */
	static const int RESEED_COUNT = 24;
};

}// namespace RANDOM
}// namespace SYNO

#endif // LIBSYNORANDOM_INCLUDE_SYNORANDOM_H_
