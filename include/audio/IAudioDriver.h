/*
 * IAudioDriver.h
 *
 *  Created on: Oct 29, 2012
 *      Author: litirvi
 */

#ifndef IAUDIODRIVER_H_
#define IAUDIODRIVER_H_

#include "core/engine/IReferenceCountedSafe.h"
#include "core/collections/stringc.h"

namespace irrgame
{
	namespace audio
	{
		//! Interface to currently used audio driver.
		class IAudioDriver: public IReferenceCountedSafe
		{
			public:

				//! Destructor
				virtual ~IAudioDriver()
				{
				}
		};

		//! Internal function. Please do not use.
		IAudioDriver* createAudioDriver();

	} // end namespace audio
} // end namespace irrgame

#endif /* IAUDIODRIVER_H_ */
