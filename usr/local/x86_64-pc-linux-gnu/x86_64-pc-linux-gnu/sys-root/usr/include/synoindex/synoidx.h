// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_H
#define _SYNO_IDX_H

#include <synodb/synodb.h>
#include <hwctl/disk.h>
#include <synofileop/index.h>

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------
// Daemon
//--------------------------------------------------

#define SZF_INDEX_QUEUE     					"/var/spool/syno_indexing_queue"
#define SZV_INDEX_QUEUE_FOLDER					"/var/spool"
#define SZV_INDEX_QUEUE_FILENAME				"syno_indexing_queue"

// pid
#define SZF_CONTROL_DAEMON_PID					"/var/run/synoindexd.pid"
#define SZF_SCAN_DAEMON_PID						"/var/run/synoindexscand.pid"
#define SZF_WORKER_DAEMON_PID					"/var/run/synoindexworkerd.pid"
#define SZF_PLUGIN_DAEMON_PID					"/var/run/synoindexplugind.pid"
#define SZF_MEDIA_DAEMON_PID					"/var/run/synomediaparserd.pid"

// daemon
#define SZF_CONTROL_DAEMON_BIN					"/usr/syno/sbin/synoindexd"
#define SZF_SCAN_DAEMON_BIN						"/usr/syno/sbin/synoindexscand"
#define SZF_WORKER_DAEMON_BIN					"/usr/syno/sbin/synoindexworkerd"
#define SZF_PLUGIN_DAEMON_BIN					"/usr/syno/sbin/synoindexplugind"
#define SZF_MEDIA_DAEMON_BIN					"/usr/syno/sbin/synomediaparserd"

// socket
#define SZF_CONTROL_DAEMON_SOCK					"/tmp/synoindexd_sock"
#define SZF_SCAN_DAEMON_SOCK					"/tmp/synoindexscand_sock"
#define SZF_WORKER_DAEMON_SOCK					"/tmp/synoindexworkerd_sock"
#define SZF_PLUGIN_DAEMON_SOCK					"/tmp/synoindexplugind_sock"
#define SZF_MEDIA_DAEMON_SOCK					"/tmp/synomediaparserd_sock"

// check
#define SZF_DAAPD_CHECK_IN						"/tmp/synoindexdaapd_checkin"
#define SZF_MEDIA_CHECK_IN						"/tmp/synomediaparserd_checkin"

// message queue
#define SZK_REQUEST_QUEUE						'x'
#define SZK_RESPONSE_QUEUE						'y'

//
#define SZV_SCAN_LATENCY_TIME					10

//--------------------------------------------------
// Tool
//--------------------------------------------------

#define SZF_SYNOINDEX_BIN						"/usr/syno/bin/synoindex"
#define SZF_SYNOINDEX_MGR_BIN					"/usr/syno/bin/synoindex_mgr"

//--------------------------------------------------
// Index
//--------------------------------------------------

#define SZK_MEDIA_INDEX_NAME					"MediaIndex"

#define SZF_INDEX_QUEUE      					"/var/spool/syno_indexing_queue"
#define SZF_INDEX_QUEUE_TMP      				"/var/spool/syno_indexing_queue.tmp"
#define SZF_INDEX_DAEMON_PID    				"/var/run/synoindexd.pid"

#define SZF_MT_DAAPD_PID    					"/var/run/mt-daapd.pid"			// iTunes Server
#define SZF_DMS_PID         					"/var/run/dms.pid"				// Media Server

#define VOL_MUSIC_LINK							"/var/services/music"
#define VOL_VIDEO_LINK							"/var/services/video"
#define VOL_PHOTO_LINK							"/var/services/photo"

#define SZD_PACKAGE_PLUGINS						"/usr/syno/etc/synoindex/packages"
#define SZF_PACKAGE_INFO						"INFO"

