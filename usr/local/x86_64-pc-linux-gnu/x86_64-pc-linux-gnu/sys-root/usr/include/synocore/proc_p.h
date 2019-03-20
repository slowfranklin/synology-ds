/**
 * @addtogroup PROC
 *
 * @{
 */

/**
 * Return the number of max connections in the system.
 * If there are "maxservices" in synoinfo.conf, we would return this value.
 * Otherwises we would return system_mem_size/4 (Only xs+ series would calculated by this fomula now)
 *
 * @retval >=0 The number of max connections
 * @retval <0 Error
 *
 * @note Not thread safe
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCMaxConnectionGet(void);

/**
 * The function would fork a new process to exec the
 * command szPath. It will:
 *
 * 1. Remove the SA_NOCLDWAIT flag of the process.
 * 2. fork a new process and close stdin, stdout, stderr.
 * 3. call execv() to execute the program.
 * 4. Wait for the command complete and return error code.
 *
 * @param[in]   szPath   The program to be executed.
 * @param[in]   ppszArgv The arguments to pass to @p szPath.
 * @param[in]   fWaitPid Pass 1 to wait for the child, and pass 0 to not wait.
 *
 * @retval   0    On success.
 * @retval   -1   On error.
 *
 * @grantable No
 * @user Who can execute @p szPath.
 *
 * @apparmor None.
 */
int SLIBCExecv(const char *szPath, char *const ppszArgv[], int fWaitPid);

/**
 * Use the specified arguments to execute the specified file.
 *
 * Please note that we will do these before exec the command:
 * 1. setsid()
 * 2. chdir to /
 * 3. clearenv() (except PATH)
 * 4. reset nice value to 0
 *
 * @param[in] szPath Must be full path.
 * @param[in] szArg1 1st argument.
 * @param[in] szArg2 2nd argument.
 * @param[in] szArg3 3rd argument.
 * @param[in] szArg4 4th argument.
 *
 * @retval -1 on error
 * @retval >=0 the returned value of executed command
 *
 * @grantable No
 * @user Who can execute @p szPath.
 *
 * @apparmor None.
 *
 * @see SLIBCExecl()
 */
int SLIBCExec(const char *szPath, const char *szArg1, const char *szArg2, const char *szArg3, const char *szArg4);

/**
 * Use the specified arguments to execute the specified file.
 *
 * @param[in]   szPath   Must be full path.
 * @param[in]   flag     Fork control flags.
 *                       Please refer to  SLIBCProcForkEx() for detail.
 *                       Or use default value: SLIBC_PROC_FORK_DEFAULT.
 * @param[in]   szArg    argments, please give a "NULL" for last argumnet
 *
 * @retval -1 on error
 * @retval >=0 the returned value of executed command
 *
 * @grantable No
 * @user Who can execute @p szPath.
 *
 * @apparmor abstractions/libsynocore/proc
 */
int SLIBCExecl(const char *szPath, int flag, const char *szArg, ...);

/**
 * Check whether a process contains @p szPsCmdline exists, or
 * enumerate all pids of processes contain @p szPsCmdline.
 * If DDSM exists, this function only searches the processes
 * running in the same host/container.
 *
 * @param[in] szPsCmdline  The specified command string to search. Should not be NULL.
 * @param[out] rgPid       The pointer to an int array that stores result of pids. NULL indicates just check the existance of process rather than enumerate all.
 * @param[in] sizeMax      The max size of @p rgPid can hold. This parameter is ignored when @p rgPid is NULL.
 *
 * @retval >=0 number of found processes.
 * @retval -1   on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception SLIBCFileEnumDir
 * @exception SLIBCProcCmdlineHasStr
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCPs(const char *szPsCmdline, int *rgPid, int sizeMax);

/**
 * Read pid value from szPidFile.
 *
 * @param[in]  szPidFile    The full path of pidfile
 *
 * @retval   >0   The value in szPidFile
 * @retval   0    The pid file exists, but there is no validate number.
 * @retval   -1   Error occurs
 *
 * @grantable No
 * @user Who can read @p szPidFile.
 *
 * @apparmor None.
 */
int SLIBCReadPidFile(const char *szPidFile);

/**
 * SLIBProcAlive() function checks if a process is alive.
 * pid argument is the process id that you want to check
 * if alive return 1, else return 0.
 *
 * @param[in]   pid    The pid to query.
 *
 * @retval  TRUE  Alive.
 * @retval  FALSE Not alive.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynocore/proc
 */
BOOL SLIBCProcAlive(int pid);

