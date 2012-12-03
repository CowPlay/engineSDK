/*
 * SSoundEffectVocalMorpher.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECTVOCALMORPHER_H_
#define SSOUNDEFFECTVOCALMORPHER_H_

#include "SSoundEffect.h"

namespace irrgame
{
	namespace audio
	{
		//! The vocal morpher consists of a pair of 4-band formant filters, used to impose vocal tract effects upon the input signal.
		struct SSoundEffectVocalMorpher: public SSoundEffect
		{
			public:

				//! Default constructor
				SSoundEffectVocalMorpher();

				//! Destructor
				virtual ~SSoundEffectVocalMorpher();

				//! Return effect type
				virtual ESoundEffectType getType();

			public:
				/* If both parameters are set to the same phoneme, that determines the filtering effect that will be
				 * heard. If these two parameters are set to different phonemes, the filtering effect will morph
				 * between the two settings at a rate specified by Rate.
				 * Range: 0 to 29
				 * Default: 0
				 */
				u32 PhonemeA;

				/* If both parameters are set to the same phoneme, that determines the filtering effect that will be
				 * heard. If these two parameters are set to different phonemes, the filtering effect will morph
				 * between the two settings at a rate specified by Rate.
				 * Range: 0 to 29
				 * Default: 10
				 */
				u32 PhonemeB;

				/* This is used to adjust the pitch of phoneme filter A in 1-semitone increments.
				 * Range: -24 to 24
				 * Default: 0
				 */
				s32 PhonemeACoarseTune;

				/* This is used to adjust the pitch of phoneme filter B in 1-semitone increments.
				 * Range: -24 to 24
				 * Default: 0
				 */
				s32 PhonemeBCoarseTune;

				/* This controls the shape of the low-frequency oscillator used to morph between the two phoneme filters.
				 * Range: 0 to 2
				 * Default: 0
				 */
				u32 Waveform;

				/* This controls the frequency of the low-frequency oscillator used to morph between the two phoneme filters.
				 * Range: 0.0 to 10.0
				 * Default: 1.41
				 */
				f32 Rate;
		};

		//! Default constructor
		SSoundEffectVocalMorpher::SSoundEffectVocalMorpher() :
				SSoundEffect(), PhonemeA(0), PhonemeB(10), PhonemeACoarseTune(
						0), PhonemeBCoarseTune(0), Waveform(0), Rate(1.41)
		{
		}

		//! Destructor
		SSoundEffectVocalMorpher::~SSoundEffectVocalMorpher()
		{

		}

		//! Return effect type
		ESoundEffectType SSoundEffectVocalMorpher::getType()
		{
			return ESET_VOCAL_MORPHER;
		}

	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECTVOCALMORPHER_H_ */
