/**
 * @addtogroup BSD
 *
 * @{
 */

/**
 * Checks if @p *ppData need to malloc or realloc. If @p *ppData
 * is NULL, malloc the @p cbNeed size to @p *ppData. If @p
 * *ppdata is not NULL, check if need to realloc by comparing
 * the two size of @p cbNeed and @p *pcbAlloc.
 *
 * Example:
 *
 * @code{.c}
 * 	PSYNOUSER *ppUser as parameter;
 *
 * 	size_t    cbAlloc = 0;
 * 	size_t    cbNeed;
 *
 *      cbNeed = the calculated size;
 * 	if (NULL != *ppUser) {
 * 		cbAlloc = (*ppUser)->nAlloc;
 * 	}
 * 	if (0 != SLIBCCheckAndRealloc((void **) ppUser, &cbAlloc, cbNeed)) {
 * 		SYSLOG(LOG_ERR, "SLIBCCheckAndRealloc failed. synoerr=%x",
 * 		       SLIBCErrGet());
 * 		goto ERR;
 * 	}
 * @endcode
 *
 * @param[in,out]    ppData      The void point
 * @param[in,out]    pcbAlloc    The malloc size before
 * @param[in]        cbNeed      The real size for *ppData
 *
 * @retval  0 On success
 * @retval -1 On error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCCheckAndRealloc(void **ppData, size_t *pcbAlloc, size_t cbNeed);

/**
 * Changes the size of the memory block pointed to by @p ptr
 * to @p size bytes.  The contents will be unchanged to the
 * minimum of the old and new sizes; newly allocated memory will
 * be uninitialized.  If @p ptr is NULL, the call is equivalent
 * to @c malloc(size); if @p size is equal to zero,
 * the call will do nothing.  Upon success, the memory
 * referenced by @p ptr is freed and a pointer to the newly
 * allocated memory is returned.  Note that this function may
 * move the memory allocation, resulting in a different return
 * value than @p ptr.  It will free the passed pointer when the
 * requested memory cannot be allocated.  This is a FreeBSD
 * specific API designed to ease the problems with traditional
 * coding styles for realloc causing memory leaks in libraries.
 *
 * @param[in,out]   ptr    The pointer that must have been returned by an earlier call to malloc(), calloc(), realloc() or reallocf(). May be NULL.
 *                         If @p ptr is NULL, the call is equivalent to @c malloc(@p size).
 * @param[in]       size   The bytes that want to allocate. If @p size is equal to zero, the  call will return NULL and do nothing.
 *
 * @return A pointer to the newly allocated memory, which is
 * suitably aligned for any kind of variable and may be
 * different from @p ptr, or NULL if the request fails.  If @p
 * size was equal to 0, either NULL or a pointer suitable to be
 * passed to free() is returned.  If reallocf() fails the
 * original block freed.
 *
 * @grantable No
 *
 * @apparmor None.
 */
void *reallocf(void *ptr, const size_t size);

/**
 * @}
 */
