#ifndef __API_NMEA0183_H
#define __API_NMEA0183_H

/*************************************************************************
	Dependent Includes :
**************************************************************************/
#include "TypeDefs.h"
#include "NMEA0183_Datatypes.h"
#include "API_DLL.h"

/*************************************************************************/
/**         Active Research Limited 2009 - ANSI C Library Header        **/
/*************************************************************************/

/*************************************************************************
 COPYRIGHT 2007-2009 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : API_NMEA0183.h

 DESCRIPTION : Header file for NMEA 0183 API for Actisense Comms dll
               Refer to Actisense Comms SDK User Manual for details

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.000
 Rev Date 	 : 2008-03-11
 Rev Author  : Phil Whitehurst
 Rev Details : First library release
 -------------------------------------------------------------------------
 Rev Number  : 1.015
 Rev Date 	 : 2008-11-14
 Rev Author  : Phil Whitehurst
 Rev Details : New data types include provided
 -------------------------------------------------------------------------
**************************************************************************/
/*************************************************************************
	Function prototypes :
**************************************************************************/
ACTISENSECOMMS_API int __stdcall ACommsN183_Write (int Handle, sN183Msg *msg);
ACTISENSECOMMS_API int __stdcall ACommsN183_Read  (int Handle, sN183Msg *msg);
ACTISENSECOMMS_API int __stdcall ACommsN183_GetRxQSize (int Handle, size_t *BufferSize);
ACTISENSECOMMS_API int __stdcall ACommsN183_FlushRx (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsN183_FlushTx (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsN183_SetRxCallback (int Handle, void  (__stdcall *pFunc)(void*), void* p);


/*************************************************************************
	Documentation : Functions
**************************************************************************/

/*************************************************************************

--------------------------------------------------------------------------
Function    : ACommsN183_Write

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sN183Msg *msg - pointer to NMEA 0183 message to transmit 
                in sN183Msg structure format
__out		int Error code (negative value), if operation deemed invalid
                (Refer to ARLErrorCodes header for details of these codes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsN183_Read

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sN183Msg *msg - pointer to empty NMEA 0183 message structure
                where received NMEA 0183 data will get stored in
                sN183Msg structure format
__out       sNMEA0183KMsg *msg - NMEA 0183 message data is copied into
				this supplied structure
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsN183_GetRxQSize

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        size_t *BufferSize - pointer to size_t in which to store size
                of buffer
__out       size_t *BufferSize - Size of buffer in NMEA 0183 Messages, 
                0 if an error was detected
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsN183_FlushRx

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsN183_FlushTx

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsN183_SetRxCallback

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

#endif /* __API_NMEA0183_H */
