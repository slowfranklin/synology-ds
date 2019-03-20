// Copyright (c) 2000-2016 Synology Inc. All rights reserved.

/**
  * @addtogroup CLOUDSERVICE
  *
  * Syno cloud service library. Provide API key registeration/get/validation and DS token generation
  *
  * @{
  */

/**
  * Generate DS token according to serial number.
  *
  * @param[in]  szSerial Serial number to generate token
  * @param[out] szToken  Output string
  * @param[in]  cbToken  Size of output string
  *
  * @retval -1 failed (on error)
  * @retval  0 success
  * @grantable N
  */
SDK_STARTING_FROM(SDK_VER_4_0) int  SYNOCloudServiceDstokenGenerateToken(const char *szSerial, char *szToken, int cbToken);

/**
  * Get(generate) DS token and read serial number to buffer.
  *
  * @param[out] szSerial Serial number
  * @param[in]  cbSerial Size of serial number
  * @param[out] szToken  Output token
  * @param[in]  cbToken  Size of output string
  *
  * @retval -1 failed (on error)
  * @retval  0 success
  * @grantable N
  */
SDK_STARTING_FROM(SDK_VER_4_0) int  SYNOCloudServiceDstokenGetToken(char *szSerialOut, int cbSerial, char *szToken, int cbToken);

/**
  * Verify the input token string is valid DS token for the input
  * serial number or not.
  *
  * @brief Verify the input token is a valid or not for the serial number
  * @param szSerial Input serial number string
  * @param szToken  Input token string
  *
  * @retval	TRUE    Input string is the DS token
  * @retval	FALSE   Input string is not the DS token
  * @grantable N
  */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOCloudServiceDstokenVerifyToken(const char *szSerial, const char *szToken);

/**
  * Get cloud service API key and save it to @p apikey.
  *
  * @brief Get API key and save it to @p apikey
  * @param[in,out] apikey API key value
  * @param[in] blRegister Register a new API key or not if get API key fail
  * @return 0: success, -1: get key failed
  * @grantable Y
  */
SDK_STARTING_FROM(SDK_VER_4_0) int  SYNOCloudServiceGetApiKey(SYNO_CLOUDSERVICE_APIKEY *apikey, BOOL blRegister);

/**
  * Validate the API key is usable or not. Validate fail might due to
  * cannot get key value or server response error
  *
  * @brief Validate input API key is usable or not
  * @param[in,out] apikey API key value
  * @retval  0 on validate success or send request to server fail
  * @retval -1 on get key failed
  * @grantable Y
  */
SDK_STARTING_FROM(SDK_VER_4_0) int  SYNOCloudServiceValidateApiKey(SYNO_CLOUDSERVICE_APIKEY *apikey);

/**
  * Validate the API key is usable or not. Validate fail might due to
  * cannot get key value or server response error
  *
  * @brief Validate input API key is usable or not
  * @param[in,out] apikey API key value
  * @retval  0 on validate success or send request to server fail
  * @retval -1 on get key failed
  * @grantable Y
  */
SDK_STARTING_FROM(SDK_VER_4_0) int  SYNOCloudServiceRegisterApiKey(SYNO_CLOUDSERVICE_APIKEY *apikey);

/**
  * Encrypt or decrypt @p data according to input seeds
  *
  * @brief Encrypt or decrypt @p data
  * @param[in,out] data data to be encrypted or decrypted
  * @param[in] length length of @p data in bytes
  * @param[in] seed1 a random number used to encrypt or decrypt @p data
  * @param[in] seed2 a random number used to encrypt or decrypt @p data
  * @param[in] seed3 a random number used to encrypt or decrypt @p data
  * @param[in] mode encrypt or decrypt mode.
  * @retval >0 the encrypted data length
  * @retval -1 on entering wrong @p CRYPT_MODE
  * @grantable N
  */
SDK_STARTING_FROM(SDK_VER_5_2) int  SYNOCloudServiceDataCrypto(char* data, int length, uint16_t seed1, uint16_t seed2, uint16_t seed3, CRYPT_MODE mode);

/**
  * Get cloud service error code
  *
  * @brief Get cloud service error code
  * @return 0-255 according to @p SYNO_CLOUDSERVICE_ERROR_CODE
  * @grantable N
  */
SDK_STARTING_FROM(SDK_VER_5_2) SYNO_CLOUDSERVICE_ERROR_CODE SYNOCloudServiceGetErrorCode();

/**
  * Handle actions provided by @p SYNO_CLOUDSERVICE_HANDLE
  * Currently, handler will only logout user if needed:
  * If API key is valid, MyDS will be logged out and API key will be removed
  *
  * @brief handle action provided by @p SYNO_CLOUDSERVICE_HANDLE
  * @param[in] handle Action to do. See @p SYNO_CLOUDSERVICE_HANDLE
  * @return None
  * @grantable Y
  */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOCloudServiceActionHandler(SYNO_CLOUDSERVICE_HANDLE handle);

/**
  * Remove API key
  *
  * @brief Get cloud service error code
  * @param[in] blForce Force to remove API key regardless of its validity
  * @return None
  * @grantable Y
  */
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOCloudServiceRemoveApiKey(BOOL blForce);

/**
  * @}
  */
