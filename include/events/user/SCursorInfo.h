/*
 * SCursorInfo.h
 *
 *  Created on: Oct 19, 2012
 *      Author: gregorytkach
 */

#ifndef SCURSORINFO_H_
#define SCURSORINFO_H_

#include "core/engine/IReferenceCountedSafe.h"
#include "core/shapes/vector2d.h"
#include "events/user/ECursorStates.h"

namespace irrgame
{
	namespace events
	{
		//! Struct which represent pc/mac mouse cursor and finger on touch devices.
		struct SCursorInfo: public IReferenceCountedSafe
		{
			public:

				//! Default constructor
				SCursorInfo(u32 number, ECursorStates state) :
						Number(number), State(state)
				{
				}

			public:

				//! Current cursor position
				vector2di Position;
				//! Last cursor offset
				vector2di Offset;
				//! Cursor number
				u32 Number;
				//! Cursor state
				ECursorStates State;
		};
	}  // namespace events

}  // namespace irrgame

#endif /* SCURSORINFO_H_ */
