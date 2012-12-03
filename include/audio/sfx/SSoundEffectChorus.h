/*
 * SSoundEffectChorus.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECTCHORUS_H_
#define SSOUNDEFFECTCHORUS_H_

#include "SSoundEffect.h"

namespace irrgame
{
	namespace audio
	{

		//! The chorus effect essentially replays the input audio accompanied by another slightly delayed version of the signal,
		//! creating a "doubling" effect.
		struct SSoundEffectChorus: public SSoundEffect
		{
			public:

				//! Default constructor
				SSoundEffectChorus();

				//! Destructor
				virtual ~SSoundEffectChorus();

				//! Return effect type
				virtual ESoundEffectType getType();

			public:

				/* This property sets the waveform shape of the LFO that controls the delay time of the delayed signals.
				 * 0 if wave form is sinusoid, 1 if wave form is triangle.
				 * Range: 0 or 1
				 * Default: 1
				 */
				u32 Waveform;

				/* This property controls the phase difference between the left and right LFO's. At zero degrees the
				 * two LFOs are synchronized. Use this parameter to create the illusion of an expanded stereo field
				 * of the output signal.
				 * Range: -180 to 180
				 * Default: 90*/
				s32 Phase;

				/* This property sets the modulation rate of the LFO that controls the delay time of the delayed signals.
				 * Range: 0.0 to 10.0
				 * Default: 1.1
				 */
				f32 Rate;

				/* This property controls the amount by which the delay time is modulated by the LFO.
				 * Range: 0.0 to 1.0
				 * Default: 0.1
				 */
				f32 Depth;

				/* This property controls the amount of processed signal that is fed back to the input of the chorus
				 * effect. Negative values will reverse the phase of the feedback signal. At full magnitude the
				 * identical sample will repeat endlessly. At lower magnitudes the sample will repeat and fade out
				 * over time. Use this parameter to create a "cascading" chorus effect.
				 * Range: -1.0 to 1.0
				 * Default: 0.25
				 */
				f32 Feedback;

				/* This property controls the average amount of time the sample is delayed before it is played back,
				 * and with feedback, the amount of time between iterations of the sample. Larger values lower the
				 * pitch. Smaller values make the chorus sound like a flanger, but with different frequency
				 * characteristics.
				 * Range: 0.0 to 0.016
				 * Default: 0.016
				 */
				f32 Delay;
		};

		//! Default constructor
		SSoundEffectChorus::SSoundEffectChorus() :
				SSoundEffect(), Waveform(1), Phase(90), Rate(1.1), Depth(0.1), Feedback(
						0.25), Delay(0.016)
		{
		}

		//! Destructor
		SSoundEffectChorus::~SSoundEffectChorus()
		{

		}

		//! Return effect type
		ESoundEffectType SSoundEffectChorus::getType()
		{
			return ESET_CHORUS;
		}

	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECTCHORUS_H_ */
