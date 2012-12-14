/*
 * SCurrentMaterial.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: gregorytkach
 */

#include "SCurrentMaterial.h"

namespace irrgame
{
	namespace scene
	{

		void SCurrentMaterial::clear()
		{
			Material = video::SMaterial();
			Name = "";
			Filename[0] = "";
			Filename[1] = "";
			Filename[2] = "";
			Filename[3] = "";
			Filename[4] = "";
			Strength[0] = 0.f;
			Strength[1] = 0.f;
			Strength[2] = 0.f;
			Strength[3] = 0.f;
			Strength[4] = 0.f;
		}

	}  // namespace scene
}  // namespace irrgame

