// Copyright (C) 2002-2009 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef STATICMATH_H_
#define STATICMATH_H_

#include "compileConfig.h"
#include "StaticConverter.h"
#include "math.h"

namespace irrgame
{
	namespace core
	{
		//#define F32_AS_S32(f)		(*((s32 *) &(f)))
		//#define F32_AS_U32(f)		(*((u32 *) &(f)))
		//#define F32_AS_U32_POINTER(f)	( ((u32 *) &(f)))
		//
		//#define F32_VALUE_0		0x00000000
		//#define F32_VALUE_1		0x3f800000
		//#define F32_SIGN_BIT		0x80000000U
		//#define F32_EXPON_MANTISSA	0x7FFFFFFFU

		//! Absolute integer representation of a floating-point value
		//#define AIR(x)				(IR(x)&0x7fffffff)

		//! integer representation of 1.0
		//#define IEEE_1_0			0x3f800000
		//! integer representation of 255.0
		//#define IEEE_255_0			0x437f0000

		//! Represents some math functions for resolve dependings
		//TODO: make static functions inline
		//TODO: Give to all func_ normal names
		//WARNING: realization of this class place here because we use inline for speed up.
		class StaticMath
		{
				/*
				 * Static constants
				 */
			public:
				static const f32 MaxFloat;

				//! Rounding error constant often used when comparing f32 values.
				static const s32 RoundErrS32;
				static const f32 RoundErrF32;

				//! Constant for PI.
				static const f32 Pi;

				//! Constant for iverted of PI.
				static const f32 PiInverted;

				//! Constant for half of PI.
				static const f32 PiHalf;

				//! 32bit Constant for converting from degrees to radians
				static const f32 DegToRad;

				//! 32bit constant for converting from radians to degrees (formally known as GRAD_PI)
				static const f32 RadToDeg;

				/*
				 float IEEE-754 bit represenation

				 0      0x00000000
				 1.0    0x3f800000
				 0.5    0x3f000000
				 3      0x40400000
				 +inf   0x7f800000
				 -inf   0xff800000
				 +NaN   0x7fc00000 or 0x7ff00000
				 in general: number = (sign ? -1:1) * 2^(exponent) * 1.(mantissa bits)
				 */
				static const f32 F32Value0;
				static const f32 F32Value1;

				/*
				 * Fast math functions for float-pointer values
				 */
			public:

				//! Returns true if value lower than zero. Otherwise returns false.
				static bool lowerZero(f32 n);

				//! Returns  true if value lower than zero or equal zero. Otherwise returns false.
				static bool lowerOrEqualZero(f32 n);

				//! Returns true if value greater than zero. Otherwise returns false.
				static bool greaterZero(f32 n);

				//! Returns  true if value greater than zero or equal zero. Otherwise returns false.
				static bool greaterEqualZero(f32 n);

				//! Returns true if value equal zero. Otherwise returns false.
				static bool equalZero(f32 n);

				//! Returns true if value equal one. Otherwise returns false.
				static bool equalOne(f32 n);

				//! Returns true if a > b. Otherwise returns false.
				static bool firstIsMax(f32 a, f32 b);

				/*
				 * Fast math functions
				 */
			public:

				// calculate: 1 / x
				static f32 invert(const f32 f);

				// calculate: 1 / sqrtf ( x )
				static f32 invertSqrt(const f32 f);

				// calculate: 1 / sqrtf( x )
				static s32 invertSqrt(const s32 x);

				// calculate: 1 / x, low precision allowed
				static f32 invertApproximate(const f32 f);

				//! These functions round x downwards to the nearest integer, returning that value as a double. Thus,
				//! floor (1.5) is 1.0 and floor (-1.5) is -2.0.
				static s32 floor_(f32 x);

				//! These functions round x upwards to the nearest integer, returning that value as a integer. Thus, ceil (1.5)
				//!  is 2.0.
				static s32 ceil_(f32 x);

				//! These functions are similar to rint, but they round halfway cases away from zero instead of to the
				//!  nearest integer (or other current rounding mode).
				static s32 roundi(f32 x);

				/*
				 * Functions
				 */
			public:

