/*
 * CAudioSourceStreamed.h
 *
 *  Created on: Nov 22, 2012
 *      Author: developer08
 */

#ifndef CAUDIOSOURCESTREAMED_H_
#define CAUDIOSOURCESTREAMED_H_

#include "audio/SAudioSource.h"
#include "io/IReadFile.h"
#include "libvorbis/include/vorbis/codec.h"
#include "libvorbis/include/vorbis/vorbisfile.h"

namespace irrgame
{
	namespace audio
	{

		struct SAudioSourceOgg: public SAudioSource
		{
			public:
				//! Default constructor
				SAudioSourceOgg(ISoundManager* manager);

				//! Destructor
				virtual ~SAudioSourceOgg();

				//! Returns True if audio source can be streamed. Otherwise return False.
				virtual bool isStreamed();

				//! Replaces the contents of the buffer for streaming audio.
				/*
				 * @param size: Size of next buffer in bytes.
				 */
				virtual void update(u32 size = 4096);

			public:
				OggVorbis_File* VorbisFile;
				vorbis_comment* Comment;
				vorbis_info* Info;
		};

	} /* namespace audio */
} /* namespace irrgame */
#endif /* CAUDIOSOURCESTREAMED_H_ */
