/*
 * SSoundEffectFrequencyShifter.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECTFREQUENCYSHIFTER_H_
#define SSOUNDEFFECTFREQUENCYSHIFTER_H_

#include "SSoundEffect.h"

namespace irrgame
{
	namespace audio
	{
		//! The frequency shifter is a single-sideband modulator, which translates all the component frequencies of the input signal by an equal amount.
		struct SSoundEffectFrequencyShifter: public SSoundEffect
		{
			public:

			//! Default constructor
			SSoundEffectFrequencyShifter();

			//! Destructor
			virtual ~SSoundEffectFrequencyShifter();

			//! Return effect type
			virtual ESoundEffectType getType();

			public:
				/* This is the carrier frequency. For carrier frequencies below the audible range, the singlesideband
				 * modulator may produce phaser effects, spatial effects or a slight pitch-shift. As the
				 * carrier frequency increases, the timbre of the sound is affected; a piano or guitar note becomes
				 * like a bell's chime, and a human voice sounds extraterrestrial!
				 * Range: 0.0 to 24000.0
				 * Default: 1.0
				 */
				f32 Frequency;

				/* These select which internal signals are added together to produce the output. Different
				 * combinations of values will produce slightly different tonal and spatial effects.
				 * direction down 0, direction up 1, direction off 2
				 * Range: 0 to 2
				 * Default: 0
				 */
				u32 Left;

				/* These select which internal signals are added together to produce the output. Different
				 * combinations of values will produce slightly different tonal and spatial effects.
				 * Range: 0 to 2
				 * Default: 0
				 */
				u32 Right;
		};

		//! Default constructor
		SSoundEffectFrequencyShifter::SSoundEffectFrequencyShifter() :
				SSoundEffect(), Frequency(1), Left(0), Right(0)
		{
		}

		//! Destructor
		SSoundEffectFrequencyShifter::~SSoundEffectFrequencyShifter()
		{

		}

		//! Return effect type
		ESoundEffectType SSoundEffectFrequencyShifter::getType()
		{
			return ESET_FREQUENCY_SHIFTER;
		}

	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECTFREQUENCYSHIFTER_H_ */
