/*
 * SSoundEffectFlanger.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECTFLANGER_H_
#define SSOUNDEFFECTFLANGER_H_

#include "SSoundEffect.h"

namespace irrgame
{
	namespace audio
	{
		//! The flanger effect creates a "tearing" or "whooshing" sound (like a jet flying overhead).
		struct SSoundEffectFlanger: public SSoundEffect
		{
			public:

				//! Default constructor
				SSoundEffectFlanger();

				//! Destructor
				virtual ~SSoundEffectFlanger();

				//! Return effect type
				virtual ESoundEffectType getType();

			public:
				/* Selects the shape of the LFO waveform that controls the amount of the delay of the sampled signal.
				 * 0 if wave form is sinusoid, 1 if wave form is triangle.
				 * Range: 0 or 1
				 * Default: 1
				 */
				u32 Waveform;

				/* This changes the phase difference between the left and right LFO's. At zero degrees the two LFOs are synchronized.
				 * Range: -180 to 180
				 * Default: 0
				 */
				s32 Phase;

				/* The number of times per second the LFO controlling the amount of delay repeats. Higher values increase the pitch modulation.
				 * Range: 0.0 to 10.0
				 * Default: 0.27
				 */
				f32 Rate;

				/* The ratio by which the delay time is modulated by the LFO. Use this parameter to increase the pitch modulation.
				 * Range: 0.0 to 1.0
				 * Default: 1.0
				 */
				f32 Depth;

				/* This is the amount of the output signal level fed back into the effect's input.
				 * A negative value will reverse the phase of the feedback signal. Use this parameter
				 * to create an "intense metallic" effect. At full magnitude, the identical sample will
				 * repeat endlessly. At less than full magnitude, the sample will repeat and fade out over time.
				 * Range: -1.0 to 1.0
				 * Default: -0.5
				 */
				f32 Feedback;

				/* The average amount of time the sample is delayed before it is played back; with feedback, the amount of time between iterations of the sample.
				 * Range: 0.0 to 0.004
				 * Default: 0.002
				 */
				f32 Delay;
		};

		//! Default constructor
		SSoundEffectFlanger::SSoundEffectFlanger() :
				SSoundEffect(), Waveform(1), Phase(0), Rate(0.27), Depth(1.0), Feedback(
						-0.5), Delay(0.002)
		{
		}

		//! Destructor
		SSoundEffectFlanger::~SSoundEffectFlanger()
		{

		}

		//! Return effect type
		ESoundEffectType SSoundEffectFlanger::getType()
		{
			return ESET_FLANGER;
		}

	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECTFLANGER_H_ */
