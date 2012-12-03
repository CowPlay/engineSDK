/*
 * StaticVorbisExtention.h
 *
 *  Created on: Nov 22, 2012
 *      Author: developer08
 */

#ifndef STATICVORBISEXTENTION_H_
#define STATICVORBISEXTENTION_H_

#include "core/collections/ICollection.h"
#include "libvorbis/include/vorbis/codec.h"

namespace irrgame
{
	namespace audio
	{

		class StaticVorbisExtention
		{
			public:

				//!Reading function.
				static size_t readOgg(void* ptr, size_t size, size_t nmemb,
						void* datasource);

				//!Seeking function.
				/**If the data source is not seekable (or the application
				 * wants the data source to be treated as unseekable at all times), the
				 * provided seek callback should always return -1 (failure) or the seek_func
				 * and tell_func fields should be set to NULL.*/
				static s32 seekOgg(void* datasource, ogg_int64_t offset,
						s32 whence);

				//!Location function.
				/**If the data source is not seekable (or the application wants the
				 * data source to be treated as unseekable at all times), the provided
				 * tell callback should always return -1 (failure) or the seek_func and
				 * tell_func fields should be set to NULL. */
				static long tellOgg(void* datasource);

				//!Source closure function.
				/**Set to NULL if libvorbisfile should not attempt to automatically
				 * close the file/data handle. */
				static s32 closeOgg(void* datasource);
		};

	} /* namespace audio */
} /* namespace irrgame */

#endif /* STATICVORBISEXTENTION_H_ */
