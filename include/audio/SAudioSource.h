/*
 * SSoundEntry.h
 *
 *  Created on: Nov 6, 2012
 *      Author: litirvi
 */

#ifndef SAUDIOSOURCE_H_
#define SAUDIOSOURCE_H_

#include "audio/EAudioFormat.h"
#include "core/engine/IReferenceCounted.h"
#include "core/collections/stringc.h"
#include "io/IReadFile.h"

namespace irrgame
{
	namespace audio
	{
		class ISoundManager;

		//! Interface for providing access to raw data from audio file.
		//! Also have few methods for work with streamed audio.
		struct SAudioSource: public IReferenceCounted
		{

			public:

				//! Default constructor
				SAudioSource(ISoundManager* manager);

				//! Destructor
				virtual ~SAudioSource();

				//! Returns True if audio source can be streamed. Otherwise return False.
				virtual bool isStreamed() = 0;

				//! Replaces the contents of the buffer for streaming audio.
				/* @param size: Size of next buffer in bytes.
				 */
				virtual void update(u32 size = 4096) = 0;

			public:

				//! Name of the source which represents a full path
				core::stringc Name;

				//! Buffer with sound data
				c8* Buffer;

				//! Size of the current buffer with sound data
				u32 BufferSize;

				//! Number of samples per of seconds (8000 Hz, 44100 Hz, etc.)
				u32 Rate;

				//! Sound format. Valid sound formats: Mono8, Mono16, Stereo8, Stereo16
				EAudioFormat Format;

				//! TODO: write comment
				io::IReadFile* File;

			private:

				//! Manager which own this source
				ISoundManager* Manager;
		};

	} // end namespace audio
} // end namespace irrgame

#endif /* SAUDIOSOURCE_H_ */
