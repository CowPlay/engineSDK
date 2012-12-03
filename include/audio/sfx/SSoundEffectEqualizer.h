/*
 * SSoundEffectEqualizer.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECTEQUALIZER_H_
#define SSOUNDEFFECTEQUALIZER_H_

#include "SSoundEffect.h"

namespace irrgame
{
	namespace audio
	{
		//! The Effects Extension EQ is very flexible, providing tonal control over four different
		//! adjustable frequency ranges.
		struct SSoundEffectEqualizer: public SSoundEffect
		{
			public:

				//! Default constructor
				SSoundEffectEqualizer();

				//! Destructor
				virtual ~SSoundEffectEqualizer();

				//! Return effect type
				virtual ESoundEffectType getType();

			public:

				/* This property controls amount of cut or boost on the low frequency range.
				 * Range: 0.126 to 7.943
				 * Default: 1.0
				 */
				f32 LowGain;

				/* This property controls the low frequency below which signal will be cut off.
				 * Range: 50.0 to 800.0 Default: 200.0*/
				f32 LowCutoff;

				/* This property allows you to cut / boost signal on the "mid1" range.
				 * Range: 0.126 to 7.943
				 * Default: 1.0
				 */
				f32 Mid1Gain;

				/* This property sets the center frequency for the "mid1" range.
				 * Range: 200.0 to 3000.0
				 * Default: 500.0
				 */
				f32 Mid1Center;

				/* This property controls the width of the "mid1" range.
				 * Range: 0.01 to 1.0
				 * Default: 1.0
				 */
				f32 Mid1Width;

				/* This property allows you to cut / boost signal on the "mid2" range.
				 * Range: 0.126 to 7.943
				 * Default: 1.0
				 */
				f32 Mid2Gain;

				/* This property sets the center frequency for the "mid2" range.
				 * Range: 1000.0 to 8000.0
				 * Default: 3000.0
				 */
				f32 Mid2Center;

				/* This property controls the width of the "mid2" range.
				 * Range: 0.01 to 1.0
				 * Default: 1.0
				 */
				f32 Mid2Width;

				/* This property allows you to cut / boost the signal at high frequencies.
				 * Range: 0.126 to 7.943
				 * Default: 1.0
				 */
				f32 HighGain;

				/* This property controls the high frequency above which signal will be cut off.
				 * Range: 4000.0 to 16000.0
				 * Default: 6000.0
				 */
				f32 HighCutoff;
		};

		//! Default constructor
		SSoundEffectEqualizer::SSoundEffectEqualizer() :
				SSoundEffect(), LowGain(1.0), LowCutoff(200.0), Mid1Gain(1.0), Mid1Center(
						500.0), Mid1Width(1.0), Mid2Gain(1.0), Mid2Center(
						3000.0), Mid2Width(1.0), HighGain(1.0), HighCutoff(
						6000.0)
		{
		}

		//! Destructor
		SSoundEffectEqualizer::~SSoundEffectEqualizer()
		{
		}

		//! Return effect type
		ESoundEffectType SSoundEffectEqualizer::getType()
		{
			return ESET_EQUALIZER;
		}
	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECTEQUALIZER_H_ */
