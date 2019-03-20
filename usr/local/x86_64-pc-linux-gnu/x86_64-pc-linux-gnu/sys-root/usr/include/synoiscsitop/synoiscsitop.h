#ifndef SYNOISCSITOP_H
#define SYNOISCSITOP_H

#include <json/value.h>

namespace SYNOiSCSITOP {

/**
 * Open iscsi iostat of all loaded LUNs in configfs,
 * and collect there throughput, latency, queue info and so on.
 * It will collect and return these data in a json format.
 *
 * @brief Get iscsitop info from configfs with json format.
 * @param[out] all iscsi lun performance info in a json format.
 * @retval true on success.
 * @retval false on error.
 * @exception no exception throw in this function.
 * @grantable Y
 * @user root
 * @apparmor abstractions/synoiscsitop
 */
bool GetSynoiscsitopInfo(Json::Value &resp);

} /* SYNOiSCSITOP */

#endif /*SYNOISCSITOP_H*/
