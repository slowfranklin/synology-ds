/* Copyright (c) 2000-2015 Synology Inc. All rights reserved. */
#ifndef _SYNO_UT_TYPE_H_
#define _SYNO_UT_TYPE_H_
#include <vector>
#include <string>

namespace SYNO {
namespace SPOTLIGHT {
namespace UTILS {

/**
 * @details this class is a representation of Uniform Type Identifiers,
 *          mainly used for create UTType mapping tree
 *
 * @brief UTType Identifier used to create UTTypeMapping
 *
 * @see https://developer.apple.com/library/mac/documentation/FileManagement/Conceptual/understanding_utis/understand_utis_intro/understand_utis_intro.html#//apple_ref/doc/uid/TP40001319
 */
class SYNOUTType {
public:
	/**
	 * UTType Id setter
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @code{.cpp}
	 * string strId = "public.jpeg";
	 * uttypeA.setId(strId);
	 * @endcode
	 */
	void setId(const std::string& strId);
	/**
	 * UTType Id setter
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @code{.cpp}
	 * uttypeA.setId("public.jpeg");
	 * @endcode
	 */
	void setId(const char* szId);
	/**
	 * UTType description setter
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @code{.cpp}
	 * string strDesc = "JPEG image";
	 * uttypeA.setDesc(strDesc);
	 * @endcode
	 */
	void setDesc(const std::string &strDesc);
	/**
	 * UTType description setter
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @code{.cpp}
	 * uttypeA.setDesc("JPEG image");
	 * @endcode
	 */
	void setDesc(const char* szDesc);
	/**
	 * add one extension to a UTType
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @code{.cpp}
	 * string strExt = "jpeg";
	 * uttypeA.addExt(strExt);
	 * @endcode
	 */
	void addExt(const std::string& strExt);
	/**
	 * add one extension to a UTType
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @code{.cpp}
	 * uttypeA.addExt("jpeg");
	 * uttypeA.addExt("jpg");
	 * @endcode
	 */
	void addExt(const char* szExt);
	/**
	 * add one type id to a UTType "comform to" list
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @code{.cpp}
	 * strPublicImageId = "public.image";
	 * uttypeA.addConformTo(strPublicImageId);
	 * @endcode
	 */
	void addConformTo(const std::string& strConform);
	/**
	 * add one type id to a UTType "comform to" list
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @code{.cpp}
	 * uttypeA.addConformTo("public.image");
	 * @endcode
	 */
	void addConformTo(const char* szConform);
	/**
	 * add a children of UTType (usually child "conforms to" parent)
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @code{.cpp}
	 * uttypeA.addConformTo(&uttypeB);
	 * @endcode
	 */
	void addChildren(const SYNOUTType* child);
	/**
	 * get UTType id
	 *
	 * @apparmor none
	 * @grantable no
	 */
	std::string getId() const;
	/**
	 * get UTType description
	 *
	 * @apparmor none
	 * @grantable no
	 */
	std::string getDesc() const;
	/**
	 * get UTType extenstions
	 *
	 * @apparmor none
	 * @grantable no
	 *
	 * @return extensions concatenated with whitespace separating them
	 */
	std::string getExts() const;
	/**
	 * get UTType "comform to" list
	 *
	 * @apparmor none
	 * @grantable no
	 */
	const std::vector<std::string>& getConformTo() const;
private:
	std::string _strId;
	std::string _strDesc;
	std::vector<std::string> _exts;
	std::vector<std::string> _conformTo;
	std::vector<const SYNOUTType*> _children;
};

} /* namespace UTILS */
} /* namespace SPOTLIGHT */
} /* namespace SYNO */

#endif /* _SYNO_UT_TYPE_H_ */
