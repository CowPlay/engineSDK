/*
 * ISoundNode.cpp
 *
 *  Created on: Dec 3, 2012
 *      Author: developer08
 */
#include "audio/ISoundNode.h"

namespace irrgame
{
	namespace audio
	{

		//! Default constructor
		ISoundNode::ISoundNode(ISoundNode* parent, SAudioSource* source) :
				core::ILeafNode<ISoundNode>(parent), Source(source)
		{

		}

	}  // namespace audio
}  // namespace irrgame

