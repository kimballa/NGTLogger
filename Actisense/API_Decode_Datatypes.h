#ifndef __API_DECODE_DATATYPES_H
#define __API_DECODE_DATATYPES_H

/*************************************************************************
 COPYRIGHT 2007-2009 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : API_Decode_Datatypes.h

 DESCRIPTION : Refer to Actisense Comms SDK User Manual for details

**************************************************************************/

/*************************************************************************
	Dependent Includes :
**************************************************************************/
#include "TypeDefs.h"
#include "BEMProtocolEnums.h"
#include "ExcelTime.h"

/*************************************************************************
	Decode Data types :
**************************************************************************/
#include "LibBSTTypes.h"


/* API Datatypes */
/*************************************************************************
This enumeration is used to change a command stream to 
**************************************************************************/

typedef enum stream_t { 
	/* Recommended enumerations for new software designs */
	CmdStreamBST = 0,
	CmdStreamN183, 
	CmdStreamN2K,
	/* Normally this value only returned where an error has occurred - e.g. handle was invalid */
	CmdStreamUnknown = 0xFF,

	/* Old definitions - do not used for new software designs */
	COMMANDSTREAM_BST = 0,
	COMMANDSTREAM_NMEA0183, 
	COMMANDSTREAM_NMEA2000,
	COMMANDSTREAM_UNKNOWN = 0xFF,	

} stream_t;

/*************************************************************************
	When a callback occurs, a reason is given for the callback - this
    enumeration allows the decoding of this reason for the API user.
**************************************************************************/
typedef enum DecodeReason_t {
	/* Data arrived ok, data can be retrieved from the API buffer */
	drDecodeDataArrived,
	/* Data did not arrive back for the command sent - a timeout occurred
       - the data type that timed out will be flagged */
	drDecodeTimeout,
	/* Data invalid - data was invalidated, probably because the user code
       cancelled a callback while the callback was being actioned, causing
       the data buffer for that callback to be destroyed before the user
       callback code could access it */
	drDecodeDataInvalid,

} DecodeReason_t;

/*************************************************************************
	DecodeDetail_t
	Description functions allow a named string to be obtained describing
    in text form the enumerated variable supplied. These functions accept
    a variable which changes the level of description available.
**************************************************************************/
typedef enum DecodeDetail_t {
	/* A description function gives a brief
	   description of the supplied variable */
	ddNameBrief,
	/* A description function gives a full
	   description of the supplied variable (if available) */
	ddNameFull,
	/* A description function gives a detailed
	   description of the supplied variable (if available) */
	ddNameDetailed,
	/* maximum value of DecodeDetail_t */
	ddNameMax

} DecodeDetail_t;

/*************************************************************************
	Enumerated and defined Data types :
**************************************************************************/
/*************************************************************************
	Definitions of ports
**************************************************************************/
typedef enum NumPorts_t {
	/* Number of baud codes for an NGW */
	ddNGWNUMPORTS = 2,
	/* Number of baud codes for an NGT */
	ddNGTNUMPORTS = 2,
	/* Maximum number of communication ports for any Actisense product-
	   used to set array size for data information coming back from
	   products - this figure could change depending upon future Actisense
	   product requirements. */
	ddMAXNUMPORTS = 16

} NumPorts_t;

/*************************************************************************
	NGW/NGT Port Channel number enumerations -
	used when changing device settings - defines which port is which
**************************************************************************/
/* Channel number enumerations - used when changing device settings */
#define	NG_CHAN_CAN 	        0
#define	NG_CHAN_SERIAL 	        1

/*************************************************************************
	Data structures :
**************************************************************************/

/*------------------------------------------------------------------------
	Decode Tag type :
	All returned data structures contain an sDecodeTag structure
	(Some only contain this).  This structure contains useful
	information about the device providing the information,
	along with a timestamp that can be used to age data in the
	users program
  -----------------------------------------------------------------------*/
typedef struct sDecodeTag {
	u32 ResponseTime;				/* Command response time in milliseconds -
									   can be used to test the comms channel's
									   performance. For regular messages, like
									   System Status, this becomes the time
									   between messages instead */
	u32 PCTickCount;				/* Tick count at time of decode */
	s32 Error;						/* Error code for message (Refer to ARLErrorCode.h) */
	u32 Serial;						/* Unique ARL Serial number of the unit
									   that returned this message */
	u32	ModelID;					/* ARL Model ID number (unique to each device type) */
	DecodeData_t DataType;			/* The data type this tag is attached to */
	stream_t SrcStream;				/* Source Stream that this message was received from */
	u32 SrcAddress;					/* Source Address that this message came from 	
									(0 if Source Stream set to BST / 'local') */
} sDecodeTag;

