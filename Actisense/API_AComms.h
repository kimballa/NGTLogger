#ifndef __API_ACOMMS_H
#define __API_ACOMMS_H

/*************************************************************************
Dependent Includes :
**************************************************************************/
#include "TypeDefs.h"
#include "API_DLL.h"
#include "API_NMEA0183.h"
#include "API_NMEA2000.h"
#include "API_BST.h"
#include "API_Command.h"
#include "API_CommsLog.h"
#include "API_Decode.h"

/*************************************************************************
 COPYRIGHT 2008-9 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME    : API_AComms.h

 DESCRIPTION : Refer to Actisense Comms SDK User Manual for details

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.000
 Rev Date 	 : 09-02-2008
 Rev Author  : Phil Whitehurst
 Rev Details : First revision
 -------------------------------------------------------------------------
 Rev Number  : 1.003 
 Rev Date 	 : 03-APR-2008
 Rev Author  : Phil Whitehurst
 Rev Details : 
 -------------------------------------------------------------------------
 Rev Number  : 1.017 
 Rev Date 	 : 24-NOV-2008
 Rev Author  : Phil Whitehurst
 Rev Details : 
    Added ACOMMS_INVALID_HANDLE to allow external software to configure a
    handle as invalid in constructor or as default value of variable
 -------------------------------------------------------------------------
 Rev Number  : 1.020
 Rev Date 	 : 07-JAN-2009
 Rev Author  : Phil Whitehurst
 Rev Details : 
    Added ACommsEnumerateSerialPorts
    Added ACommsEnumerateSerialPortsGetName
    Added ACommsGetPortNumber
    Added ACommsGetPortBaudrate
 -------------------------------------------------------------------------
 Rev Number  : 1.026
 Rev Date 	 : 06-APR-2009
 Rev Author  : Andy Campbell
 Rev Details : 
    ACommsOpen modifed to automatically close any open Comms port if given
    handle is already active, before opening new port with new parameters
 -------------------------------------------------------------------------
 Rev Number  : 1.1.0.0
 Rev Date 	 : 30-DEC-2009
 Rev Author  : Phil Whitehurst
 Rev Details : 
    ACommsGetRxLoading & ACommsGetTxLoading added
 -------------------------------------------------------------------------

**************************************************************************/


/*************************************************************************
CONSTANTS:
**************************************************************************/ 
/* Defines the invalid value for an Actisense Comms Handle (the default) */
#define ACOMMS_INVALID_HANDLE   0


/*************************************************************************
	Data structures :
**************************************************************************/

/*------------------------------------------------------------------------
	Port enumerations
  ------------------------------------------------------------------------*/
typedef enum PortEnumStatus_t {
	ACPES_Available,
	/* Port is unavailable for some other reason than already being open */
	ACPES_Unavailable,
	ACPES_Open,
	/* Port scan has not yet been performed - A method will be made 
	   available to scan through all ports and discover whether they are 
	   open, closed or unavailable.  This was in the original API, but the 
	   method is slow for some types so was removed to be made a separate 
	   function so that enumeration can be perfomed quickly */
	ACPES_Unknown

} PortEnumStatus_t;

typedef struct sPortEnum {
	/* Number of Comm ports found by the enumeration function */
	u32 Size;
	/* List of Comm port numbers found (of length 'Size') */
	u32 Ports[256];				
	/* Status of Comm ports found by the enumeration function */
	PortEnumStatus_t PortStatus[256];

} sPortEnum;


/*************************************************************************
FUNCTION PROTOYPES:
**************************************************************************/ 
ACTISENSECOMMS_API int __stdcall ACommsCreate (int *pHandle);
ACTISENSECOMMS_API int __stdcall ACommsDestroy (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsDestroyAll (void);
ACTISENSECOMMS_API int __stdcall ACommsOpen (int Handle, int PortNumber, int Baudrate);
ACTISENSECOMMS_API int __stdcall ACommsClose (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsGetPortNumber (int Handle, int *PortNumber);
ACTISENSECOMMS_API int __stdcall ACommsGetPortBaudrate (int Handle, int *Baudrate);
ACTISENSECOMMS_API int __stdcall ACommsEnumerateSerialPorts (sPortEnum *PortEnum);
ACTISENSECOMMS_API const char* __stdcall ACommsEnumerateSerialPortsGetName (u32 PortNum);

ACTISENSECOMMS_API int __stdcall ACommsGetRxLoading (int Handle, int* pLoading);
ACTISENSECOMMS_API int __stdcall ACommsGetTxLoading (int Handle, int* pLoading);


/*************************************************************************
Function 	: ACommsCreate

Refer to Actisense Comms SDK User Manual for details.

__in_out	int* pHandle - pointer (used to return created handle required
            by all access functions that operate on this resource)  
__out		int Error code (negative value), if handle could not be created
            (Refer to ARLErrorCodes header for details of these codes)
**************************************************************************/ 
/*************************************************************************
Function 	: ACommsDestroy

Refer to Actisense Comms SDK User Manual for details.

__in        int Handle to resource to destroy (returned by ACommsCreate)
__out		int Error code, if resource recovery failed (Refer to ARLErrorCodes)
**************************************************************************/ 
/*************************************************************************
Function 	: ACommsDestroyAll

Refer to Actisense Comms SDK User Manual for details.

__in		void
__out		int Error code, if resource recovery failed (Refer to ARLErrorCodes)
**************************************************************************/ 
/*************************************************************************
Function 	: ACommsOpen

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in		int Port Number to link Comms object to
__in		int Baud rate to open port with
__out		int Error code, if open port failed (Refer to ARLErrorCodes)
**************************************************************************/ 
/*************************************************************************
Function 	: ACommsClose

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if close port failed (Refer to ARLErrorCodes)
**************************************************************************/
/*************************************************************************
Function 	: ACommsGetPortNumber

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in		int *PortNumber - pointer (used to return Port number)
__out		int Error code, if Get Port Number failed (Refer to ARLErrorCodes)
**************************************************************************/
/*************************************************************************
Function 			: ACommsGetPortBaudrate

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in		int *Baudrate - pointer (used to return Baud rate)
__out		int Error code, if Get Baudrate failed (Refer to ARLErrorCodes)
**************************************************************************/
/*************************************************************************
Function 	: ACommsEnumerateSerialPorts

Refer to Actisense Comms SDK User Manual for details.

__in		sPortEnum *Port Enumeration - pointer (to user defined structure
            that will be filled in with the active enumerated ports list 
            currently available to the system) 
__out		int Error code, if Enumeration failed (Refer to ARLErrorCodes)
**************************************************************************/
/*************************************************************************
Function 	: ACommsEnumerateSerialPortsGetName

Refer to Actisense Comms SDK User Manual for details.

__in		u32 Port Number of the Comms port whose name is required
__out		char *Friendly Name - pointer to a text string of maximum 
            length 256 characters (including null terminator)
			Note : This string storage will only persist until this 
            function called again, so calling function should not use this
            pointer directly, but instead copy this string as soon as the
            function returns it.
**************************************************************************/
/*************************************************************************
Function 	: ACommsGetRxLoading
Function 	: ACommsGetTxLoading

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__inout		The loading factor on a port - returns percentage value x 1000 
			(0.000 - 100.000 %) in the passed in reference to int
__ret		int Error code
**************************************************************************/

#endif /* __API_ACOMMS_H */
