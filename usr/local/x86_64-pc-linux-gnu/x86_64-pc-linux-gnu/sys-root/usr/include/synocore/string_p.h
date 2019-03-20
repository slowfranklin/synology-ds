/**
 * @addtogroup STRING
 *
 * @{
 */

/**
 * Decodes string @p szIn that was encoded by SLIBCStrEncodeColon() and
 * stores output in string @p szOut.  The (;,) is decoded to colon
 * (:), and (;;) is decoded to semicolon (;).  The return value is the
 * string length of @p szOut.  If error, the function returns -1.
 *
 * @param[in] szIn The input string.  Should not be NULL.
 * @param[out] szOut The string buffer.  Should not be NULL.
 * @param[in] iOutSize The length of buffer. Should be greater then string length of @p szIn.
 *
 * @retval -1  Error
 * @retval >=0 Length of output string.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_ENOUGH_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCStrEncodeColon()
 */
int SLIBCStrDecodeColon(const char *szIn, char *szOut, int iOutSize);

/**
 * Separates the string @p szInput into some sub strings
 * according the delimiter in the @p szSep argument and saves
 * them in the @p ppsList argument.  A sequence of two or
 * more contiguous delimiter characters in the parsed
 * string is considered to be two delimiters with a empty
 * string.
 *
 * @param[in]    szInput    The string that contains tokens and delimiters. The string will no be modified. Should not be NULL.
 * @param[in]    szSep      The string that specifies a set of characters that delimit the tokens in the inputed string @p szInput. Should not be NULL.
 * @param[out]   ppslList   The pointer to a SZLIST that will store all tokend strings.
 *                          Each string is a null-terminated string does not include the delimiting character.
 *                          Should not be NULL.
 *
 * @retval >=0 The total number of sub strings if successful.
 * @retval -1  On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception SLIBCSzListPush()
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCStrTok()
 */
int SLIBCStrSep(const char *szInput, const char *szSep, PSLIBSZLIST *ppslList);

/**
 * Parses string @p szPair whose format is (A = B) and stores A
 * and B to the SZLIST @p ppslList.
 *
 * @param[in] szPair The string that with the format: @c "A=B". Should not be NULL.
 * @param[out] ppslList The SZLIST that will stores the tokens split from @p szPair. Should not be NULL.
 *
 * @retval 0 on success
 * @retval -1 Out of memory or not a vaild parameter line.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception SLIBCSzListPush()
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCStrSepPair(const char *szPair, PSLIBSZLIST *ppslList);

/**
 * Replaces strtok() function, gets "the first nonempty token"
 * which divide by delimiters in the @p szSep argument from the
 * string @p szInput.  A sequence of two or more contiguous
 * delimiter characters in the parsed string is considered to
 * be a single delimiter.  Delimiter characters at the start or
 * end of the string are ignored.
 *
 * This function uses strsep() to implement strtok().
 *
 * @param[in,out]   szInput   The pointer to the string that contains tokens and delimiters. The string will be modified. Should not be NULL.
 * @param[in]       szSep     The string that specifies a set of characters that delimit the tokens in string @p szInput.
 *                            The caller may specify different strings in @p szSep in successive calls that parse the same string.
 *                            Should not be NULL.
 *
 * @retval !NULL a pointer to a null-terminated string containing the next token. This string does not include the delimiting character.
 * @retval NULL No more tokens are found.
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCStrTokIndex(char **szInput, const char *szSep);

/**
 * Gets all nonempty tokens which divide by delimiters in the
 * @p szSep argument from the @p szInput string and stores
 * those tokens into @p ppslList.  A sequence of two or
 * more contiguous delimiter characters in the parsed
 * string is considered to be a single delimiter.
 * Delimiter characters at the start or end of the string
 * are ignored.
 *
 * @param[in]    szInput      The string that contains tokens and delimiters. The string will no be modified. Should not be NULL.
 * @param[in]    szSep        The string that specifies a set of characters that delimit the tokens in the inputed string @p szInput. Should not be NULL.
 * @param[out]   ppslList     The pointer to a SZLIST that will store all tokend strings.
 *                            Each string is a null-terminated string does not include the delimiting character.
 *                            Should not be NULL.
 *
 * @retval  >=0 The total number of sub strings if successful.
 * @retval  -1 On error.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 * @exception SLIBCSzListPush()
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCStrSep()
 */
