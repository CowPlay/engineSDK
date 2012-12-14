/*
 * utils.h
 *
 *  Created on: Nov 1, 2012
 *      Author: gregorytkach
 */

#ifndef VIDEOUTILS_H_
#define VIDEOUTILS_H_

#include "compileConfig.h"
#include "video/color/EColorFormat.h"
#include "video/material/EBlendFactor.h"
#include "video/material/EModulateFunc.h"
#include "video/material/EAlphaSource.h"

namespace irrgame
{
	namespace video
	{
		struct AbsRectangle;

		//! class which contains utils for video
		class StaticVideoUtils
		{
				/*
				 * Functions
				 */

			public:

				//! a more useful memset for pixel
				static void memset32(void * dest, const u32 value,
						u32 bytesize);

				/*!
				 Pixel = dest * ( 1 - alpha ) + source * alpha
				 alpha [0;256]
				 */
				static u32 PixelBlend32(const u32 c2, const u32 c1, u32 alpha);

				/*!
				 Pixel = dest * ( 1 - alpha ) + source * alpha
				 alpha [0;32]
				 */
				static u16 PixelBlend16(const u16 c2, const u32 c1,
						const u16 alpha);

				// 1 - Bit Alpha Blending
				static u16 PixelBlend16(const u16 c2, const u16 c1);

				// 1 - Bit Alpha Blending 16Bit SIMD
				static u32 PixelBlend16_simd(const u32 c2, const u32 c1);

				/*!
				 Pixel = dest * ( 1 - SourceAlpha ) + source * SourceAlpha
				 */
				static u32 PixelBlend32(const u32 c2, const u32 c1);

				/*
				 Pixel = c0 * (c1/31).
				 */
				static u16 PixelMul16_2(u16 c0, u16 c1);

				/*
				 Pixel = c0 * (c1/255). c0 Alpha Retain
				 */
				static u32 PixelMul32(const u32 c0, const u32 c1);

				/*
				 Pixel = c0 * (c1/255).
				 */
				static u32 PixelMul32_2(const u32 c0, const u32 c1);

				// integer log2 of a float ieee 754. TODO: non ieee floating point
				static s32 s32_log2_f32(f32 f);

				static s32 s32_log2_s32(u32 x);

				//! 2D Intersection test
				static bool intersect(AbsRectangle &dest, const AbsRectangle& a,
						const AbsRectangle& b);

				//! Returns the alpha component from A1R5G5B5 color
				/** In Irrlicht, alpha refers to opacity.
				 \return The alpha value of the color. 0 is transparent, 1 is opaque. */
				static u32 getAlpha(u16 color);

				//! Returns the red component from A1R5G5B5 color.
				/** Shift left by 3 to get 8 bit value. */
				static u32 getRed(u16 color);

				//! Returns the green component from A1R5G5B5 color
				/** Shift left by 3 to get 8 bit value. */
				static u32 getGreen(u16 color);

				//! Returns the blue component from A1R5G5B5 color
				/** Shift left by 3 to get 8 bit value. */
				static u32 getBlue(u16 color);

				//! Returns the average from a 16 bit A1R5G5B5 color
				static s32 getAverage(s16 color);

				//! get the amount of Bits per Pixel of the given color format
				static u32 getBitsPerPixelFromFormat(const EColorFormat format);

				//! test if the color format is only viable for RenderTarget textures
				/** Since we don't have support for e.g. floating point iimage formats
				 one should test if the color format can be used for arbitrary usage, or
				 if it is restricted to RTTs. */
				static bool isRenderTargetOnlyFormat(const EColorFormat format);

				//! EMT_ONETEXTURE_BLEND: pack srcFact, dstFact, Modulate and alpha source to MaterialTypeParam
				/** alpha source can be an OR'ed combination of E_ALPHA_SOURCE values. */
				static f32 pack_texureBlendFunc(const E_BLEND_FACTOR srcFact,
						const E_BLEND_FACTOR dstFact,
						const E_MODULATE_FUNC modulate = EMFN_MODULATE_1X,
						const u32 alphaSource = EAS_TEXTURE);

				//! EMT_ONETEXTURE_BLEND: unpack srcFact & dstFact and Modulo to MaterialTypeParam
				/** The fields don't use the full byte range, so we could pack even more... */
				static void unpack_texureBlendFunc(E_BLEND_FACTOR &srcFact,
						E_BLEND_FACTOR &dstFact, E_MODULATE_FUNC &modulo,
						u32& alphaSource, const f32 param);

				//! EMT_ONETEXTURE_BLEND: has BlendFactor Alphablending
				static bool textureBlendFuncHasAlpha(
						const E_BLEND_FACTOR factor);

				// small helper function to create vertex buffer object adress offsets
				static u8* bufferOffset(const long offset);
		};
	}  // namespace video
}  // namespace irrgame

#endif /* VIDEOUTILS_H_ */
