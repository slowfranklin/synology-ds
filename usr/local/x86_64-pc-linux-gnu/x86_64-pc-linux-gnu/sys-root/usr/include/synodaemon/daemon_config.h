/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef _SYNO_DAEMON_DAEMON_CONFIG_H_
#define _SYNO_DAEMON_DAEMON_CONFIG_H_

#include <time.h>
#include <memory>
#include <json/value.h>
#include "std.h"

namespace synodaemon {

static constexpr const char* kDomainSocket  = "domain";
static constexpr const char* kIPSocket      = "ip";
static constexpr const char* kSockType      = "sock_type";
static constexpr const char* kSockPath      = "sock_path";
static constexpr const char* kSockAddr      = "sock_addr";
static constexpr const char* kSockPort      = "sock_port";
static constexpr const char* kPidPath       = "pid_path";
static constexpr const char* kMode          = "mode";
static constexpr const char* kPreForkMode   = "prefork"; //process
static constexpr const char* kWorkerMode    = "worker"; //thread
static constexpr const char* kMinWorker     = "min_worker";
static constexpr const char* kMaxWorker     = "max_worker";
static constexpr const char* kMinFreeWorker = "min_free_worker";
static constexpr const char* kMaxFreeWorker = "max_free_worker";
static constexpr const char* kWorkerTimeout = "worker_timeout";
static constexpr const char* kTaskPerWorker = "task_per_worker";

class DaemonConfigImpl;
class DaemonConfig {
	public:
		explicit DaemonConfig(const string&);
		explicit DaemonConfig(const Json::Value& config);
		DaemonConfig(const DaemonConfig&);
		DaemonConfig& operator=(const DaemonConfig& config);
		DaemonConfig(DaemonConfig&&);
		DaemonConfig& operator=(DaemonConfig&& config);
		~DaemonConfig();

		bool IsGood() const;
		string GetSockType() const;
		string GetSockPath() const;
		string GetSockAddr() const;
		size_t GetSockPort() const;
		string GetPidPath() const;
		string GetMode() const;
		size_t GetMaxWorkerNum() const;
		size_t GetMinWorkerNum() const;
		size_t GetMaxFreeWorkerNum() const;
		size_t GetMinFreeWorkerNum() const;
		size_t GetTaskPerWorker() const;
		time_t GetWorkerTimeout() const;
	private:
		std::unique_ptr<DaemonConfigImpl> config_impl_;

};

} // namespace synodaemon

#endif
