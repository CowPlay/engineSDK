/*
 * EAlFormat.h
 *
 *  Created on: Nov 6, 2012
 *      Author: litirvi
 */

#ifndef EAUDIOFORMAT_H_
#define EAUDIOFORMAT_H_

namespace irrgame
{
	namespace audio
	{

		//! Enum which contains all audio formats.
		enum EAudioFormat
		{
			//! Represents mono 8 bit format
			EAF_MONO8 = 0,
			//! Represents mono 16 bit format
			EAF_MONO16,
			//! Represents stereo 8 bit format
			EAF_STEREO8,
			//! Represents stereo 16 bit format
			EAF_STEREO16,

			//! Not used
			EAF_COUNT
		};

	} // namespace audio
} // namespace irrgame

#endif /* EAUDIOFORMAT_H_ */
