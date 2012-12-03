/*
 * ESoundFilterTypes.h
 *
 *  Created on: Nov 27, 2012
 *      Author: developer08
 */

#ifndef ESOUNDFILTERTYPES_H_
#define ESOUNDFILTERTYPES_H_

namespace irrgame
{
	namespace audio
	{
		//! Enum of all available filter types.
		enum ESoundFilterType
		{
			//TODO:
//			ESFT_NULL = 0,
			//
			ESFT_LOWPASS = 0,
			//
			ESFT_HIGHPASS,
			//
			ESFT_BANDPASS,

			//! Not used
			ESFT_COUNT
		};

	}  // namespace audio
}  // namespace irrgame

#endif /* ESOUNDFILTERTYPES_H_ */