/**
 * Create @p szPidFile and put pid into the file.
 *
 * @param[in] szPidFile The pid file name. Should not be NULL.
 *
 * @retval  0 success
 * @retval  -1 on error.
 *
 * @grantable No
 * @user Who can create @p szPidFile.
 *
 * @apparmor None.
 *
 * @see SLIBCProcAliveByPidFile()
 * @see SLIBCReadPidFile()
 */
int SLIBCProcPidFileCreate(const char *szPidFile);

/**
 * This function encode input string by add back-slash(\) before each character.
 *
 * @param[in]  szIn    Constant input string
 * @param[out] szOut   Output buffer
 * @param[in]  cbSize  Output buffer size
 *
 * @retval 0 success
 * @retval -1 error
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCEncShParam(const char *szIn, char *szOut, int cbSize);

/**
 * Fork and close IO of child
 *
 * @retval 0  Returned in the child.
 * @retval >0 The child pid returned in the parent.
 * @retval -1 Returned in the parent, and no child process is created.
 *
 * @grantable No
 *
 * @apparmor None.
 */
pid_t SLIBCProcFork(void);

/**
 * Execute "szfProg szArg ..." until ulSecTimeout is exceeded.
 * If timed out, SLIBCTimedExecWithEnv() will kill the process forcely,
 * and ERR_TIMER_EXPIRED is set. The argument list should end
 * with NULL.
 *
 * @param[in]   ulSecTimeout   The seconds the szfProg can be executed. Should be positive.
 * @param[in]   szfProg        The full path of executive file. Should not be NULL.
 * @param[in]   szArg          The first argument of @p szfProg. May be NULL.
 *
 * @retval >=0 The return value of program.
 * @retval -1  Failed to execute program.
 *
 * @execption ERR_TIMER_EXPIRED
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 * @user Who can execute @p szfProg.
 *
 * @apparmor abstractions/libsynocore/proc
 *
 * @see SLIBCExec()
 * @see SLIBCExecv()
 */
int SLIBCTimedExecWithEnv(unsigned long ulSecTimeout, const char *szfProg, const char *szArg, ...);

/**
 * Get the SYNOPROC of the @p pid,
 *
 * @param[in]   pid       The process number. Should not be zero or negative.
 * @param[in]   ppProc    A pointer to PSYNOPROC that this SYNOPROC to be stored. Should not be NULL.
 *
 * @retval 0 success
 * @retval -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_OPEN_FAILED
 * @exception ERR_SYS_UNKNOWN
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCProcGetByPid(pid_t pid, PSYNOPROC *ppProc);

/**
 * Free a SYNOPROC which is get form SLIBCGetProc
 *
 * @param[in] pProc the pointer to a SYNOPROC to be free.
 *
 * @return None.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCProcFree(PSYNOPROC pProc);

/**
 * Fork process and avoid zombie without waiting.
 *
 * @retval 0  Returned in the child.
 * @retval 1  Returned in the parent.
 * @retval -1 Returned in the parent, and no child process is created.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCProcForkChildNoWait(void);

/**
 * send a signal by specifying pid file. call kill()
 * function to send signal.
 *
 * @param szFile pid file name
 * @param iSignal signal to send.
 *
 * @retval 0 success
 * @retval -1 error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor abstractions/libsynocore/proc
 *
 * Example:
 *
 * @code{.c}
 * SLIBCProcSignalByPidFile("/var/run/inetd.pid", SIGHUP);
 * @endcode
 */
int SLIBCProcSignalByPidFile(const char *szFile, int iSignal);
/**
 * check process is alive or not. pid is writed in pid file.
 *
 * @param szFile pid file name
 *
 * @retval 0 not alive
 * @retval 1 alive
 *
 * @grantable No
 * @user Who can read @p szFile.
 *
 * @apparmor abstractions/libsynocore/proc
 */
int SLIBCProcAliveByPidFile(const char *szFile);

