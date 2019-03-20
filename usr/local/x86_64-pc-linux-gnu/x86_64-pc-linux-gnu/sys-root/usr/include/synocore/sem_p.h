/**
 * @addtogroup SEM
 *
 * @{
 */

/**
 * Create a new or open an existing binary semaphore, The
 * semaphore is identified by keyValue.
 *
 * @param[in] keyValue The key of semaphore. Given 0 will generate a private semaphore.
 *
 * @retval  >=0 a semaphore id for further use
 * @retval  -1 fail
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSemOpen(unsigned int keyValue);

/**
 * Close the mutex referred by mutex_id. Release allocated
 * resource
 *
 * @param[in] mutex_id The mutex id to be closed.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void SLIBCSemClose(int sem_id);

/**
 * Lock the semaphore. If the semaphore is locked by others, it
 * will wait till it's unlocked.
 *
 * @param[in] sem_id The semaphore id to be locked.
 *
 * @retval  0 success
 * @retval  -1 fail
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSemLock(int sem_id);

/**
 * Try to lock a semaphore. If the semaphore is locked by
 * others, it will return immediately with error.
 *
 * @param[in] sem_id The semaphore id to be locked.
 *
 * @retval  0 success
 * @retval  -1 fail
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSemTryLock(int sem_id);

/**
 * Unlock the semaphore.
 *
 * @param[in] sem_id The semaphore id to be unlocked.
 *
 * @retval  0 success
 * @retval  -1 fail
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCSemUnlock(int sem_id);

/**
 * @}
 */
