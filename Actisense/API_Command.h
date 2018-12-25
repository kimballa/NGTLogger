#ifndef __API_COMMAND_H
#define __API_COMMAND_H

/*************************************************************************
	Dependent Includes :
**************************************************************************/
#include "TypeDefs.h"
#include "API_DLL.h"
#include "BEMProtocolEnums.h"
#include "API_Decode_Datatypes.h"

/*************************************************************************
 COPYRIGHT 2007-2009 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : API_Command.h

 DESCRIPTION : Refer to Actisense Comms SDK User Manual for details

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.003
 Rev Date 	 : 2008-04-03
 Rev Author  : Phil Whitehurst
 Rev Details : First added to library
 -------------------------------------------------------------------------
 Rev Number  : 1.026
 Rev Date 	 : 06-APR-2009
 Rev Author  : Andy Campbell
 Rev Details : 
    Added 'Get' versions of three 'Set' Commands to allow easier reading of
    these values from target device:
        ACommsCommand_GetPortBaudCodes
        ACommsCommand_GetPortPCodes
        ACommsCommand_GetPortDupDelete
 -------------------------------------------------------------------------
 Rev Number  : 1.100
 Rev Date 	 : 15-DEC-2009
 Rev Author  : Andy Campbell
 Rev Details : 
	Added new Get & Set 'ACommsCommand_xxxHardwareBaudCodes' commands - 
	these are session only for immediate hardware changes. Operation of
	'ACommsCommand_SetPortBaudCodes changed so it immediately commits the
	changes to EPPROM but does not change the hardware setup.
 -------------------------------------------------------------------------
 Rev Number  : 1.101
 Rev Date 	 : 11-JAN-2010
 Rev Author  : Phil Whitehurst & Andy Campbell
 Rev Details : 
    Added 'Get' versions for both ACommsCommand_SetStream and 
    ACommsCommand_SetN2KAddress
	Added new Get & Set 'ACommsCommand_xxxOperatingMode' commands
 -------------------------------------------------------------------------

 ACommsCommand_GetOperatingMode
**************************************************************************/


