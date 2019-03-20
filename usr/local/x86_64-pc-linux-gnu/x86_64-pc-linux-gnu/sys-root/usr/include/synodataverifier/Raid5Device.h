#ifndef RAID5_DEVICE_H
#define RAID5_DEVICE_H

#include "RaidParityDevice.h"

class Raid5Device : public RaidParityDevice {
public:
	Raid5Device(const std::string &devicePath);
	TYPE_DEVICE GetDeviceType() const { return TYPE_RAID5; }
private:
};

#endif /* RAID5_DEVICE_H */
