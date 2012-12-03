/*
 * SSoundEffectEcho.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECTECHO_H_
#define SSOUNDEFFECTECHO_H_

#include "SSoundEffect.h"

namespace irrgame
{
	namespace audio
	{
		//! The echo effect generates discrete, delayed instances of the input signal.
		struct SSoundEffectEcho: public SSoundEffect
		{
			public:

				//! Default constructor
				SSoundEffectEcho();

				//! Destructor
				virtual ~SSoundEffectEcho();

				//! Return effect type
				virtual ESoundEffectType getType();

			public:
				/* This property controls the delay between the original sound and the first "tap", or echo instance.
				 * Range: 0.0 to 0.207
				 * Default: 0.1
				 */
				f32 Delay;

				/* This property controls the delay between the first "tap" and the second "tap".
				 * Range: 0.0 to 0.404
				 * Default: 0.1
				 */
				f32 LRDelay;

				/* This property controls the amount of high frequency damping applied to each echo. As the sound
				 * is subsequently fed back for further echoes, damping results in an echo which progressively gets
				 * softer in tone as well as intensity.
				 * Range: 0.0 to 0.99
				 * Default: 0.5
				 */
				f32 Damping;

				/* This property controls the amount of feedback the output signal fed back into the input. Use this
				 * parameter to create "cascading" echoes. At full magnitude, the identical sample will repeat
				 * endlessly. Below full magnitude, the sample will repeat and fade.
				 * Range: 0.0 to 1.0
				 * Default: 0.5
				 */
				f32 Feedback;

				/* This property controls how hard panned the individual echoes are. With a value of 1.0, the first
				 * "tap" will be panned hard left, and the second "tap" hard right. A value of -1.0 gives the opposite
				 * result. Settings nearer to 0.0 result in less emphasized panning.
				 * Range: -1.0 to 1.0
				 * Default: -1.0
				 */
				f32 Spread;
		};

		//! Default constructor
		SSoundEffectEcho::SSoundEffectEcho() :
				SSoundEffect(), Delay(0.1), LRDelay(0.1), Damping(0.5), Feedback(
						0.5), Spread(-1.0)
		{
		}

		//! Destructor
		SSoundEffectEcho::~SSoundEffectEcho()
		{
		}

		//! Return effect type
		ESoundEffectType SSoundEffectEcho::getType()
		{
			return ESET_ECHO;
		}

	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECTECHO_H_ */
