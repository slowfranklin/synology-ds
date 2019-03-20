/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef _SYNO_UT_TYPE_MAPPING_H_
#define _SYNO_UT_TYPE_MAPPING_H_
#include <map>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "SYNOUTType.h"

// define constants
#define SZ_DEFAULT_PLIST_PATH	"/usr/syno/share/synospotlight/uttype.xml"

#define SZ_PLIST_NAME	"plist"
#define SZ_DICT_NAME	"dict"
#define SZ_ARRAY_NAME	"array"
#define SZ_KEY_NAME	"key"
#define SZ_STRING_NAME	"string"

#define SZ_UT_EXPORTED_TYPE_DECLARE	"UTExportedTypeDeclarations"
#define SZ_UT_IMPORTED_TYPE_DECLARE	"UTImportedTypeDeclarations"

#define SZ_UT_IDENTIFIER	"UTTypeIdentifier"
#define SZ_UT_DESCRIPTION	"UTTypeDescription"
#define SZ_UT_CONFORMS_TO	"UTTypeConformsTo"
#define SZ_UT_TAG_SPEC	"UTTypeTagSpecification"

#define SZ_PUBLIC_FILENAME_EXT	"public.filename-extension"

namespace SYNO {
namespace SPOTLIGHT {
namespace UTILS {

/**
 * @details this class is used to parse a plist file and build UTType mapping tree
 *
 * @brief UTType Mapping plist parser
 */
class SYNOUTTypeMapping {
public:
	/**
	 * Initialize mapping tree with default mapping plist file
	 *
	 * @apparmor abstractions/synospotlightutils
	 * @grantable no
	 */
	SYNOUTTypeMapping();
	/**
	 * Initialize mapping tree
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @param[in] strPlistPath  path of plist file to use
	 */
	SYNOUTTypeMapping(const std::string& strPlistPath);
	/**
	 * Get description of a given UTType
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @param[in] strType  UTType Id to get description
	 *
	 * @return description of the type if the type is found in mapping tree <br>
	 *         empty string if type not found
	 */
	std::string getTypeDesc(const std::string& strType) const;
	/**
	 * Get extensions of a given UTType
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @param[in] strType  UTType Id to get description
	 *
	 * @return list of extensions included in the UTType (concat with whitespace separating them) <br>
	 *         empty string if type not found
	 */
	std::string getTypeExts(const std::string& strType) const;
	/**
	 * interactive selftest program (only for debug)
	 *
	 * @apparmor none
	 * @grantable no
	 */
	void testProg() const;
private:
	void init();
	int parse(const std::string& szPlistPath);
	int parseContentTypeNode(const xmlNode *node);
	int parseConformToNode(SYNOUTType& uttype, const xmlNode* node);
	int parseTagSpecNode(SYNOUTType& uttype,const xmlNode *node);
	int linkUTTypeChildren();

	bool _ok;
	std::string _strPlistPath;
	std::map<std::string, SYNOUTType> _typeMapping;
};

} /* namespace UTILS */
} /* namespace SPOTLIGHT */
} /* namespace SYNO */

#endif /* _SYNO_UT_TYPE_MAPPING_H_ */
