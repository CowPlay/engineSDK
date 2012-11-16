/*
 * EThreadPriority.h
 *
 *  Created on: Nov 14, 2012
 *      Author: developer08
 */

#ifndef ETHREADPRIORITY_H_
#define ETHREADPRIORITY_H_

namespace irrgame
{
	namespace threads
	{

		//! Enum which contains thread priorities
		enum EThreadPriority
		{
			ETP_LOW = 0,
			ETP_NORMAL,
			ETP_HIGH,

			//! Not used
			ETP_COUNT
		};

	}  // namespace threads
}  // namespace irrgame

#endif /* ETHREADPRIORITY_H_ */
