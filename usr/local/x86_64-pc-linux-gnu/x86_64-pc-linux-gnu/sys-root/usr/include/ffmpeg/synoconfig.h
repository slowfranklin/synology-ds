#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/* Fixed core dump when truncate recording in QORIQ platform
 * See Surveillance bug 1151/1155
 */
#define SYNO_FIX_QORIQ_CORE_DUMP

/* Add ffmpeg option for smooth streaming.
 * -fragment_url:
 *  This option can overwrite fragment url in Manifest for smooth streaming.
 * -fragment_length:
 *  Let file name of output fragment mp4 with this duration
 *  This setting dependes on x264 option to make it work
 * -seek_time:
 *  Let file name fo output fragment mp4 start with this seek time
 * See Video Station #659
 */
#define SYNO_SMOOTH_STREAMING

/* Fixed h264_parser error in special MP4 remux
 * some MP4 file could parser error with remain PPS information
 * See Video Station #944
 */
#define SYNO_FIX_MP4_REMUX_H264PARSER

/* filter out some tag that not needed
 * those tags producted at *.ass convert *.srt
 * See Video Station #1031
 */
#define SYNO_FILTER_SRT_TAGS

/* skip parse_picture in flacdec.c
 * to avoid gapless playback fails when flac has big embedded cover
 * See Audio Station #1013
 */
#define SYNO_SKIP_FLAC_PARSE_PICTURE

/* add SynoCodecPantent mechanism
 * h264, mpe4part2, aac , vc1 enc/dec should actived at the first time.
 * See Video Station #1291
 */
#if defined(SYNO_VIDEOSTATION) || defined(SYNO_AUDIOSTATION) || defined(SYNO_MEDIASERVER) || defined(MY_DEF_HERE)
#define SYNO_CODEC_PATENT_G1
#endif

/* let ffmpeg skip audio stream with disabled codec.
 * e.g. DTS dec/enc ,AC3 enc
 */
#if !defined(STANDALONE) && !defined(SYNO_VIDEOSTATION) && !defined(SYNO_MEDIASERVER)
#define SYNO_SKIP_DISABLED_AUDIO_STREAM
#endif

/* Optional for writing RIFF info tag to wav
 * See Media Server #386
 */
#define SYNO_WRITE_RIFF_INFO_TAG_TO_WAV

/* Fixed aac copy failed on mpegts format.
 * See Video Station #1730
 */
#define SYNO_MPEGTS_FORAMT_AAC_COPY_FAILED

/* Add ffmpeg option for HLS.
 * -hls_seek_time:
 *  Let output fragment ts start with this seek time
 * See Video Station #1758
 */
#if defined(SYNO_VIDEOSTATION)
#define SYNO_VIDEOSTATION_HLS_SEEK_TIME
#endif

/* Add ffmpeg option for h264 remux.
 * -vbsf h264_mp4toannexb=repeatheader:
 *  Make output h264 stream contains SPS/PPS before every IDR Slice
 * See Video Station #3545
 */
#if defined(SYNO_VIDEOSTATION)
#define SYNO_VIDEOSTATION_REMUX_REPEAT_HEADER
#endif

/* Use neon acceleration in libswscale, which boosts transcoding
 * performance on Alpine platform.
 * The patch is provided by AnnapurnaLabs.
 * See Video Station #1858
 */
#if defined(SYNO_PLAT_NEON_LIBSWSCALE)
#define SYNO_ALPINE_NEON_LIBSWSCALE
#endif

/* Add ffmpeg option for WEBM.
 * -webm_seek_time:
 *  Let output stream with the seek time
 * See Video Station #2170
 */
#if defined(SYNO_VIDEOSTATION)
#define SYNO_VIDEOSTATION_WEBM_SEEK_TIME
#endif

/* Add hardward codec (smd) only on evansport platform
 * See Video Station #1065, DSM #50422
 */
#if defined(MY_DEF_HERE)
#define SYNO_EVANSPORT_SMD
#endif

/* on Evansport, default always using software decoder.
 * add new flag "-prefer_smd" can auto using hardware decoder.
 * See Video Station #1234, DSM #50422
 */
#if defined(SYNO_EVANSPORT_SMD)
#define SYNO_EVANSPORT_AUTO_HW_DECODER
#endif

/* smooth streaming enable hardware transcoding on Evansport.
 * fixed video not sync with subtitile.
 * See Video Station #1244
 */
#if defined(SYNO_EVANSPORT_SMD)
#define SYNO_EVANSPORT_SMOOTH_STREAMING_TIMESTAMP_INACCURATE
#endif

/* Fixed DTV recoded file or DTV streaming A/V issue on Evansport.
 * add flag "-dtv_smd" is used other way to calculate timestamp.
 * in hardware pipeline mode.
 * See Video Station #1652, #1716
 */
#if defined(SYNO_EVANSPORT_SMD)
#define SYNO_EVANSPORT_DTV_SMD_AVSYNC
#endif

/* Fixed mp4 can't hardwared trasncode that encoded by Handbrake.
 * auto enable -dtv_smd flag when detecting Handbrake encoded file.
 * See Video Station #1513
 */
#if defined(SYNO_EVANSPORT_SMD) && defined(SYNO_EVANSPORT_DTV_SMD_AVSYNC)
#define SYNO_EVANSPORT_HANDBRAKE_MP4
#endif

/* Fixed evansport coredump transcode to flv on pipeline mode
 * See Video Station #2132
 */
#if defined(SYNO_EVANSPORT_SMD)
#define SYNO_EVANSPORT_FLV_EXTRADATA
#endif

/* Add ffserver config option to support multiple audio track.
 * See Video Station #2245
 */
#if defined(SYNO_VIDEOSTATION)
#define SYNO_FFSERVER_MULTIPLE_AUDIO_TRACK
#endif

/* Add skip unknown track config to support dtv streaming with unknown codec track.
 * add flag "-dtv_skip_unknown" to skip unknown tracks.
 * See Video Station #2470
 */
#if defined(SYNO_VIDEOSTATION)
#define SYNO_DTV_SKIP_UNKNOWN_TRACK
#endif

/* Add skip visual impaired track config to support dtv streaming with visual impaired track.
 * add flag "-dtv_skip_visual_impaired" to skip visual impaired tracks.
 * See Video Station #2525
 */
#if defined(SYNO_VIDEOSTATION)
#define SYNO_DTV_SKIP_VISUAL_IMPAIRED_TRACK
#endif

/* Skip subtitle streams in teletext codec to avoid the abort casued by non monotonically increasing dts.
 * add flag "-dtv_skip_teletext" to skip subtitle streams in teletext codec.
 * See Video Station #3925
 */
#if defined(SYNO_VIDEOSTATION)
#define SYNO_DTV_SKIP_TELETEXT
#endif

/* Add patch to fix mpegts dvbsub encoding
 * https://trac.ffmpeg.org/ticket/2024
 * https://github.com/FFmpeg/FFmpeg/commit/c917cde9cc52ad1ca89926a617f847bc9861d5a0add
 * See Video Station #2500
 */
#if defined(SYNO_VIDEOSTATION)
#define SYNO_DTV_MPEGTS_DVBSUB_ENCODING
#endif

/* Fixed CVE-2017-9993
 * See DSM #102750
 */
#define SYNO_FIX_CVE_2017_9993
