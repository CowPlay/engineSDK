/*
 * ESoundEffectTypes.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef ESOUNDEFFECTTYPES_H_
#define ESOUNDEFFECTTYPES_H_

namespace irrgame
{
	namespace audio
	{
		//! Enum of all available audio effect types.
		enum ESoundEffectType
		{
			ESET_NULL = 0,
			//TODO: comment
			ESET_ECHO,
			//
			ESET_MODULATOR,
			//
			ESET_REVERB,
			//
			ESET_CHORUS,
			//
			ESET_DISTORTION,
			//
			ESET_FLANGER,
			ESET_FREQUENCY_SHIFTER,
			ESET_VOCAL_MORPHER,
			ESET_PITCH_SHIFTER,
			ESET_AUTOWAH,
			ESET_COMPRESSOR,
			ESET_EQUALIZER,

			//! Not used
			ESET_COUNT
		};

	}  // namespace audio
}  // namespace irrgame

#endif /* ESOUNDEFFECTTYPES_H_ */
