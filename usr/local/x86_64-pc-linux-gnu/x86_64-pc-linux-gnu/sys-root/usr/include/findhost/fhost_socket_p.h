#include <synocore/hash.h>
/* socket_broadcast_udp_by_interface.c */
int BroadcastUdpByInterface(unsigned char *stPkt, int Size, struct in_addr *addr);
/* socket_fhost_dump_host.c */
int SYNOFHOSTDumpHost(void);
/* socket_fhost_get2hash.c */
int SYNOFHOSTGet2Hash(PSLIBSZHASH *ppshHost);
/* socket_fhost_send_broadcast_udp.c */
int ErrFHOSTSendBroadcastUdp(unsigned char *stPkt, int size);
/* socket_fhost_send_query_pkt.c */
int ErrFHOSTSendQueryPkt(void);
