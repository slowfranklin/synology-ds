/* firewall_port_range_is_support.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOFwIsSupportPortRange(void);
/* firewall_service_enum.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOFwServiceEnum(SYNO_FW_SERVICES **ppServices);
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOProtocolMapping(unsigned int protocol);
/* firewall_service_find.c */
SDK_STARTING_FROM(SDK_VER_4_0) SYNO_FW_SERVICES *SYNOFWServiceFind(SYNO_FW_SERVICES *pServices, const char *szName);
/* firewall_service_free.c */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNOFwServiceFree(SYNO_FW_SERVICES *pServices);
/* service_compose_port_info.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOServiceComposePortInfo(const SYNO_SERVICE_CONF_PORT *pstComposePortVar, SYNO_SERVICE_CONF_PORT **ppServConfPort);
/* service_compose_section_info.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOServiceComposeSectionInfo(const SYNO_SERVICE_CONF_SECTION *pstComposeSectionVar, SYNO_SERVICE_CONF_SECTION **ppServConfSection);
/* service_conf_enum.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOServiceConfEnum(SYNO_SERVICE_CONF **ppServConf, unsigned int servType);
/* service_conf_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOServiceConfGet(const char *szFilePath, SYNO_SERVICE_CONF **ppServConf);
/* service_conf_free.c */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNOServiceConfFree(SYNO_SERVICE_CONF *pServConf);
/* service_conf_section_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOServiceConfSectionGet(const char *szFilePath, const char *szSecName, SYNO_SERVICE_CONF_SECTION **ppServConfSection);
/* service_conf_section_get.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOServiceConfServiceStringGet(char *szInRawStr, SYNO_SERVICE_STRING *pOutServiceString);
/* service_conf_section_free.c */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNOServiceConfSectionFree(SYNO_SERVICE_CONF_SECTION *pServConfSection);
/* service_conf_ports_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNOServiceConfPortsCheck(const char *szPorts);
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBServiceConfProtocolParse(char *szProtocol);
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOServiceConfPortsGet(const char *szPorts, SYNO_SERV_PORT_TARGET target, SYNO_SERVICE_CONF_PORT **ppServConfPort);
/* service_conf_ports_free.c */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNOServiceConfPortsFree(SYNO_SERVICE_CONF_PORT *pServConfPort);
/* service_conf_ports_to_str.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBServiceConfPortsToStr(const SYNO_SERVICE_CONF_PORT *pstPortList, char *pszPortPart, int cbPortPart, char *pszProtoPart, int cbProtoPart);
/* service_conf_ports_set.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBServiceConfPortsSet(SYNO_SET_VAR *pstSetVar, SYNO_SERVICE_CONF_PORT *pServConfPort);
/* service_conf_file_verify.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOServiceConfFileVerify(const char *szFilePath, const char *szConfFolder);
/* service_conf_section_port_set.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOServiceConfSectionPortSet(const SYNO_SERV_TYPE servType, const char *pszConfName, const char *pszSectionName, SYNO_SERVICE_CONF_PORT *pstPortList);
/* service_conf_common.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBServiceProtoMapSizeGet(void);
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBServiceProtoIndexGet(int iIndex, int *pProto);
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBServiceProtoStrGet(int iIndex, char *szProto, int cbProto);
SDK_STARTING_FROM(SDK_VER_4_1) int SLIBServiceConfBackup(SYNO_SET_VAR *pstSetVar);
SDK_STARTING_FROM(SDK_VER_4_1) int SLIBServiceConfRestore(SYNO_SET_VAR *pstSetVar);
SDK_STARTING_FROM(SDK_VER_4_1) int SLIBServiceBackupConfDelete(SYNO_SET_VAR *pstSetVar);
/* service_conf_remove.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBServiceConfRemove(SYNO_SET_VAR *pstSetVar); // Deprecation, please call SYNOServiceConfRemove
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBServiceConfRemoveBaseName(const char * szBaseName, SYNO_SERV_TYPE servType); // Deprecation, please call SYNOServiceConfRemoveBaseName
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOServiceConfRemove(SYNO_SET_VAR *pstSetVar);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOServiceConfRemoveBaseName(const char * szBaseName, SYNO_SERV_TYPE servType);
/* service_conf_section_remove.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBServiceConfSectionRemove(SYNO_SET_VAR *pstSetVar);
/* service_conf_install.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOServiceConfInstall(const char *szSrcPath, SYNO_SERV_TYPE servType);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOServiceConfInstallBaseName(const char *szConfBaseName, const char *szSrcPath, SYNO_SERV_TYPE servType, SYNO_SERVICE_CONF_PORT **ppConflictPorts);
/* service_conf_update.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOServiceConfUpdateBaseName(const char *szConfBaseName, const char *szNewSrcPath, SYNO_SERV_TYPE servType, SYNO_SERVICE_CONF_PORT **ppConflictPorts);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOServiceConfUpdateBaseNameWithoutNotify(const char * szConfBaseName, const char * szNewSrcPath, SYNO_SERV_TYPE servType, SYNO_SERVICE_CONF_PORT **ppConflictPorts, SYNO_NOTIFY_VAR *pstNotifyVar);
/* service_conf_section_set.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBServiceConfSectionSet(SYNO_SET_VAR *pstSetVar, SYNO_SERVICE_CONF_SECTION *pServConfSection);
/* service_is_port_conflict.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBIsPortConflict(char *szSkipServices, char *szPort, char *szProto, int servType, SYNO_SERVICE_CONF_PORT **ppstConflictPortList);
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBIsConfPortConflict(const char *szConfFile, SYNO_SERVICE_CONF_PORT **ppstConflictPortList);
/* service_conf_serv_restart.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBServiceConfServRestart(int restartServ);
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBServiceConfServNotify(SYNO_NOTIFY_VAR *pstNotifyVar); // Deprecation, please call SLIBServiceConfUpdateServNotify
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBServiceConfUpdateServNotify(SYNO_NOTIFY_VAR *pstNotifyVar);
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBServiceConfRemoveServNotify(SYNO_REMOVE_NOTIFY_VAR *pstNotifyVar);
/* service_port_range_create.c */
SDK_STARTING_FROM(SDK_VER_4_0) SYNO_PORT_RANGE *SLIBPortRangeCreate(void);
/* service_port_range_destory.c */
SDK_STARTING_FROM(SDK_VER_4_0) void SLIBPortRangeDestory(SYNO_PORT_RANGE *pPortRange);
/* service_port_range_add.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBPortRangeAdd(SYNO_PORT_RANGE *pPortList, SYNO_SERVICE_CONF_PORT *pEntry);
/* service_port_range_remove.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBPortRangeRemove(SYNO_PORT_RANGE *pPortList, SYNO_SERVICE_CONF_PORT *pEntry);
/* service_port_range_overlap.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBPortRangeOverlap(SYNO_PORT_RANGE *pQueryPortList, SYNO_PORT_RANGE *pOccupiedPortList, SYNO_PORT_RANGE *pOverlapPortList);
/* service_port_range_join.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBPortRangeJoin(SYNO_PORT_RANGE *pPortList1, SYNO_PORT_RANGE *pPortList2);
/* service_port_range_export.c */
SDK_STARTING_FROM(SDK_VER_4_0) char *SLIBPortRangeExport(SYNO_PORT_RANGE *pPortList);
/* service_port_range_import.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBPortRangeImport(SYNO_PORT_RANGE *pPortList, char *szPortRange);

/* port_conflict_conf_*.c */
SDK_STARTING_FROM(SDK_VER_6_0) PSYNO_CONF_PORT_CONFLICT_RESULT_LIST SYNOConfPortConflictResultListAllocAndCheck(PSLIBSZLIST pPortList, uint16_t uProtocol);
SDK_STARTING_FROM(SDK_VER_6_0) void SYNOConfPortConflictResultListFree(PSYNO_CONF_PORT_CONFLICT_RESULT_LIST pResultList);
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOConfIsConflictPorts(PSLIBSZLIST pPortList, uint16_t uProtocol);
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOConfIsConflictPortRange(uint16_t uFromPort, uint16_t uToPort, uint16_t uProtocol);
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNOConfIsConflictPort(uint16_t uPort, uint16_t uProtocol);

/* port_conflict_runtime_*.c */
SDK_STARTING_FROM(SDK_VER_6_0) PSYNO_RUNTIME_PORT_CONFLICT_RESULT_LIST SYNORuntimePortConflictResultListAllocAndCheck(PSLIBSZLIST pPortList, uint16_t uProtocol);
SDK_STARTING_FROM(SDK_VER_6_0) void SYNORuntimePortConflictResultListFree(PSYNO_RUNTIME_PORT_CONFLICT_RESULT_LIST pResultList);
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNORuntimeIsConflictPorts(PSLIBSZLIST pPortList, uint16_t uProtocol);
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNORuntimeIsConflictPortRange(uint16_t uFromPort, uint16_t uToPort, uint16_t uProtocol);
SDK_STARTING_FROM(SDK_VER_6_0) BOOL SYNORuntimeIsConflictPort(uint16_t uPort, uint16_t uProtocol);

const char* SYNOTCPStateToString(int iTCPState);
