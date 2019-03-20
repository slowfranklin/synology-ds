#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_HWCTL_FAN_H_
#define __SYNO_HWCTL_FAN_H_

#include <hwctl/disk.h>
#include <libxml/tree.h>
#include <hwctl/fan_def.h>

__BEGIN_DECLS;

typedef struct _tag_FAN_CONFIG_OPS_T FAN_CONFIG_OPS_T;
typedef struct _tag_FAN_TABLE_OPS_T FAN_TABLE_OPS_T;

typedef enum {
	DUAL_MODE_HIGH      = 0x01,
	DUAL_MODE_LOW       = 0x02,
	DUAL_MODE_LOW_STOP  = 0x04,
	DUAL_MODE_FULL      = 0x08,
} FAN_TYPE_BITMAP;

typedef enum {
	UI_FAN_SPEED_ON = 0,
	UI_FAN_SPEED_OFF,
	UI_FAN_SPEED_HIGH,
	UI_FAN_SPEED_LOW,
	UI_FAN_SPEED_FULL,
} UI_FAN_SETTING;

typedef enum {
	FAN_UNKNOWN_MODE = 0,
	FAN_NONE_MODE,
	FAN_SINGLE_MODE,
	FAN_DUAL_DISK_MODE,
	FAN_DUAL_COOL_MODE,
	FAN_DUAL_RS_MODE
} FAN_SUPPORT_TYPE;

typedef enum {
	DUAL_MODE_HIGH_INTERNAL = 0,
	DUAL_MODE_LOW_INTERNAL,
	DUAL_MODE_LOW_STOP_INTERNAL,
	DUAL_MODE_FULL_INTERNAL,
	DUAL_MODE_HIGH_EBOX,
	DUAL_MODE_LOW_EBOX,
	DUAL_MODE_FULL_EBOX,
	CPUFAN,
} FAN_CONFIG_TYPE_T;

typedef enum {
        FAN_CONFIG_UNKNOW = 0,
        FAN_CONFIG_INTERNAL,
        FAN_CONFIG_EBOX,
        FAN_CONFIG_CPUFAN,
} FAN_CONFIG_TYPE_NAME_T;

#define FOR_EACH_FANTABLE(index) \
        for (index = FAN_TABLE_THERMAL; index!=FAN_TABLE_TYPE_MAX; ++index)

#define IS_FAN_TABLE_NAME_VALID(EXP) !(EXP==FAN_TABLE_TYPE_UNKNOW || EXP==FAN_TABLE_TYPE_MAX)

/* FAN_TABLE_TYPE_UNKNOW should be negative value, we will use its value to check,
 * FAN_TABLE_THERMAL is the beginning type, it should be at the start,
 * and FAN_TABLE_MAX should be at end.
 * Because we will use these types for functions to do loop check, we have "FAN_TABLE_TYPE_MAX"
 *
 * If you want add some new fan table,
 * you should add it before FAN_TABLE_TYPE_MAX
 */
typedef enum {
        FAN_TABLE_TYPE_UNKNOW = 0,
        FAN_TABLE_THERMAL,
        FAN_TABLE_DISKTMP,
        FAN_TABLE_CPUTMP,
        FAN_TABLE_EUNIT_DISKTMP,
        FAN_TABLE_M2_DISKTMP,
        FAN_TABLE_TYPE_MAX,
} FAN_TABLE_TYPE_NAME_T;

/* these actions are matched by bit */
typedef enum _tag_TEMPERATURE_ACTION_T {
        TEMPERATURE_ACTION_NONE       = 0x00,
        TEMPERATURE_ACTION_ALERT_LED  = 0x01,
        TEMPERATURE_ACTION_SHUTDOWN   = 0x02,
        TEMPERATURE_ACTION_UNDERCLOCK = 0x04,
} TEMPERATURE_ACTION_T ;

typedef enum {
        GET_TEMP_FAIL = 0,
        GET_TEMP_THERMAL,
        GET_TEMP_DISK,
        GET_TEMP_CPU,
        GET_TEMP_SSD,
        GET_TEMP_EBOX,
        GET_TEMP_NO_SUPPORT_HIBERNATION,
        // treat empty ebox as a special case not error itself
        GET_TEMP_EBOX_EMPTY,
} GET_TEMP_RET_T;

