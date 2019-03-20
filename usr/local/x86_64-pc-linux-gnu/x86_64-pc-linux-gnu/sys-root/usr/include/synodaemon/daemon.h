/* Copyright (c) 2000-2016 Synology Inc. All rights reserved. */
#ifndef _SYNO_DAEMON_DAEMON_H_
#define _SYNO_DAEMON_DAEMON_H_

#include "std.h"
#include "daemon_config.h"

namespace synodaemon {

/**
 * @detail: abstract class of daemon class
 */
class DaemonBase {
	public:
		/**
		 * Contructor with daemon config path
		 *
		 * @param [IN] path: daemon config path
		 */
		DaemonBase(const string&);
		/**
		 * Contructor with DaemonConfig obj
		 *
		 * @param [IN] config: DaemonConfig
		 */
		DaemonBase(DaemonConfig config);
		virtual ~DaemonBase();
		/**
		 * It wiil start daemon
		 *
		 * 1. Call RunAsDaemon
		 * 2. mask SIGPIPE and register kill handler
		 * 3. Call MainLoop into loop
		 */
		virtual void Run();
		/**
		 * Stop daemon and clean resource
		 */
		virtual void Stop();
		/**
		 * Set kill handler
		 *
		 * @param [IN] handler: kill handler
		 */
		virtual void onKillHandler(KillHandler);

	protected:
		/**
		 * Create pid file and call daemon()
		 */
		virtual int RunAsDaemon();
		/**
		 * pure virtual function: clean your resource when stop daemon
		 */
		virtual void CleanResource() = 0;
		/**
		 * pure virtual function: let daemon goto loop
		 */
		virtual void MainLoop() = 0;

		/**
		 * daemon config
		 */
		DaemonConfig config_;
		/**
		 * kill handler
		 */
		KillHandler kill_handler_;
};

} // namespace synodaemon

#endif
