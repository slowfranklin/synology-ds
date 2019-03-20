#ifndef _SYNOUPLOAD_H_
#define _SYNOUPLOAD_H_

#include <synocore/synotype.h>
#include <synocgi/synocgi.h>

#define SZD_SLICE_FILE_ID			SZF_TMP_PATH "/slice_file_id"
#define SZK_SLICE_TMP_FILE			"SYNO_SLICE_TMP_FILE"

typedef enum _tag_cgi_upload_errno_ {
	CGI_UPLOAD_NORMAL = 1,
	CGI_UPLOAD_ERROR_PRIVILEGE = -1, //privilege not enough
	CGI_UPLOAD_ERROR_NOSPC = -2, //no space on volume
	CGI_UPLOAD_ERROR_RO = -3, //volume read-only
	CGI_UPLOAD_ERROR_PATH_NOT_FOUND = -4, // no path to upload
	CGI_UPLOAD_ERROR_FILE_SIZE_ILLEGAL = -5,  //recieved file size > OR < content-length
	CGI_UPLOAD_ERROR_CONTENT_LEN = -6, //content length is abnormal.
	CGI_UPLOAD_ERROR_TIMEOUT = -7, //cgi timeout
	CGI_UPLOAD_ERROR_NOFILE_NAME = -8, //no filename.
	CGI_UPLOAD_ERROR_PROGRAM = -9, //program error
	CGI_UPLOAD_ERROR_FILE_NAME_TOOLONG = -10, //file name too long
	CGI_UPLOAD_ERROR_QUOTA = -11, //exceed Quota,
	CGI_UPLOAD_ERROR_VOL_BUILDING = -12, //volume is building
	CGI_UPLOAD_ERROR_VOL_NOT_FOUND = -13, //volume is not found
	CGI_UPLOAD_ERROR_KILLED = -14, // Connection was killed
	CGI_UPLOAD_ERROR_FILE_TOO_LARGE = -15, // file size is over filesystem limit (ex: FAT32 limit is 4G)
	CGI_UPLOAD_ERROR_TOKEN_EXPIRED = -16, // google-drive/dropbox token is expired
	CGI_UPLOAD_ERROR_INVALID_NAME = -17
}CGI_UPLOAD_ERRNO;

typedef struct _tag_cgi_upload_progress_ {
	unsigned long long  done;			//bytes
	unsigned long long  total;
	CGI_UPLOAD_ERRNO err;
}CGI_UPLOAD_PROGRESS;

typedef BOOL (*PFUNC_CUSTOM_OUTPUT)(void);
typedef void (*PFUNC_UPLOAD_PROG)(unsigned long long ullDone, unsigned long long ullTotal);
typedef long long (*PFUNC_UPLOAD_GETREADSIZE)(unsigned long long ullWrite, unsigned long long ullDone, unsigned long long ullTotal);

typedef enum _tag_multi_part_type {
	MULTI_PART_UNKNOWN = 0,
	MULTI_PART_PARAM,
	MULTI_PART_FILE,
	MULTI_PART_EMPTY
} MULTI_PART_TYPE;

typedef enum _tag_multi_part_boundary {
	MULTI_PART_BOUNDARY_UNKNOWN = 0,
	MULTI_PART_BOUNDARY_NORMAL,
	MULTI_PART_BOUNDARY_END
} MULTI_PART_BOUNDARY;

#ifdef __cplusplus
extern "C" {
#endif

BOOL SynoCgiIsUploadRequest();
BOOL SynoCgiIsSliceUploadRequest();
BOOL SynoCgiIsSliceUploadFinish();
char * SynoCgiSliceUploadTmpFile();
unsigned long long SynoCgiGetUploadFileSize();
void SynoCgiRecvHup();
int SynoCgiLoadUploadNumParams(SYNOCGI *pCgi, unsigned int numPart, PFUNC_UPLOAD_PROG progHandler, CGI_UPLOAD_PROGRESS *prog,
										 char * szBoundary, int sizeBoundary);
int SynoCgiLoadUploadParams(SYNOCGI *pCgi, PFUNC_UPLOAD_PROG progHandler, CGI_UPLOAD_PROGRESS *prog,
										 char * szBoundary, int sizeBoundary, char * szFileKey, int sizeKey, char * szFileName, int sizeName);
int SynoCgiLoadUploadFile(SYNOCGI *pCgi, const char *szTargetPath, PFUNC_UPLOAD_PROG progHandler, CGI_UPLOAD_PROGRESS *prog,
									   char * szBoundary, char * szNameKey, char * szFileName);
int SynoCgiLoadUploadFileBW(SYNOCGI *pCgi, const char *szTargetPath, PFUNC_UPLOAD_PROG progHandler, CGI_UPLOAD_PROGRESS *prog,
									   char * szBoundary, char * szNameKey, char * szFileName, const char *szUserName);
int SynoCgiLoadUploadFileNoTruncate(SYNOCGI *pCgi, const char *szTargetPath, PFUNC_UPLOAD_PROG progHandler, CGI_UPLOAD_PROGRESS *prog, PFUNC_UPLOAD_GETREADSIZE getsizeHandler,
									   char * szBoundary, char * szNameKey, char * szFileName, unsigned long long * cbFileSize, PFUNC_CUSTOM_OUTPUT pfuncCustomOutput);
int SynoCgiLoadUploadFileToDir(SYNOCGI *pCgi, const char *szTargetDir, PFUNC_UPLOAD_PROG progHandler, CGI_UPLOAD_PROGRESS *prog,
									   char * szBoundary, char * szNameKey, char * szFileName);
CGI_UPLOAD_ERRNO SynoCgiLoadUploadData(SYNOCGI *pCgi, const char *szTargetDir, PFUNC_UPLOAD_PROG progHandler);
CGI_UPLOAD_ERRNO SynoCgiLoadUploadAll(PSLIBSZHASH *ppParams, PSLIBSZHASH *ppFiles, const char *szTargetDir, PFUNC_UPLOAD_PROG progHandler);
int SynoCgiUploadGetBoundary(char * szBdry, int sizeBdry);
#ifdef __cplusplus
}
#endif

#endif //_SYNOUPLOAD_H_
