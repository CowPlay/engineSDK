/*
 * SVideoMode.h
 *
 *  Created on: Nov 29, 2012
 *      Author: developer08
 */

#ifndef SVIDEOMODE_H_
#define SVIDEOMODE_H_

namespace irrgame
{
	namespace video
	{

		struct SVideoMode
		{
			public:
				dimension2du Size;
				s32 Depth;

			public:
				bool operator==(const SVideoMode& other) const;
				bool operator <(const SVideoMode& other) const;
		};

	}  // namespace video
}  // namespace irrgame

#endif /* SVIDEOMODE_H_ */
