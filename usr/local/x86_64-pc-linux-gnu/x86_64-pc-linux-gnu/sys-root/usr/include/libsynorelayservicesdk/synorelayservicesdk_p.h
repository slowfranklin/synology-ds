SDK_STARTING_FROM(SDK_VER_5_2) int SYNORelayServiceTunnelMapGet(uint32_t iLocalIp, uint16_t iLocalPort, uint32_t* pRemoteIp, uint16_t* pRemotePort);
SDK_STARTING_FROM(SDK_VER_5_2) int SYNORelayServiceTunnelMapAdd(uint32_t iLocalIp, uint16_t iLocalPort, uint32_t iRemoteIp, uint16_t iRemotePort);
SDK_STARTING_FROM(SDK_VER_5_2) int SYNORelayServiceTunnelMapClean();

SDK_STARTING_FROM(SDK_VER_5_2) int SYNORelayServiceGetConnectionInfoByPeerFd(int iPeerfd, RELAY_CONNECTION_INFO* pInfo) __attribute__ ((deprecated));

SDK_STARTING_FROM(SDK_VER_5_2) int SYNORelayServiceGetConnectionTypeByPeerFd(int iPeerFd, RELAY_CONNECTION_ENUM_TYPE* pType);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNORelayServiceGetConnectionTypeByAddr(const char* pszLocalIp, const char* pszLocalPort, const char* pszRemoteIp, const char* pszRemotePort, RELAY_CONNECTION_ENUM_TYPE* pType);

SDK_STARTING_FROM(SDK_VER_6_0) int SYNORelayServiceGetAddrInfoByPeerFd(int iPeerfd, RELAY_ADDR_INFO* pInfo);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNORelayServiceGetAddrInfoByAddr(const char* pszLocalIp, const char* pszLocalPort, const char* pszRemoteIp, const char* pszRemotePort, RELAY_ADDR_INFO* pInfo);
