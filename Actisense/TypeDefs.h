/*************************************************************************/
/**         Active Research Limited 2008 - ANSI C Library Header        **/
/*************************************************************************/

/*************************************************************************
 COPYRIGHT 1999-2008 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : TypeDefs.h

 DESCRIPTION : Header file for the standard ARL redirected Type Defines

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.000
 Rev Date 	 : 2008-01-09
 Rev Author  : Phil Whitehurst
 Rev Details : First library release
 -------------------------------------------------------------------------
**************************************************************************/

#ifndef __TYPEDEFS_H
#define __TYPEDEFS_H
/*************************************************************************
 	Types definitions used in the project files :
**************************************************************************/

#if defined  (_CVI_)
	/* Defined by CVI compiler for x86 micros */
	#include "TypeDefs_CVI.h"

#elif defined (_WIN32)
	/* Defined by any 'Windows 32' compiler (e.g. Borland) for x86 micros */
	#include "TypeDefs_WIN32.h"

#elif defined (__ICCARM__)
	/* Defined by IAR compiler for ARM core micros */
	#include "TypeDefs_IAR.h"

#elif defined (__CC_ARM)
	/* Defined by RealView compiler for ARM core micros 
	   redefined to add include protect */
	#include "TypeDefs_STM32F10x.h"

#elif defined (HI_TECH_C)
	/* Defined by Hi-Tec's PIC18 compiler for PIC18 micros */
	#include "TypeDefs_PIC.h"

#endif

#endif /* _TYPEDEFS_H_ */
