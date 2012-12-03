/*
 * IThread.cpp
 *
 *  Created on: Aug 13, 2012
 *      Author: gregorytkach asdasd
 */

#include "threads/IThread.h"

namespace irrgame
{
	namespace threads
	{

		//! Gets callback input args
		void* IThread::getCallbackArg()
		{
			return CallbackArg;
		}

		//! Gets thread callback
		delegateThreadCallback* IThread::getCallback()
		{
			return Callback;
		}
	}
}