				//! Utility function to convert a radian value to degrees
				/** Provided as it can be clearer to write radToDeg(X) than RADTODEG * X
				 @param radians	The radians value to convert to degrees.
				 */
				static f32 radToDeg(f32 radians);

				//! Utility function to convert a degrees value to radians
				/** Provided as it can be clearer to write degToRad(X) than DEGTORAD * X
				 \param degrees	The degrees value to convert to radians.
				 */
				static f32 degToRad(f32 degrees);

				//! returns if a equals b, taking possible rounding errors into account
				static bool equals(const f32 a, const f32 b,
						const f32 tolerance = RoundErrF32);

				//! returns if a equals b, taking an explicit rounding tolerance into account
				static bool equals(const s32 a, const s32 b,
						const s32 tolerance = RoundErrS32);

				//! returns if a equals b, taking an explicit rounding tolerance into account
				static bool equals(const u32 a, const u32 b,
						const s32 tolerance = RoundErrS32);

				//! returns if a equals zero, taking rounding errors into account
				static bool iszero(const f32 a, const f32 tolerance =
						RoundErrF32);

				//! returns if a equals not zero, taking rounding errors into account
				static bool isnotzero(const f32 a, const f32 tolerance =
						RoundErrF32);

				//! returns if a equals zero, taking rounding errors into account
				static bool iszero(const s32 a, const s32 tolerance = 0);

				//! returns if a equals zero, taking rounding errors into account
				static bool iszero(const u32 a, const u32 tolerance = 0);

				//! return min of two specify integers
				static s32 mini(s32 a, s32 b);

				//! return max of two specify integers
				static s32 maxi(s32 a, s32 b);

				//! return min of two specify floats
//				static f32 minf(const f32 a, const f32 b, const f32 c);

				//! return max of two specify floats
//				static f32 maxf(const f32 a, const f32 b, const f32 c);

				//! Clamps value to the specified low and high range
//				static s32 clampi(s32 value, s32 low, s32 high);

				//! conditional set based on mask and arithmetic shift
				static u32 ifCONDThanAelseB(const s32 condition, const u32 a,
						const u32 b);

				//! conditional set based on mask and arithmetic shift
				static u16 ifCONDThanAelseB(const s16 condition, const u16 a,
						const u16 b);

				//! conditional set based on mask and arithmetic shift
				static u32 ifCONDThanAelseZERO(const s32 condition,
						const u32 a);

				//! if (condition) state |= m; else state &= ~m;
				static void setbitCond(u32 &state, s32 condition, u32 mask);

				//! These functions are similar to rint, but they round halfway cases away from zero instead of to the
				//!  nearest integer (or other current rounding mode).
				static f32 round_(f32 x);

				// calculate: sqrt ( x )
				static f32 squareroot(const f32 f);

				// calculate: sqrt ( x )
				static s32 squarerooti(const s32 f);

				static f32 fract(f32 x);

				//! This function returns the absolute value of the floating-point number
				static f32 fabsf_(f32 x);

				//! These are general exponentiation functions, returning base raised to power.
				//! Mathematically, pow would return a complex number when base is negative and power is not an
				//!  integral value. pow can't do that, so instead it signals a domain error. pow may also underflow or
				//!  overflow the destination type.
				static f32 powf_(f32 base, f32 power);

				/*
				 * Trigonometric functions
				 */

			public:

				//! These functions return the cosine of x, where x is
				//!  given in radians. The return value is in the range -1 to 1.
				static f32 cosf_(f32 value);

				//! These functions compute the arc cosine of x---that is, the value whose cosine is x. The value is in units
				//!  of radians. Mathematically, there are infinitely many such values; the one actually returned is the one  between 0 and pi (inclusive).
				//! The arc cosine function is defined mathematically only over the domain -1 to 1. If x is outside the
				//!  domain, acos signals a domain error.
				static f32 acosf_(f32 value);

				//! These functions return the sine of x, where x is given in radians. The return value is in the range -1 to 1.
				static f32 sinf_(f32 value);