/*------------------------------------------------------------------------
sDecodeHardwareInfo	
ACommsCommand_GetHardwareInfo retuns the Hardware information.
  -----------------------------------------------------------------------*/
typedef struct sDecodeHardwareInfo {
	sDecodeTag Tag;
	u32	BootloaderSoftwareVersion;	/* Bootloader program's software version  */
	sExcelDate BootloaderDate;		/* Bootloader program's "Date of program" */
	sExcelTime BootloaderTime;		/* Bootloader program's "Time of program" */
	u32	FirmwareSoftwareVersion;	/* Main program's firmware version number */
	sExcelDate FirmwareDate;		/* Main program's firmware "Date of program" */
	sExcelTime FirmwareTime;		/* Main program's firmware "Time of program" */
	u32	HardwareVersion;			/* Main program's hardware version number */
	u32	TotalOperatingTime;			/* Total running time in seconds */
	sExcelTime TotalOperatingTimeX;	/* Total running time in Excel Time format */
	u32	ModelSubID;					/* Model Sub ID number */
	u32	ModeID;						/* Mode ID number */

} sDecodeHardwareInfo;

/*------------------------------------------------------------------------
sDecodeOperatingMode
ACommsCommand_GetOperatingMode returns a single 'Operating Mode' ID that
indicates what 'Rule set' the target is currently using to operate.

ddOperatingMode
-------------------------------------------------------------------------*/
typedef struct sDecodeOperatingMode {
	sDecodeTag Tag;
	u32	ModeID;						/* Current Operating Mode. Unique ID 
									   across all ARL models */
} sDecodeOperatingMode;

/*------------------------------------------------------------------------
sDecodePortBaudCodes	
ACommsCommand_GetPortBaudCodes returns the port Baud Codes
  -----------------------------------------------------------------------*/
#define cMaxBaudCodeSize			ddMAXNUMPORTS

typedef struct sDecodePortBaudCodes {
	sDecodeTag Tag;
	u32	NumBaudCodes;					/* Actual number of Baud codes */
	u8  HardProtocol[cMaxBaudCodeSize];	/* Hardware-Protocol enum type */
	u8  BaudCode[cMaxBaudCodeSize];		/* Baud Code enum type */

} sDecodePortBaudCodes;

/*------------------------------------------------------------------------
sDecodeArray_u8
Generic Data array structure, used as a return type where arrays of
unsigned 8-bit data are returned from a target device.

ACommsDecode_GetPortBaudCodes
ACommsDecode_GetPortPCodes
ACommsDecode_GetPortDupDelete
  -----------------------------------------------------------------------*/
#define ddMAXDATAu8_n           223
typedef struct sDecodeArray_u8 {
	sDecodeTag Tag;
	u32	nData;					/* Number of valid data members actually
                                   stored in this structure */
	u8	Data[ddMAXDATAu8_n];	/* Array where the data will be stored -
                                   only the first nData members will be valid */
} sDecodeArray_u8;

/*------------------------------------------------------------------------
sDecodeArray_u32
Generic Data array structure, used as a return type where arrays of
unsigned 32-bit data are returned from a target device.
  -----------------------------------------------------------------------*/
#define ddMAXDATAu32_n          64
typedef struct sDecodeArray_u32 {
	sDecodeTag Tag;
	u32	nData;					/* Number of valid data members actually
                                   stored in this structure */
	u32	Data[ddMAXDATAu32_n];	/* Array where the data will be stored -
                                   only the first nData members will be valid */
} sDecodeArray_u32;

/*------------------------------------------------------------------------
sDecodeTotalTime
Used for ACommsCommand_GetTotalTime returns one the total running time in
seconds of the target device
-------------------------------------------------------------------------*/
typedef struct sDecodeTotalTime {
	sDecodeTag Tag;
	u32	Valid;			        /* Validity of the time value. Can only be:
						             0 (for time invalid) or
						             1 (time is valid) */
	u32	Time;			        /* Current running time in seconds */

} sDecodeTotalTime;

/*------------------------------------------------------------------------
sProductInfoN2K

ACommsCommand_GetProductInfoN2K
ddProductInfoN2K
  -----------------------------------------------------------------------*/
#define ddMaxManStr_n           33

