#ifndef __API_NMEA2000_H
#define __API_NMEA2000_H

/*************************************************************************
	Dependent Includes :
**************************************************************************/
#include "TypeDefs.h"
#include "NMEA2000_Datatypes.h"
#include "API_DLL.h"

/*************************************************************************/
/**         Active Research Limited 2009 - ANSI C Library Header        **/
/*************************************************************************/

/*************************************************************************
 COPYRIGHT 2007-2009 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : API_NMEA2000.h

 DESCRIPTION : Header file for NMEA 2000 API for Actisense Comms dll
               Refer to Actisense Comms SDK User Manual for details

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.000
 Rev Date 	 : 2008-03-01
 Rev Author  : Phil Whitehurst
 Rev Details : First library release
 -------------------------------------------------------------------------
**************************************************************************/

/*************************************************************************
	Function prototypes :
**************************************************************************/
ACTISENSECOMMS_API int __stdcall ACommsN2K_Write (int Handle, sN2KMsg *msg);
ACTISENSECOMMS_API int __stdcall ACommsN2K_Read  (int Handle, sN2KMsg *msg);
ACTISENSECOMMS_API int __stdcall ACommsN2K_GetRxQSize (int Handle, size_t *BufferSize);
ACTISENSECOMMS_API int __stdcall ACommsN2K_FlushRx (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsN2K_FlushTx (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsN2K_SetRxCallback (int Handle, void  (__stdcall *pFunc)(void*), void* p);


/*************************************************************************
	Documentation : Functions
**************************************************************************/

/*************************************************************************

--------------------------------------------------------------------------
Function    : ACommsN2K_Write

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sN2KMsg *msg - pointer to NMEA 2000 message to transmit in 
                sN2KMsg structure format
__out		int Error code (negative value), if operation deemed invalid
                (Refer to ARLErrorCodes header for details of these codes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsN2K_Read

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sN2KMsg *msg - pointer to empty NMEA 2000 message structure
				where received NMEA 2000 data will get stored in 
                sN2KMsg structure format
__out       sN2KMsg	*msg - NMEA 2000 message data is copied into this 
                supplied structure
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsN2K_GetRxQSize

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        size_t *BufferSize - pointer to size_t in which to store size
                of buffer
__out       size_t *BufferSize - size of buffer in NMEA 2000 Messages,
                0 if an error was detected
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsN2K_FlushRx

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsN2K_FlushTx

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsN2K_SetRxCallback

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        void (*pFunc)(void*) - pointer to user callback function
__in        void* p	- user data passed back by callback to allow the user
                to differentiate between callback sources. For flexibility
                this is a void pointer so that user can select any data 
                type of their choosing
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------

**************************************************************************/

#endif /* __API_NMEA2000_H */
