#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
#ifndef _SYNODEF_H
#define _SYNODEF_H

/**
 * [curl-7.x] #1
 * 1. add proxy setting when curl run curl_easy_perform(CURL) in url.c
 * 2. add an CURL option for user to avoid libsynoproxy hook.
 * libcurl option: curl_easy_setopt(curl, CURLOPT_SYNOBYPASSSYNOPROXY, 1L);
 * curl cmd: curl --syno-bypass-synoproxy
 *
 */

#endif /* _SYNODEF_H */
