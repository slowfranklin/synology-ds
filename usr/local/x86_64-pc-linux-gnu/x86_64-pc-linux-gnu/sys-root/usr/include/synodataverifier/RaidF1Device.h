#ifndef RAIDF1_DEVICE_H
#define RAIDF1_DEVICE_H

#include "RaidParityDevice.h"

class RaidF1Device : public RaidParityDevice {
public:
	RaidF1Device(const std::string &devicePath);
	TYPE_DEVICE GetDeviceType() const { return TYPE_RAIDF1; }
private:
};

#endif /* RAIDF1_DEVICE_H */
