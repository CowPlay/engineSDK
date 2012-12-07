/*
 * ISoundListener.h
 *
 *  Created on: Nov 21, 2012
 *      Author: developer08
 */

#ifndef ISOUNDLISTENER_H_
#define ISOUNDLISTENER_H_

#include "core/engine/IReferenceCountedSafe.h"
#include "core/shapes/vector3d.h"

namespace irrgame
{
	namespace audio
	{

		//! Interface to sound listener.
		/* There is always one Listener object (per audio context), which represents the position where the
		 *  sources are heard - rendering is done from the perspective of the Listener.
		 */
		class ISoundListener: public IReferenceCountedSafe
		{
			public:

				//! Sets new volume of listener.
				/* @param value New volume of listener. Range: 0.0 to TODO
				 */
				virtual void setVolume(const f32 value) = 0;

				//! Returns volume of listener.
				virtual f32 getVolume() = 0;

				//! Sets the current listener 3d position.
				/* When playing sounds in 3D, updating the position of the listener every frame should be
				 * done using this function.
				 * @param value New position of the listener.
				 */
				virtual void setPosition(const vector3df& value) = 0;

				//! Gets the current listener 3d position.
				virtual vector3df& getPosition() = 0;

				//! Sets the current listener velocity.
				/* Position and velocity can unrelated - the speed is only used for the Doppler effect,
				 * the observer must move yourself.
				 * @param vel Velocity of the listener.
				 */
				virtual void setVelocity(const vector3df& value) = 0;

				//! Gets the current listener 3d velocity.
				virtual vector3df& getVelocity() = 0;

				//! Sets the current listener 3d rotation.
				/* Rotation contains an "at" vector and an "up" vector, where the "at" vector represents
				 * the "forward" direction of the listener and the orthogonal projection of the "up" vector
				 * into the subspace perpendicular to the "at" vector represents the "up" direction for the
				 * listener. The initial orientation is (vector3df (0, 0, (-1)), vector3df (0, 1, 0)), i.e. looking down
				 * the Z axis with the Y axis pointing upwards.
				 * @param valueAt "at" vector of the listener
				 * @param valueUp "up" vector of the listener
				 * This vector is usually (0,1,0)
				 */
				virtual void setRotation(const vector3df& valueAt,
						const vector3df& valueUp = vector3df(0, 1, 0)) = 0;

				//! Gets the current listener 3d rotation "at".
				virtual vector3df& getRotationAt() = 0;

				//! Gets the current listener 3d rotation "up".
				virtual vector3df& getRotationUp() = 0;

			protected:

				//! Currently volume of listener
				f32 Volume;

				//! Position contains the current location of the listener.
				vector3df Position;

				//! Velocity contains current velocity (speed and direction) of the listener in the world coordinate system.
				vector3df Velocity;

				//! Current listener 3d rotation "at".
				vector3df RotationAt;

				//! Current listener 3d rotation "up". Vector pointing 'up', so the engine can decide where is left and right.
				vector3df RotationUp;

		};

		//! Internal function. Please do not use.
		ISoundListener* createSoundListener();

	}  // namespace audio
}  // namespace irrgame

#endif /* ISOUNDLISTENER_H_ */
