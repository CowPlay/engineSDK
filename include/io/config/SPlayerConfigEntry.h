/*
 * SPlayerConfigEntry.h
 *
 *  Created on: Nov 16, 2012
 *      Author: developer08
 */

#ifndef SPLAYERCONFIGENTRY_H_
#define SPLAYERCONFIGENTRY_H_

#include "core/collections/stringc.h"
#include "core/shapes/dimension2d.h"

namespace irrgame
{
	namespace io
	{

		struct SPlayerConfigEntry
		{
			public:
				//! Block <application>
				core::stringc AppFile;
				core::stringc AppCreator;

				//! Block <video>
				dimension2du ScreenSize;
		};

	}  // namespace io
}  // namespace irrgame

#endif /* SPLAYERCONFIGENTRY_H_ */