int SLIBCStrTok(const char *szInput, const char *szSep, PSLIBSZLIST *ppslList);

/**
 * Encodes colon and semicolon that exist in @p szIn string and
 * stores output in string @p szOut.  The colon (:) is encoded
 * to (;,), and semicolon (;) is encoded to (;;).  The return
 * value is the string length of @p szOut.  If error, the
 * function returns -1.
 *
 * @param[in] szIn The input string. Should not be NULL.
 * @param[out] szOut The string buffer. Should not be NULL.
 * @param[in] iOutSize The length of buffer. Should greater then string length of @p szIn.
 *
 * @retval -1 Error
 * @retval  >=0 Length of output string.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_ENOUGH_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCStrDecodeColon()
 */
int SLIBCStrEncodeColon(const char *szIn, char *szOut, int iOutSize);

/**
 * Translates the string @p szInput into lower-case.  The @p
 * fIsDoubleByte argument represents the possibility that the
 * string contains double byte sub string, but has been
 * deprecated.  All input string are treated as ASCII strings.
 * If the @p szOutput is NULL, it means that the new string
 * will save in the @p szInput. The return value is a pointer
 * to the output string.
 *
 * @param[in,out] szInput       The input string. Should not be NULL. When @p szOutput is NULL, the @p szInput is modified.
 * @param[in]     fIsDoubleByte Deprecated flag.
 * @param[out]    szOutput      The string buffer. May be NULL. When @p szOutput is NULL, the @p szInput is modified.
 * @param[in]     iOutputSize   The length of string buffer @p szOutput. Should be postive. When @p szOutput is NULL, this value will be ignored.
 *
 * @retval !NULL string pointer to the output string.
 * @retval NULL Error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_ENOUGH_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
char *SLIBCStrCaseLower(char *szInput, int fIsDoubleByte, char *szOutput, int iOutputSize);

/**
 * Removes unnecessary white space characters (blank, tab,
 * newline) and double quote(") in the two ends of @p szInput
 * string and returns the length of processed final string, the
 * length doesn't include the terminating '\0'.
 *
 * Ex. note that in the following strings, the pair of
 * double quote in the two ends isn't included in the strings.
 *
 * <pre>
 *          szInput                 szOutput
 *       -----------------------------------
 *          " ab c "                "ab c"
 *          " \t\r\n abc\t \r\n"    "abc"
 *          "  "ab" "               "ab"
 *          "" ab ""                " ab "
 *          ""a"b ""                "a"b "
 *          ""ab"                   ""ab"
 *          " \n \r \t  "           ""
 *          ""                      ""
 * </pre>
 *
 * The value of szOutput can be either a NULL pointer or
 * th address of a memory space for storing the result.  If
 * szOutput is a NULL pointer, then this function will modify
 * string @p szInput directly.   It means that the content of
 * the @p szInput string will be changed to new value.  If the
 * caller allocates enough space and take its address as the
 * second argument @p szOutput, the function will store the
 * result in @p szOutput string and leave string @p szInput
 * unchanged.  The caller should guarantee @p szOutput has
 * enough space.  We suggest the buffer size of @p szOutput is
 * at least strlen(@p szInput)+1.  If there are all white spaces
 * in a line, returns an empty string.
 *
 * @param[in,out]    szInput    The string that to be filtered out white space quote and double quote. Should not be NULL.
 *                              When @p szOutput is NULL, @p szInput will be modified.
 * @param[out]       szOutput   The string that to stores the output. May be NULL.
 *                              When @p szOutput is NULL, @p szInput will be modified.
 *                              It can equal to szInput as if It is NULL.
 *                              But It should not point to the string range of @p szInput except beginning of @ szInput.
 *
 * @retval -1 On Error
 * @retval >=0 The length of processed result string, it doesn't include the terminating '\0'.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCStrTrimSpace(char *szInput, char *szOutput);

/**
 * Removes unnecessary characters (blank, tab,
 * newline) @p szInput * string and returns the
 * length of processed final string, the
 * length doesn't include the terminating '\0'.
 *
 * Ex. note that in the following strings, the pair of
 * double quote in the two ends isn't included in the strings.
 *
 * <pre>
 *          szInput                 szOutput
 *       -----------------------------------
 *          " ab c "                "ab c"
 *          " \t\r\n abc\t \r\n"    "abc"
 *          "  "ab" "               "ab"
 *          ""ab"                   ""ab"
 *          " \n \r \t  "           ""
 *          ""                      ""
 * </pre>
 *
 * The value of szOutput can be either a NULL pointer or
 * th address of a memory space for storing the result.  If
 * szOutput is a NULL pointer, then this function will modify
 * string @p szInput directly. It means that the content of
 * the @p szInput string will be changed to new value.  If the
 * caller allocates enough space and take its address as the
 * second argument @p szOutput, the function will store the
 * result in @p szOutput string and leave string @p szInput
 * unchanged.  The caller should guarantee @p szOutput has
 * enough space.  We suggest the buffer size of @p szOutput is
 * at least strlen(@p szInput) + 1.  If there are all white spaces
 * in a line, returns an empty string.
 *
 * @param[in,out] szInput   The string that to be filtered out white space quote and double quote. Should not be NULL.
 *                          When @p szOutput is NULL, @p szInput will be modified.
 * @param[out]    szOutput  The string that to stores the output. May be NULL.
 *                          When @p szOutput is NULL, @p szInput will be modified.
 *                          It can equal to szInput as if It is NULL.
 *                          But It should not point to the string range of @p szInput except beginning of @ szInput.
 * @param[in]     szDelim   The string that contains the delimiter characters to be trimmed.
 *                          Default delimiters are " \r\n\t".
 *
 * @retval -1 On Error
 * @retval >=0 The length of processed result string, it doesn't include the terminating '\0'.
 *
 * @exception ERR_BAD_PARAMETERS
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCStrTrim(char *szInput, char *szOutput, const char *szDelim);

/**
 * Replaces @p szOld (substring of @p szInput) with @p szNew and
 * return a pointer to the new string.  If @p szOutput is not
 * NULL, then result will be saved in @p szOutput, else return
 * string will be saved in @p szInput.  The @p iSzOutput is the
 * max size of result string.  If @p szInput has more than one
 * substrings @p szOld, only the first @p szOld will be
 * replaced.
 *
 * @param[in,out]   szInput     The string that to be search @p szOld. Should not be NULL.
 *                              If @p szOutput is NULL, then @p szInput will be modified.
 * @param[in]       szOld       The string that to search. Should not be NULL.
 * @param[in]       szNew       The string that to be changed to. Should not be NULL.
 * @param[out]      szOutput    The string buffer that to be stores the result string. May be NULL.
 *                              If @p szOutput is NULL, then @p szInput will be modified.
 * @param[in]       iSzOutput   The length of string buffer @p szOutput. Should be postive.
 *                              When @p szOutput is NULL, this value will be ignored.
 *
 * @retval 1 success
 * @retval 0 can not found substring
 * @retval -1 error
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_NOT_ENOUGH_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCStrReplace(char *szInput, const char *szOld, const char *szNew, char *szOutput, int iSzOutput);

/**
 * Create a zero-ended string buffer and initialize it with
 * printf() style arguments. Should be used with SLIBCStrPut().
 *
 * @param[in]      szOld     The string that already alloced.  Will use this string if the *pcbAlloc is enough.  May be NULL.  If @p szOld is not NULL, @p pcbAlloc and @p *pcbAlloc should not be NULL.
 * @param[in,out]  pcbAlloc  The size_t pointer to store malloc size. May be NULL.
 * @param[out]     pcbLen    The size_t pointer to store real string length. May be NULL.
 * @param[in]      format    format string, can not be NULL
 *
 * @retval !NULL Created string.
 * @retval NULL Encounter error.
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCStrGetEx()
 * @see SLIBCStrGet()
 * @see SLIBCStrPut()
 */
