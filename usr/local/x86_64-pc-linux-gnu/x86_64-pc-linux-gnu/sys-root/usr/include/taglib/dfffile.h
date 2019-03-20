#ifndef TAGLIB_DFFFILE_H
#define TAGLIB_DFFFILE_H

#include "taglib_export.h"
#include "tfile.h"
#include "tlist.h"
#include "tag.h"

#include "id3v2tag.h"
#include "dffproperties.h"

namespace TagLib {

	//! An implementation of DFF metadata

	/*!
	 * This is implementation of DFF metadata.
	 *
	 * This supports an ID3v2 tag as well as reading stream from the ID3 RIFF
	 * chunk as well as properties from the file.
	 */

	namespace DFF {

		//! An implementation of TagLib::File with DFF specific methods

		/*!
		 * This implements and provides an interface for DFF files to the
		 * TagLib::Tag and TagLib::AudioProperties interfaces by way of implementing
		 * the abstract TagLib::File API as well as providing some additional
		 * information specific to DFF files. 
		 */ 

		class TAGLIB_EXPORT File : public TagLib::File
		{
		public:
			/*!
			 * Constructs a DFF file from \a file.  If \a readProperties is true the
			 * file's audio properties will also be read.
			 *
			 * \note In the current implementation, \a propertiesStyle is ignored.
			 */
			File(FileName file, bool readProperties = true,
				 Properties::ReadStyle propertiesStyle = Properties::Average);

			/*!
			 * Constructs a DFF file from \a stream.  If \a readProperties is true the
			 * file's audio properties will also be read.
			 *
			 * \note TagLib will *not* take ownership of the stream, the caller is
			 * responsible for deleting it after the File object.
			 *
			 * \note In the current implementation, \a propertiesStyle is ignored.
			 */
			File(IOStream *stream, bool readProperties = true,
				 Properties::ReadStyle propertiesStyle = Properties::Average);

			/*!
			 * Destroys this instance of the File.
			 */
			virtual ~File();

			/*!
			 * Returns the ID3v2 Tag for this file.
			 * 
			 * \note This method does not return all the tags for this file for 
			 * backward compatibility.  Will be fixed in TagLib 2.0.
			 */
			ID3v2::Tag *tag() const;

			/*!
			 * Implements the unified property interface -- export function.
			 * This method forwards to ID3v2::Tag::properties().
			 */
			PropertyMap properties() const;

			void removeUnsupportedProperties(const StringList &properties);

			/*!
			 * Implements the unified property interface -- import function.
			 * This method forwards to ID3v2::Tag::setProperties().
			 */
			PropertyMap setProperties(const PropertyMap &);

			/*!
			 * Returns the DFF::Properties for this file.  If no audio properties
			 * were read then this will return a null pointer.
			 */
			virtual Properties *audioProperties() const;

			/*!
			 * Saves the file.
			 */
			virtual bool save() {return true;}

			/*!
			 * Returns whether or not the file on disk actually has an ID3v2 tag.
			 *
			 * \see ID3v2Tag()
			 */
			bool hasID3v2Tag() const;
        
		private:
			File(const File &);
			File &operator=(const File &);

			void read(bool readProperties, Properties::ReadStyle propertiesStyle);

			class FilePrivate;
			FilePrivate *d;
		};
	}
}

#endif
