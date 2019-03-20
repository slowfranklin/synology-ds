/* cgmanager
 *
 * Copyright (C) 2010 Scott James Remnant <scott@netsplit.com>.
 *
 * This file was automatically generated; see the source for copying
 * conditions.
 */

#ifndef CGMANAGER_CGMANAGER_CLIENT_H
#define CGMANAGER_CGMANAGER_CLIENT_H

#include <dbus/dbus.h>

#include <stdint.h>

#include <nih/macros.h>

#include <nih-dbus/dbus_interface.h>
#include <nih-dbus/dbus_message.h>
#include <nih-dbus/dbus_pending_data.h>
#include <nih-dbus/dbus_proxy.h>

typedef struct cgmanager_list_keys_output_element {
	char *   item0;
	uint32_t item1;
	uint32_t item2;
	uint32_t item3;
} CgmanagerListKeysOutputElement;

typedef struct cgmanager_properties {
	int32_t api_version;
} CgmanagerProperties;

typedef void (*CgmanagerPingReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerGetPidCgroupScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerGetPidCgroupReply) (void *data, NihDBusMessage *message, const char *output);

typedef void (*CgmanagerGetPidCgroupAbsScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerGetPidCgroupAbsReply) (void *data, NihDBusMessage *message, const char *output);

typedef void (*CgmanagerCreateScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerCreateReply) (void *data, NihDBusMessage *message, int32_t existed);

typedef void (*CgmanagerChownScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerChownReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerChmodScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerChmodReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerMovePidScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerMovePidReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerMovePidAbsScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerMovePidAbsReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerGetValueScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerGetValueReply) (void *data, NihDBusMessage *message, const char *value);

typedef void (*CgmanagerSetValueScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerSetValueReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerRemoveScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerRemoveReply) (void *data, NihDBusMessage *message, int32_t existed);

typedef void (*CgmanagerGetTasksScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerGetTasksReply) (void *data, NihDBusMessage *message, const int32_t *output, size_t output_len);

typedef void (*CgmanagerGetTasksRecursiveScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerGetTasksRecursiveReply) (void *data, NihDBusMessage *message, const int32_t *output, size_t output_len);

typedef void (*CgmanagerListChildrenScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerListChildrenReply) (void *data, NihDBusMessage *message, char * const *output);

typedef void (*CgmanagerRemoveOnEmptyScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerRemoveOnEmptyReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerPruneScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerPruneReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerListControllersReply) (void *data, NihDBusMessage *message, char * const *output);

typedef void (*CgmanagerListKeysScmReply) (void *data, NihDBusMessage *message);

typedef void (*CgmanagerListKeysReply) (void *data, NihDBusMessage *message, CgmanagerListKeysOutputElement * const *output);

typedef void (*CgmanagerGetApiVersionReply) (void *data, NihDBusMessage *message, int32_t value);

typedef void (*CgmanagerGetAllReply) (void *data, NihDBusMessage *message, const CgmanagerProperties *properties);

NIH_BEGIN_EXTERN

extern const NihDBusInterface  cgmanager_org_linuxcontainers_cgmanager0_0;
extern const NihDBusInterface *cgmanager_interfaces[];