typedef struct sDecodeProductInfoN2K {
	sDecodeTag Tag;
	u16 Version;		/* NMEA 2000 Version supported, contains 3 d.p.
						   div by 1000 to get floating point number (x.xxx) */
	u16 ProductCode;	/* NMEA 2000 Manufacturers Product Code (0 to 65355) */
	u8  CertLevel;		/* NMEA 2000 Certification Level type (A/0 or B/1) */	
	u8 LEN;			    /* Load Equivalency (current drain in multiples of 50 mA) */
	u8 ManModelIDStr[ddMaxManStr_n]; /* Manufacturer Model ID ASCII string */
	u8 ManSoftwareVersionStr[ddMaxManStr_n]; /* Manufacturer Software version ASCII string */
	u8 ManHardwareVersionStr[ddMaxManStr_n]; /* Manufacturer Model/Hardware version ASCII string */
	u8 ManSerialCodeStr[ddMaxManStr_n]; /* Manufacturer Model serial code ASCII string */

} sDecodeProductInfoN2K;

#ifdef ACTISENSE_COMPONENTS_LIB
struct sDecodeProductInfoN2K_Main {
	sDecodeTag Tag;
	u16 Version;						  
	u16 ProductCode;	
	u8 CertLevel;			
	u8 LEN;			   
};
struct sDecodeProductInfoN2K_ModelID {
	sDecodeTag Tag;
	u8 ManModelIDStr[ddMaxManStr_n]; /* Manufacturer Model ID ASCII string */
};
struct sDecodeProductInfoN2K_SWVersion {
	sDecodeTag Tag;
	u8 ManSoftwareVersionStr[ddMaxManStr_n];
};
struct sDecodeProductInfoN2K_HWVersion {
	sDecodeTag Tag;
	u8 ManHardwareVersionStr[ddMaxManStr_n]; /* Manufacturer Model/Hardware version ASCII string */
};
struct sDecodeProductInfoN2K_SerialID{
	sDecodeTag Tag;
	u8 ManSerialCodeStr[ddMaxManStr_n]; /* Manufacturer Model serial code ASCII string */
};
enum eDecodeProductInfoN2KSequence {
	ProductInfoN2KMain = 1,
	ProductInfoN2KModelID,
	ProductInfoN2KSWVer,
	ProductInfoN2KHWVer,
	ProductInfoN2KSerial
};
#endif /*ACTISENSE_COMPONENTS_LIB*/

/*------------------------------------------------------------------------
sDecodeCanConfig
ddCANConfig
  -----------------------------------------------------------------------*/
typedef struct sDecodeCanConfig {
	sDecodeTag Tag;
	u8	PreferredAddress;		/* PreferredAddress (to claim at startup) */
	u8	CANName[8];				/* 64-bit CAN Name (used for Address Claiming) */
	u8  PreviousSrcAddress;		/* Previous Address (claimed in last session) */
	u8  CurrentSrcAddress;		/* Current Source Address (0 - 251) */
	u8  AddressClaimStatus;		/* Source Address 'Claimed' status (YES or NO) */

} sDecodeCanConfig;

/*------------------------------------------------------------------------
sDecodeCanInfoField
ddCANInfoField1
ddCANInfoField2
ddCANInfoField3
  -----------------------------------------------------------------------*/
/* Generic CAN Info field maximum string length (in characters) - this
   is the total maximum that can be returned by the device */
#define cCANInfoFieldMaxLen	    70
/* Indiviual actual available CAN Info field string lengths (in characters)
   for each info string that can be set by the user : */
#define cCANInfo1FieldMaxLen	cCANInfoFieldMaxLen
#define cCANInfo2FieldMaxLen	cCANInfoFieldMaxLen
#define cCANInfo3FieldMaxLen	38

typedef struct sDecodeCanInfoField {
	sDecodeTag Tag;
	u8	Type;                   /* Type = 0 for ASCII, = 1 For Unicode */
	u8	Size;                   /* Length of ASCII/Unicode text string in bytes */
	/* Info String - sized to fit maximum length of CAN info string, plus
       an extra two bytes, which will always be set to NULL (0) */
	u8	String[cCANInfoFieldMaxLen + 2];

} sDecodeCanInfoField;

/*------------------------------------------------------------------------
sDecodeRxPGN
ddEnableRxPGN
  -----------------------------------------------------------------------*/
