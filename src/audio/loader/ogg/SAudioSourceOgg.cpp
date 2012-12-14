/*
 * CAudioSourceStreamed.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: developer08
 */

#include "SAudioSourceOgg.h"

namespace irrgame
{
	namespace audio
	{

		//! Default constructor
		SAudioSourceOgg::SAudioSourceOgg(ISoundManager* manager) :
				SAudioSource(manager), VorbisFile(0), Comment(0), Info(0)
		{
		}

		//! Destructor
		SAudioSourceOgg::~SAudioSourceOgg()
		{
			if (!VorbisFile)
			{
				ov_clear(VorbisFile);
				delete VorbisFile;
			}
		}

		//! Returns True if audio source can be streamed. Otherwise return False.
		bool SAudioSourceOgg::isStreamed()
		{
			return true;
		}

		//! Replaces the contents of the buffer for streaming audio.
		void SAudioSourceOgg::update(u32 size)
		{
			IRR_ASSERT(size >= 1);

			s32 currentSection;

			u32 totalRet = 0, ret;
			c8* PCM;

			PCM = new char[size];

			while (totalRet < size)
			{
				ret = ov_read(VorbisFile, PCM + totalRet, size - totalRet, 0, 2,
						1, &currentSection);

				// If the end of file
				if (ret == 0)
				{
					break;
				}
				else
				{
					IRR_ASSERT(ret >= 0);
					totalRet += ret;
				}
			}

			this->BufferSize = size;
			this->Buffer = PCM;

			delete[] PCM;
		}

	} /* namespace audio */
} /* namespace irrgame */
