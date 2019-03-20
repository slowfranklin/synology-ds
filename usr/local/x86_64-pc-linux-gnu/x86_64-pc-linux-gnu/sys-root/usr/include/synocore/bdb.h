// Copyright (c) 2000-2007 Synology Inc. All rights reserved.
#ifndef __SYNO_BDB_H__
#define __SYNO_BDB_H__

#include <stdio.h>
#include <time.h>
#include <sys/cdefs.h>

#include <synocore/synoglobal.h>
#include <synocore/synotype.h>
#include <synocore/error.h>

__BEGIN_DECLS;

/**
 * @addtogroup BDB
 *
 * @brief The structure and operation of BDB File in SynoLib.
 *
 * @{
 */

/**
 * The string that represents the prefix of keys those are the
 * meta data of Synology Database file.  Those meta data could
 * be skipped when doing enumeration.
 *
 * @see SLIBCBdbCursorGet()
 */
#define SYNO_BDB_SZK_PREFIX "#"

/**
 * The Cursor Operations used in Synology Database File Handle
 * SYNOBDB.
 */
typedef enum {
	/**
	 * Start of SYNOBDB_CURSOR_TYPE. This is for boundary checking.
	 */
	SYNOBDB_CURSOR_MIN,
	/**
	 * The data associated with the specified key is returned.  This
	 * differs from the get routines in that it sets or initializes
	 * the cursor to the location of the key as well.  For now, the
	 * DB_BTREE access method, the returned key is not necessarily
	 * an exact match for the specified key.  The returned key is
	 * the smallest key greater than or equal to the specified key,
	 * permitting partial key matches and range searches.
	 *
	 * In conformance to BDB::R_CURSOR.
	 *
	 * @deprecated We find the result of this flag is not stable.
	 *  	 So please AVOID using this flag.
	 */
	SYNOBDB_CURSOR_PARTIAL,
	/**
	 * The first key/data pair of the database is returned, and the
	 * cursor is set or initialized to reference it.
	 *
	 * In conformance to BDB::R_FIRST.
	 */
	SYNOBDB_CURSOR_FIRST,
	/**
	 * The last key/data pair of the database is returned, and the
	 * cursor is set or initialized to reference it.
	 *
	 * In conformance to BDB::R_LAST.
	 */
	SYNOBDB_CURSOR_LAST,
	/**
	 * Retrieve the key/data pair immediately after the cursor.  If
	 * the cursor is not yet set, this is the same as the
	 * SYNOBDB_CURSOR_TYPE::SYNOBDB_CURSOR_FIRST flag.
	 *
	 * In conformance to BDB::R_NEXT.
	 */
	SYNOBDB_CURSOR_NEXT,
	/**
	 * Retrieve the key/data pair immediately before the cursor.  If
	 * the cursor is not yet set, this is the same as the
	 * SYNOBDB_CURSOR_TYPE::SYNOBDB_CURSOR_LAST flag.
	 *
	 * In conformance to BDB::R_PREV.
	 */
	SYNOBDB_CURSOR_PREV,
	/**
	 * End of SYNOBDB_CURSOR_TYPE. This is for boundary checking.
	 */
	SYNOBDB_CURSOR_MAX
} SYNOBDB_CURSOR_TYPE;

/**
 * The Synology Database File Handle.  This handle is
 * implemented by BDB, is designed for caching user, group,
 * share configures.  Therefore there are extra meta data for
 * this purpose, ::SYNO_BDB_SZK_CONF_SYNC_TIME and
 * ::SYNO_BDB_SZK_DB_DEPRECATED to make caching more flexible.
 *
 * So that any key begin with ::SYNO_BDB_SZK_PREFIX may be
 * skipped in enumerate, but could be get and set.
 */
typedef struct {
	/**
	 * The wrapper for DB 1.85 DB Handle. May not be NULL.
	 */
	void       *pDBPrivate;

	/**
	 * The cursor action for SLIBCBdbCursorGet(). The vaild values
	 * please reference SYNOBDB_CURSOR_TYPE as detail. Should be set
	 * by SLIBCBdbCursorSetType() and get by SLIBCBdbCursorGetType().
	 *
	 * @see SYNOBDB_CURSOR_TYPE
	 */
	SYNOBDB_CURSOR_TYPE dbCursor;
} SYNOBDB, *PSYNOBDB;

/**
 * Checks the parameter @p dbCursorType is in the vaild range or
 * not.
 *
 * @param[in] dbCursorType The CursorType that to be checked.
 *
 * @retval TRUE a vaild value
 * @retval FALSE invaild value
 *
 * @grantable No
 */
static inline BOOL
BDbIsValidCursorType(SYNOBDB_CURSOR_TYPE dbCursorType)
{
	if ((dbCursorType > SYNOBDB_CURSOR_MIN) &&
		 (dbCursorType < SYNOBDB_CURSOR_MAX)) {
		return TRUE;
	}
	return FALSE;
}

/**
 * Gets current cursor type of @p pDb.
 *
 * @param[in] pDb The SYNOBDB Handler. Should not be NULL.
 *
 * @retval SYNOBDB_CURSOR_MIN if @p pDb is NULL.
 * @retval pDb->dbCursor
 *
 * @grantable No
 */
static inline SYNOBDB_CURSOR_TYPE
SLIBCBdbCursorGetType(const PSYNOBDB pDb)
{
	if (NULL == pDb) {
		return SYNOBDB_CURSOR_MIN;
	}
	return pDb->dbCursor;
}

/**
 * @}
 */

#ifndef NO_PROTO
#include <synocore/bdb_p.h>
#endif //NO_PROTO

__END_DECLS;
#endif	/* __SYNO_BDB_H__ */
