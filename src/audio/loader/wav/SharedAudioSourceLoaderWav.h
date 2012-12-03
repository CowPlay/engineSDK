/*
 * CMp3Loader.h
 *
 *  Created on: Oct 30, 2012
 *      Author: litirvi
 */

#ifndef SHAREDAUDIOSOURCELOADERWAV_H_
#define SHAREDAUDIOSOURCELOADERWAV_H_

#include "audio/SAudioSource.h"

namespace irrgame
{
	namespace io
	{
		class IReadFile;
	}  // namespace io

	namespace audio
	{

		//! Class that can load an WAVE file and read its specifications.
		class SharedAudioSourceLoaderWav
		{

			public:
				//! Singleton realization
				static SharedAudioSourceLoaderWav& getInstance();

			private:
				//! Default constructor. Should use only one time.
				SharedAudioSourceLoaderWav();

				//! Destructor. Should use only one time.
				virtual ~SharedAudioSourceLoaderWav();

			public:

				//! Returns a structure containing information about the uploaded file
				SAudioSource* createAudioSource(io::IReadFile* file,
						ISoundManager* manager);
		};

	} // end namespace audio
} // end namespace irrgame

#endif /* SHAREDAUDIOSOURCELOADERWAV_H_ */
