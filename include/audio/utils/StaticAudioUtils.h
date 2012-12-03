/*
 * StaticAudioUtils.h
 *
 *  Created on: Nov 22, 2012
 *      Author: developer08
 */

#ifndef STATICAUDIOUTILS_H_
#define STATICAUDIOUTILS_H_

#include "compileConfig.h"
#include "audio/EAudioFormat.h"

namespace irrgame
{
	namespace audio
	{
		class StaticAudioUtils
		{
			public:
				//! Returns the audio format.
				/** \param channels Number of channels. Mono = 1, Stereo = 2.
				 * \param bit Bits per sample. The so-called "depth" or accuracy of sound.
				 * 8 bit, 16 bit, etc.*/
				static EAudioFormat getAudioFormat(u32 channels, u32 bit);
		};
	}  // namespace audio
}  // namespace irrgame

#endif /* STATICAUDIOUTILS_H_ */
