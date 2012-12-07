/*
 * irrgameApp.h
 *
 *  Created on: Jul 23, 2012
 *      Author: gregorytkach
 */

#ifndef IENGINEAPPLICATION_H_
#define IENGINEAPPLICATION_H_

#include "core/engine/IReferenceCountedSafe.h"

namespace irrgame
{
	class IEnginePlayer;

	class IEngineApplication: public IReferenceCountedSafe
	{

		public:
			//! Default constructor
			//			irrgameApp(irrgamePlayer* player);

			//! Destructor
			virtual ~IEngineApplication()
			{
			}

			virtual void run() = 0;

//			virtual void onApplicationSuspend() = 0;

	};

} //end namespace irrgame

#endif /* IENGINEAPPLICATION_H_ */
