/*
 * SSoundEffectCompressor.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECTCOMPRESSOR_H_
#define SSOUNDEFFECTCOMPRESSOR_H_

#include "SSoundEffect.h"

namespace irrgame
{
	namespace audio
	{
		//! The Automatic Gain Control effect performs the same task as a studio compressor,
		//! evening out the audio dynamic range of an input sound.
		struct SSoundEffectCompressor: public SSoundEffect
		{
			public:

				//! Default constructor
				SSoundEffectCompressor();

				//! Destructor
				virtual ~SSoundEffectCompressor();

				//! Return effect type
				virtual ESoundEffectType getType();

			public:

				/*The Compressor can only be switched on and off  it cannot be adjusted.
				 * Default: True)
				 */
				bool Active;
		};

		//! Default constructor
		SSoundEffectCompressor::SSoundEffectCompressor() :
				SSoundEffect(), Active(true)
		{
		}

		//! Destructor
		SSoundEffectCompressor::~SSoundEffectCompressor()
		{
		}

		//! Return effect type
		ESoundEffectType SSoundEffectCompressor::getType()
		{
			return ESET_COMPRESSOR;
		}

	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECTCOMPRESSOR_H_ */