				//! These functions compute the arc sine of x---that is, the value whose sine is x. The value is in units of
				//!  radians. Mathematically, there are infinitely many such values; the one actually returned is the one
				//!  between -pi/2 and pi/2 (inclusive).
				//! The arc sine function is defined mathematically only over the domain -1 to 1. If x is outside the domain,
				//!  asin signals a domain erro
				static f32 asinf_(f32 value);

				//! These functions return the tangent of x, where x is given in radians.
				//! Mathematically, the tangent function has singularities at odd multiples of pi/2. If the argument x is too
				//!  close to one of these singularities, tan will signal overflow.
				static f32 tanf_(f32 value);

				//! These functions compute the arc tangent of x---that is, the value whose tangent is x. The value is in
				//!  units of radians. Mathematically, there are infinitely many such values; the one actually returned is the
				//!  one between -pi/2 and pi/2 (inclusive).
				static f32 atanf_(f32 value);

				//! This function computes the arc tangent of y/x, but the signs of both arguments are used to determine the
				//!  quadrant of the result, and x is permitted to be zero. The return value is given in radians and is in the
				//!  range -pi to pi, inclusive.
				//! If x and y are coordinates of a point in the plane, atan2 returns the signed angle between the line from
				//!  the origin to that point and the x-axis. Thus, atan2 is useful for converting Cartesian coordinates to polar
				//!  coordinates. (To compute the radial coordinate, use hypot; see Exponents and Logarithms.)
				//! If both x and y are zero, atan2 returns zero.
				static f32 atan2f_(f32 value1, f32 value2);

				/*
				 * Template functions
				 */

			public:

				//! returns minimum of two values. Own implementation to get rid of the STL (VS6 problems)
				template<class T>
				static const T& min(const T& a, const T& b);

				//! returns minimum of three values. Own implementation to get rid of the STL (VS6 problems)
				template<class T>
				static const T& min(const T& a, const T& b, const T& c);

				//! returns maximum of two values. Own implementation to get rid of the STL (VS6 problems)
				template<class T>
				static const T& max(const T& a, const T& b);

				//! returns maximum of three values. Own implementation to get rid of the STL (VS6 problems)
				template<class T>
				static const T& max(const T& a, const T& b, const T& c);

				//! returns abs of two values. Own implementation to get rid of STL (VS6 problems)
				template<class T>
				static T abs(const T& a);

				//! returns linear interpolation of a and b with ratio t
				//! \return: a if t==0, b if t==1, and the linear interpolation else
				template<class T>
				static T lerp(const T& a, const T& b, const f32 t);

				//! clamps a value between low and high
				template<class T>
				static const T clamp(const T& value, const T& low,
						const T& high);

				//! swaps the content of the passed parameters
				template<class T>
				static void swap(T& a, T& b);

		};

		/*
		 * Fast math functions for float-pointer values
		 */
#ifdef IRR_FAST_MATH
		inline bool StaticMath::lowerZero(f32 f)
		{
			return ((*((u32 *) &(f))) > 0x80000000U);
		}

		inline bool StaticMath::lowerOrEqualZero(f32 f)
		{
			return ((*((s32 *) &(f))) <= 0x00000000);
		}

		inline bool StaticMath::greaterZero(f32 f)
		{
			return ((*((s32 *) &(f))) > 0x00000000);
		}

		inline bool StaticMath::greaterEqualZero(f32 f)
		{
			return ((*((u32 *) &(f))) <= 0x80000000U);
		}

		inline bool StaticMath::equalOne(f32 f)
		{
			return ((*((u32 *) &(f))) == 0x3f800000);
		}

		inline bool StaticMath::equalZero(f32 f)
		{
			return (((*((u32 *) &(f))) & 0x7FFFFFFFU) == 0x00000000);
		}

		// only same sign
		inline bool F32_A_GREATER_B(f32 a, f32 b)
		{
			return ((*((s32 *) &(a))) > (*((s32 *) &(b))));
		}

