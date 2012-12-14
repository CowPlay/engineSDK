/*
 * StaticMath.cpp
 *
 *  Created on: Dec 14, 2012
 *      Author: gregorytkach
 */

#include "core/math/StaticMath.h"

namespace irrgame
{
	namespace core
	{
#ifdef IRR_FAST_MATH
		const f32 StaticMath::F32Value0 = 0x00000000;
		const f32 StaticMath::F32Value1 = 0x3f800000;
#else //not IRR_FAST_MATH
		const f32 StaticMath::F32Value0 = 0.0f;
		const f32 StaticMath::F32Value1 = 1.0f;
#endif

		const f32 StaticMath::MaxFloat = 3.402823466E+38F;

		//! Rounding error constant often used when comparing f32 values.
		const s32 StaticMath::RoundErrS32 = 0;
		const f32 StaticMath::RoundErrF32 = 0.000001f;

		//! Constant for PI.
		const f32 StaticMath::Pi = 3.14159265359f;

		//! Constant for iverted of PI.
		const f32 StaticMath::PiInverted = 1.0f / Pi;

		//! Constant for half of PI.
		const f32 StaticMath::PiHalf = Pi / 2.0f;

		//! 32bit Constant for converting from degrees to radians
		const f32 StaticMath::DegToRad = StaticMath::Pi / 180.0f;

		//! 32bit constant for converting from radians to degrees (formally known as GRAD_PI)
		const f32 StaticMath::RadToDeg = 180.0f / StaticMath::Pi;

	}  // namespace core
}  // namespace irrgame

