/*
 * COggLoader1.cpp
 *
 *  Created on: Nov 14, 2012
 *      Author: litirvi
 */

#include "SharedAudioSourceLoaderOgg.h"
#include "StaticVorbisExtention.h"
#include "SAudioSourceOgg.h"

#include "libvorbis/include/vorbis/vorbisfile.h"
#include "libvorbis/include/vorbis/codec.h"

namespace irrgame
{
	namespace audio
	{

		//! Singleton realization
		SharedAudioSourceLoaderOgg& SharedAudioSourceLoaderOgg::getInstance()
		{
			static SharedAudioSourceLoaderOgg instance;
			return instance;
		}

		SharedAudioSourceLoaderOgg::SharedAudioSourceLoaderOgg()
		{
		}

		SharedAudioSourceLoaderOgg::~SharedAudioSourceLoaderOgg()
		{
		}

		SAudioSource* SharedAudioSourceLoaderOgg::createAudioSource(
				io::IReadFile* file, ISoundManager* manager)
		{

			//check Ogg
			c8* isOgg = new c8[4];
			file->seek(0, false);
			file->read(isOgg, 4);

			core::stringc strIsOgg(isOgg);
			IRR_ASSERT(strIsOgg == "OggS");
			delete[] isOgg;

			SAudioSourceOgg* result = 0;
			result = new SAudioSourceOgg(manager);
			result->File = file;

			// Structure with callback functions.
			ov_callbacks cb;

			cb.close_func = &StaticVorbisExtention::closeOgg;
			cb.read_func = &StaticVorbisExtention::readOgg;
			cb.seek_func = &StaticVorbisExtention::seekOgg;
			cb.tell_func = &StaticVorbisExtention::tellOgg;

			OggVorbis_File* VorbisFile = new OggVorbis_File;

			IRR_ASSERT( ov_open_callbacks(file, VorbisFile, NULL, -1, cb) >= 0);

			// get comments and information about the file
			result->Comment = ov_comment(VorbisFile, -1);
			vorbis_info* Info = ov_info(VorbisFile, -1);

			result->Rate = Info->rate;
			result->Format = (Info->channels == 1) ? EAF_MONO16 : EAF_STEREO16;
			result->BufferSize = ov_pcm_total(VorbisFile, -1) * 4;

			return result;
		}

	} // end namespace audio
} // end namespace irrgame