/**
 * Fork process.
 *
 * @param   flag   See below:
 *      SLIBC_PROC_FORK_REDIRECT_STD_FD:
 *          Redirect stdin, stdout, stderr to /dev/null
 *
 *      SLIBC_PROC_FORK_CLOSE_SLIBC_FILE_LOCK:
 *          Close all file lock, please refer to SLIBCFileCloseLock().
 *
 *      SLIBC_PROC_FORK_CLOSE_NONSTD_FD:
 *          Close all file descriptors except std file descriptors.
 *
 *      SLIBC_PROC_FORK_CLEAN_ENV:
 *          Clean environment except PATH.
 *
 *      SLIBC_PROC_FORK_CHANGE_DIR:
 *          Change dir to "/".
 *
 *      SLIBC_PROC_FORK_SET_SID:
 *          Do setsid() to be a session leader.
 *
 *      SLIBC_PROC_FORK_NOWAIT:
 *          Do not wait for the child process. Use double fork to prevent zombie.
 *          If PROC_FORK_NOWAIT is set and fork sucess,
 *      The return value of parent will always be 1.
 *
 *      SLIBC_PROC_FORK_RENICE:
 *          Reset nice value to 0.
 *
 * @retval 0   Returned in the child.
 * @retval >=1 Returned in the parent, the return value is child pid. If PROC_FORK_NOWAIT set, it is always 1.
 * @retval -1  On error.
 *
 * @grantable No
 *
 * @apparmor None.
 */
pid_t SLIBCProcForkEx(int flag);

/**
 * Set a process oom score, the oom value can be control by /proc/self/oom_adj
 * or /proc/self/oom_score_adj. For old kernel (2.6.32), we use file
 * /proc/self/oom_adj, Acceptable values range for oom_adj is from -17 to +15.
 * -17 can prevent the process be killed by oom-killer.
 * For newer kerenl (> 3.2), we use file /proc/self/oom_score_adj,
 * Vaule -1000 can prevent the process be killed by oom-killer
 *
 * @param[in] iScore The value will be set to file oom_score_adj.
 *                   A positive score increases the likelihood of this process being killed by the OOM-killer;
 *                   A negative score decreases the likelihood.
 *
 * @retval  0 on success.
 * @retval -1 on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OPEN_FAILED
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCProcOomScoreSet(int iScore);

/**
 * A popen like function without called by shell.
 *
 * The standard in will be closed in read mode,
 * the standard out will be closed in write mode,
 * and the standard error will be closed in both mode.
 *
 * @param[in] szPath executable binary path, must be full path.
 * @param[in] type the same as type argument with popen().
 *                       special type as below:
 *                       'r': read, redirect stdout.
 *                       'rB': read 'B'oth, redirect stdout + stderr.
 *                       'rE': read 'E'rror, only redirect stderr.
 *                       'p': set credentials according to @p szPath, see InitCredentialsByExecutable. ignored in flash mode.
 * @param[in] argv an array of pointers to null-terminated strings that
 *                       represent the argument list available to the new program.
 *                       The first argument, by convention, should point to the
 *                       filename associated with the file being executed.
 *
 * @retval !NULL File pointer to the popen file.
 * @retval NULL On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_SYS_UNKNOWN
 * @exception ERR_OUT_OF_MEMORY
 * @exception ERR_FORK_FAIL
 * @exception ERR_OPEN_FAILED
 * @exception InitCredentialsByExecutable()
 *
 * @grantable No
 * @user Who can execute @p szPath.
 *
 * @apparmor abstractions/libsynocore/proc
 *
 * Example usage:
 *
 * @code{.c}
 * #include <stdlib.h>
 * #include <synocore/proc.h>
 *
 * int
 * main(int argc, char **argv)
 * {
 *      int ret = -1;
 *      char *szLine = NULL;
 *      size_t cbLine = 0;
 *      FILE *pfile = NULL;
 *      char *argv[3] = {NULL};
 *
 *      argv[0] = "ls";
 *      argv[1] = "/root";
 *      argv[2] = NULL;
 *
 *      if (NULL == (pfile = SLIBCPopenv("/bin/ls", "r", argv))) {
 *			goto END;
 *      }
 *
 *      while (-1 != getline(&szLine, &cbLine, pfile)) {
 *          printf("%s", szLine);
 *		}
 *		ret = SLIBCPclose(pfile);
 *  END:
 *		free(szLine);
 *      return ret;
 * }
 *
 * @endcode
 */
FILE *SLIBCPopenv(const char *szPath, const char *type, char *const argv[]);

