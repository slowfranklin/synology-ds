// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_STGCORE_VIRTUAL_SPACE_H__
#define __SYNO_STGCORE_VIRTUAL_SPACE_H__

#include <synostoragecore/space.h>

__BEGIN_DECLS;

#define SZF_VSPACE_LAYER_STATUS "/tmp/"SZ_VSPACE_LAYER_NAME".status"
#define SZ_VSPACE_LAYER_NAME "vspace_layer"
#define SZF_VSPACE_LAYER_CONF "/etc/space/"SZ_VSPACE_LAYER_NAME".conf"
#define MAX_VSPACE_PATH						MAX_LEN_DRBD_PATH
#define SZF_CACHE_LOAD_FAIL "/etc/space/cache_load_fail"
#define SZK_CACHE_MODE		"cache_mode"
#define SZK_CACHE_UUID		"cache_uuid"
#define SZK_VSPACE_REFERENCE "REFERENCE"
#define SZK_VSPACE_SPACE "SPACE"
#define SZK_FCACHE "FCACHE"
#define SZK_SNAPSHOT "SNAPSHOT_ORG"
#define SZK_HA "HA"

typedef enum VirtualSpaceType {
	VSPACE_NONE = 0,
	VSPACE_FLASH_CACHE = 0x01,
	VSPACE_SNAPSHOT_ORIGIN = 0x02,
	VSPACE_HA = 0x04,
	VSPACE_ALL = VSPACE_FLASH_CACHE | VSPACE_SNAPSHOT_ORIGIN | VSPACE_HA,
} VSPACE_TYPE;

typedef enum VirtualSpaceStatus {
	VSPACE_READ_WRITE = 1,
	VSPACE_READ_ONLY,
	VSPACE_NONE_ACCESS
} VSPACE_STATUS;

typedef enum VirtualSpaceAction {
	VSPACE_CREATE,			//Create specified virtual space
	VSPACE_DELETE,			//Delete specified virtual space
	VSPACE_LOAD,			//Load specified virtual space
	VSPACE_UNLOAD,			//Unload specified virtual space	
	VSPACE_RELOAD,			//Reload specified virtual space
	VSPACE_CREATE_ALL,
	VSPACE_DELETE_ALL,
	VSPACE_LOAD_ALL,
	VSPACE_LOAD_IN_STAGE,	//for HA(High Availability)
	VSPACE_UNLOAD_IN_STAGE,	//for HA(High Availability)
	VSPACE_UNLOAD_ALL,
	VSPACE_RESIZE_ALL,
	VSPACE_CHG_ALL,
} VSPACE_ACTION;

typedef enum VirtualSpaceEvent {
	E_BOOTUP_SPACE_ASSEMBLE = 1,
	E_HOTPLUG_SPACE_ASSEMBLE,
} VSPACE_EVENT;

typedef enum VirtualSpaceStage {
	VSPACE_BEFORE = 1,
	VSPACE_AFTER,
	VSPACE_EQUAL,
	VSPACE_NO_STAGE
} VSPACE_STAGE;

typedef enum VSpaceChangeType {
	VSPACE_CHG_REFERENCE_PATH=0x01,
	VSPACE_CHG_UUID=0x02,
} VSPACE_CHG_TYPE;

typedef struct VSpaceFilter{
	const char * szSpaceUUID;
	const char * szVSpacePath;
	const SPACE_INFO *pSpace;
} VSPACE_FILTER;

typedef struct VSpaceLayerFilter{
	char *szReferencePath;
	char *szSpacePath;
} VSPACE_LAYER_FILTER;

typedef struct VSpaceLayerInfo{
	int vspaceType;  //VSPACE_TYPE
	char *szType;
	char *szPath;
	struct VSpaceLayerInfo *pNext;
} VSPACE_LAYER_INFO;

typedef int (*PFuncNotify)(const SPACE_ADD_DISK_PROGRESS *);

typedef struct VSpaceLayerResizeAllInput{
	const SPACE_INFO *pSpace;
	PFuncNotify pNotify;
} VSPACE_RESIZE_ALL_INPUT;

typedef struct VSpaceLayerChgAllInput{
	int chgType;			//VSPACE_CHG_TYPE
	SPACE_INFO *pSpace;
	const char *szNewReferencePath;	//For Changing Reference Path
	const char *szNewSpaceUUID;		//For Changing Single RAID UUID
	PFuncNotify pNotify;
} VSPACE_CHG_ALL_INPUT;

typedef struct VSpaceConfig{
	VSPACE_TYPE type; 
	void *pConfig;
} VSPACE_CONFIG;

typedef enum VSpaceConfCheckType {
	VSPACE_CHK_SPECIFIC = 1,
	VSPACE_CHK_STAGE,
} VSPACE_CONFCHK_TYPE;

typedef struct VSpaceLayerConfCheckInput {
	VSPACE_CONFCHK_TYPE type;
	VSPACE_STAGE stage;
	int vspace;  // VSPACE_TYPE
} VSPACE_CONFIG_CHK_INPUT;

typedef struct VSpaceLayerConfFilter{
	const char *szSpaceUUID;
	const char *szSpacePath;
} VSPACE_LAYER_CONF_FILTER;

#include <synostoragecore/virtual_space_p.h>

__END_DECLS;

#endif
