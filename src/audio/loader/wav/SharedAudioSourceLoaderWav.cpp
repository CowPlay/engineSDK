/*
 * CMp3Loader.cpp
 *
 *  Created on: Oct 30, 2012
 *      Author: litirvi
 */

#include "SharedAudioSourceLoaderWav.h"
#include "audio/utils/StaticAudioUtils.h"
#include "SAudioSourceWav.h"

#include "io/SharedFileSystem.h"

namespace irrgame
{
	namespace audio
	{
		//! Singleton realization
		SharedAudioSourceLoaderWav& SharedAudioSourceLoaderWav::getInstance()
		{
			static SharedAudioSourceLoaderWav instance;
			return instance;
		}

		SharedAudioSourceLoaderWav::SharedAudioSourceLoaderWav()
		{
		}

		SharedAudioSourceLoaderWav::~SharedAudioSourceLoaderWav()
		{
		}

		SAudioSource* SharedAudioSourceLoaderWav::createAudioSource(
				io::IReadFile* file, ISoundManager* manager)
		{
			IRR_ASSERT(file && manager);

			//read information from a file to audio source

			//check is Wave
			c8* isWave = new c8[4];
			file->seek(8, false);
			file->read(isWave, 4);
			core::stringc strIsOgg(isWave);
			IRR_ASSERT(strIsOgg == "WAVE");
			delete[] isWave;

			SAudioSourceWav* result = new SAudioSourceWav(manager);
			result->File = file;

			u32 channels = 0;
			file->seek(22, false);
			file->read(&channels, 2);

			u32 bit = 0;
			file->seek(34, false);
			file->read(&bit, 2);

			result->Format = StaticAudioUtils::getAudioFormat(channels, bit);

			file->seek(28, false); // or 24
			file->read(&result->Rate, 4);

			file->seek(40, false); // or  4
			file->read(&result->BufferSize, 4);

			file->seek(44, false);
			result->Buffer = new c8[result->BufferSize];
			file->read(result->Buffer, result->BufferSize);

			return result;
		}

	} // end namespace audio
} // end namespace irrgame
