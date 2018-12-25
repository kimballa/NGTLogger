#ifndef __API_DECODE_H
#define __API_DECODE_H

/*************************************************************************
	Dependent Includes :
**************************************************************************/
#include "TypeDefs.h"
#include "API_DLL.h"
#include "ExcelTime.h"
#include "API_Decode_Datatypes.h"

/*************************************************************************
 COPYRIGHT 2007-2009 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : API_Decode.h

 DESCRIPTION : Refer to Actisense Comms SDK User Manual for details

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.000
 Rev Date 	 : 2008-06-03
 Rev Author  : Phil Whitehurst
 Rev Details : First library release
 -------------------------------------------------------------------------
 -------------------------------------------------------------------------
 Rev Number  : 1.1.0.1
 Rev Date 	 : 201001-15
 Rev Author  : Phil Whitehurst
 Rev Details : Changed ACommsDecode_GetAge to take const sDecodeTag* DecodeTag
	instead of sDecodeTag* to reflect fact function does not change tag
 -------------------------------------------------------------------------
 
**************************************************************************/

/*************************************************************************
    Function prototypes - Helper functions :
These functions provide useful services to help use the API library and 
make extra information available for the decode resources
**************************************************************************/
ACTISENSECOMMS_API u32 __stdcall ACommsDecode_GetAge (const  sDecodeTag* DecodeTag);
ACTISENSECOMMS_API const char * __stdcall ACommsDecode_GetDataTypeName (DecodeData_t DataType, DecodeDetail_t DecodeDetail);
ACTISENSECOMMS_API const char * __stdcall ACommsDecode_GetUARTBaudCodeName (u32 Code, DecodeDetail_t DecodeDetail);
ACTISENSECOMMS_API const char * __stdcall ACommsDecode_GetCANBaudCodeName (u32 Code, DecodeDetail_t DecodeDetail);
ACTISENSECOMMS_API const char * __stdcall ACommsDecode_GetModelIDName (u32 Code, DecodeDetail_t DecodeDetail);

/*************************************************************************
    Function prototypes - Setup functions :
These functions provide essential setup to allow the decode API	to work
**************************************************************************/
ACTISENSECOMMS_API int __stdcall ACommsDecode_SetCallback (int Handle, DecodeData_t DataType, void (__stdcall *pFunc)(void*,
                                                           DecodeData_t, DecodeReason_t), void* pUserCallbackData);
ACTISENSECOMMS_API int __stdcall ACommsDecode_SetCallbackGroup (int Handle, DecodeData_t *DataType, int DataTypeSize,
                                	       void (__stdcall *pFunc)(void*, DecodeData_t, DecodeReason_t), void* pUserCallbackData);
    
/*************************************************************************
    Function prototypes - Decode data functions:
These functions perform the actions of decoding the BST messages into easy
to read API structures
**************************************************************************/
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetTag			   (int Handle, sDecodeTag *pTag, DecodeData_t DataType);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetTagAndData        (int Handle, sDecodeArray_u8 *pMessage, DecodeData_t DataType,
                                                                    u32 MessageMaxSize);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetHardwareInfo	   (int Handle, sDecodeHardwareInfo  *pHardInfo);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetOperatingMode     (int Handle, sDecodeOperatingMode *pOperatingMode);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetHardwareBaudCodes (int Handle, sDecodePortBaudCodes *pBaudCodes);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetPortBaudCodes	   (int Handle, sDecodePortBaudCodes *pBaudCodes);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetPortPCodes		   (int Handle, sDecodeArray_u8	     *pPCodes);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetPortDupDelete	   (int Handle, sDecodeArray_u8	     *pDupDelete);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetTotalTime		   (int Handle, sDecodeTotalTime	 *pTotalTime);

ACTISENSECOMMS_API int __stdcall ACommsDecode_GetProductInfoN2K	   (int Handle, sDecodeProductInfoN2K *pProductInfoN2K);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetCanConfig		   (int Handle, sDecodeCanConfig	  *pCanConfig);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetCanInfoField1	   (int Handle, sDecodeCanInfoField   *pCanInfoField);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetCanInfoField2	   (int Handle, sDecodeCanInfoField   *pCanInfoField);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetCanInfoField3	   (int Handle, sDecodeCanInfoField   *pCanInfoField);

ACTISENSECOMMS_API int __stdcall ACommsDecode_GetRxPGN			   (int Handle, sDecodeRxPGN	 *pDecodeRxPGN);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetTxPGN			   (int Handle, sDecodeTxPGN	 *pDecodeTxPGN);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetRxPGNList		   (int Handle, sDecodeRxPGNList *pDecodeRxPGNList);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetTxPGNList		   (int Handle, sDecodeTxPGNList *pDecodeTxPGNList);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetParamsPGNEnableLists (int Handle, sDecodePGNEnableListStatus* pPGNListStatus);

