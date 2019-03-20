/* net_apply_pppoe_relay_config.c */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONetApplyPPPoERelayConfig(const char *szIfName);
/* net_apply_pppoe_relay_config_all.c */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONetApplyPPPoERelayConfigAll(void);
/* net_bond_ip_conflict.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetBondIPConflict(const char* szBondDev, char* szConflictDev, int size);
/* net_bridge_enum.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SLIBNetEnumBridge(PSLIBSZLIST *ppBridge, BR_TYPE type);
/* net_bridge_if_is_master.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetBridgeIfIsMaster(const char *szIfname);
/* net_bridge_if_is_slave.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetBridgeIfIsSlave(const char *szIfname);
/* net_bridge_slave_enum.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetBridgeSlaveEnum(const char *szBridge, PSLIBSZLIST *ppslList);
/* net_cal_mask.c */
SDK_STARTING_FROM(SDK_VER_4_0) int cSLIBICalMask(const int *rgMask);
/* net_cal_broadcast.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetCalBroadcast(const char *szIP, char *szBroadcast, int iBroadcastLen);
/* net_cal_network.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetCalNetwork(const char *szIP, char *szNetwork, int iNetworkLen);
/* net_clear_pppoe_relay_config.c */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONetClearPPPoERelayConfigAll(void);
/* net_conf_get_mtu_value.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOConfGetMTUValue(const char *szDev, char *szValue, int BufSize);
/* net_conf_set_mtu_value.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOConfSetMTUValue(const char *szMTUValue, const char *szDev);
/* net_default_gateway_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetDefaultGatewayGet(char *szGateway, int cbSize);
/* net_default_gateway_get_conf.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetDefaultGatewayGetConf(char *szGateway, int cbSize);
/* net_default_gateway_set.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetDefaultGatewaySet(const char *szGateway);
/* net_default_gateway_set_conf.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetDefaultGatewaySetConf(const char *szGateway);
/* net_dhcp_server_change_interface.c */
SDK_STARTING_FROM(SDK_VER_5_1) int DHCPDConfChangeInterface(const char *szDeviceOri, const char *szDeviceNew);
/* net_dhcp_server_restart.c */
SDK_STARTING_FROM(SDK_VER_5_1) int SLIBNetDHCPServerRestart(void);
/* net_dns_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetDNSGet(char *szDNS, int BufSize);
/* net_dns_list_get.c */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNONetDNSListGet(PPSLIBSZLIST pplist);
/* net_dns_static_list_get.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetStaticDNSListGet(PPSLIBSZLIST pplist);
/* net_dns_list_set.c */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNONetDNSListSet(PSLIBSZLIST plist);
/* net_dns_mode_set.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SYNONetDNSModeSet(const char *szRule);
/* net_dns_set.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetDNSSet(const char *szDNS);
/* net_dns_update.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SYNONetDNSUpdate(void);
/* net_enum_card.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetEnumCard(SYNONICENUM nicMode);
/* net_ether_wake.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBNetEtherWake(const SYNONETETHERWAKEINFO *pEtherWakeInfo);
/* net_external_ip_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) char *SYNOExternalIPGet(void);
/* net_get_addr_type.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetGetAddrType(const char *szAddr);
/* net_get_dhcp_server_conf.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNONetGetDhcpServerConf(const char *szTag, const char *szIfName, PSYNO_DHCPD_CONF pDhcpServerConf);
/* net_get_dhcp_test_net_info.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOIGetDHCPTestNetInfo(NETINFO *pnetinfo);
/* net_get_bridge_config.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SYNONetGetBridgeConfig(const char *szIfName, NETINFO *pNetInfo, PBRIDGE_INFO pBridgeInfo);
/* net_get_bridge_info.c */
SDK_STARTING_FROM(SDK_VER_4_1) BR_TYPE SLIBNETGetBridgeInfo(const char *szIfName, PBRIDGE_INFO pInfo);
/* net_get_bridge_info_by_topology.c */
SDK_STARTING_FROM(SDK_VER_4_1) BR_TYPE SLIBNETGetBridgeInfoByTopology(const char *szIfName, PBRIDGE_INFO pInfo, const TOPOLOGY_MODE mode);
/* net_get_card1.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetGetCard1(const int idxIf, const char *szIP, PNETINFO pNetInfo);
SDK_STARTING_FROM(SDK_VER_5_1) int SYNONetGetCard1Ex(const int idxIf, const char *szIP, PNETINFO pNetInfo);
/* net_get_eth_info.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetGetEthInfo(ETHINFO *pEthInfo, const char *szDev);
/* net_get_interface_info.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetGetInterfaceInfo(PSLIBNETIF rgpsnIf, int nMax, SYNONICENUM nicMode);
/* net_get_if_block.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetGetIfBlock(const char *szDev, PIF_BLOCK_MODE pMode);
/* net_get_if_cfg.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetGetIfCfg(const char *szName, struct in_addr *padrIp, struct in_addr *padrMask);
/* net_get_if_info.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetIFGetInfo(const char *szIfname, PSLIBNETIF pIF, PNETINFO pNetInfo);
SDK_STARTING_FROM(SDK_VER_5_1) int SYNONetIFGetInfoEx(const char *szIfname, PSLIBNETIF pIF, PNETINFO pNetInfo);
/* net_get_if_ipconfig.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetIFGetIPConfig(const char *szIfname, PNETINFO pNetInfo);
/* net_get_local_lan_config.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetGetLocalLanConfig(PSLIBSZLIST *ppslLocalLan);
/* net_get_mac.c */
SDK_STARTING_FROM(SDK_VER_5_2) SYNO_GET_MAC_RETURN SLIBNetGetMacAddr(unsigned int idx, char *szMac, unsigned int cbMac, BOOL blGetOriginalMac);
SDK_STARTING_FROM(SDK_VER_6_0) SYNO_GET_MAC_RETURN SLIBNetGetMacAddrByInterface(const char *szIfname, char *szMac, unsigned int cbMac, BOOL blGetOriginalMac);
/* net_get_mtu_setting.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOGetMTUSetting(const char *szDev);
/* net_get_port_used_in_range.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetGetPortUsedInRange(int *rgiList, int *cbList, int portStart, int portEnd, BOOL blTcp);
/* net_get_pppoe_relay_config.c */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONetGetPPPoERelayConfig(const char *szIfName, PPPOERELAYCONFIG *pPppoeRelayConfig);
/* net_get_topology_info.c */
SDK_STARTING_FROM(SDK_VER_4_1) TOPOLOGY_MODE SLIBNetTopologyGet(PTOPOLOGY_INFO pInfo);
/* net_hostname_change_hook.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetHostnameChangeHook(const char *szHostname);
/* net_ifchg_plugin.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SLIBNetIFChgPluginSetArgs(PSLIBPLUGIN pPlugin, const char **szOriIfName, int nOriIfName, const char **szIfName, int nIfName, int retValue);
/* net_if_down.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetIfDown(const char *szName);
/* net_if_link_down_event.c */
SDK_STARTING_FROM(SDK_VER_4_2) int SLIBNetIfLinkDownEvent(const char *szIfName);
/* net_if_link_up_event.c */
SDK_STARTING_FROM(SDK_VER_4_2) int SLIBNetIfLinkUpEvent(const char *szIfName);
/* net_if_is_static_ip.c */
SDK_STARTING_FROM(SDK_VER_4_2) BOOL SYNONetIfIsStaticIP(const char *szDevice);
/* net_if_is_bonding_slave.c */
SDK_STARTING_FROM(SDK_VER_4_2) BOOL SYNONetIfIsBondingPassive(const char *szDevice);
/* net_if_up.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetIfUp(const char *szName);
/* net_interface_enum.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SLIBNetIFIsLocalLan(const char *szIfname);
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetInterfaceEnum(PSLIBNETIF rgpsnIf, int nMax, SLIB_IF_QUERY query);
/* net_internal_lan_num_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetInternalLanNumGet(void);
/* net_ip2if.c */
SDK_STARTING_FROM(SDK_VER_4_3) BOOL SYNONetIP2If(const char *szIPAddr, char *szIF, int cbIF);
/* net_ip_change_pre_hook.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetIPChangePreHook(const IPTYPE type, const char *ifname, const char *oriAddr, const char *newAddr, const int prefixlen);
/* net_ip_conflict.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOIIpConflict(const char *szDevice, const char *szIpAddr);
/* net_ip_mask_to_subnet.c */
SDK_STARTING_FROM(SDK_VER_4_0) int ErrSLIBIpMaskToSubnet(char *szIpMask, char *szSubnet);
/* net_ipv6_conf_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetIPv6ConfGet(const char *szDevice, SYNOIPV6CONFMODE *v6mode, char *szIPv6Addr, int addrsz, int *prefixLeng, char *szRouter, int routsz);
/* net_ipv6_conf_set.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetIPv6ConfSet(SYNOIPV6CONFMODE v6mode, const char *szDevice, const char *szIPv6Addr, unsigned int prefixLeng, const char *szRouter);
/* net_ipv6_ip_action.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetIPv6IPAction(SYNOIPV6IPCMD ipcmd, const char *szDevice, const char *szV6IPAddr, unsigned int prefixLeng, const char *szV6Router);
/* net_ipv6_is_same_subnet.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetIPv6IsSameSubnet(const char *szV6IP1, const char *szV6IP2, unsigned int prefixLeng);
/* net_ipv6_proc_set.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLnxIPv6ProcAction(const char *szDevice, const BOOL bDisableIPv6);
/* net_ipv6_remove_dad_fail_ip.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetIPv6RemoveDADFailedIP(const char *szDevice, PNETIPV6 rgv6sDel, int delMax);
/* net_ipv6_flush_addr.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOLnxIPv6FlushAddr(const char *szDevice);
/* net_is_atom.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL BlSLIBIsAtom(const char *szAtom);
/* net_is_connected.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL BlSLIBIsConnected(const char *szHost, int port, int timeout);
/* net_is_dev_type_match.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNONetIsDevTypeMatch(const char *szDev, SYNONICENUM nicEnum);
/* net_is_domain.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL BlSLIBIsDomain(const char *szDomain);
/* net_is_hostname.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL BlSLIBIsHostname(const char *szHostname);
/* net_is_if_nat_master.c */
SDK_STARTING_FROM(SDK_VER_4_3) BOOL SYNONetIsIfBridgeType(const char *szIfName, const BR_TYPE type);
/* net_is_if_up.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNONetIsIFUp(const char *szName);
/* net_is_ip_addr.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL BlSLIBIsIpAddr(const char *szIpAddr);
/* net_is_ip_mask.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL BlSLIBIsIpMask(char *szIpMask);
/* net_is_ovs_up.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBNetIsOVSUp(const char *szInterface);
/* net_is_port_range_used.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNONetIsPortRangeUsed(int portStart, int portEnd, BOOL blTcp);
/* net_is_private_ip.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNONetIsPrivateIP(const char *szIpAddr);
/* net_is_same_pppoe_relay_config.c */
SDK_STARTING_FROM(SDK_VER_4_3) BOOL SYNONetIsSamePPPoERelayConfig(const PPPOERELAYCONFIG *pPppoeRelayConfig1, const PPPOERELAYCONFIG *pPppoeRelayConfig2);
/* net_is_same_subnet.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetIsSameSubnet(const char *szIP1, const char *szIP2, const char *szMask);
/* net_is_v6ip.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL BlSLIBIsv6IpAddrValid(const char *szv6IpAddr);
/* net_is_valid_ip_mask.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL BlSLIBIsValidIpMask(const char *szIP, const char *szMask);
/* net_link_aggr_conf_update_boot_proto.c */
SDK_STARTING_FROM(SDK_VER_4_0) void SYNONetLinkAggrConfUpdateBootProto(const char *szfDevConf, PSLIBSZHASH *ppshConfUpdate);
/* net_link_aggr_enum.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetLinkAggrEnum(PSLIBSZLIST *ppslResult);
/* net_link_aggr_exist.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetLinkAggrExist();
/* net_link_aggr_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetLinkAggrGet(const char *szDev, PSYNOLINKAGGROPT plaOpt);
/* net_link_aggr_opt_slave_add.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetLinkAggrOptSlsaveAdd(const PSYNOLINKAGGROPT plaOpt, const char *szDev);
/* net_link_aggr_phy_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetLinkAggrPhyGet(const char *szDev, PSLIBSZLIST *ppslResult);
/* net_link_aggr_set.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetLinkAggrSet(const PSYNOLINKAGGROPT plaOpt);
/* net_link_aggr_conf_del.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetLinkAggrConfDel(const PSYNOLINKAGGROPT plaOpts);
/* net_link_aggr_conf_set_slave.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetLinkAggrConfSetSlave(const char *szSlaveDev, BOOL blSlave, const char *szBondDev);
/* net_lnx_get_hostname.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLnxGetHostname(char *szHostname);
/* net_lnx_get_ip.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOILnxGetIP(const char *szDevice, char *szIpAddr, int size);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOILnxGetIPFromCfg(const char *szDevice, char *szIpAddr, int size);
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOILnxGetOldIPFromCfg(const char *szDevice, char *szIpAddr, int size);
/* net_lnx_get_v6ip.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLnxV6IPGet(const char *szDevice, PNETIPV6 pNetv6Ip, int sizePNet);
/* net_lnx_is_dhcp.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL BlSYNOLnxIsDHCP(const char *szDevice);
/* net_lnx_set_hostname.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOLnxSetHostname(const char *szHostname);
/* net_lnx_set_ip_netmask.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOILnxSetIPNetmask(const char *szDevice, const char *szIpAddr, const char *szNetmask);
/* net_lookup_ip.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetLookupIP(const char *szHost, PSYNOIPLIST rgpIPList, int maxIPNum, BOOL blTotal);
/* net_mtu_change_hook.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetMTUChangeHook(const char *szMTUValueOld, const char *szMTUValueNew);
/* net_netmask_to_prefix.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetNetmaskToPrefix(const char *szNetmask);
/* net_ntoa.c */
SDK_STARTING_FROM(SDK_VER_4_2) char *SYNONetNtoa(struct in_addr in);
/* net_ovs_get_original_if.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBNetOVSGetOriginalIf(const char *szInterface, char *szOutput, int BufSize);
/* net_ovs_if_is_slave.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBNetOVSIfIsSlave(const char *szInterface);
/* net_ovs_if_is_master.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBNetOVSIfIsMaster(const char *szInterface);
/* net_pppoe_disable_on_if.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBDisablePPPoEOnIf(const char *szInterface);
/* net_pppoe_get_intf.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOPPPoeIntfGet(char *pszIntf, size_t cBufLen);
/* net_pppoe_get_net_info.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNOPPPoeNetInfoGet(char *szIP, int cbIP, char *szMask, int cbMask);
/* net_rename_eth.c */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONetRenameEth(const char *szDevTo, const char *szDevFrom);
/* net_re_init_if.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetReInitIf(const char *szName);
/* net_route_table_check.c */
SDK_STARTING_FROM(SDK_VER_4_0) int NetRoutetableCheck(void);
/* net_route_table_edit.c */
SDK_STARTING_FROM(SDK_VER_4_0) int NetRoutetableEdit(const int type, const char *szIP, const char *szMask, const char *szInterface);
/* net_route_table_handler.c */
SDK_STARTING_FROM(SDK_VER_4_0) int NetRoutetableHandler(const int type, const char *szInterface);
/* net_sep_ip.c */
SDK_STARTING_FROM(SDK_VER_4_0) int cSLIBISepIP(const char *szAddr, int *rgAddr);
/* net_set_bridge_config.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetSetBridgeConfig(const NETINFO *pNetInfo, const PBRIDGE_INFO pBridgeInfo);
/* net_set_card1.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetSetCard1(PNETINFO pNetInfo, PNETINFO pNetInfoOld);
/* net_set_dhcp_server_config_files.c */
SDK_STARTING_FROM(SDK_VER_4_0) BOOL SYNONetSetDhcpServerConfigFiles(const PSYNO_DHCPD_CONF pConf, const BOOL blEnable);
/* net_set_if_block.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetSetIfBlock(const char *szDev, IF_BLOCK_MODE mode, BOOL isBlock);
/* net_set_if_cfg.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetSetIfCfg(const char *szName, struct in_addr *padrIp, struct in_addr *padrMask);
/* net_set_if_flags.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetISetIfFlags(const char *szName, int value);
/* net_set_ip.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetSetIP(const char *type, const char *ifname, const char *newAddr, const int prefixlen, const char *action);
/* net_flush_ip.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetFlushIP(const char *type, const char *ifname);
/* net_set_mtu_eth.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetSetMTUEth(const char *szMTUValue, const char *szDev);
/* net_set_mtu_value.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SYNONetSetMTUValue(const char *szMTUValue, const char *szDev);
/* net_set_pppoe_relay_config.c */
SDK_STARTING_FROM(SDK_VER_4_3) int SYNONetSetPPPoERelayConfig(const char *szIfName, const PPPOERELAYCONFIG *pPppoeRelayConfig);
/* net_set_topology_configs.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SLIBNETSetTopologyConfigs(const PTOPOLOGY_INFO pInfo);
/* net_stat_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetStatGetSingle(const char *szDevName, PSLIBNETSTAT psnStat);
/* net_stat_get_all.c */
SDK_STARTING_FROM(SDK_VER_4_3) int SLIBNetStatGetAll(PSLIBNETSTAT rgpsnStat, int nMax);
/* net_stat_init.c */
SDK_STARTING_FROM(SDK_VER_4_0) PSLIBNETSTAT SLIBNetStatInit(size_t nItem);
SDK_STARTING_FROM(SDK_VER_4_0) void SLIBNetStatFree(PSLIBNETSTAT pStat);
/* net_subnet_to_ip_mask.c */
SDK_STARTING_FROM(SDK_VER_4_0) int ErrSLIBSubnetToIpMask(char *szSubnet, char *szIpMask);
/* net_vlan_enum.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetVlanEnum(PSLIBVLAN *ppvlans, int *pItem);
/* net_vlan_create.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetVlanCreate(const char *szDevice, int vlanId, const PNETINFO pVlanNetInfo);
/* net_vlan_exist.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBNetVlanExist();
/* net_vlan_get.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetVlanGet(const char *szVlanInterface, PSLIBVLAN pVlanInfo);
/* net_vlan_get_by_row_dev.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetVlanGetByRowDev(const char *szRowDev, const int id, PSLIBVLAN pVlanInfo);
/* net_vlan_remove.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetVlanRemove(const char *szVlanIf);
/* net_vlan_valid_id.c */
SDK_STARTING_FROM(SDK_VER_4_0) int SLIBNetVlanValidId(int id);
/* net_if_is_link.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNONetIfIsLink(const char *szDevname);

/* net_link_aggr_string_to_mode.c */
SDK_STARTING_FROM(SDK_VER_6_0) const char* SYNONetLinkAggrModeToString(SYNOLINKAGGRMODE laMode);
/* net_link_aggr_mode_to_string.c */
SDK_STARTING_FROM(SDK_VER_6_0) SYNOLINKAGGRMODE SYNONetLinkAggrStringToMode(const char *szMode);
/* net_gateway_config_change_hook.c */
SDK_STARTING_FROM(SDK_VER_6_0)
int SYNONetGatewayConfigChangeHook(SDK_PLUGIN_ACTION action,
								   const char *szType,
								   const char *szIfName,
								   const char *szGatewayOld,
								   const char *szGatewayNew);
/* net_dns_config_change_hook.c */
SDK_STARTING_FROM(SDK_VER_6_0)
int SYNONetDnsConfigChangeHook(SDK_PLUGIN_ACTION action,
							   const char *szIfName,
							   PSLIBSZLIST szDnsList);
/* net_is_ip_in_range.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SLIBIsIpInRange(char *pszIpAddr,
												   char *pszIpBound1,
												   char *pszIpBound2,
												   int iAF);