typedef struct sDecodeRxPGN {
	sDecodeTag Tag;
	u32 PGN;                    /* PGN ID (0 to 131071) */
	PGNEnable_t Enable;         /* Enable (NO/0, YES/1 or Respond/2 */
	u32 Mask;                   /* PGN Mask (PGNMasks_t) (0 to 2^32) */

} sDecodeRxPGN;

/*------------------------------------------------------------------------
sDecodeTxPGN
ddEnableTxPGN
  -----------------------------------------------------------------------*/
typedef struct sDecodeTxPGN {
	sDecodeTag Tag;
	u32 PGN;                    /* PGN ID (0 to 131071) */
	PGNEnable_t Enable;         /* Enable (NO/0, YES/1 or Respond/2 */
	u32 Rate;                   /* Tx Rate */
	u32 Timeout;                /* Tx Timeout */
	u32 Priority;               /* Tx priority */

} sDecodeTxPGN;

/*------------------------------------------------------------------------
sDecodeRxPGNList
ddRxPGNEnableList
  -----------------------------------------------------------------------*/
#define ddMaxPGNListSize        55

typedef struct sDecodeRxPGNList {
	sDecodeTag Tag;
	u32 Size;
	u32 PGN[ddMaxPGNListSize];	   /* Rx PGN */
	u32 Mask[ddMaxPGNListSize];    /* Rx Mask */

} sDecodeRxPGNList;

#ifdef ACTISENSE_COMPONENTS_LIB
struct sDecodeRxPGNList_PGN
{
	sDecodeTag Tag;
	u32 Size;
	u32 PGN[ddMaxPGNListSize];	   /* Rx PGN */
};

struct sDecodeRxPGNList_Mask
{
	sDecodeTag Tag;
	u32 Size;
	u32 Mask[ddMaxPGNListSize];    /* Rx Mask */
};
enum eDecodeRxPGNListSequenceID {
	RxPGNListPGN	= 1,
	RxPGNListMask	= 2,
};
#endif /*ACTISENSE_COMPONENTS_LIB*/
/*------------------------------------------------------------------------
sDecodeTxPGNList
ddTxPGNEnableList
  -----------------------------------------------------------------------*/
typedef struct sDecodeTxPGNList {
	sDecodeTag Tag;
	u32 Size;
	u32 PGN[ddMaxPGNListSize];
	u32 Rate[ddMaxPGNListSize];     /* Tx Rate */
	u32 Timeout[ddMaxPGNListSize];	/* Tx Timeout */
	u32 Priority[ddMaxPGNListSize];	/* Tx priority */

} sDecodeTxPGNList;
#ifdef ACTISENSE_COMPONENTS_LIB
struct sDecodeTxPGNList_PGN
{
	sDecodeTag Tag;
	u32 Size;
	u32 PGN[ddMaxPGNListSize];
};
struct sDecodeTxPGNList_Rate
{
	sDecodeTag Tag;
	u32 Size;
	u32 Rate[ddMaxPGNListSize];     /* Tx Rate */
};
struct sDecodeTxPGNList_Timeout
{
	sDecodeTag Tag;
	u32 Size;
	u32 Timeout[ddMaxPGNListSize];	/* Tx Timeout */
};
struct sDecodeTxPGNList_Priority
{
	sDecodeTag Tag;
	u32 Size;
	u32 Priority[ddMaxPGNListSize];	/* Tx priority */
};
enum eDecodeTxPGNListSequenceID {
	TxPGNListPGN	= 1,
	TxPGNListRate,	
	TxPGNListTimeout,
	TxPGNListPriority,
};
#endif /*ACTISENSE_COMPONENTS_LIB*/
/*------------------------------------------------------------------------
	PGN list status structure data types :
	Returned by commands
		ACommsCommand_ActivatePGNEnableLists and
		ACommsCommand_GetParamsPGNEnableLists
	Taken as arguments by the functions
		ACommsDecode_GetActivatePGNEnableListResponse and
		ACommsDecode_GetParamsPGNEnableLists
  -----------------------------------------------------------------------*/
/* PGN Enable list status structure */
typedef struct sDecodePGNEnableListStatus {
	sDecodeTag Tag;
	u16 RealRxPGNListSize;			/* Number of Real Rx PGNs active in List */
	u16 RealRxPGNListCapacity;		/* Maximum Real Capacity of Rx List */
	u16	VirtualRxPGNListSize;		/* Number of Virtual Rx PGNs active in Rx List */
	u16	VirtualRxPGNListCapacity;	/* Maximum Virtual Capacity of Rx List */
	u16	TxPGNListSize;				/* Number of Virtual Tx PGNs active in Tx List
                                       (All Tx PGNs are virtual) */
	u16	TxPGNListCapacity;			/* Maximum Virtual Capacity of Tx List */
    u8  ListHardwareSyncStatus;     /* List->Hardware synchronisation status
                                       (YES(1), NO(0)) */
} sDecodePGNEnableListStatus;


