/*
 * EBufferType.h
 *
 *  Created on: Nov 12, 2012
 *      Author: gregorytkach
 */

#ifndef EBUFFERTYPE_H_
#define EBUFFERTYPE_H_

namespace irrgame
{
	namespace scene
	{
		enum EBufferType
		{
			//! Does not change anything
			EBT_NONE = 0,
			//! Change the vertex mapping
			EBT_VERTEX,
			//! Change the index mapping
			EBT_INDEX,
			//! Change both vertex and index mapping to the same value
			EBT_VERTEX_AND_INDEX,

			//! Not used
			EBT_COUNT
		};
	}  // namespace scene
}  // namespace irrgame

#endif /* EBUFFERTYPE_H_ */
