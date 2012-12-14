/*
 * SChunkHeader.h
 *
 *  Created on: Nov 12, 2012
 *      Author: gregorytkach
 */

#ifndef SCHUNKHEADER_H_
#define SCHUNKHEADER_H_

#include "compileConfig.h"

namespace irrgame
{
	namespace scene
	{
#if defined(_MSC_VER) ||  defined(__BORLANDC__) || defined (__BCPLUSPLUS__)
#	pragma pack( push, packing )
#	pragma pack( 1 )
#	define PACK_STRUCT
#elif defined( __GNUC__ )
#	define PACK_STRUCT	__attribute__((packed))
#else
#	error compiler not supported
#endif

		// byte-align structures
		struct SChunkHeader
		{
			public:
				u16 ID;
				s32 Length;
		}PACK_STRUCT;

	// Default alignment
#if defined(_MSC_VER) ||  defined(__BORLANDC__) || defined (__BCPLUSPLUS__)
#	pragma pack( pop, packing )
#endif

#undef PACK_STRUCT
	} // namespace scene
}  // namespace irrgame

#endif /* SCHUNKHEADER_H_ */