char *SLIBCStrGetEx(char *szOld, size_t *pcbAlloc, size_t *pcbLen, const char *format, ...);

/**
 * Create a zero-ended string buffer and initialize it with
 * printf() style arguments. Should be used with SLIBCStrPut().
 *
 * @param[in]       szOld      The string that already alloced. Will use this string if the @p *pcbAlloc is enough. May be NULL.
 *                             If @p szOld is not NULL, @p pcbAlloc and @p *pcbAlloc should not be NULL.
 * @param[in,out]   pcbAlloc   The size_t pointer to store malloc size. May be NULL.
 * @param[out]      pcbLen     The size_t pointer to store real string length. May be NULL.
 * @param[in]       format     format string, can not be NULL
 *
 * @retval !NULL Created string.
 * @retval NULL Encounter error.
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCStrGetEx()
 * @see SLIBCStrGet()
 * @see SLIBCStrPut()
 */
char *SLIBCStrGet(const char *format, ...);

/**
 * Create a zero-ended string buffer and initialize it with
 * printf() style arguments. Should be used with SLIBCStrPut().
 *
 * @param[in] format format string, can not be NULL
 *
 * @retval !NULL Created string.
 * @retval NULL Encounter error.
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCStrGetEx()
 * @see SLIBCStrGet()
 * @see SLIBCStrPut()
 */
