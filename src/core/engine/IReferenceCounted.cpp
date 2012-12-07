/*
 * IReferenceCounted.cpp
 *
 *  Created on: Dec 7, 2012
 *      Author: developer08
 */

#include "core/engine/IReferenceCounted.h"

namespace irrgame
{

	//! Default constructor.
	IReferenceCounted::IReferenceCounted() :
			DebugName(0), ReferenceCounter(1)
	{
	}

	//! Destructor.
	IReferenceCounted::~IReferenceCounted()
	{
	}

	//! Grabs the object. Increments the reference counter by one.
	void IReferenceCounted::grab() const
	{
		++ReferenceCounter;
	}

	//! Drops the object. Decrements the reference counter by one.
	bool IReferenceCounted::drop() const
	{
		// someone is doing bad reference counting.
		IRR_ASSERT(ReferenceCounter > 0)

		--ReferenceCounter;

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

}  // namespace irrgame
