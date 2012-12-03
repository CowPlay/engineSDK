/*
 * SAudioSourceWav.cpp
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#include "SAudioSourceWav.h"

namespace irrgame
{
	namespace audio
	{
		//! Default constructor
		SAudioSourceWav::SAudioSourceWav(ISoundManager* manager) :
				SAudioSource(manager)
		{
		}

		//! Destructor
		SAudioSourceWav::~SAudioSourceWav()
		{
		}

		//! Returns True if audio source can be streamed. Otherwise return False.
		bool SAudioSourceWav::isStreamed()
		{
			return false;
		}

		//! Replaces the contents of the buffer for streaming audio.
		void SAudioSourceWav::update(u32 size)
		{
			//do nothing
		}
	}  // namespace audio
}  // namespace irrgame

