/*
 * SSoundEffectAutowah.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECTAUTOWAH_H_
#define SSOUNDEFFECTAUTOWAH_H_

#include "audio/sfx/SSoundEffect.h"

namespace irrgame
{
	namespace audio
	{
		//! The Auto-wah effect emulates the sound of a wah-wah pedal used with an electric guitar, or a mute on a brass instrument.
		struct SSoundEffectAutowah: public SSoundEffect
		{
			public:

				//! Default constructor
				SSoundEffectAutowah();

				//! Destructor
				virtual ~SSoundEffectAutowah();

				//! Return effect type
				virtual ESoundEffectType getType();

			public:

				/* This property controls the time the filtering effect takes to sweep from minimum to maximum center frequency when it is triggered by input signal.
				 * Range: 0.0001 to 1.0
				 * Default: 0.06
				 */
				f32 AttackTime;

				/* This property controls the time the filtering effect takes to sweep from maximum back to base center frequency, when the input signal ends.
				 * Range: 0.0001 to 1.0
				 * Default: 0.06
				 */
				f32 ReleaseTime;

				/* This property controls the resonant peak, sometimes known as emphasis or Q, of the auto-wah
				 * band-pass filter. Resonance occurs when the effect boosts the frequency content of the sound
				 * around the point at which the filter is working. A high value promotes a highly resonant, sharp
				 * sounding effect.
				 * Range: 2.0 to 1000.0
				 * Default: 1000.0
				 */
				f32 Resonance;

				/* This property controls the input signal level at which the band-pass filter will be fully opened.
				 * Range: 0.00003 to 31621.0
				 * Default: 11.22
				 */
				f32 PeakGain;
		};

		//! Default constructor
		SSoundEffectAutowah::SSoundEffectAutowah() :
				SSoundEffect(), AttackTime(0.06), ReleaseTime(0.06), Resonance(
						1000.0), PeakGain(11.22)
		{
		}

		//! Destructor
		SSoundEffectAutowah::~SSoundEffectAutowah()
		{

		}

		//! Return effect type
		ESoundEffectType SSoundEffectAutowah::getType()
		{
			return ESET_AUTOWAH;
		}

		//! Internal function. Please do not use.
		SSoundEffect* createSoundEffectAutowah()
		{
			return new SSoundEffectAutowah();
		}

	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECTAUTOWAH_H_ */
