// Copyright (C) 2002-2009 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef IREFERENCECOUNTEDSAFE_H_
#define IREFERENCECOUNTEDSAFE_H_

#include "IReferenceCounted.h"

namespace irrgame
{
	namespace threads
	{
		class IMonitor;
	}

	//! Threadsafe version of base class of most objects of the Irrlicht Engine.
	//! For more information see IReferenceCounted
	class IReferenceCountedSafe : public IReferenceCounted
	{
		public:

			//! Default constructor.
			IReferenceCountedSafe();

			//! Destructor.
			virtual ~IReferenceCountedSafe();

			//! Grabs the object. Increments the reference counter by one.
			//! For more information see IReferenceCounted
			virtual void grab() const;

			//! Drops the object. Decrements the reference counter by one.
			//! For more information see IReferenceCounted
			virtual bool drop() const;

		private:

			//! The thread locker.
			threads::IMonitor* Monitor;
	};

} // end namespace irrgame

#endif /* IREFERENCECOUNTEDSAFE_H_ */

