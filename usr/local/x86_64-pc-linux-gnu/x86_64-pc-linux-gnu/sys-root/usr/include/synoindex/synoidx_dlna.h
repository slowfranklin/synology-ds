// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef	_SYNO_IDX_DLNA_H
#define	_SYNO_IDX_DLNA_H

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------

typedef enum {
	AAC_INVALID   =  0,
	AAC_MAIN      =  1, /* AAC Main */
	AAC_LC        =  2, /* AAC Low complexity */
	AAC_SSR       =  3, /* AAC SSR */
	AAC_LTP       =  4, /* AAC Long term prediction */
	AAC_HE        =  5, /* AAC High efficiency (SBR) */
	AAC_SCALE     =  6, /* Scalable */
	AAC_TWINVQ    =  7, /* TwinVQ */
	AAC_CELP      =  8, /* CELP */
	AAC_HVXC      =  9, /* HVXC */
	AAC_TTSI      = 12, /* TTSI */
	AAC_MS        = 13, /* Main synthetic */
	AAC_WAVE      = 14, /* Wavetable synthesis */
	AAC_MIDI      = 15, /* General MIDI */
	AAC_FX        = 16, /* Algorithmic Synthesis and Audio FX */
	AAC_LC_ER     = 17, /* AAC Low complexity with error recovery */
	AAC_LTP_ER    = 19, /* AAC Long term prediction with error recovery */
	AAC_SCALE_ER  = 20, /* AAC scalable with error recovery */
	AAC_TWINVQ_ER = 21, /* TwinVQ with error recovery */
	AAC_BSAC_ER   = 22, /* BSAC with error recovery */
	AAC_LD_ER     = 23, /* AAC LD with error recovery */
	AAC_CELP_ER   = 24, /* CELP with error recovery */
	AAC_HXVC_ER   = 25, /* HXVC with error recovery */
	AAC_HILN_ER   = 26, /* HILN with error recovery */
	AAC_PARAM_ER  = 27, /* Parametric with error recovery */
	AAC_SSC       = 28, /* AAC SSC */
	AAC_HE_L3     = 31, /* Reserved : seems to be HeAAC L3 */
} aac_object_type_t;

typedef enum {
	CT_UNKNOWN,
	CT_IMAGE, /* for PNG and JPEG */
	CT_ASF, /* usually for WMA/WMV */
	CT_AMR,
	CT_AAC,
	CT_AC3,
	CT_MP3,
	CT_WAV,
	CT_MOV,
	CT_3GP,
	CT_MP4,
	CT_FF_MPEG, /* FFMPEG "mpeg" */
	CT_FF_MPEG_TS, /* FFMPEG "mpegts" */
	CT_MPEG_ELEMENTARY_STREAM,
	CT_MPEG_PROGRAM_STREAM,
	CT_MPEG_TRANSPORT_STREAM,
	CT_MPEG_TRANSPORT_STREAM_DLNA,
	CT_MPEG_TRANSPORT_STREAM_DLNA_NO_TS,
} dlna_container_type_t;

typedef struct _SYNO_AAC_CODEC_OBJECT_INFO_ {
	const char *name;
	aac_object_type_t type;
} SYNO_AAC_CODEC_OBJECT_INFO;

typedef struct _SYNO_DLNA_CONTAINER_TYPE_INFO_ {
	const char *name;
	dlna_container_type_t type;
} SYNO_DLNA_CONTAINER_TYPE_INFO;

//--------------------------------------------------

aac_object_type_t SYNOAacObjectTypeGet(const char *name);
const char *SYNOAacCodecNameGet(aac_object_type_t type);
dlna_container_type_t SYNODlnaContainerTypeGet(const char *name);
const char *SYNODlnaContainerNameGet(dlna_container_type_t type);

//--------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
