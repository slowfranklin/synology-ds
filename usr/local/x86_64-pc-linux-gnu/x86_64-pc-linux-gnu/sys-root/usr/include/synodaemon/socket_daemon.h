#ifndef _SYNO_DAEMON_SOCKET_DAEMON_H_
#define _SYNO_DAEMON_SOCKET_DAEMON_H_

#include "macro.h"
#include "daemon.h"

namespace synodaemon {

/**
 * @detail: Socket Daemon class,
 * it will run for domain socket daemon or ip socket daemon
 */
class SocketDaemon : public DaemonBase {
	public:
		/**
		 * Constructor with daemon config path
		 *
		 * @param [IN] path: daemon config path
		 */
		explicit SocketDaemon(const string&);
		/**
		 * Contructor with DaemonConfig obj
		 *
		 * @param [IN] config: DaemonConfig
		 */
		explicit SocketDaemon(DaemonConfig config);
		virtual ~SocketDaemon();
		/**
		 * Register your task handler, daemon will pass accept fd into your callback function
		 *
		 * @param [IN] callback: callback funtion when daemon accept connection fd
		 */
		void onTaskHandler(WorkerFunc);
		void onTaskHandler(WorkerFuncPtr);

		/**
		 * Check if the daemon is idle now
		 */
		bool IsIdle();

		SYNODAEMON_NOCOPYABLE_CLASS(SocketDaemon);
	protected:

		/**
		 * Create listen socket with given type
		 *
		 * @param [IN] type: socket type (domain or ip)
		 *
		 * @return: listen socket fd
		 */
		int CreateSocket(const string&);
		/**
		 * Clean daemon resource, like pid file
		 */
		void CleanResource();
		/**
		 * Let daemon into loop, using libevent
		 */
		void MainLoop();
		/**
		 * Init socket daemon
		 */
		void Init();
};

} // namespace synodaemon

#endif
