//Copyright (c) 2000-2015 Synology Inc. All rights reserved.
#ifndef __CONTENT_SEARCH_UTILS_CONNECTION_H__
#define __CONTENT_SEARCH_UTILS_CONNECTION_H__

#include <synocontentsearchutils/common.h>
#include <json/value.h>
#include <string>

namespace SYNO {
namespace IR {
namespace DAEMON {

	/**
	 * @details You can use this class to communicate with synocontentseard,
	 *          and send query through connection
	 *
	 * @brief Deamon connection for synocontentsearchd
	 *
	 */
	class Connection {
		public:
			/**
			 * Initialize Connection
			 *
			 * @apparmor none
			 *
			 * @code{.cpp}
			 * Connection conn;
			 * @endcode
			 */
			Connection();
			/**
			 * Initialize Connection with given fd
			 *
			 * @param [IN] fd: given connected fd
			 *
			 * @apparmor none
			 *
			 * @code{.cpp}
			 * Connection conn(fd);
			 * @endcode
			 */
			Connection(int fd);
			virtual ~Connection();

			/**
			 * Connect to synocontentsearchd
			 *
			 * @param [IN] connectionTimeout: connection timeout, default is 20 second
			 *
			 * @apparmor none
			 *
			 * @return true is success, false is failed
			 */
			bool Connect(time_t connectionTimeout = 20);
			/**
			 * Close the connection
			 */
			void Close();
			/**
			 * Send search query to search daemon through the connection
			 *
			 * @param [IN] jsQuery: query param, it require to have action, index, query
			 *
			 * @code {.cpp}
			 * Json::Value jsQuery;
			 * jsData["size"] = 1000;
			 * jsData["from"] = 50;
			 * jsData["indice"] = ["test1", "test2"];
			 * jsData["query_string"] = "search";
			 * jsQuery["command"] = "search";
			 * jsQuery["data"] = jsData;
			 * @endcode
			 *
			 * @param [IN] pFunSearchCallback: callback function pointer, it will be called for each search result
			 *
			 * @param [IN] cbData: user define data, it will be passed to callback function
			 *
			 * @param [IN] strAgent: search agent name
			 *
			 * @param [IN] uid: search user uid
			 *
			 * @apparmor none
			 *
			 * @return true is success, false is failed and error will be set in _err
			 *
			 */
			bool SendQuery(const Json::Value &jsQuery, SYNOSearchCallback pFuncSearchCallback,
					void *cbData, const std::string &strAgent, uid_t uid);
			/**
			 * Get the connection error
			 *
			 * @apparmor none
			 *
			 */
			ConnectionErr GetError() const;
			/**
			 * Set the connectin error
			 *
			 * @apparmor none
			 *
			 */
			void SetError(ConnectionErr err);

		private:
			/**
			 * private function,
			 * Handle response from search daemon
			 *
			 * @apparmor none
			 */
			bool ProcessRepsonse(SYNOSearchCallback pFuncSearchCallback, void *cbData);
			/**
			 * internal connected fd
			 */
			int _fd;
			/**
			 * internal connection error
			 */
			ConnectionErr _err;
	};

} //end of DAEMON
} //end of IR
} //end of SYNO

#endif