ACTISENSECOMMS_API int __stdcall ACommsDecode_GetStartupStatus    (int Handle, sDecodeStartupStatus* pStartupStatus);
ACTISENSECOMMS_API int __stdcall ACommsDecode_GetSystemStatus     (int Handle, sDecodeSystemStatus *pSystemStatus);

ACTISENSECOMMS_API int __stdcall ACommsDecode_GetDbgTimeProfiler  (int Handle, sDbgTimeProfiler* pTimeProfile);


/*************************************************************************
	Function Documentation : 
**************************************************************************/

/*************************************************************************
--------------------------------------------------------------------------
Function    : ACommsDecodeGetAge

Refer to Actisense Comms SDK User Manual for details.

__in        sDecodeTag* - pointer to a Decode Tag structure
__out       u32 Age of the tag in milliseconds
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetDataTypeName

Refer to Actisense Comms SDK User Manual for details.

__in        DataType - enumerated DecodeData_t data type code
__in        DecodeDetail - enumerated DecodeDetail_t, requesting required
                detail of returned string required. see "API_Decode_Datatypes.h"
__out       char* - pointer to the name of the data type as a string
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetUARTBaudCodeName
Function    : ACommsDecode_GetCANBaudCodeName

Refer to Actisense Comms SDK User Manual for details.

__in        u32 Code number representing enumerated Code
__in        DecodeDetail - enumerated DecodeDetail_t, requesting required 
                detail of returned string required - see "API_Decode_Datatypes.h"
__out       char* - pointer to NULL-terminated constant string of chars
				describing the enumerated code value
--------------------------------------------------------------------------

--------------------------------------------------------------------------
Function    : ACommsDecode_SetCallback

Refer to Actisense Comms SDK User Manual for details.

Important:  No windows should be created by the callback function, as the 
            wait loop within the Comms thread does not process windows 
            messages to reduce overhead; if the callback function creates
            a window, it could cause a system deadlock due to the 
            unprocessed message queue.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        DataType_t Enumerated DecodeData_t Callback data type being registered
__in        void (*pFunc)(void*,DecodeData_t, DecodeReason_t)
                Refer to documentation below
__in        int User defined Callback data for user specific functionality
__out		int Error code (negative value), if Set operation deemed invalid
                (Refer to ARLErrorCodes header for details of these codes)
--------------------------------------------------------------------------
Callback function Details:

The callback function prototype must be of the form :
    void (*pFunc)(int DataID, int UserCallbackData)

    void*,			Pointer to user callback function accepting three variables
    DecodeData_t,   (See callback function documentation)
    DecodeReason_t

__in void*			UserData - Data applied by the ACommsDecode_SetCallback
					will be passed back to the user.  this is defined as a
					void pointer for maximum flexibility.  It is up to the
					user to assign the pointer and type check it to make 
                    sure it is valid.

__in DecodeData_t	DataType - indicates which data type the callback is 
                    being invoked for. This can be used where the same 
                    callback is used for all data types, using a switch-
                    case or similar to decide how to handle the data - 
                    see example software for more detail.

__out				None - the function must be type void
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_SetCallbackGroup

Refer to '_SetCallback' description above and the Actisense Comms SDK 
User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        DataType_t Pointer to an array of enumerated DecodeData_t 
                Callback data types being registered
__in        int Size of data type array (number of data types that will 
                trigger the calling of the given callback function)
__in        void (*pFunc)(void*,DecodeData_t, DecodeReason_t)
                Refer to documentation above
__in        int User defined Callback data for user specific functionality
__out		int Error code (negative value), if Set operation deemed invalid
                (Refer to ARLErrorCodes header for details of these codes)
--------------------------------------------------------------------------

--------------------------------------------------------------------------
Function    : ACommsDecode_GetTag

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeTag* - pointer to a decode tag structure to hold the
                responding information
__in        DecodeData_t - data type whose tag data is to be returned the
				enumerated type DecodeData_t
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetHardwareInfo
Command     : ACommsCommand_GetHardwareInfo
DataType    : ddHardwareInfo

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sHardwareInfo	: pHardInfo* - The API user must create this structure
                and pass in a pointer to it. The API will then fill out the
                structure with the information decoded from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetOperatingMode
Command     : ACommsCommand_GetOperatingMode
Command     : ACommsCommand_SetOperatingMode
DataType    : ddOperatingMode

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeArray_u8: pBaudCodes* The API user must create this structure
                and pass in a pointer to it. The API will then fill out the
                structure with the information decoded from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetHardwareBaudCodes
Command     : ACommsCommand_GetHardwareBaudCodes
Command     : ACommsCommand_SetHardwareBaudCodes
DataType    : ddHardwareBaudCfg

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeArray_u8: pBaudCodes* The API user must create this structure
                and pass in a pointer to it. The API will then fill out the
                structure with the information decoded from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetPortBaudCodes
Command     : ACommsCommand_GetPortBaudCodes
Command     : ACommsCommand_SetPortBaudCodes
DataType    : ddPortBaudCfg

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeArray_u8: pBaudCodes* The API user must create this structure
                and pass in a pointer to it. The API will then fill out the
                structure with the information decoded from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetPortPCodes
Command     : ACommsCommand_GetPortPCodes
Command     : ACommsCommand_SetPortPCodes
DataType    : ddPortPCodeCfg

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeArray_u8: pPCodes* The API user must create this structure 
                and pass in a pointer to it. The API will then fill out the
                structure with the information decoded from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetPortDupDelete
Command     : ACommsCommand_GetPortDupDelete
Command     : ACommsCommand_SetPortDupDelete
DataType    : ddPortDupDelete

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeArray_u8: pDupDelete* The API user must create this structure
                and pass in a pointer to it. The API will then fill out the
                structure with the information decoded from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetTotalTime
Command     : ACommsCommand_GetTotalTime
Command     : ACommsCommand_SetTotalTime
DataType    : ddTotalTime

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeTotalTime* : pTotalTime* The API user must create this 
                structure and pass in a pointer to it. The API will then fill
                out the structure with the information decoded from the device
                response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetProductInfoN2K
Command     : ACommsCommand_GetProductInfoN2K
DataType    : ddProductInfoN2K

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeProductInfoN2K* : pProductInfoN2K* The API user must create
                this structure and pass in a pointer to it. The API will then
                fill out the structure with the information decoded from the 
                device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetCanConfig
Command     : ACommsCommand_GetCanConfig
Command     : ACommsCommand_SetCanConfig
DataType    : ddCanConfig

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeCanConfig: *pCanConfig The API user must create this structure
                and pass in a pointer to it. The API will then fill out the
                structure with the information decoded from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetCanInfoField 1 / 2 / 3
Command     : ACommsCommand_GetCanInfoField 1 / 2 / 3
Command     : ACommsCommand_SetCanInfoField 1 / 2 / 3
DataType    : ddCanInfoField 1 / 2 / 3

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeCanInfoField: *pCanInfoField The API user must create this
                structure and pass in a pointer to it. The API will then fill
                out the structure with the information decoded from the device
                response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetRxPGN
Command     : ACommsCommand_GetRxPGN
Command     : ACommsCommand_SetRxPGN
Command     : ACommsCommand_SetRxPGNEx
DataType    : ddEnableRxPGN

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        DecodeRxPGN *pDecodeRxPGN The API user must create this structure
                and pass in a pointer to it. The API will then fill out the
                structure with the information decoded from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetTxPGN
Command     : ACommsCommand_GetTxPGN
Command     : ACommsCommand_SetTxPGN
Command     : ACommsCommand_SetTxPGNEx
DataType    : ddEnableTxPGN

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        DecodeTxPGN *pDecodeTxPGN The API user must create this structure
                and pass in a pointer to it. The API will then fill out the
                structure with the information decoded from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetRxPGNList
Command     : ACommsCommand_GetRxPGNList
DataType    : ddRxPGNEnableList

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeRxPGNList: *pDecodeRxPGNList The API user must create this
                structure and pass in a pointer to it. The API will then fill
                out the structure with the information decoded from the device
                response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetTxPGNList
Command     : ACommsCommand_GetTxPGNList
DataType    : ddTxPGNEnableList

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeTxPGNList: *pDecodeTxPGNList The API user must create this
                structure and pass in a pointer to it. The API will then fill
                out the structure with the information decoded from the device
                response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetActivatePGNEnableListResponse
Command     : ACommsCommand_ActivatePGNEnableLists
DataType    : ddActivatePGNEnableLists

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodePGNEnableListStatus: *pPGNListStatus The API user must 
                create this structure and pass in a pointer to it. The API 
                will then fill out the structure with the information decoded
                from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetParamsPGNEnableLists
Command     : ACommsCommand_GetParamsPGNEnableLists
DataType    : ddParamsPGNEnableLists

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodePGNEnableListStatus: *pPGNListStatus The API user must 
                create this structure and pass in a pointer to it. The API 
                will then fill out the structure with the information decoded
                from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------

--------------------------------------------------------------------------
Function    : ACommsDecode_GetStartupStatus
Command     : None - this message is sent once only when device starts up
DataType    : ddStartupStatus

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeStartupStatus*: pStartupStatus The API user must create this
                structure and pass in a pointer to it. The API will then fill 
                out the structure with the information decoded from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetSystemStatus
Command     : None - this message is sent once per second (if P-codes enabled)
DataType    : pSystemStatus

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDecodeSystemStatus*: pSystemStatus The API user must create this
                structure and pass in a pointer to it. The API will then fill 
                out the structure with the information decoded from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsDecode_GetDbgTimeProfiler
Command     : None - this message is sent once per second (if P-codes enabled & debug firmware)
DataType    : ddDebugTimeProfiler

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        sDbgTimeProfiler*: pTimeProfile The API user must create this
                structure and pass in a pointer to it. The API will then fill 
                out the structure with the information decoded from the device response
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------

**************************************************************************/

#endif /* __API_DECODE_H */