typedef enum {
        PECI0 = 0,
        PECI1,
        PECI2,
        PECI3,
        REMOTE1,
        LOCAL,
        REMOTE2,
        ADT_INPUT_UNKNOWN,
} ADT_INPUT_CONFIG_TYPE;

typedef enum {
        PWM_UNKNOWN = 0,
        PWM1,
        PWM2,
        PWM3,
} ADT_PWM_TYPE;

typedef enum {
        PWM_SOURCE_UNKNOWN       = 0,
        PWM_MAX_PWM              = 1,
        PWM_MANUAL               = 2,
        PWM_SOURCE_ALLINPUT      = 3,
        PWM_SOURCE_ALLPECI       = 4,
        PWM_SOURCE_PECI0         = 5,
        PWM_SOURCE_PECI1         = 6,
        PWM_SOURCE_PECI2         = 7,
        PWM_SOURCE_PECI3         = 8,
        PWM_SOURCE_ALLSENSOR     = 9,
        PWM_SOURCE_REMOTE2LOCAL  = 10,
        PWM_SOURCE_REMOTE1       = 11,
        PWM_SOURCE_LOCAL         = 12,
        PWM_SOURCE_REMOTE2       = 13,
} ADT_PWM_SOURCE_TYPE;

typedef enum {
        BMC_FAN_FULL_SPD = 0,
        BMC_FAN_AUTO_SPD = 1,
} BMC_FAN_SPD_TYPE;

typedef struct _tag_SCEMD_FAN_STATUS {
        /* We must save the Fan speed for comparing in fan control process
         *      * and save action for executing
         *           */

        unsigned int          uiCurrentThreshold;
        int                   iLevel;
        FAN_SPEED             speed;
        TEMPERATURE_ACTION_T  action;
        unsigned int          periodInSec;
        time_t                timeLastUpdate;
        unsigned int          threshold;
        /* we also save level and name , because these will be used in "buffer mode" */
        FAN_TABLE_TYPE_NAME_T tableName;
} SCEMD_FAN_STATUS;

typedef struct _tag_ADT_FAN_CHECK_STATUS_T {
        SCEMD_FAN_STATUS status;
        struct _tag_ADT_FAN_CHECK_STATUS_T *pNext;
} ADT_FAN_CHECK_STATUS_T;

typedef struct _tag_ADT_STATUS_T {
        BOOL isInFullSpeed;
        ADT_FAN_CHECK_STATUS_T *pADTCheckStatus;
} ADT_FAN_STATUS_T;

typedef struct _tag_ADT_FAN_MAPPING_T {
        unsigned int           adtFanOrder;
        int                    adtFanModuleOrder;
        ADT_PWM_TYPE           adtFanPWMSource;
} ADT_FAN_MAPPING_T;

typedef struct _tag_ADT_PWM_CONFIG_ATTR_T {
        ADT_PWM_TYPE                  pwmType;
        ADT_PWM_SOURCE_TYPE           pwmControl;
        unsigned char                 pwmHighFreq;
        unsigned char                 pwmDutyLow;
        unsigned char                 pwmDutyHigh;
        unsigned char                 pwmMinBelowTmin;
} ADT_PWM_CONFIG_ATTR_T;

typedef struct _tag_ADT_PWM_CONFIG_T {
        ADT_PWM_CONFIG_ATTR_T        pwm;
        struct _tag_ADT_PWM_CONFIG_T *pNext;
} ADT_PWM_CONFIG_T;

typedef struct _tag_ADT_SENSOR_CONFIG_ATTR_T {
        ADT_INPUT_CONFIG_TYPE           inputType;
        int                             iTempMin;
        int                             iTempTherm;
        int                             iTempRange;
        int                             iTempCritHyst;
} ADT_SENSOR_CONFIG_ATTR_T;

typedef struct _tag_ADT_SENSOR_CONFIG_T {
        ADT_SENSOR_CONFIG_ATTR_T        sensor;
        struct _tag_ADT_SENSOR_CONFIG_T *pNext;
} ADT_SENSOR_CONFIG_T;

