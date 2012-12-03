/*
 * COggLoader.h
 *
 *  Created on: Nov 7, 2012
 *      Author: litirvi
 */

#ifndef SHAREDAUDIOLOADEROGG_H_
#define SHAREDAUDIOLOADEROGG_H_

#include "audio/SAudioSource.h"
#include "io/IReadFile.h"

namespace irrgame
{
	namespace audio
	{

		//! Class that can load an OGG file and read its specifications.
		class SharedAudioSourceLoaderOgg
		{
			public:
				//! Singleton realization
				static SharedAudioSourceLoaderOgg& getInstance();

			private:
				//! Default constructor. Should use only one time.
				SharedAudioSourceLoaderOgg();

				//! Destructor. Should use only one time.
				virtual ~SharedAudioSourceLoaderOgg();

			public:
				//! Returns a structure containing information about the uploaded file
				SAudioSource* createAudioSource(io::IReadFile* file,
						ISoundManager* manager);

		};
	} // end namespace audio
} // end namespace irrgame
#endif /* SHAREDAUDIOLOADEROGG_H_ */