void SLIBCStrPut(char *sz_str);

/**
 * Finds @p szKey in @p szInput string and removes it from @p
 * szInput.  If @p szOutput is not NULL, then return string will
 * be saved in @p szOutput, else return string will be stored
 * into @p szInput. The @p iSzOutput is the max size of result
 * string.  If @p szInput has more than one @p szKey, only the
 * first @p szKey will be deleted.
 *
 * The underlying operations is implemented by SLIBCStrReplace().
 *
 * @param[in,out]    szInput      The string that to be search @p szKey. If @p szOutput is NULL, then @p szInput will be modified. Should not be NULL.
 * @param[in]        szKey        The string that to be deleted. Should not be NULL.
 * @param[out]       szOutput     The string buffer that to be stores the result string. May be NULL. If @p szOutput is NULL, then @p szInput will be modified.
 * @param[in]        iSzOutput    The length of string buffer @p szOutput. Should be a postive. When @p szOutput is NULL, this value will be ignored.
 *
 * @retval 1 success
 * @retval 0 can not found substring
 * @retval -1 error
 *
 * @exception SLIBCStrReplace()
 *
 * @grantable No
 *
 * @apparmor None.
 *
 * @see SLIBCStrReplace()
 */
int SLIBCStrDelete(char *szInput, const char *szKey, char *szOutput, int iSzOutput);

/**
 * Join @p rgszMem to a string with @p szJoin and copy the joined string into @p *pszOutStr.
 * If @p *pszOutStr is NULL, malloc a space for it.
 * If @p *pszOutStr is not NULL and *pcbSize is not enough to save the joined string, reallocf @p *pszOutStr.
 *
 * @param[in]      rgszMem   An array of string. Should not be NULL.
 * @param[in]      nItems    The items of @p rgszMem. Should be greater than 0.
 * @param[in]      szJoin    The join string. Should not be NULL.
 * @param[in,out]  pszOutStr A buffer to save the joined string.
 * @param[in,out]  pcbSize   The malloc size of @p *pszOutStr. Should not be NULL.
 *
 * @retval -1 On error.
 * @retval 0 On success.
 *
 * @exception ERR_BAD_PARAMETERS
 * @exception ERR_OUT_OF_MEMORY
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCStrJoin(char **rgszMem, int nItems, const char *szJoin, char **pszOutStr, int *pcbSize);

/**
 * syno version strcat
 * if pszDest is not enought space, it will try to expand it
 *
 * @param[in,out]   pszDest  Target String. If Target String is null, it will try to allocate.
 * @param[in,out]   pcbDest  The size of target string buffer.
 * @param[in]       szSrc    New string will be appended to target string.
 *
 * @retval -1 On error.
 * @retval 0 On success.
 *
 * @grantable No
 *
 * @apparmor None.
 */
int SLIBCStrCat(char **pszDest, int *pcbDest, const char *szSrc);

/**
 * @}
 */
