#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
// Copyright (c) 2000-2014 Synology Inc. All rights reserved.
#ifndef SYNOHA_LIBCRM_INT_H
#define SYNOHA_LIBCRM_INT_H
#if 0
#undef LOG_DEBUG
#define LOG_DEBUG LOG_ERR
#endif

#ifdef MY_ABC_HERE

#define SZF_CRM_CONF_TMP          "/tmp/crm_conf.xml"
#define SZF_HA_GREP               SZD_HA_PREFIX"/sbin/synohagrep"
#define BUFSIZ_FOR_CONF           (1024)
#define BUFSIZ_FOR_LIST           (8192)

#define SZK_CRM_CONF_COLOCATION        "COLOCATION" // crm configure colocation
#define SZK_CRM_CONF_ORDER             "ORDER" // crm configure order

/*
cy18ha> crm_resource -Q --resource DUMMY_END --locate
cy18a_-

cy18ha> crm_resource --list
 DUMMY_START    (ocf::synology:Dummy) Started
 DUMMY_END      (ocf::synology:Dummy) Started
 SERV   (ocf::synology:ocf_wrapper_serv) Started
 FS     (ocf::synology:ocf_wrapper_fs) Started
 IP     (ocf::synology:IPaddr2) Started
 Master/Slave Set: CONF_SYNC [CONF_SYNC_]
     Masters: [ cy18a_- ]
     Slaves: [ cy18a ]
 Master/Slave Set: CHECKPOINT_LAST [CHECKPOINT_LAST_]
     Masters: [ cy18a_- ]
     Slaves: [ cy18a ]
 Master/Slave Set: INFO_SET [INFO_SET_]
     Masters: [ cy18a_- ]
     Slaves: [ cy18a ]
 Master/Slave Set: DRBD [DRBD_]
     Masters: [ cy18a_- ]
     Slaves: [ cy18a ]
 */
#define SZ_CRM_RESOURCE_LOCATE           SZD_PREFIX_USR_BIN"crm_resource -Q --resource %s --locate"
#define SZ_CRM_RESOURCE_LOCATE_HOST      SZD_PREFIX_USR_BIN"crm_resource -Q --resource %%s --locate | "SZF_HA_GREP" %s"

/*
 \".*node.*status.*\" is used to filter failed actions on lowest location of crm_mon
 Failed actions:
     IP_start_0 (node=cy18a_-, call=41, rc=1, status=complete): unknown error

 Sync as handler_sb.sh `CRM_MON_NODE_STANDBY` in_standby()
 */
#define SZ_CRM_MON_NODE_STANDBY          SZF_CRM_MON" | grep -E \"standby|Online\" -A40 | grep -v standby | grep -v \".*node.*status.*\" | grep -v unmanaged | "SZF_HA_GREP" %s"
#define SZ_CRM_MON_FAILED_OP             SZF_CRM_MON" | grep \".*node.*status.*\" | "SZF_HA_GREP" %s"
#define SZ_CRM_MON_DRBD_UNMANAGE         SZF_CRM_MON" | grep unmanaged | grep "SZK_CRM_CONF_DRBD_PREFIX
#define SZ_CRM_MON_IP_UNMANAGE           SZF_CRM_MON" | grep unmanaged | grep IP"
#define SZ_CRM_MAINTENANCE_MODE_ON     SZF_CRM_CONFIGURE" property maintenance-mode=true"
#define SZ_CRM_MAINTENANCE_MODE_OFF    SZF_CRM_CONFIGURE" property maintenance-mode=false"
#define SZ_CRM_MON_UNMANAGE              SZF_CRM_MON" | grep unmanaged"
#define SZ_CRM_NODE_LIST               SZF_CRM_NODE_1" -l | "SZF_HA_GREP" %s"
#define SZ_CRM_MON_RESOURCE_NODE_EXIST   SZF_CRM_MON" | grep -E \"standby|Online\" | grep -v \".*node.*status.*\" | grep -v unmanaged | "SZF_HA_GREP" %s"

//#define SZ_CRM_CONFIGURE_STATUS        SZF_CRM_CONFIGURE" show | "SZF_HA_GREP" %s"

#define SZ_CRM_RESOURCE_MOVE      SZD_PREFIX_USR_BIN"crm resource migrate "SZ_DUMMY_START

#define SZ_CIBADMIN_QL                   SZF_CIBADMIN" -Ql "
#define SZ_CIBADMIN_QL_GREP              SZ_CIBADMIN_QL" | grep %s"

/*
cy36ha> cibadmin -Ql -o resources | grep -E '<primitive |<master '
  <primitive class="ocf" id="DUMMY_START" provider="synology" type="Dummy"/>
  <primitive class="ocf" id="DUMMY_END" provider="synology" type="Dummy"/>
  <primitive class="ocf" id="SERV" provider="synology" type="ocf_wrapper_serv">
  <primitive class="ocf" id="FS" provider="synology" type="ocf_wrapper_fs">
  <primitive class="ocf" id="IP" provider="synology" type="IPaddr2">
  <master id="CONF_SYNC">
    <primitive class="ocf" id="CONF_SYNC_" provider="synology" type="Confsync">
  <master id="CHECKPOINT_LAST">
    <primitive class="ocf" id="CHECKPOINT_LAST_" provider="synology" type="Checkpoint_last">
  <master id="INFO_SET">
    <primitive class="ocf" id="INFO_SET_" provider="synology" type="Infoset">
  <master id="DRBD">
    <primitive class="ocf" id="DRBD_" provider="synology" type="drbd">

cy36b> cibadmin -Ql -o resources | grep -E '<primitive |<master ' | wc -l
13
 */

#define SZ_CONF_ORDER_FS_IP        "FS:start IP"
// Order of CONF_SYNC:promote, SERV can't change. If we set SERV before CONF_SYNC, and then rsync daemon for network backup will not start,
// since rsync deamon for system configuration syncis alive at that time. (We can't run two rsync daemon at the same time)
#define SZ_CONF_ORDER_W_DRBD      "order "SZK_CRM_CONF_ORDER" mandatory: "SZ_DUMMY_START" "SZK_CRM_CONF_DRBD_PREFIX":promote "SZ_CONF_ORDER_FS_IP" CONF_SYNC:promote SERV INFO_SET:promote CHECKPOINT_LAST:promote "SZ_DUMMY_END
#define SZ_CONF_ORDER_WO_DRBD     "order "SZK_CRM_CONF_ORDER" mandatory: "SZ_DUMMY_START" "                                   SZ_CONF_ORDER_FS_IP" CONF_SYNC:promote SERV INFO_SET:promote CHECKPOINT_LAST:promote "SZ_DUMMY_END

#define SZ_CONF_COLOCATION_FS_IP   "FS IP"
// Order of CONF_SYNC:promote, SERV can't change. If we set SERV before CONF_SYNC, and then rsync daemon for network backup will not start,
// since rsync deamon for system configuration syncis alive at that time. (We can't run two rsync daemon at the same time)
#define SZ_CONF_COLOCATION_W_DRBD  "colocation "SZK_CRM_CONF_COLOCATION" INFINITY: "SZ_DUMMY_START" "SZK_CRM_CONF_DRBD_PREFIX":Master "SZ_CONF_COLOCATION_FS_IP" CONF_SYNC:Master SERV INFO_SET:Master CHECKPOINT_LAST:Master "SZ_DUMMY_END
#define SZ_CONF_COLOCATION_WO_DRBD "colocation "SZK_CRM_CONF_COLOCATION" INFINITY: "SZ_DUMMY_START" "                                  SZ_CONF_COLOCATION_FS_IP" CONF_SYNC:Master SERV INFO_SET:Master CHECKPOINT_LAST:Master "SZ_DUMMY_END

#define SZ_CRM_RESOURCE_TIMEOUT_S    "op start interval=\"0\" timeout=\""SZ_MAX_HA_SERV_START_FAST_SEC"s\" op stop interval=\"0\" timeout=\""SZ_MAX_HA_SERV_STOP_SEC"s\" op monitor interval=\"30s\" timeout=\"300s\" "
#define SZ_CRM_RESOURCE_TIMEOUT_L    "op start interval=\"0\" timeout=\""SZ_MAX_HA_SERV_START_SEC"s\" op stop interval=\"0\" timeout=\""SZ_MAX_HA_SERV_STOP_SEC"s\" op monitor interval=\"30s\" timeout=\"300s\" "
#define SZ_CRM_RESOURCE_MS_TIMEOUT_S "op monitor role=\"Master\" interval=\"29s\" timeout=\"300s\" op monitor role=\"Slave\" interval=\"31s\" timeout=\"300s\" \
 op start interval=\"0\" timeout=\"30s\" op stop interval=\"0\" timeout=\"30s\" op promote timeout=\"300s\" op demote timeout=\"300s\""
#define SZ_CRM_CHECKPOINT_LAST_MS_TIMEOUT_S "op monitor role=\"Master\" interval=\"9s\" timeout=\"300s\" op monitor role=\"Slave\" interval=\"11s\" timeout=\"300s\" \
 op start interval=\"0\" timeout=\"30s\" op stop interval=\"0\" timeout=\"30s\" op promote timeout=\"300s\" op demote timeout=\"300s\""
#define SZ_CRM_RESOURCE_MS_TIMEOUT_L "op monitor role=\"Master\" interval=\"29s\" timeout=\"300s\" op monitor role=\"Slave\" interval=\"31s\" timeout=\"300s\" \
 op start interval=\"0\" timeout=\"300s\" op stop interval=\"0\" timeout=\"300s\" op promote timeout=\"300s\" op demote timeout=\"300s\""
#define SZ_CRM_RESOURCE_MS_PARM    "meta master-max=1 master-node-max=1 clone-max=2 clone-node-max=1 notify=true"
#define SZ_CRM_RESOURCE_CLONE_PARM    "meta notify=true"
#define SZ_CRM_RESOURCE_TIMEOUT_PING  "op monitor interval=\"10s\" timeout=\"300s\""
#define SZ_CRM_RESOURCE_PING_PARAM    "params dampen=\"2s\" multiplier=\"1\" host_list=\"127.0.0.1\" name=\"ping_server\" timeout=\"2\""

//#define SZ_CRM_RESOURCE_CONSTRAINT_REMOVE0 SZF_CRM_RESOURCE" unmove DUMMY_START"
#define SZ_CRM_RESOURCE_CLI_STANDBY        "cli-standby-DUMMY_START"
#define ARGS_CRM_RESOURCE_CLI_STANDBY_REMOVE SZF_CRM, "configure", "delete", SZ_CRM_RESOURCE_CLI_STANDBY, NULL
#define SZ_CRM_RESOURCE_CLI_PREFER         "cli-prefer-DUMMY_START"
#define ARGS_CRM_RESOURCE_CLI_PREFER_REMOVE  SZF_CRM, "configure", "delete", SZ_CRM_RESOURCE_CLI_PREFER, NULL

#define SZ_CRM_RESOURCE_TARGET_ROLE                        "target-role"
#define ARGS_CRM_RESOURCE_TARGET_ROLE_REMOVE_INFO_SET        SZF_CRM_RESOURCE, "--resource", SZ_INFO_SET, "--delete-parameter", SZ_CRM_RESOURCE_TARGET_ROLE, "--meta", NULL
#define ARGS_CRM_RESOURCE_TARGET_ROLE_REMOVE_CONF_SYNC       SZF_CRM_RESOURCE, "--resource", SZ_CONF_SYNC, "--delete-parameter", SZ_CRM_RESOURCE_TARGET_ROLE, "--meta", NULL
#define ARGS_CRM_RESOURCE_TARGET_ROLE_REMOVE_CHECKPOINT_LAST SZF_CRM_RESOURCE, "--resource", SZ_CHECKPOINT_LAST, "--delete-parameter", SZ_CRM_RESOURCE_TARGET_ROLE, "--meta", NULL
#define ARGS_CRM_RESOURCE_TARGET_ROLE_REMOVE_DRBD            SZF_CRM_RESOURCE, "--resource", SZK_CRM_CONF_DRBD_PREFIX, "--delete-parameter", SZ_CRM_RESOURCE_TARGET_ROLE, "--meta", NULL
#define SZ_CIBADMIN_QL_TARGET_ROLE                         SZ_CIBADMIN_QL_GREP" | grep "SZ_CRM_RESOURCE_TARGET_ROLE
#define SZ_CRM_RESOURCE_IS_MANAGED                         "is-managed"
#define SZ_CIBADMIN_QL_IS_MANAGED                          SZ_CIBADMIN_QL_GREP" | grep "SZ_CRM_RESOURCE_IS_MANAGED
#define ARGS_CRM_RESOURCE_IS_MANAGED_REMOVE_DRBD             SZF_CRM_RESOURCE, "--resource", SZK_CRM_CONF_DRBD_PREFIX, "--delete-parameter", SZ_CRM_RESOURCE_IS_MANAGED, "--meta", NULL

// grep '\"%s\"' is used to grep hostname,
// sample input:
//     <rsc_location id="RULE_SYNC_DONE" node="cy36b" rsc="DUMMY_START" score="-INFINITY"/>
#define SZ_CIBADMIN_QL_CONSTRAINTS_CHECK                   SZ_CIBADMIN_QL" | grep %s | grep '\"%%s\"'"

#define SZ_CRM_MIGRATION_THRESHOLD "meta migration-threshold=1"

#endif /* MY_ABC_HERE */

#if 0
#undef LOG_DEBUG
#define LOG_DEBUG LOG_ERR
#else
#endif

#endif
