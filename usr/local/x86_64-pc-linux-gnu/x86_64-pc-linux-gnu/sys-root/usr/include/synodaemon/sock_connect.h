#ifndef _SYNO_DAEMON_SOCK_CONNECT_H_
#define _SYNO_DAEMON_SOCK_CONNECT_H_

#include "std.h"

namespace synodaemon {

/**
 * @detail: Socket connection class, it is for communicate with socket daemon
 */
class SockConnection {
	public:
		SockConnection() : fd_(-1) { }
		virtual ~SockConnection() { Disconnect(); }

		/**
		 * Disconnect with daemon
		 */
		virtual void Disconnect() {
			if (-1 != fd_) {
				close(fd_);
				fd_ = -1;
			}
		}
		/**
		 * Send data to daemon
		 *
		 * @param [IN] data: data string you want to send to daemon
		 *
		 * @return: success(true) or fail(false)
		 */
		bool Send(const string&);
		/**
		 * Recv data from daemon
		 *
		 * @param [IN] data: data string recv from daemon
		 *
		 * @return: success(true) or fail(false)
		 */
		bool Recv(string&);

		/**
		 * Get the raw socket between daemon
		 *
		 * @return: raw socket
		 */
		int GetRawFd() const { return fd_; }

		/**
		 * pure virtual function
		 */
		virtual bool Connect() = 0;
	protected:
		int fd_;
};

class DomainSockConnection : public SockConnection {
	public:
		/**
		 * Constructor with domain socket daemon path
		 */
		explicit DomainSockConnection(string path) :
			sock_path_(std::move(path)) { }
		~DomainSockConnection() { }

		/**
		 * Connect to domain socket daemon
		 *
		 * @return: success(true) or fail(false)
		 */
		bool Connect();
		bool Connect(time_t);
	private:
		string sock_path_;

};

} // namespace synodaemon

#endif
