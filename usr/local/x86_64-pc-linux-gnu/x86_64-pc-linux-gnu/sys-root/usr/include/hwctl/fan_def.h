// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef __SYNO_HWCTL_FAN_DEF_H_
#define __SYNO_HWCTL_FAN_DEF_H_

__BEGIN_DECLS;

#define SZK_FAN_SPEED   "fanspeed"
#define SZK_FAN_TIME    "fantime"
#define SZK_SUPPORT_FAN "support_fan"
#define SZK_SUPPORT_DUAL_MODE "support_fan_adjust_dual_mode"
#define SZK_SUPPORT_FAN_ADJUST_BY_EXT_NIC "support_fan_adjust_by_ext_nic"

#define SZ_FAN_SPEED_0 "000"
#define SZ_FAN_SPEED_1 "001"
#define SZ_FAN_SPEED_2 "010"
#define SZ_FAN_SPEED_3 "011"
#define SZ_FAN_SPEED_4 "100"
#define SZ_FAN_SPEED_5 "101"
#define SZ_FAN_SPEED_6 "110"
#define SZ_FAN_SPEED_7 "111"

#define FAN_ADJUSTER_AUTO 0
#define FAN_ADJUSTER_MANUAL 1
#define DEFAULT_TEMPERATURE_CHECK_PERIOD 20
#define DEFAULT_TEMPERATURE_THRESHOLD 6
#define ADT_FAN_FILE_DESCRIPTOR_SIZE 256
#define ADT_PWM_MAX 3

#define CUSTOM_KEY                              "custom_fan_control"
#define ADT_FAN_SUPPORT_KEY                     "supportadt7490"
#define BMC_FAN_SUPPORT_KEY                     "support_bmc_fan"

#define CONFIG_FILE                             "/usr/syno/etc/scemd.xml"
#define DEFAULT_CONFIG_FILE                     "/usr/syno/etc.defaults/scemd.xml"

#define DOC_ROOT_NODE                           "scemd"
#define DOC_FAN_CONFIG_NODE                     "fan_config"
#define DOC_ADT_FAN_CONFIG_NODE                 "adt_fan_config"
#define DOC_BMC_FAN_CONFIG_NODE                 "bmc_fan_config"
#define DOC_FAN_CONFIG_ATTR_CONFIG_TYPE         "type"
#define DOC_FAN_CONFIG_ATTR_HIBERNATION_SPEED   "hibernation_speed"
#define DOC_FAN_CONFIG_ATTR_PERIOD              "period"
#define DOC_FAN_CONFIG_ATTR_THRESHOLD           "threshold"
#define DOC_FAN_CONFIG_HW_VERSION               "hw_version"
#define DOC_FAN_MODULE_CONFIG                   "fan_module_config"
#define DOC_FAN_ORDER                           "order"
#define DOC_FAN_MODULE_ORDER                    "module"
#define DOC_THERMAL_TEMPERATURE_NODE            "temperature"
#define DOC_DISK_TEMPERATURE_NODE               "disk_temperature"
#define DOC_CPU_TEMPERATURE_NODE                "cpu_temperature"
#define DOC_M2_TEMPERATURE_NODE                 "m2_temperature"
#define SZF_SYS_TEMPERATURE_DEBUG               "/proc/sys/kernel/syno_temperature_debug"
#define SZF_M2_TEMPERATURE_DEBUG                "/tmp/m2tmp.txt"
#define SZF_DISK_TEMPERATURE_DEBUG              "/tmp/disktmp.txt"
#define SZF_CPU_TEMPERATURE_DEBUG               "/tmp/cputmp.txt"
#define SZF_EBOX_TEMPERATURE_DEBUG              "/tmp/ebox_"
#define SZF_SYS_TEMPERATURE_WARNING             "/tmp/systempwarning"

