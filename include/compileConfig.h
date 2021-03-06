/*
 * compileConfig.h
 * Generic config for all platforms
 *  Created on: Sep 14, 2012
 *      Author: gregorytkach
 *      Description: This file contains generic configuration for compile sdk.
 */

#ifndef COMPILECONFIG_H_
#define COMPILECONFIG_H_

#include "config/compileConfigLinux.h"
#include "config/compileConfigOSX.h"
#include "config/compileConfigWindows.h"

/*
 * Constants
 */

//We use attribute "unused" for disable warnings
#define XMLTagConfig "config"
#define XMLTagApplication "application"
#define XMLTagAttributes "attributes"
#define XMLAttrAppFile "appFile"
#define XMLAttrAppCreator  "appCreator"
//__attribute__ ((unused)) static const c8* XMLTagConfig = "config";
//__attribute__ ((unused)) static const c8* XMLTagApplication = "application";
//__attribute__ ((unused)) static const c8* XMLTagAttributes = "attributes";

//__attribute__ ((unused)) static const c8* XMLAttrAppFile = "appFile";
//__attribute__ ((unused)) static const c8* XMLAttrAppCreator = "appCreator";

//Use in collections
static const s32 IrrNotFound = -1;

//! Maximum number of texture an SMaterial can have, up to 8 are supported by Irrlicht.
static const u32 MaterialMaxTextures = 4;

/*
 * creates four CC codes used in Irrlicht for simple ids
 * some compilers can create those by directly writing the
 * code like 'code', but some generate warnings so we use this macro here
 */
#define MAKE_IRR_ID(c0, c1, c2, c3) \
		((u32)(u8)(c0) | ((u32)(u8)(c1) << 8) | \
		((u32)(u8)(c2) << 16) | ((u32)(u8)(c3) << 24 ))

//! threads
#define PRIORITY_LOW	-20
#define PRIORITY_NORMAL	0
#define PRIORITY_HIGH	20

#endif /* COMPILECONFIG_H_ */
