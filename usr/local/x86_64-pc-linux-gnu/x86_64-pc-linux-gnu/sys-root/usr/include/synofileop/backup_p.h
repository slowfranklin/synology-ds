/**
 * @brief clean source dir's ArchiveBit.
 *
 * @detail implementation see backup_clean_dir_archive_bit.c
 * 
 * @author \$Author: claudiac $
 * @version \$Revision: 1.2 $
 * @ingroup : BACKUP
 * 
 * @param szSrcDirName
 *               : [IN] The full path of source dir. Should not
 *               be NULL.
 *
 * @apparmor abstractions/libsynofileop
 *
 * @grantable N
 *
 * @return 
 *         <ul>
 *         <li>0 : success</li>
 *         <li>-1: fail</li>
 *         </ul>
 *  
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOBackupCleanDirArchiveBit(const char *szSrcDirName);

/**
 * @brief clean source file's ArchiveBit.
 *
 * @detail implementation see backup_clean_file_archive_bit.c
 * 
 * @author \$Author: claudiac $
 * @version \$Revision: 1.2 $
 * @ingroup : BACKUP
 * 
 * @param szSrcFileName
 *               : [IN] The full path of source file. Should not
 *               be NULL.
 * 
 * @apparmor abstractions/libsynofileop
 *
 * @grantable N
 *
 * @return 
 *         <ul>
 *         <li>0 : success</li>
 *         <li>-1: fail</li>
 *         </ul>
 *  
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOBackupCleanFileArchiveBit(const char *szSrcFileName);
