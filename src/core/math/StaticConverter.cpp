/*
 * atoffast.cpp
 *
 *  Created on: Nov 2, 2012
 *      Author: gregorytkach
 */

#include "core/math/StaticMath.h"
#include "core/math/StaticConverter.h"

#include <limits.h> // For INT_MAX / UINT_MAX

namespace irrgame
{
	namespace core
	{
		// we write [17] here instead of [] to work around a swig bug
		f32 StaticConverter::atofTable[17] =
		{ 0.f, 0.1f, 0.01f, 0.001f, 0.0001f, 0.00001f, 0.000001f, 0.0000001f,
				0.00000001f, 0.000000001f, 0.0000000001f, 0.00000000001f,
				0.000000000001f, 0.0000000000001f, 0.00000000000001f,
				0.000000000000001f, 0.0000000000000001f };

		//! Convert a string to a floating point number
		f32 StaticConverter::convertToFloat(const c8* value,
				bool moveStringCursor)
		{
			f32 ret;

			if (moveStringCursor)
			{
				value = move(value, ret);
			}
			else
			{
				move(value, ret);
			}

			return ret;
		}


		//! Convert a simple string of base 10 digits into a signed 32 bit integer.
		s32 StaticConverter::strtol10(const c8* in, const c8** out)
		{
			s32 result = 0;

			IRR_ASSERT(in);

			bool negative = false;
			if ('-' == *in)
			{
				negative = true;
				++in;
			}
			else if ('+' == *in)
			{
				++in;
			}

			u32 unsignedValue = 0;

			while ((*in >= '0') && (*in <= '9'))
			{
				unsignedValue = (unsignedValue * 10) + (*in - '0');
				++in;

				if (unsignedValue > (u32) INT_MAX)
				{
					unsignedValue = (u32) INT_MAX;
					break;
				}
			}

			if (out)
			{
				*out = in;
			}

			result = negative ? -((s32) unsignedValue) : (s32) unsignedValue;

			return result;
		}

		//! Converts a sequence of digits into a whole positive floating point value.
		//! Only digits 0 to 9 are parsed.  Parsing stops at any other character,
		//! including sign characters or a decimal point.
		f32 StaticConverter::strtof10(const c8* in, const c8** out)
		{
			IRR_ASSERT(in);

			if (out)
			{
				*out = in;
			}

			static const u32 MAX_SAFE_U32_VALUE = UINT_MAX / 10 - 10;
			f32 floatValue = 0.f;
			u32 intValue = 0;

			// Use integer arithmetic for as long as possible, for speed
			// and precision.
			while ((*in >= '0') && (*in <= '9'))
			{
				// If it looks like we're going to overflow, bail out
				// now and start using floating point.
				if (intValue >= MAX_SAFE_U32_VALUE)
				{
					break;
				}

				intValue = (intValue * 10) + (*in - '0');
				++in;
			}

			floatValue = (f32) intValue;

			// If there are any digits left to parse, then we need to use
			// floating point arithmetic from here.
			while ((*in >= '0') && (*in <= '9'))
			{
				floatValue = (floatValue * 10.f) + (f32) (*in - '0');
				++in;
				if (floatValue > StaticMath::MaxFloat) // Just give up.
				{
					break;
				}
			}

			if (out)
			{
				*out = in;
			}

			return floatValue;
		}

		//! Provides a fast function for converting a string into a float.
		//! This is not guaranteed to be as accurate as atof(), but is
		//! approximately 6 to 8 times as fast.
		const c8* StaticConverter::move(const c8* in, f32& out)
		{
			IRR_ASSERT(in);

			// Please run this regression test when making any modifications to this function:
			// https://sourceforge.net/tracker/download.php?group_id=74339&atid=540676&file_id=298968&aid=1865300

			out = 0.f;

			bool negative = false;

			if (*in == '-')
			{
				negative = true;
				++in;
			}

			f32 value = strtof10(in, &in);

			if (*in == '.')
			{
				++in;

				const c8 * afterDecimal = in;
				f32 decimal = strtof10(in, &afterDecimal);
				decimal *= atofTable[afterDecimal - in];

				value += decimal;

				in = afterDecimal;
			}

			if ('e' == *in || 'E' == *in)
			{
				++in;
				// Assume that the exponent is a whole number.
				// strtol10() will deal with both + and - signs,
				// but cast to (f32) to prevent overflow at FLT_MAX
				value *= (f32) StaticMath::powf_(10.0f, (f32) strtol10(in, &in));
			}

			out = negative ? -value : value;

			return in;
		}

	} // namespace core
} // namespace irrgame