typedef struct _tag_ADT_TEMP_ALERT_ATTR_T {
        FAN_TABLE_TYPE_NAME_T        name;
        int                          iWarningTemp; /* sys warning temperature for UI to show light */
        int                          iUnderClockTemp; /* sys warning temperature for underclocking */
        int                          iTurboBoostTemp; /* sys temperature for turboboost */
        int                          iShutDownTemp;  /* sys warning temperature for shutdown */
        unsigned int                 uiThreshold;
        unsigned int                 uiPeriod;
} ADT_TEMP_ALERT_ATTR_T;

typedef struct _tag_ADT_TEMP_ALERT_T {
        ADT_TEMP_ALERT_ATTR_T        alert;
        struct _tag_ADT_TEMP_ALERT_T *pNext;
} ADT_TEMP_ALERT_T;

typedef struct _tag_ADT_FAN_CONFIG_T {
        FAN_CONFIG_TYPE_T           type;
        char                        *szHWVersion;
        int                         iFanEnableFullSpeedTemp;
        int                         iFanDisableFullSpeedTemp;
        int                         iPECIOffset;
        int                         iSkipFanCheckTemp;
        ADT_TEMP_ALERT_T            *pCritSysTemp;
        ADT_SENSOR_CONFIG_T         *pADTSensorConfig;
        ADT_PWM_CONFIG_T            *pADTPWMConfig;
        ADT_FAN_MAPPING_T           *pADTIntFanMapping;
} ADT_FAN_CONFIG_T;

typedef struct _tag_BMC_FAN_MAPPING_T {
        unsigned int           bmcFanOrder;
} BMC_FAN_MAPPING_T;

typedef struct _tag_BMC_TEMP_ALERT_ATTR_T {
        FAN_TABLE_TYPE_NAME_T        name;
        int                          iWarningTemp; /* sys warning temperature for UI to show light */
        int                          iShutDownTemp;  /* sys warning temperature for shutdown */
        unsigned int                 uiThreshold;
        unsigned int                 uiPeriod;
        int                          fullspd_temp;
        int                          fullspd_hyst;
} BMC_TEMP_ALERT_ATTR_T;

typedef struct _tag_BMC_TEMP_ALERT_T {
        BMC_TEMP_ALERT_ATTR_T        alert;
        struct _tag_BMC_TEMP_ALERT_T *pNext;
} BMC_TEMP_ALERT_T;

typedef struct _tag_BMC_FAN_CONFIG_T {
        FAN_CONFIG_TYPE_T           type;
        char                        *szHWVersion;
        int                         iFanEnableFullSpeedTemp;
        int                         iFanDisableFullSpeedTemp;
        int                         iSkipFanCheckTemp;
        int                         iFullSpeedDuty;
        BMC_TEMP_ALERT_T            *pCritSysTemp;
        BMC_FAN_MAPPING_T           *pBMCIntFanMapping;
} BMC_FAN_CONFIG_T;

typedef struct _tag_FAN_TABLE_LEVEL_T {
        unsigned int temperature;
        FAN_SPEED    speed;
        TEMPERATURE_ACTION_T action;
        unsigned int periodInSec;
        unsigned int threshold;
        /* this attribute is not in scemd.xml */
        unsigned int level;
} FAN_TABLE_LEVEL_T;

typedef struct _tag_FAN_TABLE_TYPE_T {
        FAN_TABLE_TYPE_NAME_T name;
        FAN_TABLE_LEVEL_T *pFanTableLevels;
        unsigned int iFanTableSize;
        FAN_TABLE_OPS_T *ops;
        struct _tag_FAN_TABLE_TYPE_T *pNext;
} FAN_TABLE_TYPE_T;

typedef struct _tag_SCEMD_FAN_STATUS_LIST {
        SCEMD_FAN_STATUS status;
        struct _tag_SCEMD_FAN_STATUS_LIST *pNext;
} SCEMD_FAN_STATUS_LIST;

 /* This handle is pass from scemd(call SYNOFanSpeedAdjuster) to fan control(fan_config ops)
 *  and scemd also retrieve some fan control info. from this handle.
 */