		// calculate: 1 / sqrtf ( x )
		inline f32 StaticMath::invertSqrt(const f32 f)
		{
#ifdef _MSC_VER
// SSE reciprocal square root estimate, accurate to 12 significant
// bits of the mantissa
			f32 recsqrt;
			__asm rsqrtss xmm0, f// xmm0 = rsqrtss(f)
			__asm movss recsqrt, xmm0// return xmm0
			return recsqrt;

			/*
			 // comes from Nvidia
			 u32 tmp = (u32(IEEE_1_0 << 1) + IEEE_1_0 - *(u32*)&x) >> 1;
			 f32 y = *(f32*)&tmp;
			 return y * (1.47f - 0.47f * x * y * y);
			 */
#else
			return 1.f / sqrtf(f);
#endif
		}

		// calculate: 1 / x
		inline f32 StaticMath::invert(const f32 f)
		{
#ifdef _MSC_VER

// SSE Newton-Raphson reciprocal estimate, accurate to 23 significant
// bi ts of the mantissa
// One Newtown-Raphson Iteration:
// f(i+1) = 2 * rcpss(f) - f * rcpss(f) * rcpss(f)
			f32 rec;
			__asm rcpss xmm0, f// xmm0 = rcpss(f)
			__asm movss xmm1, f// xmm1 = f
			__asm mulss xmm1, xmm0// xmm1 = f * rcpss(f)
			__asm mulss xmm1, xmm0// xmm2 = f * rcpss(f) * rcpss(f)
			__asm addss xmm0, xmm0// xmm0 = 2 * rcpss(f)
			__asm subss xmm0, xmm1// xmm0 = 2 * rcpss(f)
//        - f * rcpss(f) * rcpss(f)
			__asm movss rec, xmm0// return xmm0
			return rec;

//! i do not divide through 0.. (fpu expection)
// instead set f to a high value to get a return value near zero..
// -1000000000000.f.. is use minus to stay negative..
// must test's here (plane.normal dot anything ) checks on <= 0.f
//u32 x = (-(AIR(f) != 0 ) >> 31 ) & ( IR(f) ^ 0xd368d4a5 ) ^ 0xd368d4a5;
//return 1.f / FR ( x );

#else // no fast math
			return 1.f / f;
#endif
		}

		// calculate: 1 / x, low precision allowed
		inline f32 StaticMath::invertApproximate(const f32 f)
		{
#ifdef _MSC_VER

// SSE Newton-Raphson reciprocal estimate, accurate to 23 significant
// bi ts of the mantissa
// One Newtown-Raphson Iteration:
// f(i+1) = 2 * rcpss(f) - f * rcpss(f) * rcpss(f)
			f32 rec;
			__asm rcpss xmm0, f// xmm0 = rcpss(f)
			__asm movss xmm1, f// xmm1 = f
			__asm mulss xmm1, xmm0// xmm1 = f * rcpss(f)
			__asm mulss xmm1, xmm0// xmm2 = f * rcpss(f) * rcpss(f)
			__asm addss xmm0, xmm0// xmm0 = 2 * rcpss(f)
			__asm subss xmm0, xmm1// xmm0 = 2 * rcpss(f)
//        - f * rcpss(f) * rcpss(f)
			__asm movss rec, xmm0// return xmm0
			return rec;

			/*
			 // SSE reciprocal estimate, accurate to 12 significant bits of
			 f32 rec;
			 __asm rcpss xmm0, f             // xmm0 = rcpss(f)
			 __asm movss rec , xmm0          // return xmm0
			 return rec;
			 */
			/*
			 register u32 x = 0x7F000000 - IR ( p );
			 const f32 r = FR ( x );
			 return r * (2.0f - p * r);
			 */
#else // no fast math
			return 1.f / f;
#endif
		}

		inline s32 StaticMath::floor_(f32 x)
		{
			const f32 h = 0.5f;

			s32 t;

#ifdef _MSC_VER
			__asm
			{
				fld x
				fsub h
				fistp t
			}
#elif defined(__GNUC__)
			__asm__ __volatile__ (
					"fsub %2 \n\t"
					"fistpl %0"
					: "=m" (t)
					: "t" (x), "f" (h)
					: "st"
			);
#else
#  warn IRRLICHT_FAST_MATH not supported.
			return (s32) floor_ ( x );
#endif
			return t;
		}

