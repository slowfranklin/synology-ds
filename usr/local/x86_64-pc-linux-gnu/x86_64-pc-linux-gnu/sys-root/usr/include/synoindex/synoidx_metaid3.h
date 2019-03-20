// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_IDX_METAID3_H
#define _SYNO_IDX_METAID3_H

#include <synoindex/synoidx.h>

#define BUFFERSIZE   16384
#define MAX_ID3_GENRE 148

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

/* ID3v1 TAG
 * Do not change me. I am used in fread(ID3v1Info, sizeof(ID3v1Info)
 */
typedef struct {
        char szTitle[30];
        char szArtist[30];
        char szAlbum [30];
        char szYear [4];
        char szComment [30];
        unsigned char cGenre;
} ID3V1_INFO;

/**
 * ID3v2 TAG
 */
typedef struct __tag_ID3_INFO {
	char szTitle[1024];
	char szArtist[1024];
	char szAlbum[1024];
	char szYear[8];
	char szGenre[128];
	char szTrackNo[8];
	char szDiscNo[8];
	char szComposer[1024];
	char szComment[1024];
	int blTitleUTF16;
	int blArtistUTF16;
	int blAlbumUTF16;
	int blGenreUTF16;
	int blComposerUTF16;
	int blCommentUTF16;
	int coverCount;
} ID3_INFO;

typedef struct __tag_AUDIO_INFO {
	int mpeg_ver;
	int layer;
	int protect;
	int bitrate;
	float byte_rate;
	int sampling_rate;
	int mode;
	int padding;
	int modext;
	int emphasis_index;
	int copyright;
	int original;
	double duration;
	int frame_length;
	off_t first_frame_offset;
} AUDIO_INFO;

typedef struct __tag_PARSE_HANDLER {
	FILE* pfFile;
	off_t FileSize;
	unsigned char Buffer[BUFFERSIZE];
	off_t BufStart;
	off_t BufEnd;
	int MpegVersion;
} PARSE_HANDLER;

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
