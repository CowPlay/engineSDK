/*
 * ISoundManager.h
 *
 *  Created on: Nov 22, 2012
 *      Author: developer08
 */

#ifndef ISOUNDMANAGER_H_
#define ISOUNDMANAGER_H_

#include "core/engine/IReferenceCountedSafe.h"
#include "core/collections/stringc.h"
#include "sfx/ESoundEffectType.h"

namespace irrgame
{
	namespace audio
	{

		class ISoundNode;
		class ISoundListener;
		struct SAudioSource;
		struct SSoundEffect;

		//! Interface to sound manager
		/* Manager should manipulate with audio sources, sound nodes
		 *
		 */
		class ISoundManager: public IReferenceCountedSafe
		{
			public:

				//! Destructor
				virtual ~ISoundManager()
				{
				}

				//! Returns sound source.
				/* Loads the sound source from disk.The source can be in several
				 * audioformats, such as Ogg and Wav.
				 * @return Pointer to the sound source.
				 * This pointer should not be dropped manually. See
				 * IReferenceCounted::drop() for more information.
				 */
				virtual SAudioSource* getAudioSource(const core::stringc& path) = 0;

				//! Remove audio source from driver cache. Do not call manually!
				/* This function must calls automatic from IAudioSource::~IAudioSource()
				 * when specify source is no longer used
				 */
				virtual void removeAudioSource(SAudioSource* value) = 0;

				//! Adds sound node to sound scene graph.
				/* Sound node is a node in a hierarchical scene audio environment. Each node can have the
				 * children, who are also sound nodes. If the parent node does not
				 * have the volume, his children will not be heard. So, if you delete the
				 * parent sound, all the children will be deleted.
				 * Audio data from the file is completely written to memory or streamed in depends from source.
				 */
				virtual ISoundNode* addSoundNode(SAudioSource* source) = 0;

				//! Returns sound listener.
				/* The listener object defines various properties that affect processing
				 * of the sound for the actual output. The listener is unique for an context,
				 * and has no name. By controlling the listener, the application controls
				 * the way the user experiences the virtual world, as the listener defines
				 * the sampling/pickup point and orientation, and other parameters that
				 * affect the output stream.
				 */
				virtual ISoundListener* getSoundListener() = 0;

				//! Returns root node on the sound
				virtual ISoundNode* getRoot() = 0;
		};

		//! Internal function. Please do not use.
		ISoundManager* createSoundManager();

	}  // namespace audio
}  // namespace irrgame

#endif /* ISOUNDMANAGER_H_ */
