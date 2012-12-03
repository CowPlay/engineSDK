/*
 * SSoundEffectDistirtion.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECTDISTORTION_H_
#define SSOUNDEFFECTDISTORTION_H_

#include "SSoundEffect.h"

namespace irrgame
{
	namespace audio
	{

		//! The distortion effect simulates turning up (overdriving) the gain stage on a guitar amplifier or adding a distortion pedal to an instrument's output.
		struct SSoundEffectDistortion: public SSoundEffect
		{
			public:

				//! Default constructor
				SSoundEffectDistortion();

				//! Destructor
				virtual ~SSoundEffectDistortion();

				//! Return effect type
				virtual ESoundEffectType getType();

			public:

				//! This property controls the shape of the distortion. The higher the value for Edge, the "dirtier" and "fuzzier" the effect.
				/* Range: 0.0 to 1.0
				 * Default: 0.2
				 */
				f32 Edge;

				//! This property allows you to attenuate the distorted sound.
				/* Range: 0.01 to 1.0
				 * Default: 0.05)
				 */
				f32 Gain;

				//! Input signal can have a low pass filter applied, to limit the amount of high frequency signal feeding into the distortion effect.
				/* Range: 80.0 to 24000.0
				 * Default: 8000.0
				 */
				f32 LowpassCutoff;

				//! This property controls the frequency at which the post-distortion attenuation (Gain) is active.
				/* Range: 80.0 to 24000.0
				 * Default: 3600.0
				 */
				f32 EqCenter;

				//! This property controls the bandwidth of the post-distortion attenuation.
				/* Range: 80.0 to 24000.0
				 * Default: 3600.0
				 */
				f32 EqBandwidth;
		};

		//! Default constructor
		SSoundEffectDistortion::SSoundEffectDistortion() :
				SSoundEffect(), Edge(0.2), Gain(0.05), LowpassCutoff(8000.0), EqCenter(
						3600.0), EqBandwidth(3600.0)
		{
		}

		//! Destructor
		SSoundEffectDistortion::~SSoundEffectDistortion()
		{

		}

		//! Return effect type
		ESoundFilterType SSoundEffectDistortion::getType()
		{
			return ESET_DISTORTION;
		}
	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECTDISTORTION_H_ */
