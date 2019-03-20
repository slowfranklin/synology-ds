#ifndef STRIPE_GROUP_H
#define STRIPE_GROUP_H

#include "RaidDevice.h"

#define PARITY_CHUNK_P	-1
#define PARITY_CHUNK_Q	-2

typedef enum _tag_RAID_LEVEL {
	RAID_LEVEL_ERROR = -1,
	RAID_LEVEL_5,
	RAID_LEVEL_6,
	RAID_LEVEL_F1
} RAID_LEVEL;

struct ChunkPosition {
	ChunkPosition() : deviceNum(0), stripeNum(0) {}
	ChunkPosition(int x, int y) : deviceNum(x), stripeNum(y) {}
	int deviceNum;
	int stripeNum;
};

class StripeGroup {
public:
	StripeGroup(RAID_LEVEL raidLevel, RAID_PARITY_ALGORITHM layout, int numDevices);
	// Return PARITY_CHUNK_P and PARITY_CHUNK_Q when get P and Q chunk
	int GetChunkNum(unsigned int deviceNum, unsigned int stripeNum) const;
	ChunkPosition GetChunkPosition(unsigned int chunkNum) const;
	int GetNumDevices() const {return _numDevices;}
	int GetNumStripes() const {return _numStripes;}
	int GetNumDataChunks() const {return _numDataChunks;}
private:
	/*
	 * Define stripes in a whole cycle of parity as a group, which generally has size of numDevices * numDevices chunks
	 * Chunk table: (take raid5 left-symmetric for example)
	 *  ---------------------
	 *  | 0 | 1 | 2 | 3 | P |   (P is stored as -1 in table)
	 *  ---------------------
	 *  | 5 | 6 | 7 | P | 4 |   (parity Q is stored as -2 in table)
	 *  ---------------------
	 *  |10 |11 | P | 8 | 9 |
	 *  ---------------------
	 *  |15 | P |12 |13 |14 |
	 *  ---------------------
	 *  | P |16 |17 |18 |19 |
	 *  ---------------------
	 * Use chunkNumTable to convert chunk position to chunk number. For example : chunkNumTable[3][2] = 8
	 */
	int _chunkNumTable[MAX_NUM_SUBDEVICE][MAX_NUM_SUBDEVICE];
	// In above example, numStripes = 5, numDevices = 5, numDataChunks = 20 (not count the parity chunks)
	int _numDevices;
	int _numStripes;
	int _numDataChunks;
	// ChunkPos store the coordinates of the chunk, chunkPos[5(chunk number)] = {x = 0, y = 1}
	std::vector<ChunkPosition> _dataChunkPositions;

	int InitializeForRaid5(RAID_PARITY_ALGORITHM layout, int initNumDevice);
	int InitializeForRaid6(RAID_PARITY_ALGORITHM layout, int initNumDevice);
	int InitializeForRaidF1(RAID_PARITY_ALGORITHM layout, int initNumDevice);
};

#endif /* STRIPE_GROUP_H */