//--------------------------------------------------
// Photo thumb
//--------------------------------------------------
#define SZF_PROG_SYNOTHUMB						"/usr/syno/bin/synothumb"
#define SZF_PROG_SYNOMKTHUMBD					"/usr/syno/bin/synomkthumbd"
#define SZF_PHOTO_THUMB_DAEMON_PID				"/var/run/synomkthumbd.pid"
#define SZF_THUMB_CREATE_QUEUE					"/var/spool/thumb_create.queue"
#define SZF_THUMB_CREATE_QUEUE_TMP				"/var/spool/thumb_create.queue.tmp"
#define SZF_THUMBNAIL_CONF 						"/usr/syno/etc.defaults/thumb.conf"
#define SZF_THUMBNAIL_CONF_HIGH 				"/usr/syno/etc.defaults/thumb_high.conf"

//--------------------------------------------------
// Video FLV
//--------------------------------------------------
#define SZF_PROG_SYNOFLVCONV					"/usr/syno/bin/synoflvconv"
#define SZF_PROG_SYNOMKFLVD						"/usr/syno/sbin/synomkflvd"
#define SZF_PHOTO_FLV_DAEMON_PID				"/var/run/synomkflvd.pid"
#define SZF_PHOTO_FLV_CONV_PID					"/var/run/synoflvconv.pid"
#define SZF_FLV_CREATE_QUEUE					"/var/spool/flv_create.queue"
#define SZF_FLV_CREATE_QUEUE_TMP				"/var/spool/flv_create.queue.tmp"
#define SZF_PHOTO_FILMICON						"/usr/syno/synoman/phpsrc/photo/images/mplayer_40x40.png"
#define SZF_DEF_SYNOINFO						"/etc.defaults/synoinfo.conf"
#define SZF_SYNOINFO							"/etc/synoinfo.conf"

//--------------------------------------------------
// File names in EA dir (Deprecated)
//--------------------------------------------------

#define SYNO_PHOTO_THUMB_B						SYNO_PHOTO_PREFIX"THUMB_B.jpg"
#define SYNO_PHOTO_THUMB_S						SYNO_PHOTO_PREFIX"THUMB_S.jpg"
#define SYNO_PHOTO_THUMB_M						SYNO_PHOTO_PREFIX"THUMB_M.jpg"
#define SYNO_PHOTO_THUMB_L						SYNO_PHOTO_PREFIX"THUMB_L.jpg"
#define SYNO_PHOTO_THUMB_XL						SYNO_PHOTO_PREFIX"THUMB_XL.jpg"
#define SYNO_PHOTO_THUMB_SM						SYNO_PHOTO_PREFIX"THUMB_SM.jpg"
#define SYNO_PHOTO_THUMB_B_FAIL					SYNO_PHOTO_PREFIX"THUMB_B.fail"
#define SYNO_PHOTO_THUMB_S_FAIL					SYNO_PHOTO_PREFIX"THUMB_S.fail"
#define SYNO_PHOTO_THUMB_M_FAIL					SYNO_PHOTO_PREFIX"THUMB_M.fail"
#define SYNO_PHOTO_THUMB_L_FAIL					SYNO_PHOTO_PREFIX"THUMB_L.fail"
#define SYNO_PHOTO_THUMB_XL_FAIL				SYNO_PHOTO_PREFIX"THUMB_XL.fail"
#define SYNO_PHOTO_THUMB_SM_FAIL				SYNO_PHOTO_PREFIX"THUMB_SM.fail"

#define SYNO_PHOTO_MP4_H264 					SYNO_PHOTO_PREFIX"FILM_H264.mp4"
#define SYNO_PHOTO_MP4_MPEG4					SYNO_PHOTO_PREFIX"FILM_MPEG4.mp4"
#define SYNO_PHOTO_FLV							SYNO_PHOTO_PREFIX"FILM.flv"
#define SYNO_PHOTO_FLV_FAIL						SYNO_PHOTO_PREFIX"FILM.fail"
#define SYNO_PHOTO_MP4_MPEG4_CONVERT			SYNO_PHOTO_PREFIX"FILM_CONVERT_MPEG4.mp4"
#define SYNO_PHOTO_MP4_MPEG4_CONVERT_FAIL		SYNO_PHOTO_PREFIX"FILM_CONVERT_MPEG4.fail"

