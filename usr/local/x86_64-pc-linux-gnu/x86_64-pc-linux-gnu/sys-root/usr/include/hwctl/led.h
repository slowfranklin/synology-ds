// Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __SYNO_HWCTL_LED_BRIGHTNESS_H_
#define __SYNO_HWCTL_LED_BRIGHTNESS_H_

#define SZF_I2CGET "/usr/sbin/i2cget"
#define SZF_I2CSET "/usr/sbin/i2cset"

// To avoid interrupting hibernation, move all related files to /tmp
#define SZF_TMP_I2CGET "/tmp/syno_led_brightness/i2cget"
#define SZF_TMP_I2CSET "/tmp/syno_led_brightness/i2cset"
//#define SZF_TMP_LED_BRIGHTNESS_CONF "/tmp/syno_led_brightness/led_brightness.conf"
#define SZF_TMP_LED_BRIGHTNESS_XML "/tmp/syno_led_brightness/led_brightness.xml"
#define SZF_LED_BRIGHTNESS_XML	"/usr/syno/etc.defaults/led_brightness.xml"
#define SZF_LED_BRIGHTNESS_UTIL "/tmp/syno_led_brightness/syno_led_brightness"
#define SZK_LED_BRIGHTNESS_SCHEDULE "led_brightness_schedule"
#define SZK_LED_BRIGHTNESS_ADJUST_LEVEL "led_brightness_adjusted_level"

#define SZ_DEFAULT_SCHEDULE \
	"111111111111111111111111" \
	"111111111111111111111111" \
	"111111111111111111111111" \
	"111111111111111111111111" \
	"111111111111111111111111" \
	"111111111111111111111111" \
	"111111111111111111111111"

int SYNOSetLedBrightness (int brightness);
int SYNOGetLedBrightness (int *brightness);
int SYNOSetLedBrightnessConfiguration (int brightness, char *szSchedule);
int SYNOGetLedBrightnessConfiguration (int *brightness, char *szSchedule);
int SYNOUpdateLedBrightnessByConfiguration (int isForceUpdate);

typedef struct __tag_syno_led_brightness_static_data {
	int min_brightness;
	int max_brightness;
	int default_brightness;
} SYNO_LED_BRIGHTNESS_STATIC_DATA;

int SYNOGetLedBrightnessStaticData(SYNO_LED_BRIGHTNESS_STATIC_DATA *data);

#endif /* __SYNO_HWCTL_LED_BRIGHTNESS_H_ */
