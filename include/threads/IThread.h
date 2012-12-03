/*
 * IThread.h
 *
 *  Created on: Jul 25, 2012
 *      Author: gregorytkach
 */

#ifndef ITHREAD_H_
#define ITHREAD_H_

#include "threads/EThreadPriority.h"
#include "core/delegate.h"

namespace irrgame
{
	namespace threads
	{

		//! use this delegate for run some func in individual thread
		typedef delegate<s32, void*> delegateThreadCallback;

		//! Interface providing acces to system thread
		class IThread: public IReferenceCounted
		{
				/*
				 * Static functions
				 */

			public:
				//! IThread creator
				static IThread* createThread(delegateThreadCallback* callback,
						void* callbackArg = 0, EThreadPriority prior =
								ETP_NORMAL);

				//! Causes the operating system to sleep current thread.
				//! Platform dependent
				//@ param0 - time in ms.
				static void sleep(s32 time);

				//! Returns current thread id
				static s32 getCurrentThreadID();

				/*
				 * Instance methods
				 */

			public:

				//! Destructor
				virtual ~IThread()
				{
				}

				//! Causes the operating system to start thread, and optionally supplies an object containing data to be used by the method the thread executes
				//! Platform dependent
				virtual void start() = 0;

				//! Blocks the calling thread until a thread terminates.
				//! Platform dependent
				virtual void join() = 0;

				//! Causes the operating system to kill thread
				//! Platform dependent
				//TODO: implement it
//				virtual void kill() = 0;

				//! Gets thread callback
				virtual delegateThreadCallback* getCallback();

				//! Gets callback input args
				virtual void* getCallbackArg();

			protected:

				//! Function which will be started
				delegateThreadCallback* Callback;

				//! Callback input args
				void* CallbackArg;
		};

	}
}

#endif /* ITHREAD_H_ */
