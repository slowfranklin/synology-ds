#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef __SYNO_HWCTL_ENCLOSURE_H_
#define __SYNO_HWCTL_ENCLOSURE_H_
#ifdef MY_DEF_HERE
#include <hwctl/disk.h>
#include <synosas/enclosure.h>

__BEGIN_DECLS

/* lib/enclosure/enclosure_get_temperature_by_disk.c */
int SYNOEnclosureTempGetFromDisk(ENCLOSURE_INFO *pEnclosureInfo, int *temp);

__END_DECLS;
#endif /* MY_DEF_HERE */
#endif /* __SYNO_HWCTL_ENCLOSURE_H_ */