		inline s32 StaticMath::ceil_(f32 x)
		{
			const f32 h = 0.5f;

			s32 t;

#if defined(_MSC_VER)
			__asm
			{
				fld x
				fadd h
				fistp t
			}
#elif defined(__GNUC__)
			__asm__ __volatile__ (
					"fadd %2 \n\t"
					"fistpl %0 \n\t"
					: "=m"(t)
					: "t"(x), "f"(h)
					: "st"
			);
#else
#  warn IRRLICHT_FAST_MATH not supported.
			return (s32) ceilf ( x );
#endif
			return t;
		}

		inline s32 StaticMath::round_(f32 x)
		{
			s32 t;

#if defined(_MSC_VER)
			__asm
			{
				fld x
				fistp t
			}
#elif defined(__GNUC__)
			__asm__ __volatile__ (
					"fistpl %0 \n\t"
					: "=m"(t)
					: "t"(x)
					: "st"
			);
#else
#  warn IRRLICHT_FAST_MATH not supported.
			return floor_(x + 0.5f);
#endif
			return t;
		}

#else //not IRR_FAST_MATH

		inline bool StaticMath::lowerZero(f32 n)
		{
			return n < 0.0f;
		}

		inline bool StaticMath::lowerOrEqualZero(f32 n)
		{
			return n <= 0.0f;
		}

		inline bool StaticMath::greaterZero(f32 n)
		{
			return n > 0.0f;
		}

		inline bool StaticMath::greaterEqualZero(f32 n)
		{
			return n >= 0.0f;
		}

		inline bool StaticMath::equalOne(f32 n)
		{
			return n == 1.0f;
		}

		inline bool StaticMath::equalZero(f32 n)
		{
			return n == 0.0f;
		}

		inline bool StaticMath::firstIsMax(f32 a, f32 b)
		{
			return a > b;
		}

		inline f32 StaticMath::invert(const f32 f)
		{
			return 1.f / f;
		}

		inline f32 StaticMath::invertSqrt(const f32 f)
		{
			return 1.f / sqrtf(f);
		}

		inline s32 StaticMath::invertSqrt(const s32 x)
		{
			return StaticConverter::convertToInt(
					invertSqrt(StaticConverter::convertToFloat(x)));
		}

		inline f32 StaticMath::invertApproximate(const f32 f)
		{
			return 1.f / f;
		}

		inline s32 StaticMath::floor_(f32 x)
		{
			return StaticConverter::convertToInt(floorf(x));
		}

		inline s32 StaticMath::ceil_(f32 x)
		{
			return StaticConverter::convertToInt(ceilf(x));
		}

		inline s32 StaticMath::roundi(f32 x)
		{
			return StaticConverter::convertToInt(StaticMath::round_(x));
		}

#endif /* IRR_FAST_MATH */

		/*
		 * Functions
		 */

		inline f32 StaticMath::radToDeg(f32 radians)
		{
			return RadToDeg * radians;
		}

		inline f32 StaticMath::degToRad(f32 degrees)
		{
			return DegToRad * degrees;
		}

		inline bool StaticMath::equals(const f32 a, const f32 b,
				const f32 tolerance)
		{
			return (a + tolerance >= b) && (a - tolerance <= b);
		}

		inline bool StaticMath::equals(const s32 a, const s32 b,
				const s32 tolerance)
		{
			return (a + tolerance >= b) && (a - tolerance <= b);
		}

		inline bool StaticMath::equals(const u32 a, const u32 b,
				const s32 tolerance)
		{
			return (a + tolerance >= b) && (a - tolerance <= b);
		}

		inline bool StaticMath::iszero(const f32 a, const f32 tolerance)
		{
			return fabsf_(a) <= tolerance;
		}

		inline bool StaticMath::isnotzero(const f32 a, const f32 tolerance)
		{
			return fabsf_(a) > tolerance;
		}

		inline bool StaticMath::iszero(const s32 a, const s32 tolerance)
		{
			return (a & 0x7ffffff) <= tolerance;
		}

		//! returns if a equals zero, taking rounding errors into account
		inline bool StaticMath::iszero(const u32 a, const u32 tolerance)
		{
			return a <= tolerance;
		}

		inline s32 StaticMath::mini(s32 a, s32 b)
		{
			const s32 mask = (a - b) >> 31;
			return (a & mask) | (b & ~mask);
		}

