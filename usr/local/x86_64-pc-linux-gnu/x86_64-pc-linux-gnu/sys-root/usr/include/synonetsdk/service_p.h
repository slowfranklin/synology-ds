#include <synosdk/service.h>

/* service_pppoe.c */
SDK_STARTING_FROM(SDK_VER_4_0) int PPPoEConfigGet(PPPOECONFIG *PPPoEConf);
SDK_STARTING_FROM(SDK_VER_4_0) int PPPoEConfigSet(PPPOECONFIG PPPoEConf);
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOPPPoEService(int op);
/* service_tunnel_config_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOTunnelConfigGet(TUNNELCONFIG *pTunnelCfg);
/* service_tunnel_config_set.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOTunnelConfigSet(TUNNELCONFIG *pTunnelCfgNew);
/* service_tunnel_execute.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOTunnelExecute(SERVICE_ACTION iOperation, TUNNELCONFIG *pTunnelCfg);
/* service_pppoe.c */
SDK_STARTING_FROM(SDK_VER_5_0) int SYNOPPPoECheckStatus(BOOL blIfUpdateRunKey);
/* service_stop_before_ip_change.c */
SDK_STARTING_FROM(SDK_VER_5_0) int SLIBServiceStopBeforeIPChange();
/* service_net_service_plugin.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBServicePlugin(DAEMON_ACTION action, int eType);
