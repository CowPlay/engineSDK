/*
 * IPlayerConfigReader.h
 *
 *  Created on: Aug 20, 2012
 *      Author: gregorytkach
 */

#ifndef IPLAYERCONFIGREADER_H_
#define IPLAYERCONFIGREADER_H_

#include "io/config/IConfigReader.h"
#include "io/config/SPlayerConfigEntry.h"
#include "core/collections/stringc.h"
#include "core/shapes/dimension2d.h"

namespace irrgame
{
	namespace io
	{
		class IXMLReader;

		class IPlayerConfigReader: public IConfigReader
		{
			public:
				//! Destructor
				virtual ~IPlayerConfigReader()
				{
				}

				//! Gets enty which contains data from config
				virtual SPlayerConfigEntry* getEntry() = 0;

			protected:
				//! Parse <application/>
				virtual void parseApplication(IXMLReader* xml) = 0;
		};

		//! Internal funtcion. Please do not use.
		IPlayerConfigReader* createPlayerConfigReader();
	}
}

#endif /* IPLAYERCONFIGREADER_H_ */
