/*
 * compileConfigLinux.h
 *
 *  Created on: Nov 13, 2012
 *      Author: gregorytkach
 *      Description: This file contains configuration for compile sdk on linux platforms.
 */

#if defined(__linux) || defined(linux)

#ifndef DEV_OS_LINUX
#define DEV_OS_LINUX

/*
 * Fundamental types. This typedefs ensures portability of the engine.
 */

//! 8 bit unsigned variable.
typedef unsigned char u8;
//! 8 bit signed variable.
typedef signed char s8;
//! 8 bit character variable.
typedef char c8;
//! 16 bit unsigned variable.
typedef unsigned short u16;
//! 16 bit signed variable.
typedef signed short s16;
//! 32 bit unsigned variable.
typedef unsigned int u32;
//! 32 bit signed variable.
typedef signed int s32;
//! 32 bit floating point variable.
typedef float f32;

/*
 * DEBUG
 */

#ifdef DEBUG

/*
 * define a assert macro for debugging.
 */
#include "assert.h"
#define IRR_ASSERT( _CONDITION_ ) assert( (_CONDITION_) );
#else
/*
 * RELEASE
 */
/*
 * undefine a assert macro for debugging.
 */
#define IRR_ASSERT( _CONDITION_ )

/*
 * enable fast math
 */
#define IRR_FAST_MATH
#endif /* DEBUG */

/*
 * REALINLINE
 */
#ifndef REALINLINE
#define REALINLINE inline
#endif /* REALINLINE */
/*
 * io
 */
#define LINEBREAK "\r"

#endif /* DEV_OS_LINUX */

#endif /* defined(__linux) || defined(linux) */
