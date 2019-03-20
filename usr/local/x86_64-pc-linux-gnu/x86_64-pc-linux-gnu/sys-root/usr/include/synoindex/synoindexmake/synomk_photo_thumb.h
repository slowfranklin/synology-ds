// Copyright (c) 2000-2013 Synology Inc. All rights reserved.
#ifndef _SYNO_SYNOMK_PHOTO_THUMB_H
#define _SYNO_SYNOMK_PHOTO_THUMB_H

// standard
#include <string>
#include <vector>

// syno
#include <synoutilscpp/synoutils.h>

using std::string;
using std::vector;
using namespace SYNOUtils;

//--------------------------------------------------

class PhotoThumbSetting
{
public:
	string src_path;				// source photo path
	string dest_path;				// destination thumbnail path
	string temp_path;				// set a temporary path to put work files for ImageMagick
	string output_path;				// internal use. don't set this value.

	bool caret;						// enable wxh^
	int width;						// width of thumbnail
	int height;						// height of thumbnail
	int quality;					// JPEG/MIFF/PNG compression level. [1, 100]
	bool strip;						// strip the image of any profiles or comments.
	bool flatten;					// alias for the -layers method "flatten".
	bool auto_orient;				// adjusts an image so that its orientation is suitable for viewing
	int rotate;						// apply Paeth image rotation (using shear operations) to the image.
	string unsharp;					// sharpen the image with an unsharp mask operator. radiusxsigma{+gain}{+threshold}
	string colorspace;				// set the image colorspace.

	PhotoThumbSetting();
	PhotoThumbSetting& operator=(const PhotoThumbSetting& other);
};

//--------------------------------------------------

class PhotoThumbMaker
{
public:
	PhotoThumbMaker();

	int AddSetting(PhotoThumbSetting& setting);
	int Make();
	int Reset();

private:
	string GetSourcePath();
	string GetOutputPath(string path);

	void AddTheFirstThumbArgs(ProcessRunner& cmd, PhotoThumbSetting& setting);
	void AddTheMiddleThumbArgs(ProcessRunner& cmd, PhotoThumbSetting& setting);
	void AddTheLastThumbArgs(ProcessRunner& cmd, PhotoThumbSetting& setting);
	void AddCommonArgs(ProcessRunner& cmd, PhotoThumbSetting& setting);
	int Check(const char* src_path, blkcnt_t src_blocks);

	const char* _exe_path;
	vector<PhotoThumbSetting> _pool;
};

//--------------------------------------------------

#endif
