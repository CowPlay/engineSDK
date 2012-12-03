/*
 * irrgame.h
 *
 *  Created on: Jul 24, 2012
 *      Author: gregorytkach
 */

#ifndef IRRGAME_H_
#define IRRGAME_H_

#include "compileConfig.h"
#include "IEngineApplication.h"
#include "IEnginePlayer.h"

//events
#include "events/EEventTypes.h"
#include "events/IEvent.h"
#include "events/IEventReceiver.h"

//engine events
#include "events/engine/SharedEventScheduler.h"
#include "events/engine/IEngineEvent.h"

//user events
#include "events/user/ECursorStates.h"
#include "events/user/EUserEventTypes.h"
#include "events/user/EUserKeyStates.h"
#include "events/user/EUserKeys.h"
#include "events/user/IUserEvent.h"
#include "events/user/IUserEventHandler.h"
#include "events/user/SCursorInfo.h"

//core
#include "core/collections.h"
#include "core/math.h"
#include "core/shapes.h"
#include "core/delegate.h"

//io
#include "io/utils/StaticIOUtils.h"
#include "io/SharedFileSystem.h"
#include "io/IReadFile.h"
#include "io/IWriteFile.h"
#include "io/SPath.h"

#include "io/xml/IXMLReader.h"
#include "io/xml/IXMLWriter.h"

#include "io/config/IConfigReader.h"
#include "io/config/IPlayerConfigReader.h"

//logic
//#include "IGameObject.h"

//threads

#include "threads/IMonitor.h"
#include "threads/IThread.h"

//video
#include "video/utils/SharedVideoUtils.h"
#include "video/driver/IVideoDriver.h"
#include "video/color.h"

#endif /* IRRGAME_H_ */
