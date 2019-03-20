/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef OUTPUT_FUNCTIONS_H
#define OUTPUT_FUNCTIONS_H

#include <stdio.h>
#include <syslog.h>
#include <synocore/synoglobal.h>

#ifdef DEBUG
#define DEBUG_MSG(x, args...) printf("[Debug]\t" x "\n", ##args)
#else
#define DEBUG_MSG(x, args...) 
#endif

#define ERROR_MSG_TOOL(x, args...) fprintf(stderr, "[Error]\t" x "\tin file: %s, line: %3d\n", ##args, __FILE__, __LINE__)
#define NOTICE_MSG_TOOL(x, args...) fprintf(stderr, x "\n", ##args)
#define ERROR_MSG(x, args...) SYSLOG(LOG_ERR, x , ##args)
#define PRINT_MSG(x, args...) printf(x, ##args)

// XXX: ERROR_MSG_EXIT

#endif /* OUTPUT_FUNCTIONS_H */