#define SYNO_PHOTO_MP4_HIGH   					SYNO_PHOTO_PREFIX"FILM_H.mp4"
#define SYNO_PHOTO_MP4_MEDIUM   				SYNO_PHOTO_PREFIX"FILM_M.mp4"
#define SYNO_PHOTO_MP4_LOW   					SYNO_PHOTO_PREFIX"FILM_L.mp4"

#define SYNO_PHOTO_MP4_MOBILE					SYNO_PHOTO_PREFIX"FILM_MOBILE.mp4"
#define SYNO_PHOTO_IPHONE_VIDEO					SYNO_PHOTO_PREFIX"FILM_MOBILE_IPHONE"
#define SYNO_PHOTO_ANDROID_UPLOAD				SYNO_PHOTO_PREFIX"FILM_MOBILE_ANDROID"

//--------------------------------------------------
// File names in EA dir
//--------------------------------------------------

#define SYNO_PHOTO_NEW_PREFIX					"SYNOPHOTO_"

#define SYNO_PHOTO_NEW_THUMB_B					SYNO_PHOTO_NEW_PREFIX"THUMB_B.jpg"
#define SYNO_PHOTO_NEW_THUMB_S					SYNO_PHOTO_NEW_PREFIX"THUMB_S.jpg"
#define SYNO_PHOTO_NEW_THUMB_M					SYNO_PHOTO_NEW_PREFIX"THUMB_M.jpg"
#define SYNO_PHOTO_NEW_THUMB_L					SYNO_PHOTO_NEW_PREFIX"THUMB_L.jpg"
#define SYNO_PHOTO_NEW_THUMB_XL					SYNO_PHOTO_NEW_PREFIX"THUMB_XL.jpg"
#define SYNO_PHOTO_NEW_THUMB_SM					SYNO_PHOTO_NEW_PREFIX"THUMB_SM.jpg"
#define SYNO_PHOTO_NEW_THUMB_B_FAIL				SYNO_PHOTO_NEW_PREFIX"THUMB_B.fail"
#define SYNO_PHOTO_NEW_THUMB_S_FAIL				SYNO_PHOTO_NEW_PREFIX"THUMB_S.fail"
#define SYNO_PHOTO_NEW_THUMB_M_FAIL				SYNO_PHOTO_NEW_PREFIX"THUMB_M.fail"
#define SYNO_PHOTO_NEW_THUMB_L_FAIL				SYNO_PHOTO_NEW_PREFIX"THUMB_L.fail"
#define SYNO_PHOTO_NEW_THUMB_XL_FAIL			SYNO_PHOTO_NEW_PREFIX"THUMB_XL.fail"
#define SYNO_PHOTO_NEW_THUMB_SM_FAIL			SYNO_PHOTO_NEW_PREFIX"THUMB_SM.fail"

#define SYNO_PHOTO_NEW_MP4_H264 				SYNO_PHOTO_NEW_PREFIX"FILM_H264.mp4"
#define SYNO_PHOTO_NEW_MP4_MPEG4				SYNO_PHOTO_NEW_PREFIX"FILM_MPEG4.mp4"
#define SYNO_PHOTO_NEW_FLV						SYNO_PHOTO_NEW_PREFIX"FILM.flv"
#define SYNO_PHOTO_NEW_FLV_FAIL					SYNO_PHOTO_NEW_PREFIX"FILM.fail"
#define SYNO_PHOTO_NEW_MP4_MPEG4_CONVERT		SYNO_PHOTO_NEW_PREFIX"FILM_CONVERT_MPEG4.mp4"
#define SYNO_PHOTO_NEW_MP4_MPEG4_CONVERT_FAIL	SYNO_PHOTO_NEW_PREFIX"FILM_CONVERT_MPEG4.fail"
#define SYNO_PHOTO_NEW_MP4_H264_CONVERT			SYNO_PHOTO_NEW_MP4_MEDIUM // use uploader medium file name, to avoid modify for package/client
#define SYNO_PHOTO_NEW_MP4_H264_CONVERT_FAIL	SYNO_PHOTO_NEW_FLV_FAIL   // use flv fail file name, to avoid modify for package/client

