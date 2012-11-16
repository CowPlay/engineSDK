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
		if(Monitor)
			Monitor->drop();
	}

	//! Grabs the object. Increments the reference counter by one.
	/** Someone who calls grab() to an object, should later also
	 call drop() to it. If an object never gets as much drop() as
	 grab() calls, it will never be destroyed. The
	 IReferenceCounted class provides a basic reference counting
	 mechanism with its methods grab() and drop(). Most objects of
	 the Irrlicht Engine are derived from IReferenceCounted, and so
	 they are reference counted.

	 When you create an object in the Irrlicht engine, calling a
	 method which starts with 'create', an object is created, and
	 you get a pointer to the new object. If you no longer need the
	 object, you have to call drop(). This will destroy the object,
	 if grab() was not called in another part of you program,
	 because this part still needs the object. Note, that you only
	 need to call drop() to the object, if you created it, and the
	 method had a 'create' in it.

	 A simple example:

	 If you want to create a texture, you may want to call an
	 imaginable method IDriver::createTexture. You call
	 ITexture* texture = driver->createTexture(dimension2d<u32>(128, 128));
	 If you no longer need the texture, call texture->drop().
	 If you want to load a texture, you may want to call imaginable
	 method IDriver::loadTexture. You do this like
	 ITexture* texture = driver->loadTexture("example.jpg");
	 You will not have to drop the pointer to the loaded texture,
	 because the name of the method does not start with 'create'.
	 The texture is stored somewhere by the driver. */
	void IReferenceCounted::grab() const
	{
		Monitor->enter();
		++ReferenceCounter;
		Monitor->exit();
	}

	//! Drops the object. Decrements the reference counter by one.
	/** The IReferenceCounted class provides a basic reference
	 counting mechanism with its methods grab() and drop(). Most
	 objects of the Irrlicht Engine are derived from
	 IReferenceCounted, and so they are reference counted.

	 When you create an object in the Irrlicht engine, calling a
	 method which starts with 'create', an object is created, and
	 you get a pointer to the new object. If you no longer need the
	 object, you have to call drop(). This will destroy the object,
	 if grab() was not called in another part of you program,
	 because this part still needs the object. Note, that you only
	 need to call drop() to the object, if you created it, and the
	 method had a 'create' in it.

	 A simple example:

	 If you want to create a texture, you may want to call an
	 imaginable method IDriver::createTexture. You call
	 ITexture* texture = driver->createTexture(dimension2d<u32>(128, 128));
	 If you no longer need the texture, call texture->drop().
	 If you want to load a texture, you may want to call imaginable
	 method IDriver::loadTexture. You do this like
	 ITexture* texture = driver->loadTexture("example.jpg");
	 You will not have to drop the pointer to the loaded texture,
	 because the name of the method does not start with 'create'.
	 The texture is stored somewhere by the driver.
	 \return True, if the object was deleted. */
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

