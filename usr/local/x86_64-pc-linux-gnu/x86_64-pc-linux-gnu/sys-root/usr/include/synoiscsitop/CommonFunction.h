#ifndef SYNOISCSITOP_COMMON_FUNCTION_H
#define SYNOISCSITOP_COMMON_FUNCTION_H

#include <string>
#include <json/value.h>
#include <synoiscsiep/lun.h>
#include <synoiscsiep/iscsi.h>
#include "synoiscsitop/target_core_iostat.h"

#define SZF_TCM_HBA_EPIO0_CFS                  "epio_0"
#define SZF_TCM_HBA_EPIO0                      ISCSI_CONFIGFS_CORE_ROOT_PATH "/" SZF_TCM_HBA_EPIO0_CFS

bool OpenIostat(const char *lunPath);
bool ReadInfo(const char *path, char *result, int maxSize);
bool LunInfoParser(const std::string &lunPath, Json::Value &output);
bool GetLunIostatInfo(const char *lunPath, io_stat_report_t *lunInfo);

#endif /* SYNOISCSITOP_COMMON_FUNCTION_H */
