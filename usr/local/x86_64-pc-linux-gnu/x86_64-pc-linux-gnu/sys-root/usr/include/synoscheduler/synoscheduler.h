// Copyright (c) 2000-2012 Synology Inc. All rights reserved.
#ifndef __SYNO_SCHEDULER_H__
#define __SYNO_SCHEDULER_H__
#include<sys/types.h>
#include<synocore/synotype.h>
#include<time.h>

#define BACKEND_SYNOSCHEDULE -2
#define BACKEND_SYNOAUTOPOWER -3
#define MAX_CMD_SIZE 16384

enum SYNO_SCHED_TASK_STATE {SYNO_SCHED_TASK_STATE_DISABLED, SYNO_SCHED_TASK_STATE_ENABLED, SYNO_SCHED_TASK_STATE_NOTEXIST};
enum SYNO_SCHED_DATE_REPEAT_TYPE {SYNO_SCHED_DATE_REPEAT_TYPE_ONCE = 0, SYNO_SCHED_DATE_REPEAT_TYPE_DAILY, \
		SYNO_SCHED_DATE_REPEAT_TYPE_WEEKLY, SYNO_SCHED_DATE_REPEAT_TYPE_MONTHLY, \
		SYNO_SCHED_DATE_REPEAT_TYPE_YEARLY, SYNO_SCHED_DATE_REPEAT_TYPE_HALFYEARLY};
/********************************** Task File **********************************/

/*typedef */struct _tag_syno_sched_task_ {
	struct _tag_syno_sched_task_ *pNext;
	long backend;								// backend
	/* Basic */
	long id;									// index
	uid_t owner;								// owner uid
	char szName[4096];							// task name, max len = 4095 in spec
	/* Schedule */
	char szNextTriggerTime[1024];				// next trigger time
	enum SYNO_SCHED_TASK_STATE state;			// state of the entry
	enum SYNO_SCHED_DATE_REPEAT_TYPE type;		// date repeat type
	char week[8];								// 0(Sun), 1(Mon), 2(Tue), 3(Wed), 4(Thr), 5(Fri), 6(Sat)
	unsigned start_year;						// start year 
	unsigned start_month;						// start month
	unsigned start_day;							// start day
	unsigned run_hour;							// run hour
	unsigned run_min;							// run minute
	unsigned repeat_hour;						// repeat period (in hour) in one day at most 23
	unsigned repeat_min;						// repeat period (in min) in one day
	char repeat_hour_store_config[4096];		
	char repeat_min_store_config[4096];			
	unsigned last_work_hour;					// end hour. available when repeat_hour > 0 || repeat_min > 0
	/* Customized Settings */
	/* UI behavior */
	char szEditDialog[1024];					// edit dialog
	char szEditForm[1024];						// edit form
	long blSimpleEditForm;						// embed app setting panel in basic tab
	long blListable;							// listable on UI
	long blCanEditName;							// if user can edit task name
	long blCanEditOwner;						// if user can edit owner
	long blCanRunAppSameTime;					// if user can run app at the same time
	long blCanRunTaskSameTime;					// if user can run task at the same time
	long blCanRunFromUI;						// if user can run task from UI
	long blCanDeleteFromUI;						// if user can delete task from UI
	long blCanEditFromUI;						// if user can edit task from UI
	/* Task data */
	char szApp[1024];							// application
	char szAppName[1024];						// application name
	char szAppArgs[8192];						// arguements for application
	char szAction[1024];						// action
	char szCmd[MAX_CMD_SIZE];					// command or script for execution
};// SYNO_SCHED_TASK, *SYNO_SCHED_TASK_LIST;
typedef struct _tag_syno_sched_task_ SYNO_SCHED_TASK, *SYNO_SCHED_TASK_LIST;

typedef struct _tag_syno_sched_date_ {
	unsigned year; // AD year, e.g., 2014
	unsigned month; // 1 ~ 12
	unsigned day; // 1 ~ 31
	unsigned wday; // 0(Sun), 1(Mon), 2(Tue), 3(Wed), 4(Thu), 5(Fri), 6(Sat)
	unsigned hour; // 0 ~ 23
	unsigned min; // 0 ~ 59
} SYNO_SCHED_DATE;
#include "synoscheduler_p.h"
#endif // __SYNO_SCHEDULER_H__
