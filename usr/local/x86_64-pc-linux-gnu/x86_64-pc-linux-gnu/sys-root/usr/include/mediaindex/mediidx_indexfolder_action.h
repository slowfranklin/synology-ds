// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_MEDIIDX_INDEXFOLDER_ACTION_H
#define _SYNO_MEDIIDX_INDEXFOLDER_ACTION_H

#include <string>
#include <json/reader.h>

using std::string;

#define SZF_INDEX_FOLDER_CONF "/usr/syno/etc/index_folder.conf"

//--------------------------------------------------

Json::Value createRule(string name, string path, bool blPhoto, bool blMusic, bool blVideo, bool blDefault);
string getDefaultSharePath(const char* szShare);
string getShareName(string strPath);
string getVolumePath(string strFullPath);
string getFolderPath(string strSharePath);
string appendPath(string strBase, string strPath);
Json::Value createDefaultShareRule(const char* szShare, BOOL blForceSharePath);

Json::Value IndexFolderConfOpen();
int IndexFolderConfSave(const Json::Value &folders);
Json::Value IndexFolderConfLoad();

bool IsEqualOrSubPath(const string &strDest, const string &strSrc);
int FindIndexFolderByPath(const Json::Value &indexFolder, const char *szPath, const Json::Value **ppIndexFolder);

bool IsIndexFolderConfExist();
int WriteDefaultConf();

//--------------------------------------------------

class IndexFolderAction
{
public:
	/* This function is deprecated, please use onApply(const Json::Value) */
	bool onApply(const Json::Value &newFolders, const Json::Value &updatedFolders);
	bool onApply(const Json::Value &setupFolders);

private:
	Json::Value _newFolders;
	Json::Value _updatedFolders;
	Json::Value _origFolders;

	Json::Value _addedFolders;
	Json::Value _deletedFolders;
	Json::Value _modifiedFolders;

	void checkFoldersExist(Json::Value &folders);
	void setUpdatedIndexFolders();
	void setDeletedIndexFolders();
	bool compareFolder(const Json::Value &folder_a, const Json::Value &folder_b);
	void ReindexFolders(Json::Value &folders);
	void ModifyShareStatus();
};

//--------------------------------------------------

#endif