		inline s32 StaticMath::maxi(s32 a, s32 b)
		{
			const s32 mask = (a - b) >> 31;
			return (b & mask) | (a & ~mask);
		}

		//! conditional set based on mask and arithmetic shift
		inline u32 StaticMath::ifCONDThanAelseB(const s32 condition,
				const u32 a, const u32 b)
		{
			return ((-condition >> 31) & (a ^ b)) ^ b;
		}

		//! conditional set based on mask and arithmetic shift
		inline u16 StaticMath::ifCONDThanAelseB(const s16 condition,
				const u16 a, const u16 b)
		{
			return ((-condition >> 15) & (a ^ b)) ^ b;
		}

		//! conditional set based on mask and arithmetic shift
		inline u32 StaticMath::ifCONDThanAelseZERO(const s32 condition,
				const u32 a)
		{
			return (-condition >> 31) & a;
		}

		//! if (condition) state |= m; else state &= ~m;
		inline void StaticMath::setbitCond(u32 &state, s32 condition, u32 mask)
		{
			// 0, or any postive to mask
			//s32 conmask = -condition >> 31;
			state ^= ((-condition >> 31) ^ state) & mask;
		}

		//! These functions are similar to rint, but they round halfway cases away from zero instead of to the
		//!  nearest integer (or other current rounding mode).
		inline f32 StaticMath::round_(f32 x)
		{
			return floor_(x + 0.5f);
		}

		// calculate: sqrt ( x )
		inline f32 StaticMath::squareroot(const f32 f)
		{
			return sqrtf(f);
		}

		// calculate: sqrt ( x )
		inline s32 StaticMath::squarerooti(const s32 f)
		{
			return StaticConverter::convertToInt(
					(squareroot(StaticConverter::convertToFloat(f))));
		}

		inline f32 StaticMath::fract(f32 x)
		{
			return x - floor_(x);
		}

		inline f32 StaticMath::fabsf_(f32 value)
		{
			return fabsf(value);
		}

		inline f32 StaticMath::powf_(f32 base, f32 power)
		{
			return powf(base, power);
		}

		/*
		 * Trigonometric functions
		 */

		inline f32 StaticMath::cosf_(f32 value)
		{
			return cosf(value);
		}

		inline f32 StaticMath::acosf_(f32 value)
		{
			return acosf(value);
		}

		inline f32 StaticMath::sinf_(f32 value)
		{
			return sinf(value);
		}

		inline f32 StaticMath::asinf_(f32 value)
		{
			return asinf(value);
		}

		inline f32 StaticMath::tanf_(f32 value)
		{
			return tanf(value);
		}

		inline f32 StaticMath::atanf_(f32 value)
		{
			return atanf(value);
		}

		inline f32 StaticMath::atan2f_(f32 value1, f32 value2)
		{
			return atan2f(value1, value2);
		}

		/*
		 * Template functions
		 */

		template<class T>
		inline const T& StaticMath::min(const T& a, const T& b)
		{
			return a < b ? a : b;
		}

		template<class T>
		inline const T& StaticMath::min(const T& a, const T& b, const T& c)
		{
			return a < b ? min(a, c) : min(b, c);
		}

		template<class T>
		inline const T& StaticMath::max(const T& a, const T& b)
		{
			return a < b ? b : a;
		}

		template<class T>
		inline const T& StaticMath::max(const T& a, const T& b, const T& c)
		{
			return a < b ? max(b, c) : max(a, c);
		}

		template<class T>
		inline T StaticMath::abs(const T& a)
		{
			return a < (T) 0 ? -a : a;
		}

		template<class T>
		inline T StaticMath::lerp(const T& a, const T& b, const f32 t)
		{
			return (T) (a * (1.f - t)) + (b * t);
		}

		template<class T>
		inline const T StaticMath::clamp(const T& value, const T& low,
				const T& high)
		{
			return min(max(value, low), high);
		}

		template<class T>
		inline void StaticMath::swap(T& a, T& b)
		{
			T c(a);
			a = b;
			b = c;
		}

	} // end namespace core
} // end namespace irrgame

#endif /* STATICMATH_H_ */

