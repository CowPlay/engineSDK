/*
 * StaticAudioUtils.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: developer08
 */

#include "audio/utils/StaticAudioUtils.h"

namespace irrgame
{
	namespace audio
	{

		EAudioFormat StaticAudioUtils::getAudioFormat(u32 channels, u32 bit)
		{
			EAudioFormat result = EAF_COUNT;

			if (channels == 1)
			{
				result = bit == 8 ? EAF_MONO8 : EAF_MONO16;
			}
			else
			{
				result = bit == 8 ? EAF_STEREO8 : EAF_STEREO16;
			}

			return result;
		}

	}  // namespace audio
}  // namespace irrgame

