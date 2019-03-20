/* sched_task_convert_from_json.cpp */
/* Convert json["basic"] to values in task struct */
bool SYNOSchedTaskConvertFromJson_Basic(const Json::Value &json, SYNO_SCHED_TASK &task);
/* Convert json["schedule"] to values in task struct */
bool SYNOSchedTaskConvertFromJson_Schedule(const Json::Value &json, SYNO_SCHED_TASK &task);
/* sched_task_convert_to_json.cpp */
/* Generate json["basic"] from task struct */
bool SYNOSchedTaskConvertToJson_Basic(const SYNO_SCHED_TASK &task, Json::Value &json);
/* Generate json["schedule"] from task struct */
bool SYNOSchedTaskConvertToJson_Schedule(const SYNO_SCHED_TASK &task, Json::Value &json);
/* Get run status */
int SYNOSchedTaskGetRunStatus(const int iTaskID, Json::Value &json);

/**
 * The following functions SYNOSchedTask... work as same as SYNOSchedCTask...,
 * but they provide more intuitive interfaces for use in C++.
 */
/**** Getter functions ****/
#define SYNO_SCHED_BOOL_GETTER_FUNC(var, val, suffix) \
bool SYNOSchedTaskIs##suffix(const SYNO_SCHED_TASK &task);

#define SYNO_SCHED_VAL_GETTER_FUNC(valType, var, suffix) \
valType SYNOSchedTaskGet##suffix(const SYNO_SCHED_TASK &task);

#define SYNO_SCHED_STR_GETTER_FUNC(var, suffix) SYNO_SCHED_VAL_GETTER_FUNC(std::string, var, suffix)

#include "synoschedgetter.h"

#undef SYNO_SCHED_BOOL_GETTER_FUNC
#undef SYNO_SCHED_VAL_GETTER_FUNC
#undef SYNO_SCHED_STR_GETTER_FUNC