// for adt7490
#define DOC_ADT_CONFIG                          "adt_config"
#define DOC_ADT_HW_CONFIG                       "adt_hw_config"
#define DOC_ADT_ALERT_CONFIG                    "alert_config"
#define DOC_ADT_SENSOR_CONFIG                   "sensor_config"
#define DOC_ADT_PWM_CONFIG                      "pwm_config"
#define DOC_ADT_FAN_MAPPING_CONFIG              "fan_mapping_config"
#define DOC_ADT_NAME                            "name"
#define DOC_ADT_FULL_SPEED                      "full_speed"
#define DOC_ADT_FULL_SPEED_HYST                 "full_speed_hyst"
#define DOC_ADT_PECI_OFFSET                     "peci_offset"
#define DOC_ADT_SKIP_CHECK_TEMP                 "skip_check_temp"
#define DOC_ADT_ALERT_TEMP                      "alert_temp"
#define DOC_ADT_UNDERCLOCK_TEMP                 "underclock_temp"
#define DOC_ADT_TURBO_BOOST_TEMP                "turbo_temp"
#define DOC_ADT_SHUTDOWN_TEMP                   "shutdown_temp"
#define DOC_ADT_PWM_SENSOR_TYPE                 "sensor_type"
#define DOC_ADT_PWM_HIGH_FREQ                   "high_freq"
#define DOC_ADT_PWM_DUTY_LOW                    "pwm_duty_low"
#define DOC_ADT_PWM_DUTY_HIGH                   "pwm_duty_high"
#define DOC_ADT_PWM_MIN_BELOW_TMIN              "pwm_min_below_tmin"
#define DOC_ADT_SENSOR_MIN                      "min"
#define DOC_ADT_SENSOR_THERM                    "therm"
#define DOC_ADT_SENSOR_RANGE                    "range"
#define DOC_ADT_SENSOR_CRIT_HYST                "crit_hyst"
#define DOC_ADT_FAN_MAPPING_PWM                 "pwm"

//for bmc_hw_config
#define DOC_BMC_CONFIG                          "bmc_config"
#define DOC_BMC_HW_CONFIG                       "bmc_hw_config"
#define DOC_BMC_ALERT_CONFIG                    "alert_config"
#define DOC_BMC_FAN_MAPPING_CONFIG              "fan_mapping_config"
#define DOC_BMC_NAME                            "name"
#define DOC_BMC_ALERTDUTY                       "alert_duty"
#define DOC_BMC_ALERT_TEMP                      "alert_temp"
#define DOC_BMC_SHUTDOWN_TEMP                   "shutdown_temp"
#define DOC_BMC_FULLSPEED_TEMP                  "fullspd_temp"
#define DOC_BMC_FULLSPEED_HYST                  "fullspd_hyst"

#define SZK_SYS_MODE_FULL_WARNING               "mode_full"
#define SZK_SYS_MODE_HIGH_WARNING               "mode_high"
#define SZK_SYS_MODE_LOW_WARNING                "mode_low"
#define SZK_SYS_MODE_LOW_STOP_WARNING           "mode_low_stop"
#define SZK_SYS_MODE_CPU_WARNING                "mode_cpu"

#define DOC_TEMPERATURE_ATTR_FAN_SPEED          "fan_speed"
#define DOC_TEMPERATURE_ATTR_ACTION             "action"
#define FAN_PARSING_XPATH                       "/"DOC_ROOT_NODE"/"DOC_FAN_CONFIG_NODE
#define FAN_PARSING_XPATH_WITH_HW_VERSION       "/"DOC_ROOT_NODE"/"DOC_FAN_CONFIG_NODE"[@"DOC_FAN_CONFIG_HW_VERSION"='%s']"
#define ADT_FAN_PARSING_XPATH                   "/"DOC_ROOT_NODE"/"DOC_ADT_FAN_CONFIG_NODE
#define ADT_FAN_PARSING_XPATH_WITH_HW_VERSION   "/"DOC_ROOT_NODE"/"DOC_ADT_FAN_CONFIG_NODE"[@"DOC_FAN_CONFIG_HW_VERSION"='%s']"
#define BMC_FAN_PARSING_XPATH                   "/"DOC_ROOT_NODE"/"DOC_BMC_FAN_CONFIG_NODE
#define BMC_FAN_PARSING_XPATH_WITH_HW_VERSION   "/"DOC_ROOT_NODE"/"DOC_BMC_FAN_CONFIG_NODE"[@"DOC_FAN_CONFIG_HW_VERSION"='%s']"