DBusPendingCall *cgmanager_ping                         (NihDBusProxy *proxy, int32_t junk, CgmanagerPingReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_ping_sync                    (const void *parent, NihDBusProxy *proxy, int32_t junk)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_get_pid_cgroup_scm           (NihDBusProxy *proxy, const char *controller, int sockfd, CgmanagerGetPidCgroupScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_get_pid_cgroup_scm_sync      (const void *parent, NihDBusProxy *proxy, const char *controller, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_get_pid_cgroup               (NihDBusProxy *proxy, const char *controller, int32_t pid, CgmanagerGetPidCgroupReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_get_pid_cgroup_sync          (const void *parent, NihDBusProxy *proxy, const char *controller, int32_t pid, char **output)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_get_pid_cgroup_abs_scm       (NihDBusProxy *proxy, const char *controller, int sockfd, CgmanagerGetPidCgroupAbsScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_get_pid_cgroup_abs_scm_sync  (const void *parent, NihDBusProxy *proxy, const char *controller, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_get_pid_cgroup_abs           (NihDBusProxy *proxy, const char *controller, int32_t pid, CgmanagerGetPidCgroupAbsReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_get_pid_cgroup_abs_sync      (const void *parent, NihDBusProxy *proxy, const char *controller, int32_t pid, char **output)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_create_scm                   (NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd, CgmanagerCreateScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_create_scm_sync              (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_create                       (NihDBusProxy *proxy, const char *controller, const char *cgroup, CgmanagerCreateReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_create_sync                  (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t *existed)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_chown_scm                    (NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd, CgmanagerChownScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_chown_scm_sync               (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_chown                        (NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t uid, int32_t gid, CgmanagerChownReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_chown_sync                   (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t uid, int32_t gid)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_chmod_scm                    (NihDBusProxy *proxy, const char *controller, const char *cgroup, const char *file, int32_t mode, int sockfd, CgmanagerChmodScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_chmod_scm_sync               (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, const char *file, int32_t mode, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_chmod                        (NihDBusProxy *proxy, const char *controller, const char *cgroup, const char *file, int32_t mode, CgmanagerChmodReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_chmod_sync                   (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, const char *file, int32_t mode)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_move_pid_scm                 (NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd, CgmanagerMovePidScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_move_pid_scm_sync            (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_move_pid                     (NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t pid, CgmanagerMovePidReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_move_pid_sync                (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t pid)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_move_pid_abs_scm             (NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd, CgmanagerMovePidAbsScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_move_pid_abs_scm_sync        (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_move_pid_abs                 (NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t pid, CgmanagerMovePidAbsReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_move_pid_abs_sync            (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t pid)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_get_value_scm                (NihDBusProxy *proxy, const char *controller, const char *cgroup, const char *key, int sockfd, CgmanagerGetValueScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_get_value_scm_sync           (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, const char *key, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_get_value                    (NihDBusProxy *proxy, const char *controller, const char *cgroup, const char *key, CgmanagerGetValueReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_get_value_sync               (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, const char *key, char **value)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_set_value_scm                (NihDBusProxy *proxy, const char *controller, const char *cgroup, const char *key, const char *value, int sockfd, CgmanagerSetValueScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_set_value_scm_sync           (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, const char *key, const char *value, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_set_value                    (NihDBusProxy *proxy, const char *controller, const char *cgroup, const char *key, const char *value, CgmanagerSetValueReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_set_value_sync               (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, const char *key, const char *value)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_remove_scm                   (NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t recursive, int sockfd, CgmanagerRemoveScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_remove_scm_sync              (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t recursive, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_remove                       (NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t recursive, CgmanagerRemoveReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_remove_sync                  (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t recursive, int32_t *existed)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_get_tasks_scm                (NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd, CgmanagerGetTasksScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_get_tasks_scm_sync           (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_get_tasks                    (NihDBusProxy *proxy, const char *controller, const char *cgroup, CgmanagerGetTasksReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_get_tasks_sync               (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t **output, size_t *output_len)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_get_tasks_recursive_scm      (NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd, CgmanagerGetTasksRecursiveScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_get_tasks_recursive_scm_sync (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_get_tasks_recursive          (NihDBusProxy *proxy, const char *controller, const char *cgroup, CgmanagerGetTasksRecursiveReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_get_tasks_recursive_sync     (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int32_t **output, size_t *output_len)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_list_children_scm            (NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd, CgmanagerListChildrenScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_list_children_scm_sync       (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_list_children                (NihDBusProxy *proxy, const char *controller, const char *cgroup, CgmanagerListChildrenReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_list_children_sync           (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, char ***output)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_remove_on_empty_scm          (NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd, CgmanagerRemoveOnEmptyScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_remove_on_empty_scm_sync     (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_remove_on_empty              (NihDBusProxy *proxy, const char *controller, const char *cgroup, CgmanagerRemoveOnEmptyReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_remove_on_empty_sync         (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_prune_scm                    (NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd, CgmanagerPruneScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_prune_scm_sync               (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_prune                        (NihDBusProxy *proxy, const char *controller, const char *cgroup, CgmanagerPruneReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_prune_sync                   (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_list_controllers             (NihDBusProxy *proxy, CgmanagerListControllersReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_list_controllers_sync        (const void *parent, NihDBusProxy *proxy, char ***output)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_list_keys_scm                (NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd, CgmanagerListKeysScmReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_list_keys_scm_sync           (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, int sockfd)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_list_keys                    (NihDBusProxy *proxy, const char *controller, const char *cgroup, CgmanagerListKeysReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_list_keys_sync               (const void *parent, NihDBusProxy *proxy, const char *controller, const char *cgroup, CgmanagerListKeysOutputElement ***output)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_get_api_version              (NihDBusProxy *proxy, CgmanagerGetApiVersionReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_get_api_version_sync         (const void *parent, NihDBusProxy *proxy, int32_t *value)
	__attribute__ ((warn_unused_result));
DBusPendingCall *cgmanager_get_all                      (NihDBusProxy *proxy, CgmanagerGetAllReply handler, NihDBusErrorHandler error_handler, void *data, int timeout)
	__attribute__ ((warn_unused_result));
int              cgmanager_get_all_sync                 (const void *parent, NihDBusProxy *proxy, CgmanagerProperties **properties)
	__attribute__ ((warn_unused_result));

NIH_END_EXTERN

#endif /* CGMANAGER_CGMANAGER_CLIENT_H */
