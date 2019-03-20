
/* Check if the task runs once (i.e. no repeat in date). */
SYNO_SCHED_BOOL_GETTER_FUNC(type, SYNO_SCHED_DATE_REPEAT_TYPE_ONCE, Once)

/* Check if the task runs daily. */
SYNO_SCHED_BOOL_GETTER_FUNC(type, SYNO_SCHED_DATE_REPEAT_TYPE_DAILY, Daily)

/* Check if the task runs weekly. */
SYNO_SCHED_BOOL_GETTER_FUNC(type, SYNO_SCHED_DATE_REPEAT_TYPE_WEEKLY, Weekly)

/* Check if the task runs monthly. */
SYNO_SCHED_BOOL_GETTER_FUNC(type, SYNO_SCHED_DATE_REPEAT_TYPE_MONTHLY, Monthly)

/* Check if the task runs yearly. */
SYNO_SCHED_BOOL_GETTER_FUNC(type, SYNO_SCHED_DATE_REPEAT_TYPE_YEARLY, Yearly)

/* Check if the task runs half-yearly. */
SYNO_SCHED_BOOL_GETTER_FUNC(type, SYNO_SCHED_DATE_REPEAT_TYPE_HALFYEARLY, Halfyearly)

/* Check if the task is a new task (i.e., id = -1). */
SYNO_SCHED_BOOL_GETTER_FUNC(id, -1, New)

/* Check if state of the task is enabled. */
SYNO_SCHED_BOOL_GETTER_FUNC(state, SYNO_SCHED_TASK_STATE_ENABLED, Enabled)

/* Check if the task can be listed in task scheduler UI. */
SYNO_SCHED_BOOL_GETTER_FUNC(blListable, 1, Listable)

/* Check if the task name is editable in the edit dialog opened from task scheduler UI. */
SYNO_SCHED_BOOL_GETTER_FUNC(blCanEditName, 1, CanEditName)

/* Check if the task owner is editable in the edit dialog opened from task scheduler UI. */
SYNO_SCHED_BOOL_GETTER_FUNC(blCanEditOwner, 1, CanEditOwner)

/* Check if the task formpanel will be merged into same tab page with basic information in the edit dialog opened from task scheduler UI. */
SYNO_SCHED_BOOL_GETTER_FUNC(blSimpleEditForm, 1, SimpleEditForm)

/* Check if the task can be run when other same application tasks are running. */
SYNO_SCHED_BOOL_GETTER_FUNC(blCanRunAppSameTime, 1, CanRunAppSameTime)

/* Check if the task can be run when another same task is running. */
SYNO_SCHED_BOOL_GETTER_FUNC(blCanRunTaskSameTime, 1, CanRunTaskSameTime)

/* Check if the task can be run by pressing 'run' button in task scheduler UI. */
SYNO_SCHED_BOOL_GETTER_FUNC(blCanRunFromUI, 1, CanRunFromUI)

/* Check if the task can be deleted by pressing 'delete' button in task scheduler UI. */
SYNO_SCHED_BOOL_GETTER_FUNC(blCanDeleteFromUI, 1, CanDeleteFromUI)

/* Check if the task can be edited by pressing 'edit' button in task scheduler UI. */
SYNO_SCHED_BOOL_GETTER_FUNC(blCanEditFromUI, 1, CanEditFromUI)

/* Get the owner uid of the task. */
SYNO_SCHED_VAL_GETTER_FUNC(unsigned, owner, Owner)

/* Get the A.D. year of start date if the task runs no repeat, monthly or yearly. */
SYNO_SCHED_VAL_GETTER_FUNC(unsigned, start_year, StartYear)

/* Get the month (1 ~ 12) of start date if the task runs no repeat, monthly or yearly. */
SYNO_SCHED_VAL_GETTER_FUNC(unsigned, start_month, StartMonth)

/* Get the day (1 ~ 31) of start date if the task runs no repeat, monthly or yearly. */
SYNO_SCHED_VAL_GETTER_FUNC(unsigned, start_day, StartDay)

/* Get the hour (0 ~ 23) of starting run time. */
SYNO_SCHED_VAL_GETTER_FUNC(unsigned, run_hour, RunHour)

/* Get the minute (0 ~ 23) of starting run time. */
SYNO_SCHED_VAL_GETTER_FUNC(unsigned, run_min, RunMin)

SYNO_SCHED_STR_GETTER_FUNC(repeat_hour_store_config, RepeatHourStoreConfig)
SYNO_SCHED_STR_GETTER_FUNC(repeat_min_store_config, RepeatMinStoreConfig)

/* Get the repeat period (in hour) on run day, 0 means no repeat. */
SYNO_SCHED_VAL_GETTER_FUNC(unsigned, repeat_hour, RepeatHour)

/* Get the repeat period (in min) on run day, 0 means no repeat. */
SYNO_SCHED_VAL_GETTER_FUNC(unsigned, repeat_min, RepeatMin)

/* Get the last run hour on run day. */
SYNO_SCHED_VAL_GETTER_FUNC(unsigned, last_work_hour, LastWorkHour)

/* Get the task id. */
SYNO_SCHED_VAL_GETTER_FUNC(long, id, ID)

/* Get the configuration backend of the task, -2 is for BACKEND_SYNOSCHEDULE, -3 is for BACKEND_SYNOAUTOPOWER. */
SYNO_SCHED_VAL_GETTER_FUNC(long, backend, Backend)

/* Get the task name. */
SYNO_SCHED_STR_GETTER_FUNC(szName, Name)

/* Get the arguments of application settings. */
SYNO_SCHED_STR_GETTER_FUNC(szAppArgs, AppArgs)

/* Get the application name (might contains multilingual string with '#section:key#' pairs) that will show on task lists in task scheduler UI. */
SYNO_SCHED_STR_GETTER_FUNC(szAppName, AppName)

/* Get the formpanel that will be embeded in the edit dialog opened from task scheduler UI. */
SYNO_SCHED_STR_GETTER_FUNC(szEditForm, EditForm)

/* Get the dialog that will be opened from task scheduler UI when editing. Empty string means the task is non-editable. */
SYNO_SCHED_STR_GETTER_FUNC(szEditDialog, EditDialog)

/* Get the application identity, e.g., SYNO.SDS.TaskScheduler.Beep. */
SYNO_SCHED_STR_GETTER_FUNC(szApp, App)

/* Get the weekday indicator if the task runs weekly. The string contains 7 characters in '0'(non-selected) or '1'(selected) in (Sun, Mon, Tue, ..., Sat) order. */
SYNO_SCHED_STR_GETTER_FUNC(week, Week)

/* Get the execution command of the task. */
SYNO_SCHED_STR_GETTER_FUNC(szCmd, Command)

/* Get the action description (might contains multilingual string with '#section:key#' pairs) that will show on task lists in task scheduler UI. */
SYNO_SCHED_STR_GETTER_FUNC(szAction, Action)

/* Get the next run time of the task that will show on task lists in task scheduler UI. */
SYNO_SCHED_STR_GETTER_FUNC(szNextTriggerTime, NextTriggerTime)
