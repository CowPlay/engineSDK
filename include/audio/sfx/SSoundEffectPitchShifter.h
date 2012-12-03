/*
 * SSoundEffectPitchShifter.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECTPITCHSHIFTER_H_
#define SSOUNDEFFECTPITCHSHIFTER_H_

#include "SSoundEffect.h"

namespace irrgame
{
	namespace audio
	{
		//! The pitch shifter applies time-invariant pitch shifting to the input signal, over a one octave range
		//! and controllable at a semi-tone and cent resolution.
		struct SSoundEffectPitchShifter: public SSoundEffect
		{
			public:

				//! Default constructor
				SSoundEffectPitchShifter();

				//! Destructor
				virtual ~SSoundEffectPitchShifter();

				//! Return effect type
				virtual ESoundEffectType getType();

			public:
				/* This sets the number of semitones by which the pitch is shifted. There are 12 semitones per
				 * octave. Negative values create a downwards shift in pitch, positive values pitch the sound
				 * upwards.
				 * Range: -12 to 12
				 * Default: 12
				 */
				s32 CoarseTune;

				/* This sets the number of cents between Semitones a pitch is shifted. A Cent is 1/100th of a
				 * Semitone. Negative values create a downwards shift in pitch, positive values pitch the sound
				 * upwards.
				 * Range: -50 to 50
				 * Default: 0
				 */
				s32 FineTune;
		};

		//! Default constructor
		SSoundEffectPitchShifter::SSoundEffectPitchShifter() :
				SSoundEffect(), CoarseTune(12), FineTune(0)
		{
		}

		//! Destructor
		SSoundEffectPitchShifter::~SSoundEffectPitchShifter()
		{

		}

		//! Return effect type
		ESoundEffectType SSoundEffectPitchShifter::getType()
		{
			return ESET_PITCH_SHIFTER;
		}

	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECTPITCHSHIFTER_H_ */
