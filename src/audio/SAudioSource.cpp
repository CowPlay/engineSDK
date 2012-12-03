/*
 * SAudioSource.cpp
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#include "audio/SAudioSource.h"

namespace irrgame
{
	namespace audio
	{
		//! Default constructor
		SAudioSource::SAudioSource(ISoundManager* manager) :
				Buffer(0), BufferSize(0), Rate(0), Format(EAF_COUNT), Manager(
						manager)
		{
		}

		//! Destructor
		SAudioSource::~SAudioSource()
		{
			if (Buffer)
				delete[] Buffer;
		}
	}  // namespace audio
}  // namespace irrgame

