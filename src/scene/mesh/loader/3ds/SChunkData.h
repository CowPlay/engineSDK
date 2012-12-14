/*
 * SChunkData.h
 *
 *  Created on: Nov 12, 2012
 *      Author: gregorytkach
 */

#ifndef SCHUNKDATA_H_
#define SCHUNKDATA_H_

#include "SChunkHeader.h"

namespace irrgame
{
	namespace scene
	{

		struct SChunkData
		{
			public:
				//! Default constructor
				SChunkData();

			public:
				SChunkHeader Header;
				s32 Read;
		};

	} // namespace scene
}  // namespace irrgame

#endif /* SCHUNKDATA_H_ */