#define SYNO_PHOTO_NEW_MP4_HIGH   				SYNO_PHOTO_NEW_PREFIX"FILM_H.mp4"
#define SYNO_PHOTO_NEW_MP4_MEDIUM   			SYNO_PHOTO_NEW_PREFIX"FILM_M.mp4"
#define SYNO_PHOTO_NEW_MP4_LOW   				SYNO_PHOTO_NEW_PREFIX"FILM_L.mp4"

#define SYNO_PHOTO_NEW_MP4_MOBILE				SYNO_PHOTO_NEW_PREFIX"FILM_MOBILE.mp4"
#define SYNO_PHOTO_NEW_IPHONE_VIDEO				SYNO_PHOTO_NEW_PREFIX"FILM_MOBILE_IPHONE"
#define SYNO_PHOTO_NEW_ANDROID_UPLOAD			SYNO_PHOTO_NEW_PREFIX"FILM_MOBILE_ANDROID"

//--------------------------------------------------
// eaDir converted video type, values should be sync with
// convert_type column in mediaserver viceo_converted table
//--------------------------------------------------

#define VIDEO_CONVERT_TYPE_FLV					"PHOTO_STATION_FLV"
#define VIDEO_CONVERT_TYPE_MP4_HIGH				"ASSISTANT_HIGH"
#define VIDEO_CONVERT_TYPE_MP4_MEDIUM			"ASSISTANT_MEDIUM"
#define VIDEO_CONVERT_TYPE_MP4_LOW				"ASSISTANT_LOW"
#define VIDEO_CONVERT_TYPE_ANDROID_UPLOAD		"ANDROID_UPLOAD"

// qt-faststart program path
#define SZF_PROG_QTFASTSTART 					"/usr/bin/qt-faststart"

// dcraw program path
#define SZF_PROG_DCRAW 							"/usr/bin/dcraw"

#define SZ_DELETE_CMD 							"/bin/rm"
#define SZ_EXT_JPEG 							"jpg"
#define SZ_EXT_PNG 								"png"
#define MIME_JPEG 								0x1
#define MIME_PNG 								0x2

#define JPEG_MIN_SIZE 							10
#define PNG_MIN_SIZE 							8

#define SYNO_INDEX_PARSE_FAILED 				0x01

// converted h.264 video related definition
#define CONVERTED_H264_VIDEO_MAX_WIDTH		1280
#define CONVERTED_H264_VIDEO_MAX_HEIGHT		720

// converted mobile compatible video related definition
#define CONVERTED_MOBILE_VIDEO_MAX_WIDTH		640
#define CONVERTED_MOBILE_VIDEO_MAX_HEIGHT		360

// mobile compatible video related definition
#define MOBILE_VIDEO_MAX_WIDTH					480
#define MOBILE_VIDEO_MAX_HEIGHT					320
#define MOBILE_VIDEO_MAX_BIT_RATE				4500000 // video + audio stream bit rate (4.5mbps)

// iPhone playable video related definition
#define IPHONE_VIDEO_MAX_WIDTH					640
#define IPHONE_VIDEO_MAX_HEIGHT					480
#define IPHONE_VIDEO_MAX_BIT_RATE				4500000 // video + audio stream bit rate (4.5mbps)

// flv expect frame size
#define FLV_EXPECT_FRAME_SIZE_WIDTH				640
#define FLV_EXPECT_FRAME_SIZE_HEIGHT			480

// codec string
#define SZ_CODEC_H264 							"h264"
#define SZ_CODEC_MPEG4							"mpeg4"
#define SZ_CODEC_H263							"h263"
#define SZ_CODEC_FLV1							"flv1"
#define SZ_CODEC_MP3							"mp3"
#define SZ_CODEC_AAC							"aac"
#define SZ_CODEC_AMR_NB							"amr_nb"
#define SZ_CODEC_AMR_WB							"amr_wb"
#define SZ_CODEC_OTHER							"other"

