#ifndef __API_ACOMMS_DLL_H
#define __API_ACOMMS_DLL_H

/*************************************************************************
 COPYRIGHT 2008-2009 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME    :   API_DLL.h

 DESCRIPTION : Refer to Actisense Comms SDK User Manual for details

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number	: 1.000
 Rev Date 	: 2008-09-12
 Rev Author	: Phil Whitehurst
    First revision
 -------------------------------------------------------------------------
 Rev Number	: 1.001
 Rev Date 	: 2008-10-05
 Rev Author	: Phil Whitehurst
    Changed export to extern "C", and applied a .def file to provide
    undecorated function definitions for full compatibility with all C 
    and C++ compilers.
--------------------------------------------------------------------------
**************************************************************************/

/* The following ifdef block is the standard way of creating macros which
   make exporting from a DLL simpler. All files within this DLL are compiled
   with the ACTISENSECOMMS_EXPORTS symbol defined on the command line. 
   This symbol should not be defined on any project that uses this DLL.
   This way any other project whose source files include this file see 
   ACTISENSECOMMS_API functions as being imported from a DLL, whereas this
   DLL sees symbols defined with this macro as being exported. */
#ifdef ACTISENSECOMMS_EXPORTS
  #define ACTISENSECOMMS_API extern "C" __declspec(dllexport)
#else
  #if defined (_CVI_)
	/* This redefine required to override the import setting for
	   a labwindows CVI environment */
	#define ACTISENSECOMMS_API __declspec(dllimport)
  #else 
 	#define ACTISENSECOMMS_API extern "C" __declspec(dllimport)
  #endif
#endif

#endif /* __API_ACOMMS_DLL_H */
