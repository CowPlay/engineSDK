/*
 * IReferenceCounted.cpp
 *
 *  Created on: Aug 14, 2012
 *      Author: gregorytkach
 */

#include "core/engine/IReferenceCountedSafe.h"
#include "threads/IThread.h"
#include "threads/IMonitor.h"

namespace irrgame
{

	//! Default constructor.
	IReferenceCountedSafe::IReferenceCountedSafe() :
			IReferenceCounted(), Monitor(0)
	{
		Monitor = threads::IMonitor::createMonitor();
	}

	//! Destructor.
	IReferenceCountedSafe::~IReferenceCountedSafe()
	{
		if (Monitor)
			Monitor->drop();
	}

	//! Grabs the object. Increments the reference counter by one.
	void IReferenceCountedSafe::grab() const
	{
		Monitor->enter();
		++ReferenceCounter;
		Monitor->exit();
	}

	//! Drops the object. Decrements the reference counter by one.
	bool IReferenceCountedSafe::drop() const
	{
		// someone is doing bad reference counting.
		IRR_ASSERT(ReferenceCounter > 0)

		Monitor->enter();
		--ReferenceCounter;
		Monitor->exit();

		if (!ReferenceCounter)
		{
			delete this;
			return true;
		}

		return false;
	}

}