typedef struct _tag_FAN_CONFIG_HANDLE {
        BOOL blHibernation; /* [IN] Is the device in Hibernation */
        BOOL blForceChange; /* [IN] Is the device need to force speed change */

        /* [IN/OUT] the device current fan status, fan control may modify it */
        SCEMD_FAN_STATUS *pCurrFanStatus;

        /* every fan table have a status in pCurrFanList*/
        SCEMD_FAN_STATUS_LIST *pCurrFanList;

        /* Now we only need Ebox info, maybe in the furture we need another handle for
         *      * different devices
         *           */
        FAN_CONFIG_TYPE_NAME_T type;
        union{
                EBOX_INFO *pEBoxInfo; /* [IN] the info of EBOX */
#ifdef MY_DEF_HERE
                ENCLOSURE_INFO *pEnclosureInfo;
#endif
        }deviceInfo;

        /*
         * The status of shared resource
         */
        SHARED_RESOURCE_STATUS sharedResourceStatus;
} FAN_CONFIG_HANDLE;

struct _tag_FAN_TABLE_OPS_T {
        FAN_TABLE_TYPE_NAME_T name;
        BOOL (*IsDebugON)(int *piTemperature,
                        const FAN_CONFIG_HANDLE *pHandle);
        GET_TEMP_RET_T (*TemperatureGet)(int *piTemperature,
                        const FAN_CONFIG_HANDLE *pHandle);
        int (*LevelGet)(FAN_TABLE_LEVEL_T **ppFanLevel,
                        int temperature,
                        const FAN_TABLE_TYPE_T *pFanTable);
        FAN_TABLE_OPS_T *pNext;
};

typedef struct _tag_FAN_MODULE_T {
        unsigned int FanOrder;
        int          FanModuleOrder;
} FAN_MODULE_T;

typedef struct _tag_FAN_CONFIG_T {
        unsigned int                periodInSec;
        /* global threshold, only keeping the lowest one when there are multiple devices */
        unsigned int                threshold;
        unsigned char               manual_mode;
        unsigned char               buffer_mode;
        /* extends for multi mode */
        char                        *szHWVersion;
        int                         iWarningTmp; /* sys warning temperature for UI to show light */
        FAN_CONFIG_TYPE_T           type;
        FAN_SPEED                   fan_speed_hibernation;
        FAN_TABLE_TYPE_T            *pFanTableList;
        FAN_CONFIG_OPS_T            *ops;
        FAN_MODULE_T                *pFanModule;
} FAN_CONFIG_T;

struct _tag_FAN_CONFIG_OPS_T {
        FAN_CONFIG_TYPE_NAME_T name;
        BOOL (*TemperatureUpdate)(FAN_CONFIG_HANDLE *pHandle,
                        const FAN_TABLE_TYPE_T *pFanTableList,
                        BOOL *pblDebugOn);
        BOOL (*TableLookUp)(const FAN_CONFIG_HANDLE *pHandle,
                        const FAN_TABLE_TYPE_T *pFanTableList,
                        SCEMD_FAN_STATUS *pLookUpFanStatus);
        BOOL (*IsOverBufferLimit)(const FAN_CONFIG_HANDLE *pHandle,
                        const FAN_TABLE_TYPE_T *pFanTableList,
                        SCEMD_FAN_STATUS *pLookUpFanStatus);
        void (*DebugPrint)(const FAN_CONFIG_HANDLE *phandle,
                        const FAN_CONFIG_T *pFanConfig,
                        const SCEMD_FAN_STATUS *pLookUpFanStatus,
                        BOOL blLevelCHG);
        int  (*FanSpeedChange)(FAN_SPEED fanSpeed,
                        const FAN_CONFIG_HANDLE *pHandle);
        FAN_CONFIG_OPS_T *pNext;
};

typedef struct _tag_FAN_ADT_XML_MODEL_T{
        unsigned int     num;
        ADT_FAN_CONFIG_T *rgFanConfig;
} FAN_XML_ADT_MODEL_T;

typedef struct _tag_FAN_BMC_XML_MODEL_T{
        unsigned int     num;
        BMC_FAN_CONFIG_T *rgFanConfig;
} FAN_XML_BMC_MODEL_T;

