#ifndef SHAREDCONVERTER_H_
#define SHAREDCONVERTER_H_

#include "compileConfig.h"
#include "UIntToFloat.h"

namespace irrgame
{
	namespace core
	{
		//! Represents simple converter for base types
		class StaticConverter
		{
				/*
				 * Methods
				 */
			public:
				//! Provides a fast function for converting a string into a float.
				//! This is not guaranteed to be as accurate as atof(), but is
				//! approximately 6 to 8 times as fast.
				//! \param floatAsString: The string to convert.
				//! \param moveStringCursor: If True input string will be a pointer to the first character in the string that wasn't
				//!         use to create the float value.
				//! \return The resultant float.
				static f32 convertToFloat(const c8* value,
						bool moveStringCursor = false);

				//! Floating-point representation of an integer value.
				static f32 convertToFloat(u32 x);

				//! Floating-point representation of an integer value.
				static f32 convertToFloat(s32 x);

				//! code is taken from IceFPU
				//! Integer representation of a floating-point value.
				static u32 convertToUInt(f32 x);

				//! Returns integer representation of floating-point value
				static s32 convertToInt(f32 x);

			private:
				static const c8* move(const c8* in, f32& out);

				//! Convert a simple string of base 10 digits into a signed 32 bit integer.
				//! \param[in] in: The string of digits to convert. Only a leading - or + followed
				//!					by digits 0 to 9 will be considered.  Parsing stops at the
				//!					first non-digit.
				//! \param[out] out: (optional) If provided, it will be set to point at the first
				//!					 character not used in the calculation.
				//! \return The signed integer value of the digits. If the string specifies too many
				//!			digits to encode in an s32 then +INT_MAX or -INT_MAX will be returned.
				static s32 strtol10(const c8* in, const c8** out = 0);

				//! Converts a sequence of digits into a whole positive floating point value.
				//! Only digits 0 to 9 are parsed.  Parsing stops at any other character,
				//! including sign characters or a decimal point.
				//! \param in: the sequence of digits to convert.
				//! \param out: (optional) will be set to point at the first non-converted character.
				//! \return The whole positive floating point representation of the digit sequence.
				static f32 strtof10(const c8* in, const c8** out = 0);

			private:

				// we write [17] here instead of [] to work around a swig bug
				static f32 atofTable[17];
		};

#ifdef IRR_FAST_MATH

		//! Floating-point representation of an integer value.
		inline f32 StaticConverter::convertToFloat(u32 x)
		{
			return ((f32&) (x));
		}

		//! Floating-point representation of an integer value.
		inline f32 StaticConverter::convertToFloat(s32 x)
		{
			return ((f32&) (x));
		}

		//! code is taken from IceFPU
		//! Unsigned integer representation of a floating-point value.
		inline u32 StaticConverter::convertToUInt(f32 x)
		{
			return ((u32&) (x));
		}

		//! Integer representation of a floating-point value.
		inline s32 StaticConverter::convertToInt(f32 x)
		{
			return ((s32&) (x));
		}
#else
		//! Floating-point representation of an integer value.
		inline f32 StaticConverter::convertToFloat(u32 x)
		{
			UIntToFloat tmp;
			tmp.u = x;
			return tmp.f;
		}

		//! Floating-point representation of an integer value.
		inline f32 StaticConverter::convertToFloat(s32 x)
		{
			UIntToFloat tmp;
			tmp.s = x;
			return tmp.f;
		}

		//! Unsigned integer representation of a floating-point value.
		inline u32 StaticConverter::convertToUInt(f32 x)
		{
			UIntToFloat tmp;
			tmp.f = x;
			return tmp.u;
		}

		//! Integer representation of a floating-point value.
		inline s32 StaticConverter::convertToInt(f32 x)
		{
			UIntToFloat tmp;
			tmp.f = x;
			return tmp.s;
		}
#endif

	} // end namespace core
} // end namespace irrgame

#endif /* SHAREDCONVERTER_H_ */

