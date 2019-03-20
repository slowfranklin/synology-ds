// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_SYNOMK_THUMB_PROFILE_H
#define _SYNO_SYNOMK_THUMB_PROFILE_H

#include <string>

using std::string;

//--------------------------------------------------

class ThumbnailProfile
{
public:
	ThumbnailProfile(int size, int quality, const string& strUnsharp, const string& strFileName, int phase);

	unsigned int getSize() const;
	int getQuality() const;
	string getUnsharp() const;
	string getFileName() const;
	unsigned int getPhase() const;
	bool getUseCaret() const;

	bool statEAFile(const string &strEADir, string &strPath, struct stat &stFile) const;
	void removeAllFiles(const string &strEADir) const;
	void createFailFile(const string &strEADir) const;

private:
	unsigned int _size;
	unsigned int _quality;
	string _strUnsharp;
	string _strOldFileName;
	string _strFileName;
	unsigned int _phase;
	bool _useCaret;
};

//--------------------------------------------------

#endif
