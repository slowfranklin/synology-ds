#ifndef RAID6_DEVICE_H
#define RAID6_DEVICE_H

#include "RaidParityDevice.h"
#include "StripeGroup.h"

class Raid6Device : public RaidParityDevice {
public:
	Raid6Device(const std::string &devicePath);
	TYPE_DEVICE GetDeviceType() const { return TYPE_RAID6; }
private:
};

#endif /* RAID6_DEVICE_H */
