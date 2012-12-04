/*
 * irrgamePlayer.h
 *
 *  Created on: Jul 23, 2012
 *      Author: gregorytkach
 */

#ifndef IENGINEPLAYER_H_
#define IENGINEPLAYER_H_

#include "compileConfig.h"
#include "io/SPath.h"
#include "io/config/IPlayerConfigReader.h"
#include "IEngineApplication.h"

namespace irrgame
{
	namespace audio
	{
		class IAudioDriver;
		class ISoundManager;
	}  // namespace audio

	namespace events
	{
		class IUserEventHandler;
	}  // namespace events

	namespace io
	{
		class SharedFileSystem;
	}  // namespace io

	namespace scene
	{
		class ISceneManager;
	}  // namespace scene

	namespace video
	{
		class IVideoDriver;
	}  // namespace video

	class IEngineApplication;

	//! Interface of most important object in irrgame.
	class IEnginePlayer: public IReferenceCounted
	{

			/*
			 * Static functions
			 */
		public:
			//! Player creator
			static IEnginePlayer* createEnginePlayer();

			/*
			 * Instance methods
			 */
		public:

			//! Destructor
			virtual ~IEnginePlayer()
			{
			}

			//! Return pointer to current audio driver
			virtual audio::IAudioDriver* getAudioDriver() = 0;

			//! Return pointer to current video driver
			virtual video::IVideoDriver* getVideoDriver() = 0;

			//! Return pointer to config reader
			virtual io::IPlayerConfigReader* getConfigReader() = 0;

			//! Return pointer to scene manager
			virtual scene::ISceneManager* getSceneManager() = 0;

			//! Return pointer to audio manager
			virtual audio::ISoundManager* getSoundManager() = 0;

			//! Return pointer to user event handler
			/* If you want handle any user event - you must work with this object. */
			virtual events::IUserEventHandler* getUserEventsHandler() = 0;

			//! Run engine application
			virtual void run(IEngineApplication* application) = 0;

		protected:

			//! Run player internal. Must be overriden in every realization of player.
			/* Need for handle user events, update timers etc. */
			virtual bool runInternal() = 0;
	};

}

#endif /* IENGINEPLAYER_H_ */
