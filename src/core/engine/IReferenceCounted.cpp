/*
 * IReferenceCounted.cpp
 *
 *  Created on: Aug 14, 2012
 *      Author: gregorytkach
 */

#include "core/engine/IReferenceCounted.h"
#include "threads/IThread.h"
#include "threads/IMonitor.h"

namespace irrgame
{

	//! Constructor.
	IReferenceCounted::IReferenceCounted() :
			DebugName(0), ReferenceCounter(1)
	{
		Monitor = threads::IMonitor::createMonitor();
	}

	//! Destructor.
	IReferenceCounted::~IReferenceCounted()
	{
		if (Monitor)
			Monitor->drop();
	}

	//! Grabs the object. Increments the reference counter by one.
	void IReferenceCounted::grab() const
	{
		Monitor->enter();
		++ReferenceCounter;
		Monitor->exit();
	}

	//! Drops the object. Decrements the reference counter by one.
	bool IReferenceCounted::drop() const
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

	//! Get the reference count.
	s32 IReferenceCounted::getReferenceCount() const
	{
		return ReferenceCounter;
	}

	//! Returns the debug name of the object.
	const c8* IReferenceCounted::getDebugName() const
	{
		return DebugName;
	}

	//! Sets the debug name of the object.
	void IReferenceCounted::setDebugName(const c8* newName)
	{
		DebugName = newName;
	}
}

