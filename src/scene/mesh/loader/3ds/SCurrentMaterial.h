/*
 * SCurrentMaterial.h
 *
 *  Created on: Nov 12, 2012
 *      Author: gregorytkach
 */

#ifndef SCURRENTMATERIAL_H_
#define SCURRENTMATERIAL_H_

#include "compileConfig.h"
#include "video/material/SMaterial.h"

namespace irrgame
{
	namespace scene
	{
		struct SCurrentMaterial
		{
			public:

				void clear();

			public:

				video::SMaterial Material;
				core::stringc Name;
				core::stringc Filename[5];
				f32 Strength[5];
		};

	}  // namespace scene
}  // namespace irrgame

#endif /* SCURRENTMATERIAL_H_ */
