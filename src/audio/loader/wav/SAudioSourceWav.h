/*
 * SAudioSourceWav.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SAUDIOSOURCEWAV_H_
#define SAUDIOSOURCEWAV_H_

#include "audio/SAudioSource.h"

namespace irrgame
{
	namespace audio
	{
		struct SAudioSourceWav: public SAudioSource
		{
			public:

				//! Default constructor
				SAudioSourceWav(ISoundManager* manager);

				//! Destructor
				virtual ~SAudioSourceWav();

				//! Returns True if audio source can be streamed. Otherwise return False.
				virtual bool isStreamed();

				//! Replaces the contents of the buffer for streaming audio.
				virtual void update(u32 size = 0);
		};
	}  // namespace audio
}  // namespace irrgame

#endif /* SAUDIOSOURCEWAV_H_ */
