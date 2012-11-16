
#ifndef ISERIALIZABLE_H_
#define ISERIALIZABLE_H_

#include "io/serialize/SAttributeReadWriteOptions.h"

namespace irrgame
{
	class IAttributes;

	namespace io
	{
		//! An object which is able to serialize and deserialize its attributes into an attributes object
		class ISerializable: virtual public IReferenceCounted
		{
			public:

				//! Destructor
				virtual ~ISerializable()
				{
				}

				//! Writes attributes of the object.
				/** Implement this to expose the attributes of your scene node animator for
				 scripting languages, editors, debuggers or xml serialization purposes. */
				virtual void serialize(IAttributes* out) const;

				//! Reads attributes of the object.
				/** Implement this to set the attributes of your scene node animator for
				 scripting languages, editors, debuggers or xml deserialization purposes. */
				virtual void deserialize(IAttributes* in) = 0;

		};

	}  // namespace io
} // end namespace irrgame

#endif /* ISERIALIZABLE_H_ */

