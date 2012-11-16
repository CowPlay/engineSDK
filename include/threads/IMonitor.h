/*
 * IMonitor.h
 *
 *  Created on: Jul 25, 2012
 *      Author: gregorytkach
 */

#ifndef IMONITOR_H_
#define IMONITOR_H_

#include "core/engine/IReferenceCounted.h"

namespace irrgame
{
	namespace threads
	{
		//! Interface which represent thread locker.
		class IMonitor: public IReferenceCounted
		{
				/*
				 * Static functions
				 */

			public:

				//! IMonitor creator.
				static IMonitor* createMonitor();

				/*
				 * Instance methods
				 */

			public:
				//! Destructor
				virtual ~IMonitor()
				{
				}

				//! Acquires a lock for an object. This action also marks the beginning of a critical section.
				//! No other thread can enter the critical section unless it is executing the instructions
				//! in the critical section using a different locked object.
				virtual void enter() = 0;

				//! Releases the lock on an object. This action also marks the end of a critical section protected by the locked object.
				virtual void exit() = 0;
		};
	}
}

#endif /* IMONITOR_H_ */
