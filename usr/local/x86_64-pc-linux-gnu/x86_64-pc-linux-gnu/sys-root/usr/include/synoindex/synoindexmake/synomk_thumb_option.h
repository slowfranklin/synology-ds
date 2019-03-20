// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_SYNOMK_THUMB_OPTION_H
#define _SYNO_SYNOMK_THUMB_OPTION_H

#include <vector>
#include <synomk_thumb_profile.h>

//--------------------------------------------------

typedef std::vector<ThumbnailProfile*> ThumbnailProfileList;

//--------------------------------------------------

class ConvertOptions
{
public:
	ConvertOptions();
	~ConvertOptions();

	bool parse(const char* szConfigPath, const char *szPath);
	int getThumbProfileCount(int phase = -1);
	ThumbnailProfile* getThumbProfile(unsigned int i, int phase = -1);

private:
	ThumbnailProfileList &getPhaseList(int i);

	ThumbnailProfileList _profiles;

	/* always generate from original file */
	ThumbnailProfileList _profiles_phase0;

	/* always generate from largest phase0 file */
	ThumbnailProfileList _profiles_phase1;
	ThumbnailProfileList _profiles_phase2;
};

//--------------------------------------------------

#endif