/*------------------------------------------------------------------------
    sDecodeStartupStatus
    Startup status structure data types - this message is never
    "Requested", it is always Broadcast every time the device powers on.
------------------------------------------------------------------------*/
/* System status structure */
typedef struct sDecodeStartupStatus	{
	sDecodeTag Tag;
	u16 FirmwareVersion;		/* Firmware version (/1000 for fp number) */
	u32 ResetStatus;			/* (cause of last reset) */

} sDecodeStartupStatus;

/*------------------------------------------------------------------------
	System status structure data types :
	The main structure type is the sSystemStatus, the other structures
    are member structures of sSystemStatus
  -----------------------------------------------------------------------*/
typedef struct sDecodeIndiPercent {
	u8 RxBandwidth;
	u8 RxLoad;
	u8 RxFiltered;
	u8 RxDropped;
	u8 TxBandwidth;
	u8 TxLoad;

} sDecodeIndiPercent;

typedef struct sDecodeUniPercent {
	u8 Bandwidth;
	u8 Deleted;
	u8 BufferLoading;
	u8 PointerLoading;

} sDecodeUniPercent;

/* Maximum number of Indi and Uni Buffers that can currently be handled */
#define	APIDECODE_maxnIndi          16
#define	APIDECODE_maxnUni           8

/* System status structure */
typedef struct sDecodeSystemStatus {
	sDecodeTag Tag;
	u32 nIndi;
	sDecodeIndiPercent Indi[APIDECODE_maxnIndi];
	u32 nUni;
	sDecodeUniPercent Uni[APIDECODE_maxnUni];

} sDecodeSystemStatus;

/*------------------------------------------------------------------------
	Time Profiler Debug status structure data types :
	The main structure type is the sDbgTimeProfiler, the other structure
    is a member structure of sDbgTimeProfiler
  -----------------------------------------------------------------------*/
typedef struct sTimeProfile {
    /* Values received in Time Profile status message */
    u32 MaxDuration;
    u32 AccumDuration;
    u32 InstanceCount;
    /* Values derived from the Time Profile status message */
    float Period;
    float PercentDuration;
    float AverageDuration;

} sTimeProfile;

/* Maximum number of Time Profiles that can currently be handled */
#define	APIDECODE_maxnTProfile      8

/* Debug Time Profile status structure */
typedef struct sDbgTimeProfiler {
	sDecodeTag Tag;
	u32 nProfile;
	sTimeProfile Profile[APIDECODE_maxnTProfile];

} sDbgTimeProfiler;


/*************************************************************************
	Documentation : API Data types
**************************************************************************/

