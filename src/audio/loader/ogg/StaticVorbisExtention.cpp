/*
 * StaticVorbisExtention.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: developer08
 */

#include "StaticVorbisExtention.h"
#include "io/IReadFile.h"

namespace irrgame
{
	namespace audio
	{
		size_t StaticVorbisExtention::readOgg(void* ptr, size_t size,
				size_t nmemb, void* datasource)
		{
			size_t result;

			io::IReadFile* file = reinterpret_cast<io::IReadFile*>(datasource);
			result = file->read((c8*) ptr, size * nmemb);

			return result;
		}

		s32 StaticVorbisExtention::seekOgg(void* datasource, ogg_int64_t offset,
				s32 whence)
		{
			s32 result;

			IRR_ASSERT(datasource);

			io::IReadFile* file = reinterpret_cast<io::IReadFile*>(datasource);
			file->seek(0, false);

			bool relativeMovement;

			switch (whence)
			{
				case SEEK_SET:
				{
					relativeMovement = false;

					result =
							(file->seek((long) offset, relativeMovement) ?
									0 : -1);

					break;
				}
				case SEEK_CUR:
				{
					relativeMovement = true;

					result =
							(file->seek((long) offset, relativeMovement) ?
									0 : -1);

					break;
				}

				case SEEK_END:
				{
					relativeMovement = false;

					if (offset <= 0)
					{
						offset = (file->getSize() - 1) - offset;
						result = (
								file->seek((long) offset, relativeMovement) ?
										0 : -1);
					}
					else
					{
						result = -1;
					}

					break;
				}

				default:
				{
					//Not implemented
					IRR_ASSERT(false);
					break;
				}
			}

			return result;
		}

		long StaticVorbisExtention::tellOgg(void *datasource)
		{
			io::IReadFile *file = reinterpret_cast<io::IReadFile*>(datasource);
			return file->getPos();
		}

		s32 StaticVorbisExtention::closeOgg(void* datasource)
		{
			return 0;
		}
	} /* namespace audio */
} /* namespace irrgame */
