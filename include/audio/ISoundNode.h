/*
 * ISound.h
 *
 *  Created on: Oct 26, 2012
 *      Author: litirvi
 */

#ifndef ISOUNDNODE_H_
#define ISOUNDNODE_H_

#include "core/collections/ILeafNode.h"
#include "audio/SAudioSource.h"
#include "audio/ESoundFilterType.h"

namespace irrgame
{
	namespace audio
	{
		class IAudioSource;
		struct SSoundEffect;

		//! Manipulate the source and the associated buffer.
		class ISoundNode: public core::ILeafNode<ISoundNode>
		{
			public:

				//! Default constructor
				ISoundNode(ISoundNode* parent, SAudioSource* source);

				//! Destructor
				virtual ~ISoundNode()
				{
				}

				//! Plays a sound source
				/* @param pos the position at which to begin playing
				 * @param loop means that our sound will be played endlessly in a loop
				 */
				virtual void play(u32 pos = 0, bool loop = false) = 0;

				//! Stop playing.
				/* When you start to play playing from the beginning.
				 */
				virtual void stop() = 0;

				//! Pause playing.
				/* When you start to play playing from where it paused.
				 */
				virtual void pause() = 0;

				//! Check the sound is loaded entirely into memory, or streamed in parts.
				/* returns true if sound loaded parts.
				 */
				virtual bool isStreamed() = 0;

				//! Connect directly to the sound of the filter.
				/* @param value: a pointer to the effect to apply.
				 */
				virtual void applyEffect(SSoundEffect* value) = 0;

				//! Disconnected from the source directly effect.
				/* @param value: a pointer to the effect to remove.
				 */
				virtual void removeEffect(SSoundEffect* value) = 0;

				//! Connect directly to the sound of the filter.
				/* @param value: a pointer to the filter to apply,
				 * @param lfGain: low frequency part of the gain. Range: 0.0..1.0 (default 1.0)
				 * @param hfGain: high frequency part of the gain. Range: 0.0..1.0 (default 1.0)
				 * @param gain: value is given only for the filter ESET_BANDPASS.
				 * Range: 0.0..1.0 (default 1.0).
				 */
				virtual void applyFilter(ESoundFilterType value, f32 gainLf,
						f32 GainHf, f32 gain = 1.0) = 0;

				//! Disconnected from the source directly filter.
				/* @param value: a pointer to the filter to remove.
				 */
				virtual void removeFilter(ESoundFilterType value) = 0;

			protected:

				SAudioSource* Source;
		};

		//! Internal function. Please do not use.
		ISoundNode* createSoundNode(ISoundNode* parent, SAudioSource* source);

	} // end namespace audio
} // end namespace irrgame

#endif /* ISOUNDNODE_H_ */
