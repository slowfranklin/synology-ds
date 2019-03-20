
#ifdef __cplusplus
extern "C" {
#endif

/* sched_task_alloc.c */
SYNO_SCHED_TASK * SYNOSchedTaskAlloc();
int SYNOSchedTaskFree(SYNO_SCHED_TASK *pTask);
/* sched_task_load.c */
int SYNOSchedTaskLoad(long id, SYNO_SCHED_TASK *pTask);
/* sched_task_save.c */
int SYNOSchedTaskSave(SYNO_SCHED_TASK *pTask);
/* sched_task_remove.c */
int SYNOSchedTaskRemove(long id);
/* sched_task_run.c */
int SYNOSchedTaskRun(long id, BOOL blCheckTime, BOOL blCheckStatus);
/* sched_task_list_get.c */
int SYNOSchedTaskListGet(SYNO_SCHED_TASK_LIST *pTaskList, BOOL (*isKeepTask)(SYNO_SCHED_TASK *pTask));
/* sched_task_list_sort.c */
int SYNOSchedTaskListSort(SYNO_SCHED_TASK_LIST *pTaskList, const char *szKey, BOOL blASC);
SYNO_SCHED_TASK * SYNOSchedTaskNext(const SYNO_SCHED_TASK *pTask);
/* sched_task_list_free.c */
void SYNOSchedTaskListFree(SYNO_SCHED_TASK_LIST *pTaskList);
/* sched_date.c */
int SYNOSchedNextTriggerTime(SYNO_SCHED_TASK *pTask);
int SYNOSchedNextRunEstimate(const SYNO_SCHED_TASK *pTask, time_t now, SYNO_SCHED_DATE *pDate);
/* sched_task_convert_to_json_string.cpp */
int SYNOSchedTaskConvertToJson(const SYNO_SCHED_TASK *pTask, char *szJson, size_t nJson);
int SYNOSchedTaskConvertToJsonById(long id, char *szJson, size_t nJson);
BOOL SYNOSchedTaskIsBuildInApp(const SYNO_SCHED_TASK *pTask);
/* sched_task_save_from_json_string.cpp */
int SYNOSchedTaskSaveFromJson(const char *szJson, BOOL blTryOverwrite);

/**** Getter functions ****/
#define SYNO_SCHED_BOOL_GETTER_FUNC(var, val, suffix) \
int SYNOSchedCTaskIs##suffix(BOOL *pVal, const SYNO_SCHED_TASK *pTask);

#define SYNO_SCHED_VAL_GETTER_FUNC(valType, var, suffix) \
int SYNOSchedCTaskGet##suffix(valType *pVal, const SYNO_SCHED_TASK *pTask);

#define SYNO_SCHED_STR_GETTER_FUNC(var, suffix) \
int SYNOSchedCTaskGet##suffix(char *szBuf, size_t cbBuf, const SYNO_SCHED_TASK *pTask);
#include "synoschedgetter.h"

#undef SYNO_SCHED_BOOL_GETTER_FUNC
#undef SYNO_SCHED_VAL_GETTER_FUNC
#undef SYNO_SCHED_STR_GETTER_FUNC

/**** Setter functions ****/
#define SYNO_SCHED_ENUM_SETTER_FUNC(var, enum_val, suffix) \
int SYNOSchedCTaskSet##suffix(SYNO_SCHED_TASK *pTask, BOOL blEnable);

#define SYNO_SCHED_BOOL_SETTER_FUNC(var, enable_val, disable_val, suffix) \
int SYNOSchedCTaskSet##suffix(SYNO_SCHED_TASK *pTask, BOOL blEnable);

#define SYNO_SCHED_VAL_SETTER_FUNC(valType, var, suffix) \
int SYNOSchedCTaskSet##suffix(SYNO_SCHED_TASK *pTask, valType val);

#define SYNO_SCHED_STR_SETTER_FUNC(var, suffix) \
int SYNOSchedCTaskSet##suffix(SYNO_SCHED_TASK *pTask, const char *szVal);
#include "synoschedsetter.h"

#undef SYNO_SCHED_ENUM_SETTER_FUNC
#undef SYNO_SCHED_BOOL_SETTER_FUNC
#undef SYNO_SCHED_VAL_SETTER_FUNC
#undef SYNO_SCHED_STR_SETTER_FUNC

#ifdef __cplusplus
};
#endif