/* API Command Setup Functions */
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetStream (int Handle, stream_t *Stream);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetStream (int Handle, stream_t Stream);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetN2KAddress (int Handle, u8 *N2KAddress);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetN2KAddress (int Handle, u8 N2KAddress);
/* API Command Functions */
ACTISENSECOMMS_API int __stdcall ACommsCommand_Reboot (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_ReInitMainApp (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_CommitToEEPROM (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_CommitToFlash (int Handle);

ACTISENSECOMMS_API int __stdcall ACommsCommand_GetHardwareInfo (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetOperatingMode (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetOperatingMode (int Handle, u16 OperatingMode);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetHardwareBaudCodes (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetHardwareBaudCodes (int Handle, int nBaudCodes, u8 *BaudCodes);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetPortBaudCodes (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetPortBaudCodes (int Handle, int nBaudCodes, u8 *BaudCodes);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetPortPCodes (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetPortPCodes (int Handle, int nPCodes, u8 *PCodes);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetPortDupDelete (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetPortDupDelete (int Handle, int nPortDupDelete, u8 *PortDupDelete);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetTotalTime (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetTotalTime (int Handle, u32 TotalTime, u32 Passkey);

ACTISENSECOMMS_API int __stdcall ACommsCommand_GetProductInfoN2K (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetCanConfig (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetCanConfig (int Handle, int Preferred, int SystemInstance, int DeviceInstance);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetCanInfoField1 (int Handle, const char *InfoString);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetCanInfoField2 (int Handle, const char *InfoString);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetCanInfoField3 (int Handle, const char *InfoString);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetCanInfoField1 (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetCanInfoField2 (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetCanInfoField3 (int Handle);

ACTISENSECOMMS_API int __stdcall ACommsCommand_SetRxPGN (int Handle, u32 PGN, PGNEnable_t Enable);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetRxPGNEx (int Handle, u32 PGN, PGNEnable_t Enable, PGNMask_t Mask);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetRxPGN (int Handle, u32 PGN);

ACTISENSECOMMS_API int __stdcall ACommsCommand_SetTxPGN (int Handle, u32 PGN, PGNEnable_t Enable);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetTxPGNEx (int Handle, u32 PGN, PGNEnable_t Enable, u32 Rate, u32 Timeout);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetTxPGN (int Handle, u32 PGN);

ACTISENSECOMMS_API int __stdcall ACommsCommand_GetRxPGNList (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetTxPGNList (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_ClearPGNList (int Handle, PGNEnableList_t ListID);
ACTISENSECOMMS_API int __stdcall ACommsCommand_ClearRxPGNList (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_ClearTxPGNList (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_ActivatePGNEnableLists  (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsCommand_SetDefaultPGNEnableList (int Handle, PGNEnableList_t ListID);
ACTISENSECOMMS_API int __stdcall ACommsCommand_GetParamsPGNEnableLists  (int Handle);


/*************************************************************************
	Documentation : Data types
**************************************************************************/

/*************************************************************************
stream_t
--------
Enumerator for the possible streams that commands can be sent over
Possible values :
CmdStreamBST		: Command is sent in Actisense proprietary BST 
						  format over the local serial link.
						  Use with Actisense BST interfaced devices 
						  connected to the local serial port e.g. NGT
CmdStreamN183	: Command is wrapped as a proprietary NMEA 0183 
						  string formatted as Actisense $PARL and sent
						  over the local serial link.
						  Use with Actisense NMEA 0183 interfaced devices 
						  connected to the local serial port e.g. NGW
CmdStreamN2K	: Command is wrapped as a proprietary NMEA 2000
						  message and sent to the target device whose
						  address can be set using the function
						  ACommsCommand_SetN2KAddress.
						  Used for targetting remote Actisense devices 
						  over the NMEA 2000 network (via a local NGT)
**************************************************************************/


/*************************************************************************
Documentation : Functions
**************************************************************************/
/*************************************************************************
All API functions are of the following form:

ACTISENSECOMMS_API int __stdcall <ACommsFunctionName>( int Handle, ... )

1) All take an integer Handle as their first argument, this is the handle
   returned by the ACommsCreate function allowing these functions to access
   the required Actisense comms resource pointed to by that handle.
2) All return an integer Error code. This error code should be zero if no
   error has occurred. If an error has occurred, a negative error code is
   returned, the error may be discovered by looking them up in
   "ARLErrorCodes.h"

**************************************************************************/

/*************************************************************************
API COMMANDS:
THESE COMMANDS AFFECT THE API SETTINGS, NOT THE TARGET UNIT
**************************************************************************
--------------------------------------------------------------------------
Function    : ACommsCommand_GetStream

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        stream_t Pointer to return current Stream API commands are using
__out		int Error code (negative value), if given stream deemed invalid
                (Refer to ARLErrorCodes header for details of these codes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_SetStream

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        stream_t New Stream to send future API commands to
__out		int Error code (negative value), if given stream deemed invalid
                (Refer to ARLErrorCodes header for details of these codes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_GetN2KAddress

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        u8 Pointer to return current NMEA 2000 Address API commands are
				using (if stream is also set to NMEA 2000)
__out		int Error code, if Address deemed invalid (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_SetN2KAddress

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        u8  New NMEA 2000 Address to route future API command to
                (if stream is also set to NMEA 2000)
__out		int Error code, if Address deemed invalid (Refer to ARLErrorCodes)
--------------------------------------------------------------------------

/*************************************************************************
TARGET UNIT COMMANDS:
THESE COMMANDS ARE SENT OVER THE CURRENT COMMAND STREAM TO A TARGET 
(local or remote) ACTISENSE DEVICE
**************************************************************************
--------------------------------------------------------------------------
Function    : ACommsCommand_Reboot
Decode      : ACommsDecode_GetTag
DataType    : ddConfirmSoftwareReset

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_ReInitMainApp
Decode      : ACommsDecode_GetTag
DataType    : ddHardwareInfo

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_CommitToEEPROM
Decode      : ACommsDecode_GetTag
DataType    : ddCommitToEEPROM

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_CommitToFlash
Decode      : ACommsDecode_GetTag
DataType    : ddCommitToFlash

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------

/*************************************************************************
GENRAL INFORMATION AND DEVICE SETTING COMMANDS: 
THESE COMMANDS HANDLE BASIC SETTINGS OF THE TARGET DEVICE
**************************************************************************
--------------------------------------------------------------------------
Function    : ACommsCommand_GetHardwareInfo
Decode      : ACommsDecode_GetHardwareInfo
DataType    : ddHardwareInfo

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_GetOperatingMode
Decode      : ACommsDecode_GetOperatingMode
DataType    : ddOperatingMode

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_SetHardwareBaudCodes
Decode      : ACommsDecode_GetHardwareBaudCodes
DataType    : ddHardwareBaud

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        int Number of Baud codes (0 if command is simple request for data)
__in        u8  *BaudCodes - pointer to array containing new Baud codes.
                (Pointer is NULL if command is simple request for data)
				Each member is set to the required Baud rate code defined
                in the ARLBaudCode header
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_SetPortBaudCodes
Decode      : ACommsDecode_GetPortBaudCodes
DataType    : ddPortBaudCfg

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        int Number of Baud codes (0 if command is simple request for data)
__in        u8  *BaudCodes - pointer to array containing new Baud codes.
                (Pointer is NULL if command is simple request for data)
				Each member is set to the required Baud rate code defined
                in the ARLBaudCode header
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_SetPortPCodes
Decode      : ACommsDecode_GetPortPCodes
DataType    : ddPortPCodeCfg

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        int Number of P code enables (0 if command is simple request for data)
__in        u8  *PCodes	- pointer to array containing new P code enables.
                (Pointer is NULL if command is simple request for data)
				Each member is 0 for disable, or 1 for enable
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_SetPortDupDelete
Decode      : ACommsDecode_GetPortDupDelete
DataType    : ddPortDupDelete

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        int Number of Port duplicate delete settings 
                (0 if command is simple request for data)
__in        u8  *PortDupDelete - pointer to array containing new duplicate
				delete enables (pointer is NULL if command is simple request for data)
				Each member is 0 for disable, or 1 for enable
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_GetTotalTime
Decode      : ACommsDecode_GetTotalTime
DataType    : ddTotalTime

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_SetTotalTime
Decode      : ACommsDecode_GetTotalTime
DataType    : ddTotalTime

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        u32 Total Time in seconds (0 - 136 years)
__in        u32 Passkey - required to allow access to this operation
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------

/*************************************************************************
NMEA 2000 COMMANDS: 
THESE COMMANDS HANDLE NMEA 2000 / CAN BUS RELATED SETTINGS
FOR THE TARGET DEVICE, SO AR EONLY RELEVANT TO ACTISENSE 
DEVICES  THAT SUPPORT NMEA 2000 
**************************************************************************
--------------------------------------------------------------------------
Function    : ACommsCommand_GetProductInfoN2K
Decode      : ACommsDecode_GetProductInfoN2K
DataType    : ddProductInfoN2K

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_GetCanConfig
Decode      : ACommsDecode_GetCanConfig
DataType    : ddCANConfig

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_SetCanConfig
Decode      : ACommsDecode_GetCanConfig
DataType    : ddCANConfig

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        int Preferred Address (0 - 251). Use DONOT_CHANGE_U8 defined 
                value (0xFF) if Preferred Address field should not be changed
__in        int New System Instance (0 - 12). Use DONOT_CHANGE_U8 defined 
                value (0xFF) if System instance field should not be changed
__in        int New Device Instance (0 - 252). Use DONOT_CHANGE_U8 defined 
                value (0xFF) if Device instance field should not be changed
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_SetCanInfoField1
Function    : ACommsCommand_SetCanInfoField2
Function    : ACommsCommand_SetCanInfoField3
Function    : ACommsCommand_GetCanInfoField1
Function    : ACommsCommand_GetCanInfoField2
Function    : ACommsCommand_GetCanInfoField3

Decode      : ACommsDecode_GetCanInfo
DataType    : ddCANInfoField 1 / 2 / 3

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        char* InfoString - pointer to a NULL-terminated string containing
                the requested new CAN information text string. 
                ("ACommsDecode_Get" Functions do not have this parameter)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_SetRxPGN
Function    : ACommsCommand_SetRxPGNEx
Decode      : ACommsDecode_GetRxPGN
DataType    : ddEnableRxPGN

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        u32 NMEA 2000 PGN Number being set up
__in        u32 Enable (1) or Disable (0) status
__in        PGNmask_t Enumerated type Mask value
                (PGNmask_t defined in "BEMProtocolEnums.h").
                #defines from library: USE_DEFAULT_PGN_MASK to specify the
                library default set in the Gateway.
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_GetRxPGN
Decode      : ACommsDecode_GetRxPGN
DataType    : ddEnableRxPGN

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        u32 NMEA 2000 PGN Number who's enable status is being requested
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_SetTxPGN 
Function    : ACommsCommand_SetTxPGNEx
Decode      : ACommsDecode_GetTxPGN
DataType    : ddEnableTxPGN

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        u32 NMEA 2000 PGN Number being set up
__in        u32 Enable (1) or Disable (0) status
__in        u32 Desired transmission rate of data in milliseconds - 
                this is time period between successive transmissions of this
                PGN. Device programmed to have a minimum setting for this, 
                and will respond with an error code if the setting is too low.
				#defines from library: USE_DEFAULTS_U32 for "Use default"
__in        u32 For repeated PGNs, this setting is the Timeout for the data
                - the gateway must receive new data from the PC within this
                time period, or the PGN will stop being sent.
				#defines from library: USE_DEFAULTS_U32 for "Use default"
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_GetTxPGN
Decode      : ACommsDecode_GetTxPGN
DataType    : ddEnableTxPGN

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        u32 NMEA 2000 PGN Number who's enable status is being requested
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_GetRxPGNList
Decode      : ACommsDecode_GetRxPGNList
DataType    : ddRxPGNEnableList

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_GetTxPGNList
Decode      : ACommsDecode_GetTxPGNList
DataType    : ddTxPGNEnableList

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : ACommsCommand_ClearPGNList
Function    : ACommsCommand_ClearRxPGNList
Function    : ACommsCommand_ClearTxPGNList
Decode      : ACommsDecode_GetTag
DataType    : ddDeletePGNEnableList

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        PGNEnableList_t	List ID - one of:
				ENABLE_LIST_RX, ENABLE_LIST_TX or ENABLE_LIST_RXTX (delete both lists)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : int ACommsCommand_ActivatePGNEnableLists 
Decode      : GetActivatePGNEnableListResponse
DataType    : ddActivatePGNEnableLists

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : int ACommsCommand_SetDefaultPGNEnableList
Decode      : ACommsDecode_GetTag
DataType    : ddDefaultPGNEnableList

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__in        PGNEnableList_t ListID - one of : 
				ENABLE_LIST_RX, ENABLE_LIST_TX, or ENABLE_LIST_RXTX (default both lists)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Function    : int ACommsCommand_GetParamsPGNEnableLists
Decode      : ACommsDecode_GetParamsPGNEnableLists
DataType    : ddParamsPGNEnableLists

Refer to Actisense Comms SDK User Manual for details.

__in		int Handle to Comms object (returned by ACommsCreate)
__out		int Error code, if operation failed (Refer to ARLErrorCodes)
--------------------------------------------------------------------------

**************************************************************************/

#endif /* __API_COMMAND_H */
