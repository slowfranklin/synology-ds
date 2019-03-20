
#ifndef TAGLIB_DFFPROPERTIES_H
#define TAGLIB_DFFPROPERTIES_H

#include "taglib.h"
#include "audioproperties.h"

namespace TagLib {

	class ByteVector;

	namespace DFF {

		class File;

		//! An implementation of audio property reading for DFF

		/*!
		 * This reads the data from an DFF stream found in the AudioProperties
		 * API.
		 */
		class TAGLIB_EXPORT Properties : public AudioProperties
		{
		public:
			/*!
			 * Create an instance of DFF::Properties with the data read from the
			 * ByteVector \a data.
			 */
			Properties(const ByteVector &data, ReadStyle style);

			/*!
			 * Create an instance of DFF::Properties with the data read from the
			 * ByteVector \a data and the length calculated using \a streamLength.
			 */
			Properties(const ByteVector &data, uint streamLength, ReadStyle style);

			/*!
			 * Destroys this DFF::Properties instance.
			 */
			virtual ~Properties();

			// Reimplementations.
			virtual int length() const;
			virtual int bitrate() const;
			virtual int sampleRate() const;
			virtual int channels() const;
			int bitPerSample() const;

		private:
			Properties(const Properties &);
			Properties &operator=(const Properties &);

			void read(const ByteVector &data);

			class PropertiesPrivate;
			PropertiesPrivate *d;
		};
	}
}
#endif