//--------------------------------------------------
// Struct
//--------------------------------------------------

// video H264 profile id
typedef enum _H264_PROFILE_ID {
	H264_PROFILE_ID_UNKNOWN = 0,
	H264_PROFILE_ID_BASELINE,
	H264_PROFILE_ID_MAIN,
	H264_PROFILE_ID_HIGH
} H264_PROFILE_ID;

#define	DBGMESG(x...)
//#define	DBGMESG(x...)	syslog(LOG_ERR, x)

typedef	struct __tag_SYNO_MEDIA_INFO {
	unsigned long ID;             	/* music, playlist, photo, video */
	char szPath[PATH_MAX];        	/* music, playlist, photo, video */
	char szName[NAME_MAX];		  	/* photo_image */
	char szDesc[PATH_MAX];		  	/* photo_image */
	int track;                    	/* music */
	int disc;                     	/* music */
	int year;                     	/* music */
	char szTitle[NAME_MAX];       	/* music, playlist, photo, video */
	char szAlbum[NAME_MAX];       	/* music, playlist, photo, video */
	char szArtist[NAME_MAX];      	/* music */
	char szAlbumArtist[NAME_MAX]; 	/* music */
	char szGenre[NAME_MAX];       	/* music */
	char szComposer[NAME_MAX];    	/* music */
	char szComment[NAME_MAX];     	/* music */
	char szMake[100];             	/* photo */
	char szModel[100];            	/* photo */
	char szExposure[20];          	/* photo */
	char szAperture[20];          	/* photo */
	char szTakenTime[32];         	/* photo */
	char szDate[32];              	/* music, playlist, photo, video */
	char szMDate[32];             	/* music, playlist, photo, video */
	float duration;               	/* music, video */
	unsigned int audio_bitrate;   	/* music, video */
	unsigned int frame_bitrate;   	/* video */
	unsigned int video_bitrate;   	/* video */
	int frame_rate_num;           	/* video */
	int frame_rate_den;           	/* video */
	int frequency;                	/* music, video */
	int channel;                  	/* music, video */
	int resolutionX;              	/* video, photo.width */
	int resolutionY;              	/* video, photo.height */
	off_t fileSize;               	/* music, playlist, photo, video */
	int song_count;				  	/* playlist */
	int blTitleUTF16;             	/* music */
	int blArtistUTF16;            	/* music */
	int blAlbumUTF16;             	/* music */
	int blGenreUTF16;             	/* music */
	int blComposerUTF16;          	/* music */
	int blCommentUTF16;           	/* music */
	int coverCount;               	/* music */
	int iso;                      	/* photo */
	char szVideoCodec[NAME_MAX]; 	/* video */
	char szContainerType[NAME_MAX]; /* video */
	int videoProfile;				/* video profile (for H264 codec) */
	int videoLevel;			  		/* video profile level (for H264 codec)*/
	char szAudioCodec[NAME_MAX]; 	/* music, video*/
	char szFsUUID[NAME_MAX];       	/* music, playlist, photo, video */
	//int displayX;              	/* video */
	//int displayY;              	/* video */
	//int rotation                  /* video */
	//int ff_videoProfile;			/* video ffmpeg profile (libavcodec/avcodec.h) */
} SYNO_MEDIA_INFO;

typedef	struct __tag_SYNO_PHOTO_INFO {
	unsigned long ID;
	char szPath[PATH_MAX];
	char szName[NAME_MAX];
	char szTitle[NAME_MAX];
	char szDesc[NAME_MAX];
	char szAlbum[NAME_MAX];
	char szMake[100];
	char szModel[100];
	char szExposure[20];
	char szAperture[20];
	char szTakenTime[32];
	char szCreateTime[32];
	int width;
	int height;
	int iso;
	off_t fileSize;
} SYNO_PHOTO_INFO;

typedef	struct __tag_SYNO_DIR_INFO {
	char szPath[PATH_MAX];
	char szDirName[PATH_MAX];
	char szCTime[32];
	char szMTime[32];
	char szUUID[SIZE_GUID_BUF];
} SYNO_DIR_INFO;