typedef struct _tag_FAN_XML_MODEL_T{
        unsigned int    num;
        FAN_CONFIG_T    *rgFanConfig;
        /* Although you can see we save current 'rgFanConfig' index in 'current_model_index'.
         * But you can't use this index as what config we use now.
         * because we have multi device's' will use config's' in xml model
         * so this index didn't mean what config the device use now, we only use this index
         * to decide what config we should print now you can see
         * ScemFanConfigGet(...) and ScemFanConfigInfo(..)
        */
        unsigned int    current_model_index;
} FAN_XML_MODEL_T;

typedef enum {
	TEMPERATURE_UNKNOWN = -1,
	TEMPERATURE_MIN     =  0,
	TEMPERATURE_MAX     = 99,
} TEMPERATURE_T;

int SYNOFanParsingAdjustADTModel(xmlNodePtr fan_config_node, ADT_FAN_CONFIG_T *pFanConfig);
GET_TEMP_RET_T ThermalTemperatureGet(int *piTemperature, const FAN_CONFIG_HANDLE *pHandle);
void SYNOFanTableTypeThermalOpsInit(void);
BOOL SYNOFanIsTemperatureDebugON(int *piTemperature, const char *szTemperatureName);
void SYNOFanConfigTypeMatch(char *szRawText, FAN_CONFIG_TYPE_T *pType);
int SYNOFanNumGet(void);
unsigned int SYNOExternalFanTypeInternalEnum(void);
void SYNOFanConfigOpsRegister(FAN_CONFIG_OPS_T *pFanConfigOps);
void SYNOFanConfigOpsListInit(void);
void SYNOFanConfigOpsListFree(void);
FAN_CONFIG_OPS_T *SYNOFanConfigOpsGet(FAN_CONFIG_TYPE_NAME_T name);
BOOL IsIncludeCacheSlotTemperature(void);
int SYNOFanTableGetDiskHighestTemp(int *piTemperature, const PSLIBSZLIST pslDiskList, const FAN_CONFIG_HANDLE *pHandle);
GET_TEMP_RET_T DiskTemperatureGetCommon(int *piTemperature,
                                        const FAN_CONFIG_HANDLE *pHandle,
                                        PSLIBSZLIST psDisklList);
GET_TEMP_RET_T DiskTemperatureGet(int *piTemperature, const FAN_CONFIG_HANDLE *pHandle);
GET_TEMP_RET_T M2TemperatureGet(int *piTemperature,
                                const FAN_CONFIG_HANDLE *pHandle);