/**
 * A popen like function without called by shell.
 *
 * The standard in will be closed in read mode,
 * the standard out will be closed in write mode,
 * and the standard error will be closed in both mode.
 *
 * @param[in] szPath executable binary path, must be full path.
 * @param[in] type the same as type argument with popen().
 *                       special type as below:
 *                       'r': read, redirect stdout.
 *                       'rB': read 'B'oth, redirect stdout + stderr.
 *                       'rE': read 'E'rror, only redirect stderr.
 *                       'p': set credentials according to @p szPath, see InitCredentialsByExecutable. ignored in flash mode.
 * @param[in] szArg argments, please give a "NULL" for last argumnet.
 *
 * @retval !NULL File pointer to the popen file.
 * @retval NULL on error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception SLIBCPopenv()
 *
 * @grantable No
 * @user Who can execute @p szPath.
 *
 * @apparmor abstractions/libsynocore/proc
 *
 * Example usage:
 *
 * @code{.c}
 * #include <stdlib.h>
 * #include <synocore/proc.h>
 *
 * int
 * main(int argc, char **argv)
 * {
 *      int ret = -1;
 *      char *szLine = NULL;
 *      size_t cbLine = 0;
 *      FILE *pfile = NULL;
 *
 *      if (NULL == (pfile = SLIBCPopen("/bin/ls", "r", "/root", NULL))) {
 *			goto END;
 *      }
 *
 *      while (-1 != getline(&szLine, &cbLine, pfile)) {
 *          printf("%s", szLine);
 *		}
 *		ret = SLIBCPclose(pfile);
 *  END:
 *		free(szLine);
 *      return ret;
 * }
 *
 * @endcode
 */
FILE *SLIBCPopen(const char *szPath, const char *type, const char *szArg, ...);

/**
 * A pclose like function for SLIBCPopen().
 *
 * @param[in] file file descriptor for SLIBCPopen().
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_CLOSE_FAILED
 *
 * @retval -1 on failure.
 * @retval >=0 on success, exit value of calling process.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynocore/proc
 */
int SLIBCPclose(FILE *file);

/**
 * Wrap function of fgets, it will retry if EINTR occurs
 *
 * Parameters and return value are the same with fgets
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCFgets(char *szBuf, int cbBuf, FILE *pFile);

/**
 * Wrap function of read, it will retry if EINTR occurs
 *
 * Parameters and return value are the same with read
 *
 * @grantable No
 *
 * @apparmor None.
 */
ssize_t SLIBCRead(int fd, void *pBuf, size_t cbBuf);

/**
 * Wrap function of write, it will retry if EINTR occurs
 *
 * Parameters and return value are the same with write
 *
 * @grantable No
 *
 * @apparmor None.
 */
ssize_t SLIBCWrite(int fd, const void *pBuf, size_t cbBuf);

/**
 * Use the specified arguments to execute the specified file.
 *
 * @param[in] szPath   The path of the executable.
 * @param[in] szArg1   The 1st argument.
 * @param[in] szArg2   The 2nd argument.
 * @param[in] szArg3   The 3rd argument.
 * @param[in] szArg4   The 4th argument.
 *
 * @retval 0 The pid of the child.
 * @retval -1 Error. (didn't wait for process done)
 *
 * @grantable No
 * @user Who can execute @p szPath.
 *
 * @apparmor None.
 */
int SLIBCBackgroundExec(const char *szPath, const char *szArg1, const char *szArg2, const char *szArg3, const char *szArg4);

/**
 * Answers whether process @p szProc is alive.
 *
 * @param[in]   szProc   The program name to check.
 *
 * @retval TRUE Alive.
 * @retval FALSE Not alive.
 *
 * @grantable No
 *
 * @apparmor abstractions/libsynocore/proc
 */
BOOL SLIBCIsProcAlive(const char *szProc);

/**
 * Kills all processes having substring @p szProc and return number of processes killed.
 *
 * @param[in]   szProc   The program name to kill.
 * @param[in]   blForce  If TRUE, send SIGKILL. Else send SIGTERM first, then SIGKILL if SIGTERM didn't work.
 *
 * @retval >=0 The number of processes killed.
 * @retval -1 Error occurs.
 *
 * @grantable No
 * @user Who can send signals to @p szProc.
 *
 * @apparmor abstractions/libsynocore/proc
 */
int SLIBCKill(const char *szProc, BOOL blForce);

/**
 * Check if linux kernel module is load
 *
 * check /sys/module/@p szModule.
 * If the folder is exist, means the module has been loaded in system.
 *
 * @param[in]   szModule    The string that contains Module name. Should not be null or empty string.
 *
 * @retval 1 module has been loaded.
 * @retval 0 module is not loaded.
 * @retval -1 on error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_STAT_FAILED
 * @exception ERR_NOT_DIRECTORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCModuleIsLoad(const char *szModule);

/**
 * Fork some processes to call your callback to achieve parallel processing
 *
 * @param[in] itemNum total number of items to be processed
 * @param[in] callback callback to be called parallelly
 * @param[in] pParams params pass to callback
 *
 * @retval 0 success
 * @retval -1 error
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCProcParallelProcess(int itemNum, PFuncCallback callback, void *pParams);

/**
 * @}
 */
