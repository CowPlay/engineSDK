/*
 * irrgamePlayer.h
 *
 *  Created on: Jul 23, 2012
 *      Author: gregorytkach
 */

#ifndef IENGINEPLAYER_H_
#define IENGINEPLAYER_H_

#include "playerCompileConfig.h"
#include "io/SPath.h"
#include "io/config/IPlayerConfigReader.h"
#include "IEngineApplication.h"

namespace irrgame
{
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

	class irrgameApp;

	//! Interface of most important object in irrgame.
	class IEnginePlayer: public IReferenceCounted
	{
		public:

			//! Destructor
			virtual ~IEnginePlayer()
			{
			}

			//! Gets pointer to config reader
			//! @return - pointer to config reader
			virtual io::IPlayerConfigReader* getConfigReader() = 0;

			virtual scene::ISceneManager* getSceneManager() = 0;

			virtual video::IVideoDriver* getVideoDriver() = 0;

			//! Returns user event receiver
			/* If you want handle any user event - you must work with this object.
			 * */
			virtual events::IUserEventHandler* getUserEventsHandler() = 0;

			virtual void run(irrgameApp* application) = 0;

			//! This func need for flush OpenGL context
			virtual void flush() = 0;

			//get application

		protected:

			//! Run player internal. Must be overriden in every realization of player.
			//! Handle user events in this func
			virtual bool runInternal() = 0;
	};

	//! irrgamePlayer creator
	irrgamePlayer* createIrrgamePlayer();
}

#endif /* IENGINEPLAYER_H_ */
