/*
 * SSoundEffect.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECT_H_
#define SSOUNDEFFECT_H_

#include "core/engine/IReferenceCounted.h"
#include "audio/sfx/ESoundEffectType.h"

namespace irrgame
{
	namespace audio
	{
		//! Base type for sound effects
		struct SSoundEffect: public IReferenceCounted
		{
			public:
				//! Destructor
				virtual ~SSoundEffect()
				{
				}

				//! Return effect type
				virtual ESoundEffectType* getType() = 0;
		};

		//! Internal function. Please do not use.
		SSoundEffect* createSoundEffectAutowah();

	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECT_H_ */
