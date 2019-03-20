
/* Set the task to run once (i.e. no repeat in date). */
SYNO_SCHED_ENUM_SETTER_FUNC(type, SYNO_SCHED_DATE_REPEAT_TYPE_ONCE, Once)

/* Set the task to run daily. */
SYNO_SCHED_ENUM_SETTER_FUNC(type, SYNO_SCHED_DATE_REPEAT_TYPE_DAILY, Daily)

/* Set the task to run weekly. */
SYNO_SCHED_ENUM_SETTER_FUNC(type, SYNO_SCHED_DATE_REPEAT_TYPE_WEEKLY, Weekly)

/* Set the task to run monthly. */
SYNO_SCHED_ENUM_SETTER_FUNC(type, SYNO_SCHED_DATE_REPEAT_TYPE_MONTHLY, Monthly)

/* Set the task to run yearly. */
SYNO_SCHED_ENUM_SETTER_FUNC(type, SYNO_SCHED_DATE_REPEAT_TYPE_YEARLY, Yearly)

/* Set the task to run half-yearly. */
SYNO_SCHED_ENUM_SETTER_FUNC(type, SYNO_SCHED_DATE_REPEAT_TYPE_HALFYEARLY, Halfyearly)

/* Set state of the task. 'blEnable = TRUE' to be enabled, otherwise to be disabled. */
SYNO_SCHED_BOOL_SETTER_FUNC(state, SYNO_SCHED_TASK_STATE_ENABLED, SYNO_SCHED_TASK_STATE_DISABLED, State)

/* Set the task to be listable on task scheduler UI if 'blEnable = TRUE', otherwise to be non listable. */
SYNO_SCHED_BOOL_SETTER_FUNC(blListable, 1, 0, Listable)

/* Set the name of the task to be editable in the edit dialog opened from task scheduler UI if 'blEnable = TRUE', otherwise to be non editable. */
SYNO_SCHED_BOOL_SETTER_FUNC(blCanEditName, 1, 0, CanEditName)

/* Set the owner of the task to be editable in the edit dialog opened from task scheduler UI if 'blEnable = TRUE', otherwise to be non editable. */
SYNO_SCHED_BOOL_SETTER_FUNC(blCanEditOwner, 1, 0, CanEditOwner)

/* Set to TRUE means the task formpanel will be merged into same tab page with basic information in the edit dialog opened from task scheduler UI. 
   Otherwise, the formpanel will be embeded in a stand-alone tab page. */
SYNO_SCHED_BOOL_SETTER_FUNC(blSimpleEditForm, 1, 0, SimpleEditForm)

/* Set to TRUE means the task can be run when other same application tasks are running. */
SYNO_SCHED_BOOL_SETTER_FUNC(blCanRunAppSameTime, 1, 0, CanRunAppSameTime)

/* Set to TRUE means the task can be run when another same task task is running. */
SYNO_SCHED_BOOL_SETTER_FUNC(blCanRunTaskSameTime, 1, 0, CanRunTaskSameTime)

/* Set to TRUE means the task can be run by pressing 'run' button in task scheduler UI. */
SYNO_SCHED_BOOL_SETTER_FUNC(blCanRunFromUI, 1, 0, CanRunFromUI)

/* Set to TRUE means the task can be deleted by pressing 'delete' button in task scheduler UI. */
SYNO_SCHED_BOOL_SETTER_FUNC(blCanDeleteFromUI, 1, 0, CanDeleteFromUI)

/* Set to TRUE means the task can be edited by pressing 'edit' button in task scheduler UI. */
SYNO_SCHED_BOOL_SETTER_FUNC(blCanEditFromUI, 1, 0, CanEditFromUI)

/* Set the owner uid of the task. */
SYNO_SCHED_VAL_SETTER_FUNC(unsigned, owner, Owner)

/* Set the A.D. year of start date for the task that runs no repeat, monthly or yearly. */
SYNO_SCHED_VAL_SETTER_FUNC(unsigned, start_year, StartYear)

/* Set the month (1 ~ 12) of start date for the task that runs no repeat, monthly or yearly. */
SYNO_SCHED_VAL_SETTER_FUNC(unsigned, start_month, StartMonth)

/* Set the day (1 ~ 31) of start date for the task that runs no repeat, monthly or yearly. */
SYNO_SCHED_VAL_SETTER_FUNC(unsigned, start_day, StartDay)

/* Set the hour (0 ~ 23) of starting run time. */
SYNO_SCHED_VAL_SETTER_FUNC(unsigned, run_hour, RunHour)

/* Set the minute (0 ~ 23) of starting run time. */
SYNO_SCHED_VAL_SETTER_FUNC(unsigned, run_min, RunMin)

SYNO_SCHED_STR_SETTER_FUNC(repeat_hour_store_config, RepeatHourStoreConfig)
SYNO_SCHED_STR_SETTER_FUNC(repeat_min_store_config, RepeatMinStoreConfig)

/* Set the repeat period (in hour) on run day, 0 means no repeat. */
SYNO_SCHED_VAL_SETTER_FUNC(unsigned, repeat_hour, RepeatHour)

/* Set the repeat period (in min) on run day, 0 means no repeat. */
SYNO_SCHED_VAL_SETTER_FUNC(unsigned, repeat_min, RepeatMin)

/* Set the last run hour on run day. */
SYNO_SCHED_VAL_SETTER_FUNC(unsigned, last_work_hour, LastWorkHour)

/* Set the task id. */
SYNO_SCHED_VAL_SETTER_FUNC(long, id, ID)

/* Set the configuration backend of the task, -2 is for BACKEND_SYNOSCHEDULE, -3 is for BACKEND_SYNOAUTOPOWER. */
SYNO_SCHED_VAL_SETTER_FUNC(long, backend, Backend)

/* Set the dialog that will be opened from task scheduler UI when editing. Empty string means the task is non-editable. */
SYNO_SCHED_STR_SETTER_FUNC(szEditDialog, EditDialog)

/* Set the formpanel that will be embeded in the edit dialog opened from task scheduler UI. */
SYNO_SCHED_STR_SETTER_FUNC(szEditForm, EditForm)

/* Set the task name. */
SYNO_SCHED_STR_SETTER_FUNC(szName, Name)

/* Set the arguments of application settings. */
SYNO_SCHED_STR_SETTER_FUNC(szAppArgs, AppArgs)

/* Set the application name (might contains multilingual string with '#section:key#' pairs) that will show on task lists in task scheduler UI. */
SYNO_SCHED_STR_SETTER_FUNC(szAppName, AppName)

/* Set the application identity, e.g., SYNO.SDS.TaskScheduler.Beep. */
SYNO_SCHED_STR_SETTER_FUNC(szApp, App)

/* Set the weekday indicator if the task runs weekly. The string contains 7 characters in '0'(non-selected) or '1'(selected) in (Sun, Mon, Tue, ..., Sat) order. */
SYNO_SCHED_STR_SETTER_FUNC(week, Week)

/* Set the execution command of the task. */
SYNO_SCHED_STR_SETTER_FUNC(szCmd, Command)

/* Set the action description (might contains multilingual string with '#section:key#' pairs) that will show on task lists in task scheduler UI. */
SYNO_SCHED_STR_SETTER_FUNC(szAction, Action)