#define SZF_FAN_CONFIG_TYPE_KEY_INTERNAL        "fan_config_type_internal"
#define SZF_FAN_CONFIG_TYPE_KEY_INTERNAL_BACKUP "fan_config_type_internal_backup"
#define SZF_FAN_CONFIG_TYPE_KEY_EBOX            "fan_config_type_ebox"
#define SZF_FAN_CONFIG_DUAL_MODE_VALUE_FULL      "full"
#define SZF_FAN_CONFIG_DUAL_MODE_VALUE_HIGH      "high"
#define SZF_FAN_CONFIG_DUAL_MODE_VALUE_LOW       "low"
#define SZF_FAN_CONFIG_DUAL_MODE_VALUE_LOW_STOP  "low_stop"

#define FAN_SPEED_CHANGE_DELAY_TIMER 1

#define ADT_FAN_CONTROL_PATH "/tmp/ADTFanPath/"
#define SZ_ADT7490 "adt7490"

#define ADTVALUEFORMAT 1000

#define ADTPWM  "pwm"
#define ADTPWM1 "pwm1"
#define ADTPWM2 "pwm2"
#define ADTPWM3 "pwm3"
#define ADTOFFSET  "offset"

#define PWMCONTROL    "syno_control"
#define PWMDUTYLOW    "auto_point1_pwm"
#define PWMDUTYHIGH   "auto_point2_pwm"
#define PWMHIGHFREQ   "high_freq"

#define PECI_ERROR    "peci_error"
#define ENHANCED_ACOUSTIC_REG "enhanced_acoustic_register"

#define ADTTEMPMIN       "auto_point1_temp"
#define ADTTEMPTHERM     "crit"
#define ADTTEMPRANGE     "auto_point2_temp"
#define ADTTEMPCRITHYST  "crit_hyst"
#define ADTFULLDUTYCYCLE "full_duty_cycle"

#define ADTINPUT     "input"
#define ADTFAN       "fan"
#define ADT_PECI     "peci"
#define ADT_PECI_MIN "min"
#define ADT_PECI_MAX "max"

#define ADT_PECI0_FD   "peci0"
#define ADT_PECI1_FD   "peci1"
#define ADT_PECI2_FD   "peci2"
#define ADT_PECI3_FD   "peci3"
#define ADT_REMOTE1_FD "temp1"
#define ADT_LOCAL_FD   "temp2"
#define ADT_REMOTE2_FD "temp3"

#define ADT_SENSOR_CONFIG_ALL "allinput"
#define ADT_SENSOR_CONFIG_ALL_PECI "allpeci"
#define ADT_SENSOR_CONFIG_ALL_SENSOR "allsensor"
#define ADT_SENSOR_CONFIG_REMOTE2_AND_LOCAL "remote2local"
#define ADT_SENSOR_CONFIG_PECI0 "peci0"
#define ADT_SENSOR_CONFIG_PECI1 "peci1"
#define ADT_SENSOR_CONFIG_PECI2 "peci2"
#define ADT_SENSOR_CONFIG_PECI3 "peci3"
#define ADT_SENSOR_CONFIG_REMOTE1 "remote1"
#define ADT_SENSOR_CONFIG_REMOTE2 "remote2"
#define ADT_SENSOR_CONFIG_LOCAL "local"

#define ADT_ALERT_CONFIG_DISK "disk"
#define ADT_ALERT_CONFIG_CPU  "cpu"

#define BMC_ALERT_CONFIG_DISK "disk"
#define BMC_ALERT_CONFIG_CPU  "cpu"

#define ADT_FAN_TYPE_CPU      "cpu"
#define ADT_FAN_TYPE_INTERNAL "internal"

#define BMC_FAN_TYPE_CPU      "cpu"
#define BMC_FAN_TYPE_INTERNAL "internal"

__END_DECLS;
#endif /* __SYNO_HWCTL_FAN_DEF_H_ */
