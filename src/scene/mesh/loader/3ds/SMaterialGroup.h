/*
 * SMaterialGroup.h
 *
 *  Created on: Nov 12, 2012
 *      Author: gregorytkach
 */

#ifndef SMATERIALGROUP_H_
#define SMATERIALGROUP_H_

#include "core/collections/stringc.h"

namespace irrgame
{
	namespace scene
	{
		struct SMaterialGroup
		{
			public:

				//! Default constructor
				SMaterialGroup();

				//! Copy constructor
				SMaterialGroup(const SMaterialGroup& other);

				//! Destructor
				virtual ~SMaterialGroup();

				void clear();

				void operator=(const SMaterialGroup& other);

			public:

				core::stringc MaterialName;
				u16 FaceCount;
				u16* Faces;
		};

	}  // namespace scene
}  // namespace irrgame

#endif /* SMATERIALGROUP_H_ */
