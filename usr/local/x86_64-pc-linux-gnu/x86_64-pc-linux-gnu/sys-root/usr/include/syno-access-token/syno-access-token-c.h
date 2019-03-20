#ifndef _SYNO_ACCESS_TOKEN_C_H_
#define _SYNO_ACCESS_TOKEN_C_H_

__BEGIN_DECLS

/* Delete token by specify bind_sid
 * Return: 0 : success, -1 : error
 */
int  SynoAccessTokenDeleteByBindSid(const char *szSid);

__END_DECLS

#endif /*_SYNO_ACCESS_TOKEN_C_H_ */
