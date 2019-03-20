//Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __CONTENT_SEARCH_UTILS_FILEINDEX_CWRAP_H__
#define __CONTENT_SEARCH_UTILS_FILEINDEX_CWRAP_H__

#include <synocore/synotype.h>

__BEGIN_DECLS;

/**
 * @addtogroup FileIndex_CWrap
 *
 * @brief The C function for fileindex utils
 *
 * @{
 */

/**
 * Check if share folder is indexed
 *
 * @param szShareName [IN] The share name. Should not be NULL
 *
 * @apparmor abstractions/fileindex
 * @return <ul>
 *         <li> TRUE: Yes</li>
 *         <li> FALSE: No</li>
 *         </ul>
 */
BOOL FILEIDXIsShareIndexed(const char *szShareName);

/**
 * Check if this path contains any indexed path
 *
 * @param szPath [IN] The path. Should not be NULL
 *
 * @apparmor abstractions/fileindex
 * @return <ul>
 *         <li> TRUE: Yes</li>
 *         <li> FALSE: No</li>
 *         </ul>
 */
BOOL FILEIDXIsPathContainIndexed(const char *szPath);

/**
 * Check if this path is indexed
 *
 * @param szPath [IN] The path. Should not be NULL
 *
 * @apparmor abstractions/fileindex
 * @return <ul>
 *         <li> TRUE: Yes</li>
 *         <li> FALSE: No</li>
 *         </ul>
 */
BOOL FILEIDXIsPathIndexed(const char *szPath);

/**
 * Check if this full path is indexed
 *
 * @param szFullPath [IN] The path. Should not be NULL
 *
 * @apparmor abstractions/fileindex
 * @return <ul>
 *         <li> TRUE: Yes</li>
 *         <li> FALSE: No</li>
 *         </ul>
 */
BOOL FILEIDXIsFullPathIndexed(const char *szFullPath);

/**
 * Get path of file index database of a shared folder.
 *
 * @param szName       [IN] The share name. Should not be NULL
 * @param szOutDBPath  [OUT] Output buffer for index DB path
 * @param cbOutLen     [IN] Length of Output buffer for index DB path
 *
 * @author ericlee
 * @apparmor abstractions/fileindex
 * @return <ul>
 *         <li> > 0: length of index DB path</li>
 *         <li> 0 >=: On error </li>
 *         </ul>
 */
int FILEIDXDBPathGet(const char *szName, char *szOutDBPath, const int cbOutLen);

/**
 * Compose path of file index database of a shared folder.
 *
 * @param szSharePath  [IN] The share full path. Should not be NULL
 * @param szOutDBPath  [OUT] Output buffer for index DB path
 * @param cbOutLen     [IN] Length of Output buffer for index DB path
 *
 * @author ericlee
 * @apparmor abstractions/fileindex
 * @return <ul>
 *         <li> > 0: length of index DB path</li>
 *         <li> 0 >=: On error </li>
 *         </ul>
 */
int FILEIDXDBPathCompose(const char *szSharePath, char *szOutDBPath, const int cbOutLen);

/**
 * Get path of file index command queue of a shared folder.
 *
 * @param szName         [IN] The share name. Should not be NULL
 * @param szOutQueuePath [OUT] Output buffer for index command queue path
 * @param cbOutLen       [IN] Length of Output buffer for index DB path
 *
 * @author ericlee
 * @apparmor abstractions/fileindex
 * @return <ul>
 *         <li> > 0: length of index DB path</li>
 *         <li> 0 >=: On error </li>
 *         </ul>
 */
int FILEIDXQueuePathGet(const char *szName, char *szOutQueuePath, const int cbOutLen);

/**
 * Compose path of file index command queue of a shared folder.
 *
 * @param szSharePath    [IN] The share full path. Should not be NULL
 * @param szOutQueuePath [OUT] Output buffer for index command queue path
 * @param cbOutLen       [IN] Length of Output buffer for index DB path
 *
 * @author ericlee
 * @apparmor abstractions/fileindex
 * @return <ul>
 *         <li> > 0: length of index DB path</li>
 *         <li> 0 >=: On error </li>
 *         </ul>
 */
int FILEIDXQueuePathCompose(const char *szSharePath, char *szOutQueuePath, const int cbOutLen);

/**
 * Get elastic index id from share name.
 *
 * @param szShareName    [IN] The share name. Should not be NULL
 * @param szIndexID      [OUT] The elastic index id
 *
 * @author waynepai
 * @apparmor abstractions/fileindex
 * @return <ul>
 *		   <li> true: success </li>
 *		   <li> false: failed </li>
 *         </ul>
 */
BOOL
FILEIDXGetIndexID(const char *szShareName, char *szIndexID, const int cbOutLen);

/**
 * Check if share folder is indexed
 *
 * @param szShareName [IN] The share name. Should not be NULL
 * @param blRealTime  [IN] Realtime result or cached result.
 *
 * @apparmor abstractions/fileindex
 * @return <ul>
 *         <li> TRUE: Yes</li>
 *         <li> FALSE: No</li>
 *         </ul>
 */
BOOL FILEIDXIsShareIndexedEx(const char *szShareName, BOOL blRealTime);

/**
 * Check if this path contains any indexed path
 *
 * @param szPath [IN] The path. Should not be NULL
 * @param blRealTime  [IN] Realtime result or cached result.
 *
 * @apparmor abstractions/fileindex
 * @return <ul>
 *         <li> TRUE: Yes</li>
 *         <li> FALSE: No</li>
 *         </ul>
 */
BOOL FILEIDXIsPathContainIndexedEx(const char *szPath, BOOL blRealTime);

/**
 * Check if this path is indexed
 *
 * @param szPath [IN] The path. Should not be NULL
 * @param blRealTime  [IN] Realtime result or cached result.
 *
 * @apparmor abstractions/fileindex
 * @return <ul>
 *         <li> TRUE: Yes</li>
 *         <li> FALSE: No</li>
 *         </ul>
 */
BOOL FILEIDXIsPathIndexedEx(const char *szPath, BOOL blRealTime);

/**
 * Check if this full path is indexed
 *
 * @param szFullPath [IN] The path. Should not be NULL
 * @param blRealTime  [IN] Realtime result or cached result.
 *
 * @apparmor abstractions/fileindex
 * @return <ul>
 *         <li> TRUE: Yes</li>
 *         <li> FALSE: No</li>
 *         </ul>
 */
BOOL FILEIDXIsFullPathIndexedEx(const char *szFullPath, BOOL blRealTime);

/**
 * @}
 */

__END_DECLS;

#endif