/*************************************************************************
--------------------------------------------------------------------------
--------------------------------------------------------------------------
sDecodeTag structure:
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Usage - this tag is added to all received information packets that are
decoded by the decoding API.  It adds information to discover whether the
info is valid and how old the information is.

ResponseTime (u32)
------------------
Command response time in milliseconds
Can be used to test the performance of the comms channel if needed.
This variable will not be the response time for regular messages like the
System Status messages, as these are not requested by the user, so
response time will contain the time between messages

PCTickCount (u32)
-----------------
Last time this data was received at the PC. Information data is timestamped
as it arrives in the PC to the nearest millisecond. This time stamp is
represented here as a 32-bit number. The number is based upon the PC Tick
Count, and will wrap around when the PC has been powered for 2^32 millisecs
(approx 49.7 days). This parameter is useful to see how long it has been
since the unit data was last requested.

Error (s32)
-----------
Error code for message, 0 = No error

Serial (u32)
------------
Actisense (unique) Serial Number of the unit that sent this data message.

ModelID (u32)
-------------
Actisense (unique) Model ID number - refers to the hardware model of the
connected unit.

DataType (DecodeData_t)
-----------------------
The data type this tag is attached to.

--------------------------------------------------------------------------
--------------------------------------------------------------------------
sDecodeHardwareInfo structure
Associated Decode function : ACommsDecode_GetHardwareInfo
Associated Command function: ACommsCommand_GetHardwareInfo
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Usage - This structure contains the decoded data filled into a structure
passed into the ACommsDecode_GetHardwareInfo command.
This data will be sent back as a packet from the unit in response to the
command ACommsCommand_GetHardwareInfo.

Structure members:
------------------
sDecodeTag Tag
u32	BootloaderSoftwareVersion;
sExcelDate  BootloaderDate
sExcelTime	BootloaderTime
u32	FirmwareSoftwareVersion
sExcelDate	FirmwareDate
sExcelTime	FirmwareTime
u32	HardwareVersion
u32	TotalOperatingTime
u32	ModelSubID
u32	ModeID

Extended descriptions of members:
--------------------------------

Tag (sDecodeTag)
----------------
Standard information about the data (see above).

BootloaderSoftwareVersion (u32)
-------------------------------
A 32-bit number indicating the bootloader software version.

BootloaderDate (sExcelDate)
-------------------------------
A structure containing the bootloader program date in excel format.

BootloaderTime (sExcelTime)
-------------------------------
A structure containing the bootloader program time in excel format.

FirmwareSoftwareVersion (u32)
-------------------------------
Main program's firmware version number

FirmwareDate (sExcelDate)
-------------------------------
An "sExcelDate" structure containing the Main program's firmware
"Date of program"

FirmwareTime (sExcelTime)
-------------------------------
An "sExcelTime" structure containing the main program's firmware "Time of program"

u32	HardwareVersion
-------------------------------
Main program's hardware version number

TotalOperatingTime (u32)
-------------------------------
Total running time in seconds

u32	ModelSubID
-------------------------------
Model Sub ID number - extended information about an actisense
model may be represented here where necessary.  Included for
later expansion as needed.

u32	ModeID
-------------------------------
Mode ID number - some Actisense products may have more than one mode of
operation (e.g. NDC-4 multiplexer also fucntion as an autoswitch)

This extra mode may be represented here.  Most instruments will
report zero here, as there is only one defined mode of operation,
with the product being defined solely by the "Model ID", cointained
with the data tag structure.




--------------------------------------------------------------------------
--------------------------------------------------------------------------
sDecodeSystemStatus structure
Associated Decode function : ACommsDecode_GetSystemStatus
Associated Command function: None
--------------------------------------------------------------------------
--------------------------------------------------------------------------
Usage - This structure contains the decoded data filled into a structure
passed into the ACommsDecode_GetSystemStatus command.
This data is sent back at regular (normally 1 second) intervals from the
attached device(s), when their "P" or proprietary code output is enabled.
The system status data is never requested from the target unit, so there
is no corresponding request command.

Structure members:
------------------
sDecodeTag Tag
u32	BootloaderSoftwareVersion;
sExcelDate  BootloaderDate
sExcelTime	BootloaderTime
u32	FirmwareSoftwareVersion
sExcelDate	FirmwareDate
sExcelTime	FirmwareTime
u32	HardwareVersion
u32	TotalOperatingTime
u32	ModelSubID
u32	ModeID

Extended descriptions of members:
--------------------------------

Tag (sDecodeTag)
----------------
Standard information about the data (see above).

BootloaderSoftwareVersion (u32)
-------------------------------
A 32-bit number indicating the bootloader software version.

BootloaderDate (sExcelDate)
-------------------------------
A structure containing the bootloader program date in excel format.

BootloaderTime (sExcelTime)
-------------------------------
A structure containing the bootloader program time in excel format.

FirmwareSoftwareVersion (u32)
-------------------------------
Main program's firmware version number

FirmwareDate (sExcelDate)
-------------------------------
An "sExcelDate" structure containing the Main program's firmware
"Date of program"

FirmwareTime (sExcelTime)
-------------------------------
An "sExcelTime" structure containing the main program's firmware "Time of program"

u32	HardwareVersion
-------------------------------
Main program's hardware version number

TotalOperatingTime (u32)
-------------------------------
Total running time in seconds

u32	ModelSubID
-------------------------------
Model Sub ID number - extended information about an actisense
model may be represented here where necessary.  Included for
later expansion as needed.

u32	ModeID
-------------------------------
Mode ID number - some actisense products may have more than one mode of
operation (e.g. NDC-4 multiplexer also fucntion as an autoswitch)

This extra mode may be represented here.  Most instruments will
report zero here, as there is only one defined mode of operation,
with the product being defined solely by the "Model ID", cointained
with the data tag structure.

**************************************************************************/

#endif /* __API_DECODE_DATATYPES_H */
