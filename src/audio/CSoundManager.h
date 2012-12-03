/*
 * CSoundManager.h
 *
 *  Created on: Nov 22, 2012
 *      Author: developer08
 */

#ifndef CSOUNDMANAGER_H_
#define CSOUNDMANAGER_H_

#include "audio/ISoundManager.h"
#include "audio/ISoundNode.h"
#include "audio/ISoundListener.h"

namespace irrgame
{
	namespace audio
	{

		class CSoundManager: public ISoundManager, public ISoundNode
		{
			public:
				//! Default constructor
				CSoundManager();

				//! Destructor
				virtual ~CSoundManager();

				//! Returns sound source.
				/* Loads the sound source from disk.The source can be in several
				 * audioformats, such as Ogg and Wav.
				 * @return Pointer to the sound source, or 0 if the sound source
				 * could not be loaded. This pointer should not be dropped manually. See
				 * IReferenceCounted::drop() for more information.
				 */
				virtual SAudioSource* getAudioSource(const core::stringc& path) = 0;

				//! Remove audio source from driver cache. Do not call manually!
				/* This function must calls automatic from IAudioSource::~IAudioSource()
				 * when specify source
				 */
				virtual void removeAudioSource(core::stringc& path) = 0;

				//! Adds sound node to sound scene graph.
				/* Sound node is a node in a hierarchical scene audio environment. Each node can have the
				 * children, who are also sound nodes. If the parent node does not
				 * have the volume, his children will not be heard. So, if you delete the
				 * parent sound, all the children will be deleted.
				 * Audio data from the file is completely written to memory or streamed in depends from source.
				 */
				ISoundNode* addSoundNode(SAudioSource* source);

				//! Returns sound listener.
				/* The listener object defines various properties that affect processing
				 * of the sound for the actual output. The listener is unique for an context,
				 * and has no name. By controlling the listener, the application controls
				 * the way the user experiences the virtual world, as the listener defines
				 * the sampling/pickup point and orientation, and other parameters that
				 * affect the output stream.
				 */
				ISoundListener* getSoundListener();

				//! Returns root node on the sound
				ISoundNode* getRoot();

			protected:

				ISoundListener* Listener;
		};

	} /* namespace audio */
} /* namespace irrgame */
#endif /* CSOUNDMANAGER_H_ */
