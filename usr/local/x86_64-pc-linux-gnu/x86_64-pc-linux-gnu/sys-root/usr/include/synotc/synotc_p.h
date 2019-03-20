/* firewall_tc_rule_get_by_adapter.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SYNOFwTcRuleGetByAdapter(const char *szRootPath, const char *szAdapterName, SYNO_FW_TC_ADAPTER **ppAdapter);
/* firewall_tc_rule_free_by_adapter.c */
SDK_STARTING_FROM(SDK_VER_4_1) void SYNOFwTcRulesFreeByAdapter(SYNO_FW_TC_ADAPTER *pAdapter);
/* firewall_tc_rule_open.c */
SDK_STARTING_FROM(SDK_VER_4_1) FILE *SYNOFwTcRuleOpen(const char *szRootPath, const char *szAdapterName);
/* firewall_tc_rule_close.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SYNOFwTcRuleClose(const char *szRootPath, FILE *fd, const char *szAdapterName);
/* firewall_tc_restart.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SYNOFwTcRestart(const char *szRootPath);
/* firewall_tc_rules_reload.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SYNOFwTcRuleReload(const char *szRootPath);
/* firewall_tc_rule_write.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SYNOFwTcRuleWrite(FILE *fd, SYNO_FW_TC_RULES *pRule);
/* firewall_tc_reset.c */
SDK_STARTING_FROM(SDK_VER_4_1) void SYNOFwTcReset(void);
/* firewall_tc_rule_dump.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SYNOFwTcRulesDump(const char *szRootPath, const SYNO_FW_TC_RULEDUMP_OPT *pOpt);
/* firewall_tc_qdisc_free.c */
SDK_STARTING_FROM(SDK_VER_4_1) void SYNOFwTcQdiscFree(SYNO_FW_TC_QDISC *pQdisc);
/* firewall_tc_class_free.c */
SDK_STARTING_FROM(SDK_VER_4_1) void SYNOFwTcClassFree(SYNO_FW_TC_CLASS *pClass);
/* firewall_tc_is_run.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SYNOFwTcIsRun(void);
/* firewall_tc_rule_hup.c */
SDK_STARTING_FROM(SDK_VER_4_1) int SYNOFwTcRuleHup(void);
/* firewall_tc_buf_rule_init.c */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNOFwTcBufRuleInit(SYNO_FW_TC_RULES **ppRules);
/* firewall_tc_buf_rules_free.c */
SDK_STARTING_FROM(SDK_VER_4_2) void SYNOFwTcBufRulesFree(SYNO_FW_TC_RULES *pRules);
/* firewall_tc_iptables_buf_rule_init.c */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNOFwTcBufIptablesRuleInit(SYNO_FW_TC_IPTABLE_RULE **ppRules);
/* firewall_tc_buf_iptables_rule_free.c */
SDK_STARTING_FROM(SDK_VER_4_2) void SYNOFwTcBufIptablesRuleFree(SYNO_FW_TC_IPTABLE_RULE *pRules);
/* firewall_tc_buf_iptables_rule_copy.c */
SDK_STARTING_FROM(SDK_VER_4_2) int SYNOFwTcBufIptablesRuleCopy(SYNO_FW_TC_IPTABLE_RULE *pDstRule, SYNO_FW_TC_IPTABLE_RULE *pSrcRule);
/* firewall_change_interface.c */
SDK_STARTING_FROM(SDK_VER_6_0) int SYNOFwChangeTcInterface(const char *szOriginalIfName, const char *szNewIfName);