void SYNOFanTableTypeDiskTMPOpsInit(void);
void SYNOAdjusterModelFree(FAN_XML_MODEL_T *pFanXmlModel);
int SYNOFanAdjustDualModeSetWithoutNotify(FAN_CONFIG_TYPE_T type);
int SYNOFanAdjustDualModeSet(FAN_CONFIG_TYPE_T type);
char *SYNOFanTableNameGet(FAN_TABLE_TYPE_NAME_T tableTypeName);
int SYNOFanAdjusterGet(FAN_XML_MODEL_T *pFanXmlModel, BOOL blInit);
FAN_SUPPORT_TYPE SYNOExternalFanTypeCheck(void);
BOOL SYNOFanTemperatureUpdate(FAN_CONFIG_HANDLE *pHandle, const FAN_TABLE_TYPE_T *pFanTableList, BOOL *pblDebugOn);
BOOL SYNOFanTableLookUp(const FAN_CONFIG_HANDLE *pHandle, const FAN_TABLE_TYPE_T *pFanTableList, SCEMD_FAN_STATUS *pLookUpFanStatus);
void SYNOFanDebugPrint(const FAN_CONFIG_HANDLE *pHandle, const FAN_CONFIG_T *pFanConfig, const SCEMD_FAN_STATUS *pLookUpFanStatus, BOOL blLevelCHG);
const FAN_TABLE_TYPE_T *SYNOFanTableGet(FAN_TABLE_TYPE_NAME_T name, const FAN_TABLE_TYPE_T *pList);
UI_FAN_SETTING SYNOFanConfigSpeedGet(void);
int SYNOFanParingTemperature(xmlNodePtr cur_node, FAN_CONFIG_T *pFanConfig);
int SYNOFanParingFanModule(xmlNodePtr fan_config_node, FAN_CONFIG_T *pFanConfig, const FAN_CONFIG_TYPE_NAME_T type);
int SYNOFanConfigTimeSet(const char *szFantime);
int SYNOCheckDiskListAccessible(const PSLIBSZLIST pslDiskList);
void SYNOFanTableTypeEUnitTMPOpsInit(void);
FAN_CONFIG_TYPE_NAME_T SYNOFanConfigNameGet(FAN_CONFIG_TYPE_T fanConfigType);
int SYNOFanADTAdjusterGet(FAN_XML_ADT_MODEL_T *pFanXmlModel, BOOL blInit);
void SYNOFanConfigInternalOpsInit(void);
void SYNOFanActionMatch(char *szRawText, TEMPERATURE_ACTION_T *action);
FAN_CONFIG_TYPE_T SYNOFanAdjustDualModeGet(const char *szFanConfigTypeKey);
int SYNOFanTableLevelGet(FAN_TABLE_LEVEL_T **ppFanLevel, int iTemperature, const FAN_TABLE_TYPE_T *pFanTable);
void SYNOFanConfigCPUFanOpsInit(void);
void SYNOAdjusterADTModelFree(FAN_XML_ADT_MODEL_T *pFanXmlModel);
void SYNOFanSpeedMatch(char *szRawText, FAN_SPEED *speed);
GET_TEMP_RET_T CPUTemperatureGet(int *piTemperature, const FAN_CONFIG_HANDLE *pHandle);
void SYNOFanTableTypeCPUOpsInit(void);
void SYNOFanTableTypeM2TMPOpsInit(void);
BOOL SYNOIsOverBufferLimit(const FAN_CONFIG_HANDLE *pHandle, const FAN_TABLE_TYPE_T *pFanTableList, SCEMD_FAN_STATUS *pLookUpFanStatus);
void SYNOFanConfigEboxOpsInit(void);
int SYNOFanConfigTimeGet(void);
int SYNOFanParsingAdjustModel(xmlNodePtr fan_config_node, FAN_CONFIG_T *pFanConfig);
int SYNOFanConfigSpeedSet(UI_FAN_SETTING FanSpeed);
int SYNOFanParsingADTConfig(char *szFile, FAN_XML_ADT_MODEL_T *pFanXmlModel);
int SYNOFanAdjusterConfigFullSpeed(FAN_XML_MODEL_T *pFanXmlModel);
int SYNOFanAdjusterConfigFullSpeedADT(FAN_XML_ADT_MODEL_T *pFanXmlModel);
int SYNOFanAdjusterConfigFullSpeedBMC(FAN_XML_BMC_MODEL_T *pFanXmlModel);
void SYNOFanAdjusterConfigInit(FAN_CONFIG_T *pFanConfig, BOOL blAllocTemprature);
void SYNOFanTableTypeOpsRegister(FAN_TABLE_OPS_T *pFanTableTypeOps);
void SYNOFanTableTypeOpsListInit(void);
void SYNOFanTableTypeOpsListFree(void);
FAN_TABLE_OPS_T *SYNOFanTableTypeOpsGet(FAN_TABLE_TYPE_NAME_T name);
int SYNOADTGetFanControlPath(char *pADTControlPath, const int iLen);
int SYNOFanParsingConfig(char *szFile, FAN_XML_MODEL_T *pFanXmlModel);
GET_TEMP_RET_T SYNOHWCPUSurfaceTempGet(int *piTemperature, const FAN_CONFIG_HANDLE *pHandle);
int SYNOHWSysTempDegree(int *piTemperature);
int SYNOHWSysTempWarning(BOOL *pblSysTempWarning);
//for BMC
void SYNOAdjusterBMCModelFree(FAN_XML_BMC_MODEL_T *pFanXmlModel);
int SYNOFanParsingBMCConfig(char *szFile, FAN_XML_BMC_MODEL_T *pFanXmlModel);
int SYNOFanParsingAdjustBMCModel(xmlNodePtr fan_config_node, BMC_FAN_CONFIG_T *pFanConfig);
int SYNOFanBMCAdjusterGet(FAN_XML_BMC_MODEL_T *pFanXmlModel, BOOL blInit);

__END_DECLS;
#endif /* __SYNO_HWCTL_FAN_H_ */
