/*
 * SEventType.h
 *
 *  Created on: Oct 19, 2012
 *      Author: gregorytkach
 */

#ifndef SEVENTTYPE_H_
#define SEVENTTYPE_H_

namespace irrgame
{
	namespace events
	{
		enum EEventTypes
		{
			EET_ENGINE = 0, //events which generated by engine
			EET_NETWORK, 	//events which receive from network
			EET_USER,		//events which receive from user

			//! Not used
			EET_COUNT
		};
	}  // namespace events
}  // namespace irrgame

#endif /* SEVENTTYPE_H_ */
