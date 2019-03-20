/* log.c */
int FHOSTLog(const FHOSTLOG *pfhostLog, FHOSTLOG_PRIOR logPrior, const char *szFmt, ...);
int FHOSTLogFuncSet(FHOSTLOG *pfhostLog, FHOSTLOG_PRIOR logPrior, FUNCLOG pfuncLog);
FUNCLOG FHOSTLogFuncGet(const FHOSTLOG *pfhostLog, FHOSTLOG_PRIOR logPrior);
int FHOSTLogLock(const FHOSTLOG *pfhostLog, int iToLock);
int FHOSTLogDefSyslogErr(const char *szMsg);
int FHOSTLogDefSyslogDebug(const char *szMsg);
int FHOSTLogDefConsole(const char *szMsg);
/* packet.c */
int FHOSTPacketReadString(const FHOSTLOG *pLog, const unsigned char *szPKTInput, int cbPKTInput, void *pFieldOutput, size_t cbFieldOutput, int options, const unsigned int cArrayElement);
int FHOSTPacketWriteString(const FHOSTLOG *pLog, char *szPKTOutput, int cbPKTOutput, FHOST_PKT_ID PktId, const void *pFieldInput, size_t cbFieldInput, int options, const void *pNASInfo);
int FHOSTPacketReadInteger(const FHOSTLOG *pLog, const unsigned char *szPKTInput, int cbPKTInput, void *puFieldOutput, size_t cbFieldOutput, int options, const unsigned int cArrayElement);
int FHOSTPacketWriteInteger(const FHOSTLOG *pLog, char *szPKTOutput, int cbPKTOutput, FHOST_PKT_ID PktId, const void *pulFieldInput, size_t cbFieldInput, int options, const void *pNASInfo);
int FHOSTPacketReadArray(const FHOSTLOG *pLog, const unsigned char *szPKTInput, int cbPKTInput, void *pFieldOutput, size_t cbFieldOutput, int options, const unsigned int cArrayElement);
int FHOSTPacketWriteArray(const FHOSTLOG *pLog, char *szPKTOutput, int cbPKTOutput, FHOST_PKT_ID PktId, const void *pFieldInput, size_t cbFieldInput, int options, const void *pNASInfo);
int FHOSTPacketRead(const FHOSTLOG *pLog, const unsigned char *szPKTInput, int cbPKTInput, NASINFO *pnasinfoOutput);
int FHOSTPacketWrite(const FHOSTLOG *pLog, unsigned char **pszPKTOutput, int *pcbPKTOutput, const FHOSTSEND *pfhostSend);
int FHOSTSendPktIDAdd(const FHOSTLOG *pLog, FHOSTSEND *pfhostSend, FHOST_PKT_ID pktID1, ...);
int FHOSTSendPktIDSet(const FHOSTLOG *pLog, FHOSTSEND *pfhostSend, FHOST_PKT_ID pktID, const void *pFieldInput, size_t cbFieldInput);
int FHOSTSendPktIDAddServ(const FHOSTLOG *pLog, FHOSTSEND *pfhostSend, int blServSupp, int blServRun);
/* socket.c */
unsigned long FHOSTSocketHtonl(unsigned long ulHost);
unsigned long FHOSTSocketNtohl(unsigned long ulNetwork);
unsigned long long FHOSTSocketHtonll(unsigned long long ullHost);
unsigned long long FHOSTSocketNtohll(unsigned long long ulNetwork);
unsigned short FHOSTSocketHtons(unsigned short usHost);
unsigned short FHOSTSocketNtohs(unsigned short usNetwork);
unsigned long FHOSTSocketHtoLEl(unsigned long ulHost);
unsigned long FHOSTSocketLEtoHl(unsigned long ulLittle);
unsigned long long FHOSTSocketHtoLEll(unsigned long long ullHost);
unsigned long long FHOSTSocketLEtoHll(unsigned long long ullLittle);
/* udp.c */
int FHOSTSocketInit(const FHOSTLOG *pLog);
int FHOSTUDPSend(const FHOSTLOG *pLog, const unsigned char *szPKTOutput, int cbPKTOutput, const FHOSTCONN *pfhostConn, const FHOSTNETIF *pNetIf, int blBindNIC);
int FHOSTUDPClient(const FHOSTCONN *pfhostConn, FHOSTSEND *pfhostSend);
int FHOSTUDPServer(const FHOSTCONN *pfhostConnServ, const FHOSTRECV *pfhostRecv, const FHOSTCONN *pfhostConnClient, FHOSTSEND *pfhostSend);
/* iface.c */
int FHOSTIfaceGetActive(FHOSTLOG *pLog, const char *szIf);
int FHOSTIfaceGetNetSetting(FHOSTLOG *pLog, FHOSTNETIF *pNetIf);
int FHOSTIfaceDump(FHOSTLOG *pLog);
int FHOSTIfaceInit(FHOSTLOG *pLog, FHOSTNETIF *rgNetIf, int numNetIf);
/* iface_lnx.c */
int FHOSTGetIfListLnx(FHOSTLOG *pLog, FHOSTNETIF *rgNetIf, int numNetIf);
int FHOSTIfaceInitLnx(FHOSTLOG *pLog, FHOSTNETIF *rgNetIf, int numNetIf);
/* nasinfo.c */
int FHOSTNasinfoServSuppClear(const FHOSTLOG *pLog, NASINFO *pnasInfo);
int FHOSTNasinfoServSuppSet(const FHOSTLOG *pLog, NASINFO *pnasInfo, FHOST_SERVICE id);
int FHOSTNasinfoServSuppGet(const FHOSTLOG *pLog, const NASINFO *pnasInfo, FHOST_SERVICE id);
int FHOSTNasinfoServRunClear(const FHOSTLOG *pLog, NASINFO *pnasInfo);
int FHOSTNasinfoServRunSet(const FHOSTLOG *pLog, NASINFO *pnasInfo, FHOST_SERVICE id);
int FHOSTNasinfoServRunGet(const FHOSTLOG *pLog, const NASINFO *pnasInfo, FHOST_SERVICE id);
