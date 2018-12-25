#ifndef __API_COMMSLOG_H
#define __API_COMMSLOG_H

/*************************************************************************
	Dependent Includes :
**************************************************************************/
#include "TypeDefs.h"
#include "API_DLL.h"

/*************************************************************************
 COPYRIGHT 2007-2009 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : API_CommsLog.h

 DESCRIPTION : Refer to Actisense Comms SDK User Manual for details

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.001
 Rev Date 	 : 2008-05-28
 Rev Author  : Phil Whitehurst
 Rev Details : 
	First added to library
 -------------------------------------------------------------------------
 Rev Number  : 1.002
 Rev Date 	 : 2008-10-09
 Rev Author  : Phil Whitehurst
 Rev Details : 
	New revision removes other file output options in favour of new .ebl
	file format for enhanced binary file data
	Deleted ACommsLog_SetFileStem function, as it was always necessary
	to both set the filestem and the enables at the same time
 -------------------------------------------------------------------------
  -------------------------------------------------------------------------
 Rev Number  : 1.003
 Rev Date 	 : 2009-01-06
 Rev Author  : Phil Whitehurst
 Rev Details : 
	Revision to header file documentation
 -------------------------------------------------------------------------
 Rev Number  : 1.023
 Rev Date 	 : 29-JAN-2009
 Rev Author  : Phil Whitehurst
    Fixed bug in ACommsLog_Enable, files will now correctly close and reopen
    a new log file on subsequent calls.  Previously, an invalid file handle 
    could be created and cause a fault on closing down the DLL or closing 
    the comms handle
 -------------------------------------------------------------------------
**************************************************************************/

/*************************************************************************
API Definitions:
**************************************************************************/
enum APICOMMS_LOGMASKS
{
	COMMSLOG_EBL_RX		= 0x0001,
	COMMSLOG_EBL_TX		= 0x0002,
};

/*************************************************************************
API Functions:
**************************************************************************/
ACTISENSECOMMS_API int __stdcall ACommsLog_Enable (int Handle, const char* FileStem, u32 EnableMask);


/*************************************************************************
	Documentation : Definitions
**************************************************************************/

/*************************************************************************
COMMSLOGMASKS
--------
"Logical Or" together the COMMSLOGMASKS to open and write to the required 
log files. Only current option is to output an "Enhanced Binary Log" (EBL).
This is a data log in a pure binary form with embedded control codes to
give timestamping and other information to the file to aid reconstruction 
of data timeline for replay etc.

Possible values	:
COMMSLOG_EBL_RX	:	Logs received data byte by byte with enhanced embedded
                    control codes file extension will be ".rx.ebl"
COMMSLOG_EBL_TX	:	Logs transmitted data byte by byte with enhanced 
                    embedded control codes file extension will be ".tx.ebl"
**************************************************************************/


/*************************************************************************
	Documentation : Functions
**************************************************************************/
/*************************************************************************
-------------------------------------------------------------------------
Function    :  int ACommsLog_Enable

Refer to Actisense Comms SDK User Manual for details.

__in        int Handle			  : Current Handle for the Actisense comms resource
__in        const char* FileStem : Stem for the filename to use
__in        u32 EnableMask		  : Required logging for this comms resource
__out		int Error code (negative value), if given stream deemed invalid
                (Refer to ARLErrorCodes header for details of these codes)

Revisions:
    Added at 1.003
-------------------------------------------------------------------------

**************************************************************************/

#endif /* __API_COMMSLOG_H */
