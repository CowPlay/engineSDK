///*
// * CAudioSource.cpp
// *
// *  Created on: Nov 22, 2012
// *      Author: developer08
// */
//
//#include "CAudioSourceMemory.h"
//
//namespace irrgame
//{
//	namespace audio
//	{
//
//		CAudioSourceMemory::CAudioSourceMemory(SAudioSourceEntry* entry,
//				IAudioDriver* driver) :
//				Entry(entry), Driver(driver)
//		{
//			if (Entry)
//				Entry->grab();
//		}
//
//		CAudioSourceMemory::~CAudioSourceMemory()
//		{
//			Driver->removeAudioSource(this->Name);
//			if (Entry)
//				Entry->drop();
//		}
//
//		SAudioSourceEntry* CAudioSourceMemory::getEntry()
//		{
//			return Entry;
//		}
//
//		//! Returns audio source name which represents full path.
//		core::stringc CAudioSourceMemory::getName()
//		{
//			return Name;
//		}
//
//		//! Internal function. Please do not use.
//		IAudioSource* createAudioSourceMemory(SAudioSourceEntry* entry,
//				IAudioDriver* driver)
//		{
//			IRR_ASSERT(driver);
//
//			return new CAudioSourceMemory(entry, driver);
//		}
//
//	} /* namespace audio */
//} /* namespace irrgame */
