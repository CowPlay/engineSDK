/*
 * CSoundManager.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: developer08
 */

#include "CSoundManager.h"
#include "io/SharedFileSystem.h"
#include "io/utils/StaticIOUtils.h"

#include "audio/loader/wav/SharedAudioSourceLoaderWav.h"
#include "audio/loader/ogg/SharedAudioSourceLoaderOgg.h"

namespace irrgame
{
	namespace audio
	{

		//! Default constructor
		CSoundManager::CSoundManager() :
				ISoundNode(0, 0), Listener(0)
		{
			//create listener
			Listener = createSoundListener();
		}

		//! Destructor
		CSoundManager::~CSoundManager()
		{
			if (Listener)
				Listener->drop();
		}

		SAudioSource* CSoundManager::getAudioSource(const core::stringc& path)
		{
			//TODO: add to cache
			SAudioSource* result = 0;

			io::IReadFile* file =
					io::SharedFileSystem::getInstance().createReadFile(path);

			IRR_ASSERT(file);

			core::stringc* extension = io::StaticIOUtils::getFileNameExtension(
					path);

			if (extension->equalsIgnoreCase("wav"))
			{
				result =
						SharedAudioSourceLoaderWav::getInstance().createAudioSource(
								file, this);
			}
			else if (extension->equalsIgnoreCase("ogg"))
			{
				result =
						SharedAudioSourceLoaderOgg::getInstance().createAudioSource(
								file, this);
			}
			else
			{
				//Not implemented
				IRR_ASSERT(false);
			}

			return result;
		}

		void CSoundManager::removeAudioSource(SAudioSource* value)
		{
			IRR_ASSERT(false);
		}

		ISoundNode* CSoundManager::addSoundNode(SAudioSource* source)
		{
			return createSoundNode(this, source);
		}

		ISoundListener* CSoundManager::getSoundListener()
		{
			return Listener;
		}

		ISoundNode* CSoundManager::getRoot()
		{
			return this;
		}
		void CSoundManager::play(u32 pos, bool loop)
		{
		}
		void CSoundManager::stop()
		{
		}
		void CSoundManager::pause()
		{
		}
		bool CSoundManager::isStreamed()
		{
			return false;
		}
		void CSoundManager::applyEffect(SSoundEffect* value)
		{
		}
		void CSoundManager::removeEffect(SSoundEffect* value)
		{
		}
		void CSoundManager::applyFilter(ESoundFilterType value, f32 gainLf,
				f32 GainHf, f32 gain)
		{
		}
		void CSoundManager::removeFilter(ESoundFilterType value)
		{
		}

		ISoundManager* createSoundManager()
		{
			return new CSoundManager();
		}
	} /* namespace audio */
} /* namespace irrgame */
