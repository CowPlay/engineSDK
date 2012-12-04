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

		//TODO: write comment, see ref: ISceneManager::addSceneNode()
		ISoundNode* CSoundManager::addSoundNode(SAudioSource* source)
		{
			return createSoundNode(this, source);
		}

		//TODO: write comment, see ISceneManager::getRoot
		ISoundNode* CSoundManager::getRoot()
		{
			return this;
		}


		//! Internal function. Please do not use.
		ISoundManager* createSoundManager()
		{
			return new CSoundManager;
		}

	} /* namespace audio */
} /* namespace irrgame */
