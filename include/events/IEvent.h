/*
 * IEvent.h
 *
 *  Created on: Sep 12, 2012
 *      Author: gregorytkach
 */

#ifndef IEVENT_H_
#define IEVENT_H_

#include "core/engine/IReferenceCountedSafe.h"
#include "events/EEventTypes.h"

namespace irrgame
{
	namespace events
	{

		//! Base class for all events
		class IEvent: public IReferenceCountedSafe
		{
			public:

				//! Destructor
				virtual ~IEvent()
				{
				}

				//! Returns event type
				virtual EEventTypes getType() = 0;
		};

	}  // namespace events
}
// namespace irrgame

#endif /* IEVENT_H_ */
