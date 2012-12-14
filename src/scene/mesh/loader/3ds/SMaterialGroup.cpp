/*
 * SMaterialGroup.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: gregorytkach
 */

#include "SMaterialGroup.h"

namespace irrgame
{
	namespace scene
	{

		//! Default constructor
		SMaterialGroup::SMaterialGroup() :
				FaceCount(0), Faces(0)
		{
		}

		//! Copy constructor
		SMaterialGroup::SMaterialGroup(const SMaterialGroup& other)
		{
			*this = other;
		}

		//! Destructor
		SMaterialGroup::~SMaterialGroup()
		{
			clear();
		}

		void SMaterialGroup::clear()
		{
			delete[] Faces;
			Faces = 0;
			FaceCount = 0;
		}

		void SMaterialGroup::operator=(const SMaterialGroup& other)
		{
			MaterialName = other.MaterialName;
			FaceCount = other.FaceCount;
			Faces = new u16[FaceCount];
			for (u32 i = 0; i < FaceCount; ++i)
			{
				Faces[i] = other.Faces[i];
			}
		}

	}  // namespace scene
}  // namespace irrgame

