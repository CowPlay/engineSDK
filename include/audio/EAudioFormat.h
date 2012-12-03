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
			//! Represents mono 8 bit(?) format
			EAF_MONO8 = 0,

			EAF_MONO16,
			EAF_STEREO8,
			EAF_STEREO16,

			//! Not used
			EAF_COUNT
		};

	} // namespace audio
} // namespace irrgame

#endif /* EAUDIOFORMAT_H_ */
