/*
 * IGameObject.h
 *
 *  Created on: Jul 23, 2012
 *      Author: gregorytkach
 */

#ifndef IGAMEOBJECT_H_
#define IGAMEOBJECT_H_

#include "core/collections.h"
#include "events/IEventReceiver.h"
#include "core/shapes.h"
#include "core/engine/IDimensionalObject.h"

namespace irrgame
{
	namespace audio
	{
		class ISoundNode;
	}  // namespace audio

	namespace scene
	{
		class ISceneNode;
	}  // namespace scene

	class IGameObjectAnimator;

	namespace logic //TODO: rename  or delete namespace
	{
		//! A base class of all game objects.
		/*
		 * Every game object can have only one of video representation (SceneNode),
		 * audio representation (SoundNode).
		 */
		class IGameObject  //: public events::IEventReceiver,
		//public core::IDimensionalObject<IGameObject>
		{
			public:
				//! Default constructor
				//TODO: move to .cpp
				IGameObject() :
						SoundNode(0), SceneNode(0)
				{
				}

				//! Destructor
				//TODO: move to .cpp
				virtual ~IGameObject()
				{
				}

			protected:

				audio::ISoundNode* SoundNode;

				scene::ISceneNode* SceneNode;

		};

	}  // namespace logic

}  // namespace irrgame

#endif /* IGAMEOBJECT_H_ */
