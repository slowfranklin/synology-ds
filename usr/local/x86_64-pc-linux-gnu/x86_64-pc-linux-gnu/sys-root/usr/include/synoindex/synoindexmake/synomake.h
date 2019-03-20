// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_SYNOMK_H
#define _SYNO_SYNOMK_H

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

#define SZF_CONVERT_THUMB_PROG 					"/usr/syno/bin/convert-thumb"
#define SZF_FFMPEG_THUMB_PROG  					"/usr/syno/bin/ffmpeg-thumb"

//--------------------------------------------------

#define SZF_CONV_PROGRESS_PHOTO					"/var/spool/conv_progress_photo"
#define SZF_CONV_PROGRESS_VIDEO					"/var/spool/conv_progress_video"

#define SZK_THUMB_CONV_PAUSED       			"thumb_conv_paused"
#define SZK_THUMB_CONV_RESUME_TIME  			"thumb_conv_resume_time"
#define SZK_THUMB_CONV_QUALITY      			"thumb_conv_quality"
#define SZK_CONV_PROGRESS_TOTAL_THUMB			"total_thumb"
#define SZK_CONV_PROGRESS_COMPLETED_THUMB		"completed_thumb"
#define SZK_CONV_PROGRESS_TOTAL					"total"
#define SZK_CONV_PROGRESS_COMPLETED				"completed"
#define SZK_ENABLE_MOBILE_VIDEO 				"enable_mobile_video"

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif