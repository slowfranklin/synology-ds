// Copyright (c) 2000-2008 Synology Inc. All rights reserved.
#ifndef SYNO_FHOST_CONN_H
#define SYNO_FHOST_CONN_H

#ifdef  __cplusplus
extern "C" {
#endif

/* select timeout*/
#define FHOST_SELECT_TIMEOUT 5	/*seconds */

/* port */
#define FHOST_PORT_RECV 9999
#define FHOST_PORT_SEND 1234

/** 
 * The common connection options for TCP/UDP.
 */
struct FHOSTCONN {
	/**
	 * The string that contains TCP/UDP destination IP.  This will be used
	 * in client functions but ignored by server functions.  If this
	 * connection is tended to broadcast, this string should be
	 * 255.255.255.255.
	 */
	char        szDestIP[FHOST_IPADDR_LEN];
	/**
	 * The TCP/UDP destination port in client function, or to be binded in
	 * server function, host endian.
	 */
	int         iPort;
	/**
	 * The timeout seconds.  May be used in select().
	 */
	int         iTimeoutSec;
	/**
	 * The timeout microseconds.  May be used in select().
	 */
	int         iTimeoutMSec;
	/**
	 * The callback function that returns 1 when this UDP/TCP server
	 * should be terminated.  May be NULL.  When this field is NULL, the
	 * UDP/TCP server will run forever.
	 */
	FUNCISCANCEL pfuncIsCancel;
	/**
	 * The group of callback function that receives error log or debug log
	 * mssages.  May be NULL for each field.
	 */
	FHOSTLOG   *pfunLogOp;
};

/**
 * The operations when receiving NASINFO packets are needed.
 */
struct FHOSTRECV {
	/**
	 * The callback function that locks mutex when running in multi-thread
	 * environment.  May be NULL.
	 */
	FUNCLOCKER  pfuncLocker;
	/**
	 * The callback function that filters incoming NASINFO packets. When
	 * this fuction return 1, this packet will be added by calling
	 * FHOSTRECV::pfuncAdd(). Otherwise, the packet will be discarded.
	 * May be NULL.  When this field is NULL, accepts all packets.
	 */
	FUNCISACCEPT pfuncIsAccept;
	/**
	 * The callback function that updates incoming NASINFO packets to
	 * client.  Should not be NULL.
	 */
	FUNCADD     pfuncAdd;
	/**
	 * The callback function that updates receiving timeout progress.  May
	 * be NULL.
	 */
	FUNCUPDATEPROG pfuncUpdateProgress;
};

/**
 * The operations when sending NASINFO packets are needed.
 */
struct FHOSTSEND {
	NASINFO    *pnasInfo;
	int         nPktID;
	FHOST_PKT_ID rgPktID[PKT_ID_MAX];
};

#ifdef  __cplusplus
}
#endif
#endif // SYNO_FHOST_CONN_H
