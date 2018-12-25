/*************************************************************************/
/**         Active Research Limited 2008 - ANSI C Library Header        **/
/*************************************************************************/

/*************************************************************************
 COPYRIGHT 1999-2008 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : TypeDefs_Win32.h

 DESCRIPTION : Header file for the standard ARL Win32 Type Defines

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.000
 Rev Date 	 : 2008-01-09
 Rev Author  : Phil Whitehurst
 Rev Details : First library release
 -------------------------------------------------------------------------
**************************************************************************/

#ifndef __TYPEDEFS_WIN32_H
#define __TYPEDEFS_WIN32_H
/*************************************************************************
 	Types definitions used in the project files :
**************************************************************************/

/* An unsigned integer of 8 bits          : (1 byte)  */
typedef unsigned char u8;
/* An unsigned integer of 16 bits         : (2 bytes) */
typedef unsigned short u16;
/* An unsigned integer of 32 bits         : (4 bytes) */
typedef unsigned long u32;
/* An unsigned integer of 64 bits         : (8 bytes) */
typedef unsigned long long u64;

/* A signed integer of 8 bits             : (1 byte)  */
typedef signed char s8;
/* A signed integer of 16 bits            : (2 bytes) */
typedef signed short s16;
/* A signed integer of 32 bits            : (4 bytes) */
typedef signed long s32;
/* A signed integer of 64 bits            : (8 bytes) */
typedef signed long long s64;

/* A constant integer of 8 bits           : (1 byte)  */
typedef const char c8;
/* A constant unsigned integer of 8 bits  : (1 byte)  */
typedef const unsigned char cu8;
/* A constant unsigned integer of 16 bits : (2 bytes) */
typedef const unsigned short cu16;
/* A constant unsigned integer of 32 bits : (4 bytes) */
typedef const unsigned long cu32;
/* A constant unsigned integer of 64 bits : (8 bytes) */
typedef const unsigned long long cu64;

/* A volatile unsigned integer of 8 bits  : (1 byte)  */
typedef volatile unsigned char vu8;
/* A volatile unsigned integer of 16 bits : (2 bytes) */
typedef volatile unsigned short vu16;
/* A volatile unsigned integer of 32 bits : (4 bytes) */
typedef volatile unsigned long vu32;
/* A volatile unsigned integer of 64 bits : (8 bytes) */
typedef volatile unsigned long vu64;

/* A volatile signed integer of 8 bits    : (1 byte)  */
typedef  volatile signed char vs8;
/* A volatile signed integer of 16 bits   : (2 bytes) */
typedef volatile signed short vs16;
/* A volatile signed integer of 32 bits   : (4 bytes) */
typedef volatile signed long vs32;
/* A volatile signed integer of 64 bits   : (8 bytes) */
typedef volatile signed long vs64;

/* Union/structure definition that allows both bytes in u16 to be accessed */
typedef union U16Bytes {
	u16 x16;

	struct x8 {
		u8 lo;
		u8 hi;
	} x8;

} U16Bytes;

/* Union/structure definition that allows bytes and s16's in s32 to be accessed */
typedef union S32Bytes {
	s32 x32;

	struct x16 {
		s16 lo;
		s16 hi;
	} x16;

	struct x8 {
		s8 b0;
		s8 b1;
		s8 b2;
		s8 b3;
	} x8;

} S32Bytes;

/* Union/structure definition that allows u8, u16 and u32's in u64 to be accessed */
typedef union S64Bytes {
	s64 x64;

	struct x32 {
		u32 v0;
		s32 v1;
	} x32;

	struct x16 {
		u16 v0;
		u16 v1;
		u16 v2;
		s16 v3;
	} x16;

	struct x8 {
		u8 b0;
		u8 b1;
		u8 b2;
		u8 b3;
		u8 b4;
		u8 b5;
		u8 b6;
		s8 b7;
	} x8;

} S64Bytes;


/* Union/structure definition that allows bytes and u16's in u32 to be accessed */
typedef union U32Bytes {
	u32 x32;

	struct x16 {
		u16 lo;
		u16 hi;
	} x16;

	struct x8 {
		u8 b0;
		u8 b1;
		u8 b2;
		u8 b3;
	} x8;

} U32Bytes;

/* Union/structure definition that allows u8, u16 and u32's in u64 to be accessed */
typedef union U64Bytes {
	u64 x64;

	struct x32 {
		u32 v0;
		u32 v1;
	} x32;

	struct x16 {
		u16 v0;
		u16 v1;
		u16 v2;
		u16 v3;
	} x16;

	struct x8 {
		u8 b0;
		u8 b1;
		u8 b2;
		u8 b3;
		u8 b4;
		u8 b5;
		u8 b6;
		u8 b7;
	} x8;

} U64Bytes;

#endif /* _TYPEDEFS_WIN32_H_ */