typedef enum _tag_MEDIA_TABLE_TYPE {
	MEDIA_TABLE_MUSIC = 0,
	MEDIA_TABLE_VIDEO,
	MEDIA_TABLE_PHOTO,
	MEDIA_TABLE_PLAYLIST,
	MEDIA_TABLE_DIRECTORY,
	MEDIA_TABLE_VIDEO_CONVERT,
	MEDIA_TABLE_ALL,
} MEDIA_TABLE_TYPE;

enum tag_SYNOINDEX_TYPE {
	SYNOINDEX_MEDIA = 0x01,
	SYNOINDEX_PHOTO = 0x02,
	SYNOINDEX_MUSIC = 0x04,
	SYNOINDEX_VIDEO = 0x08,
};

enum tag_PLAYLIST_INCLUDE_TYPE {
	PLAYLIST_INCLUDE_EXIST    = 0x01,
	PLAYLIST_INCLUDE_NONEXIST = 0x02, // including items that is not in the DB anymore
	PLAYLIST_INCLUDE_HTTP     = 0x04, // including items that comes form internet radio or other media server i.e. path starts with "http://"
	PLAYLIST_INCLUDE_ALL      = (PLAYLIST_INCLUDE_EXIST | PLAYLIST_INCLUDE_NONEXIST | PLAYLIST_INCLUDE_HTTP),
};

typedef enum _PKG_INDEX_MODE_ {
	SKIP_INDEX = 0,
	ONLY_INDEX
} PKG_INDEX_MODE;

typedef struct _PLAYLIST_REC {
	SYNO_MEDIA_INFO MediaInfo;
	struct _PLAYLIST_REC *next;
} PLAYLIST_REC;

typedef	struct __tag_MEDIA_DB_HANDLER {
	DBConnect *pConnection;
	DBResult *pResult;
	DBRow Row;
	unsigned long NumRows;
	MEDIA_TABLE_TYPE TableType;
} MEDIA_DB_HANDLER;

typedef struct _IMAGEPATH_REC {
	char *szPath;
	struct _IMAGEPATH_REC *next;
} IMAGEPATH_REC;

typedef struct _CONVERT_VIDEO_INFO_ {
	const char *szName;
	const char *szType;
} CONVERT_VIDEO_INFO;

typedef struct Resolution {
	int width;
	int height;
} Resolution;

typedef struct _VIDEO_METADATA_ {
	int rotation;
	Resolution PAR;
} VIDEO_METADATA;

typedef struct _VIDEO_METADATA_V2_ {
	int ff_videoProfile;
	int rotation;
	Resolution PAR;
} VIDEO_METADATA_V2;

typedef struct _AUDIO_REPLAYGAIN_METADATA_ {
	float rg_track_gain;
	float rg_track_peak;
	float rg_album_gain;
	float rg_album_peak;
} AUDIO_REPLAYGAIN_METADATA;

typedef enum tag_THUMB_MAP {
	THUMB_MAP_S  = 0x01,
	THUMB_MAP_M  = 0x02,
	THUMB_MAP_B  = 0x04,
	THUMB_MAP_L  = 0x08,
	THUMB_MAP_XL = 0x10,
	THUMB_MAP_SM = 0x20,
} THUMB_MAP;

//--------------------------------------------------

typedef enum _EA_THUMB_TYPE_ {
	EA_THUMB_S = 0,
	EA_THUMB_M,
	EA_THUMB_B,
	EA_THUMB_L,
	EA_THUMB_XL,
	EA_THUMB_SM
} EA_THUMB_TYPE;

typedef enum _EA_VIDEO_TYPE_ {
	EA_VIDEO_FLV = 0,
	EA_VIDEO_MPEG4,
	EA_VIDEO_H264
} EA_VIDEO_TYPE;

typedef enum tag_FILE_TYPE {
	FILE_TYPE_OTHER = 0,
	FILE_TYPE_IMAGE,
	FILE_TYPE_VIDEO,
	FILE_TYPE_VIDEO_OTHER,
} FILE_TYPE;

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
