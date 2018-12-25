/*************************************************************************/
/**         Active Research Limited 2008 - ANSI C Library Header        **/
/*************************************************************************/

/*************************************************************************
 COPYRIGHT 2007-2008 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : ARLErrorCodes.h

 DESCRIPTION : ARL definition for enumeration of Errors Codes

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.000
 Rev Date 	 : 2007-11-09
 Rev Author  : Vlad Y Gaw
 Rev Details : First library release
 -------------------------------------------------------------------------
 Rev Number  : 1.010
 Rev Date 	 : 2008-01-09
 Rev Author  : Phil Whitehurst & Andy Campbell
 Rev Details : Tweaked groups of various error codes, and created 6 new
 			   sectors (Drivers (2), Library (6), EEPROM (7), NMEA 0183 (8)
 			   NMEA 2000 (9), BST Protocol (10))
 -------------------------------------------------------------------------
 Rev Number  : 1.020
 Rev Date 	 : 2010-01-12
 Rev Author  : Andy Campbell
 Rev Details : Changed ES2 definitions (to shorted and remove "USB" text)
 -------------------------------------------------------------------------
**************************************************************************/

#ifndef __ARL_ERRORCODES_H
#define __ARL_ERRORCODES_H
/*************************************************************************
	Dependent Includes :
**************************************************************************/


/*************************************************************************
	Definitions :
**************************************************************************/
/* Not for new designs */
#define ES_NO_ERROR 					0
#define ES_SUCCESS						0
#define ES_UNSPECIFIED 					-1
/* Use these defintions for new software designs */
//#define ES_NoError	 					0
#define ES_Success						0
#define ES_Unspecified 					-1
/* Base definition for project specific error codes */
#define ES_PRJErrorBase					-1000000

/*************************************************************************/
/*                  Error Codes Section 0 - Comms Errors                 */
/*                Low-level communication port error codes               */
/*************************************************************************/
typedef enum ARLErrorCodes_t
{
	/* Note for Actisense Comms library DLL: Use ES11 */
	ES_NoError						= 0,

	/* Catch-all for undefined comms errors */
	ES0_UNSPECIFIED_COMMS	    		=  -99,
	ES0_PORT_IN_USE,					/* -98 */
	ES0_PORT_CLOSED,					/* -97 */
	ES0_PORT_NUMBER_OUT_OF_RANGE,  		/* -96 */
	ES0_PORT_NUMBER_DOES_NOT_EXIST,		/* -95 */
	ES0_PORT_NUMBER_CANNOT_OPEN,		/* -94 */
	ES0_PORT_NO_UNDEFINED,				/* -93 */

	ES0_COMMS_QUEUE_EMPTY,				/* -92 */

	ES0_INVALID_CHECKSUM,				/* -91 */
	ES0_INVALID_CRC,					/* -90 */
	ES0_INVALID_RESPONSE,				/* -89 */
	ES0_TX_FAIL,						/* -88 */
	ES0_TIMED_OUT,						/* -87 */
	ES0_INVALID_BAUDRATE,				/* -86 */
	ES0_INVALID_CHANNEL,				/* -85 */

	ES0_CVI_ERROR,						/* -84 */
	/* Trying to use CVI instead of DLL or visa-versa */
	ES0_COMMS_ACCESS_METHOD,			/* -83 */
	/* Baud Code enumeration is invalid */
	ES0_PortBaudCodeInvalid,			/* -82 */


/*************************************************************************/
/*                  Error Codes Section 1 - File Errors                  */
/*                  Low-level file operation error codes                 */
/*************************************************************************/

	ES1_FILE_NOT_SELECTED				=  -199,
	ES1_FILE_NOT_FOUND,					/* -198 */
	ES1_FILE_LINE_OVER_LENGTH,			/* -197 */
	ES1_FILE_INVALID_BOOTLOADER, 		/* -196 */
	ES1_FILE_INVALID_OVERLAY,			/* -195 */
	ES1_FILE_INVALID_MAIN_APP,			/* -194 */
	ES1_FILE_INVALID_FORMAT,			/* -193 */
	ES1_FILE_INVALID_ADDRESS,			/* -192 */
	ES1_FILE_UNEXPECTED_EOF,			/* -191 */
	ES1_ARRAY_TO_FILE_FAIL,				/* -190 */
	ES1_FILE_TO_ARRAY_FAIL,				/* -189 */

	ES1_ADDRESS_MISMATCH,				/* -188 */
	ES1_ADDRESS_OVERLAP,				/* -187 */

	ES1_READFILE_ERROR,   				/* -186: reported by Win32 ReadFile function */
	ES1_WRITEFILE_ERROR,   				/* -185: reported by Win32 WriteFile function */
	ES1_LOCKFILE_SET,					/* -184 */

	ES1_FilenameFormatInvalid,			/* -183 */
	ES1_FileNotOpen,						/* -182 */
	

/*************************************************************************/
/*                 Error Codes Section 2 - Driver Errors                 */
/*                 Driver or external program error codes                */
/*************************************************************************/

	ES2_ExternalExeFail 				=  -299,
	ES2_ExternalModuleFail,				/* -298 */
	ES2_CVI_FunctionError,				/* -297 */

	/* Translation of ftStatus in 'FTD2XX.h' */
	ES2_D2XX_InvalidHandle,				/* -296 */
	ES2_D2XX_DeviceNotFound,			/* -295 */
	ES2_D2XX_DeviceNotOpened,			/* -294 */
	ES2_D2XX_IOError,					/* -293 */
	ES2_D2XX_InsufficentResources,		/* -292 */
	ES2_D2XX_InvalidParameter,			/* -291 */
	ES2_D2XX_InvalidBaudRate,			/* -290 */
	ES2_D2XX_NotOpenedForErase, 		/* -289 */
	ES2_D2XX_NotOpenedForWrite, 		/* -288 */
	ES2_D2XX_FailedToWriteDevice,		/* -287 */
	ES2_D2XX_EEPROMReadFailed,			/* -286 */
	ES2_D2XX_EEPROMWriteFailed,			/* -285 */
	ES2_D2XX_EEPROMEraseFailed,			/* -284 */
	ES2_D2XX_EEPROMNotPresent,			/* -283 */
	ES2_D2XX_EEPROMNotProgrammed,	 	/* -282 */
	ES2_D2XX_InvalidArguments,			/* -281 */
	ES2_D2XX_NotSupported,				/* -280 */
	ES2_D2XX_OtherError,				/* -279 */

	/* Non FTD2XX.h USB Errors */
	ES2_D2XX_PortAlreadyClosed, 		/* -278 */
	ES2_D2XX_PortAlreadyOpened,	 		/* -277 */
	ES2_D2XX_ModuleIDSettingFailed, 	/* -276 */
	ES2_D2XX_IncompatibleDriverVer,		/* -275 */
	ES2_D2XX_WillNotOpen,				/* -274 */
	ES2_D2XX_WillNotClose,		    	/* -273 */
	ES2_D2XX_DriversNotLoaded,			/* -272 */
	ES2_VCP_PortWillNotClose,	    	/* -271 */

	/* RLink error codes: redefine if needed for matching non-RLink errors */
	ES2_Rlink_NoSectorsSelected,		/* -270 */
	ES2_Rlink_CmdlineUnverified,		/* -269 */
	ES2_Rlink_CmdLineBufferOverrun,		/* -268 */
	ES2_Rlink_CmdLineEmpty,				/* -267 */
	ES2_Rlink_CmdLineInvalid,			/* -266 */
	ES2_Rlink_Timeout,					/* -265 */


/*************************************************************************/
/*                  Error Codes Section 3 - Test Errors                  */
/*                 Production device testing error codes                 */
/*************************************************************************/

	ES3_OUT_OF_LIMITS					=  -399,
	ES3_OVER_THRESHOLD,					/* -398 */
	ES3_UNDER_THRESHOLD,				/* -397 */


/*************************************************************************/
/*               Error Codes Section 4 -  Operation Errors               */
/*              Errors that occur during program operations              */
/*************************************************************************/

	ES4_INVALID_STATE					=  -499,
	ES4_INVALID_FLAG,					/* -498 */
	ES4_INVALID_COMMAND,				/* -497 */
	ES4_INVALID_DATA,					/* -496 */
	ES4_INVALID_DEVICE,					/* -495 */
	ES4_INVALID_CHANNEL,				/* -494 */

	/* Use for switch case defaults and functions inputs */
	ES4_VALUE_OUT_OF_RANGE,				/* -493 */

	ES4_UNKNOWN_HARDWARE,				/* -492 */
	ES4_NO_DEVICE_PRESENT,				/* -491 */
	ES4_DEVICE_IN_RESET,				/* -490 */
	ES4_ERASE_FAIL,						/* -489 */
	ES4_PROGRAM_FAIL,					/* -488 */
	ES4_DATA_VERIFY_FAIL,				/* -487 */
	ES4_ACCESS_DENIED,					/* -486 */

	ES4_USER_ABORT,						/* -485 */
	ES4_UNDEFINED_CODEC,				/* -484 */
	ES4_CAN_CONFIG_MISMATCH,			/* -483 */
	ES4_INVALID_SERIAL_NO,				/* -482 */

	ES4_VALUES_PRESET,					/* -481 */
	ES4_BOOTVER_STRING_MISMATCH,		/* -480 */
	ES4_SERIALID_STRING_MISMATCH,		/* -479 */


/*************************************************************************/
/*            Error Codes Section 5 - MetaTag/XML Library Errors         */
/*            Errors that occur when processing MetaTag data             */
/*************************************************************************/

	ES5_INVALID_METATAG_FLAG			=  -599,
	ES5_START_TAG_ALREADY_FOUND,		/* -598 */
	ES5_NO_END_TAG_FOUND,				/* -597 */
	ES5_END_OF_LINE_FOUND,				/* -596 */
	/* Failed to instantiate XML DOMDocument30 class */
	ES5_DOMDocument30InstantiateFail	=  -590,
	/* The DOM is not yet loaded - check class / DOM instantiation */
	ES5_DOMDocument30NotLoaded,			/* -589 */
	/* Failed to load the XML Document */
	ES5_XMLLoadFail,					/* -588 */
	/* Failed to find library reference in list */
	ES5_XMLNoLibRef,					/* -587 */
	/* Library access attempted whn not loaded */
	ES5_XMLNoLibraryLoaded,				/* -586 */
	/* Node not found - a child node search failed to find the node being searched for */
	ES5_XMLNodeNotFound,				/* -585 */
	/* XML could not be extracted in a valid form */
	ES5_XMLExtraction,					/* -584 */


/*************************************************************************/
/*                Error Codes Section 6 - Library Errors                 */
/*               Library structure interaction error codes               */
/*************************************************************************/

	ES6_LIBRARY_CRC_INVALID 			=  -699,
	ES6_LIBRARY_FORMAT_INVALID,			/* -698 */
	ES6_LIBRARY_MATCH_SEARCH_FAILED,	/* -697 */
	/* Bad alignment setting was attempted - e.g. u16 definition has been
	   aligned on an odd byte, or alignment setting of 3 was requested on
	   a memory only accepting aligmnets of 1,2 or 4 */
	ES6_LIBRARY_BADALIGN,				/* -696 */
	ES6_LIBRARY_MISSING,				/* -695 */
	ES6_LIBRARY_BADSIZE,				/* -694 */
	ES6_LIBRARY_BADINDEX,				/* -693 */
	ES6_LIBRARY_INVALIDTYPE,			/* -692 - no matching library type was found in a decoder or encoder */


/*************************************************************************/
/*                 Error Codes Section 7 - EEPROM Errors                 */
/*                 Low-level EEPROM operation error codes                */
/*************************************************************************/

	ES7_EEPROM_SECTOR_ERROR 			=  -799,
	ES7_EEPROM_INVALID_SIZE,			/* -798 */
	ES7_EEPROM_INVALID_SECTOR_NUMBER, 	/* -797 */
	ES7_EEPROM_INVALID_SECTOR_SIZE, 	/* -796 */
	ES7_EEPROM_INVALID_LOAD_ADDRESS,	/* -795 */
	ES7_EEPROM_READ_BAD,				/* -794 */
	ES7_EEPROM_WRITE_BAD,				/* -793 */
	ES7_EEPROM_INVALID_SECTOR_ADDRESS, 	/* -792 */


/*************************************************************************/
/*               Error Codes Section 8 - NMEA 0183 Errors                */
/*                   NMEA 0183 processing error codes                    */
/*************************************************************************/

	/* Catch-all for undefined NMEA 0183 errors */
	ES8_N183_Invalid 					=  -899,

	ES8_N183_SentenceFormatterNotFound,	/* -898 */
	ES8_N183_SentenceTalkerIdNotFound,	/* -897 */
	ES8_N183_SentenceFieldNotFound,		/* -896 */

	ES8_N183_SentenceMatchFailed,		/* -895 */
	ES8_N183_SentenceOverflow,			/* -894 */
	/* An empty field was found / encoded during processing (Can be interpreted as
	   information or a warning, not an error depending upon the situation) */
	ES8_N183_EmptyField,				/* -893 */
	/* No fields were found/encoded for this sentence */
	ES8_N183_EmptySentence,				/* -892 */
	/* Critical fields were missing / corrupted on decode or
	   critical data missing when encoding this sentence */
	ES8_N183_InvalidSentence,			/* -892 */

	/* An incorrect character or format was found when decoding an
	   NMEA 0183 field */
	ES8_N183_BadField,					/* -891 */
	/* A field number was used that was incorrect or non-existent for the
	   given sentence in the extraction or formatting functions */
	ES8_N183_BadFieldNum,				/* -890 */
	/* A field number was re-used that already had formatting information */
	ES8_N183_FieldExists,				/* -889 */
	/* Unit mismatch - no valid unit field exists for the field being scanned */
	ES8_N183_UnitSymbolMismatch,		/* -888 */
	/* Multi part sentence mismatch */
	ES8_N183_MultiMismatch,				/* -887 */
	/* Multi part sentence order error */
	ES8_N183_MultiSentenceOrder,		/* -886 */
	/* Multi part sentence sequential message ID order error */
	ES8_N183_MultiSeqMsgIDOrder,		/* -885 */


/*************************************************************************/
/*               Error Codes Section 9 - NMEA 2000 Errors                */
/*                   NMEA 2000 processing error codes                    */
/*************************************************************************/

	/* Catch-all for undefined NMEA 2000 errors */
	ES9_N2000_INVALID_FORMAT			=  -999,
	ES9_N2000_PGN_RES_BIT_SET,			/* -998 */

	ES9_N2000_PGN_NOT_IN_LIBRARY,		/* -997 */
	ES9_N2000_PGN_ALREADY_ENABLED,		/* -996 */
	ES9_N2000_PGN_NOT_ON_LIST,			/* -995 */
	ES9_N2000_PGN_TXRATE_BELOW_MIN,		/* -994 */
	ES9_N2000_PGN_TXRATE_ABOVE_MAX,		/* -993 */
	ES9_N2000_PGN_TIMEOUT_BELOW_MIN,	/* -992 */
	ES9_N2000_PGN_TIMEOUT_ABOVE_MAX,	/* -991 */
	ES9_N2000_PGN_ENABLE_LIST_FULL,		/* -990 */
	ES9_N2000_PGN_ENABLE_LIST_EMPTY,	/* -989 */
	ES9_N2000_PGN_TXRATE_FIXED_TO_ZERO,	/* -988 */

	ES9_N2000_INVALID_PGN_ENABLE_LIST 	=  -980,
	ES9_N2000_INVALID_PGN_MASK,			/* -979 */
	ES9_N2000_ADDRESS_CLAIM_BUSY,		/* -978 */
	
	ES9_N2K_TxObjectCapacityExceeded,	/* -977 */

	/* NMEA 2000 Encoding / Decoding errors */
	/* NMEA 2000 field could not be decoded correctly (Check library definitions) */
	ES9_N2K_FieldNotDecoded				=  -960,
	/* An attempt was made to create a PGN with too much data */
	ES9_N2K_PGNOverLength,				/* -959 */
	/* Critical fields were missing / corrupted on decode or critical data
	   missing when encoding this message */
	ES9_N2K_MessageInvalid,				/* -958 */


/*************************************************************************/
/*             Error Codes Section 10 - BST Protocol Errors              */
/*               BST & BEM Protocol processing error codes				 */
/*************************************************************************/

	ES10_BST_UNKNOWN_COMMAND_ID			=  -1099,
	ES10_BST_UNKNOWN_BEMP_ID,			/* -1098 */
	/* Use when length indicators inconsistent with packet length */
	ES10_BST_WRONG_LENGTH,				/* -1097 */

	ES10_BST_INVALID_PARAMETER_LEN,		/* -1096 */
	ES10_BST_INVALID_STRING_LEN,		/* -1095 */
	ES10_BST_INVALID_PARAMETER_VAL,		/* -1094 */
	ES10_BST_NOT_SUPPORTED,				/* -1093 */
	ES10_BST_CHANGE_NOT_SUPPORTED,		/* -1092 */
    ES10_BST_PASSKEY_INVALID,           /* -1091 */

	/* BST decoding errors */
	/* BST-BEM field could not be decoded correctly (Check library definitions) */
	ES10_BSTBEM_FieldNotDecoded			=  -1080,
	/* Critical fields were missing / corrupted on decode or critical data
	   missing when encoding this message */
	ES10_BSTBEM_MessageInvalid,			/* -1079 */
	/* BST Datatype enumeration not recognised */
	ES10_BSTBEM_DTypeEnumInvalid,		/* -1078 */
	/* BEM Error field indicates an error detected by target hardware */
	ES10_BSTBEM_TargetDetectedError,	/* -1077 */


/*************************************************************************/
/*        Error Codes Section 11 - Actisense Comms Library Errors        */
/*         Reserved for use with the Actisense Comms Library DLL         */
/*************************************************************************/

	/* Catch-all for undefined Actisense comms errors */
	ES11_UNSPECIFIED_COMMS_LIB			=  -1199,

	/* Open / Closing errors */
	/* Comms Library handle not created (using ACommsCreate),
	   and access attempted */
	ES11_COMMS_UNINITIALISED,			/* -1198 */
	ES11_INVALID_HANDLE,				/* -1197 */
	/* Too many comms objects have been opened */
	ES11_TOO_MANY_HANDLES,				/* -1196 */
	ES11_COMMS_THREAD_START_FAIL,		/* -1195 */
	/* Comms resource failed at basic Win32 call to Readfile */
	ES11_READFILE_ERROR,				/* -1194 */
	/* Comms resource failed at basic Win32 call to Writefile */
	ES11_WRITEFILE_ERROR,				/* -1193 */
	/* Comms thread failed in TX */
	ES11_TX_ERROR,						/* -1192 */
	ES11_COMMS_CANNOT_CLOSE,			/* -1191 */
	/* Trying to open a port without closing it */
	ES11_PORT_IN_USE,					/* -1190 */
	/* Port is closed - open the a physical comms port
	   first before using this resource */
	ES11_PORT_CLOSED,					/* -1189 */

	/* Configuration errors */
	ES11_COMMS_CANNOT_GET_DCB			=  -1180,
	ES11_COMMS_CANNOT_SET_DCB,			/* -1179 */
	ES11_COMMS_CANNOT_SET_TIMEOUTS,		/* -1178 */

	ES11_PORT_NUMBER_OUT_OF_RANGE,		/* -1177 */
	ES11_PORT_NUMBER_DOES_NOT_EXIST,	/* -1176 */
	ES11_PORT_NUMBER_CANNOT_OPEN,		/* -1175 */
	/* Enumerator did not work */
	ES11_PORT_ENUMERATOR_ERROR,			/* -1174 */
	/* Baud rate invalid */
	ES11_PORT_BAUDRATE_INVALID,         /* -1173 */

	/* Buffer errors */
	ES11_BUFFER_OVERFLOW				=  -1170,
	ES11_BUFFER_UNDERFLOW,				/* -1169 */
	ES11_INVALID_CHECKSUM,				/* -1168 */

	/* Command errors */
	ES11_COMMAND_BUFFER_OVERRUN			=  -1160,
	ES11_COMMAND_DATA_OUT_OF_RANGE,		/* -1159 */
	ES11_COMMAND_TIMEOUT,				/* -1158 */
	ES11_COMMAND_TRACKER,				/* -1157 */
	/* No tracker exists for this decode type - check that
	   callback was set up with the correct datatype! */
	ES11_COMMAND_UNEXPECTED_DATATYPE,	/* -1156 */
	/* Internal API error is message inilialisation has not
	   been performed before message data was added - check API code
	   error should not be seen outside API unless code not fully debugged */
	ES11_COMMAND_MESSAGE_UNINITIALISED,	/* -1155 */
	/* An invalid address was sent to the API (e.g.
	   N2K address 253 was set as the targte N2K address */
	ES11_COMMAND_INVALID_ADDRESS,		/* -1154 */
	ES11_COMMAND_INVALID_STREAM,		/* -1153 */
	/* Command in incompatible with devices ARL Model ID */
	ES11_CommandARLModelIDMismatch,  	/* -1152 */

	/* Log file errors */
	ES11_COMMSLOG_FILE_ERROR            =  -1150,
    ES11_COMMSLOG_FILENAME_NULL, 		/* -1149 */
	ES11_COMMSLOG_FILENAME_TOOLONG,     /* -1148 */
	ES11_COMMSLOG_CANNOT_OPEN,          /* -1147 */

	/* Decode errors */
	/* Data returned from remote device does not meet specified format */
	ES11_DecodeBadCommsData				=  -1140,
	/* No definition exists for this data type */
	ES11_DecodeHasNoDefinition,			/* -1139 */
	/* Device's Model ID unknown - cannot be decode correctly */
	ES11_DecodeModelIDUnknown,			/* -1138 */


/*************************************************************************/
/*          Error Codes Section 12 -  Actisense UniBuffer Errors         */
/*          Reserved for use with the Actisense UniBuffer Library        */
/*************************************************************************/

	/* Catch-all for undefined Actisense Uni-Buffer errors */
	ES12_UNSPECIFIED_UNIBUFFER			=  -1299,
	/* Cannot add to Uni-Buffer - as it's full */
	ES12_UNIBUFFER_FULL,				/* -1298 */
	/* Genernal purpose - it's full */
	ES12_UNIBUFFER_OVERRUN,				/* -1297 */


/*************************************************************************/
/*   Error Codes Section 13 -  Actisense Buffers, Pipes & Queue Errors   */
/*      Reserved for use with the Actisense Buffers, Pipes & Queues      */
/*************************************************************************/

	/* Catch-all for undefined Actisense Buffer errors */
	ES13_UNSPECIFIED_BUFFER				=  -1399,
	/* Buffer is full */
	ES13_BUFFER_FULL,					/* -1398 */
	/* Error - buffer overrun would occur if function proceeded */
	ES13_BUFFER_OVERRUN,				/* -1397 */
	/* Error - address out of range */
	ES13_BUFFER_ADDRESS_RANGE,			/* -1396 */
	/* Error - Buffer not initialised before use */
	ES13_BufferNotInitialsed,			/* -1395 */
	/* Malloc allocation operation failed */
	ES13_MallocAllocationFailed,		/* -1394 */
	/* Malloc capacity has been exceeded */
	ES13_MallocAllocationOverrun,		/* -1393 */
	/* More memory has been freed that was allocated */
	ES13_MallocAllocationUnderrun,		/* -1392 */


/*************************************************************************/
/*            Error Codes Section 14 -  Actisense BITE Errors            */
/*     Errors detected by the device Built-In Test Equipment (BITE)      */
/*************************************************************************/

	/* Catch-all for undefined Actisense BITE errors */
	ES14_UNSPECIFIED_BITEERROR			=  -1499,
	/* EEPROM Sector error detected */
	ES14_EEPROM_SECTOR_ERROR,			/* -1498 */
	/* EEPROM Sector warning detected */
	ES14_EEPROM_SECTOR_WARNING,			/* -1497 */
	/* ARL Model ID error detected */
	ES14_ARLModelIDInvalid,   			/* -1496 */
	/* Malloc / Free operation error detected */
	ES14_MallocFreeOperatingError,  	/* -1495 */


/*************************************************************************/
/*            Error Codes Section 15 -  Actisense Maths Errors           */
/*            Errors detected in internal numerical algorithms           */
/*************************************************************************/

	/* Catch-all for undefined Actisense Maths errors */
	ES15_UNSPECIFIED_MATHSERROR			=  -1599,
	/* A variable has overflowed */
	ES15_MATHS_OVERFLOW,				/* -1598 */


/*************************************************************************/
/*        Error Codes Section 16 -  Actisense Flash Program Errors       */
/*           Errors detected during Flash Programming operations         */
/*************************************************************************/

	/* Catch-all for undefined Actisense Flash Program errors */
	ES16_FlashProgramError	 			=  -1699,

	ES16_FlashSectorIDInvalid,		 	/* -1698 */
	ES16_FlashSectorIDNotSet,			/* -1697 */
	ES16_FlashSectorIDMatchFailed,		/* -1696 */
	ES16_FlashSectorCRCFailed,		 	/* -1695 */
	ES16_FlashSectorTooSmall,		 	/* -1694 */

	ES16_FlashEraseSectorInvalid,		/* -1693 */
	ES16_FlashEraseBad,					/* -1692 */

	ES16_FlashWriteSectorInvalid,		/* -1691 */
	ES16_FlashWriteBad,					/* -1690 */
	ES16_FlashWriteBlockSizeInvalid,	/* -1689 */
	ES16_FlashWriteDatabaseInvalid,		/* -1688 */
	ES16_FlashWriteAddressInvalid,		/* -1687 */

	ES16_FlashFinaliseSectorInvalid,	/* -1686 */
	ES16_FlashFinaliseCRCMismatch,		/* -1685 */

	ES16_FlashReadSectorInvalid,		/* -1684 */
	ES16_FlashReadBad,					/* -1683 */

	ES16_FlashMaxBlockSizeInvalid,		/* -1682 */
	ES16_FlashCodecIDInvalid,			/* -1681 */
	ES16_FlashTimeoutOccurred,			/* -1680 */
	ES16_FlashSetUserCallbackFailed,	/* -1679 */
	ES16_FlashStateInvalid,				/* -1678 */
	ES16_FlashDatabaseTooSmall,			/* -1677 */


/*************************************************************************/
/*         Error Codes Section 17 -  Actisense Repository Errors         */
/*              Errors detected during Repository operations             */
/*************************************************************************/

	/* Catch-all for undefined Repository errors */
	ES17_ReposError 					=  -1799,
	ES17_ReposDTInvalid,			 	/* -1798 */
	ES17_ReposNotFound,				 	/* -1797 */
	/* The modifier instance did not match with the field instance found -
	   not an error, just for information */
	ES17_ReposModifierMismatch,		 	/* -1796 */
	/* Value out of range */
	ES17_ReposValueRange,			 	/* -1795 */
	/* Source priority too low - value exists which has
	   priority over incoming data - repository cannot be opened
	   for this source */
	ES17_ReposSrcPriorityLow,			/* -1794 */
	/* Returned for Source IDs of 255 - timestamp is not tracked for this src id */
	ES17_ReposTimestampInvalid,		 	/* -1793 */
	/* Index Out of range */
	ES17_ReposDTIndexOutOfRange,	 	/* -1792 */


/*************************************************************************/
/*              Error Codes Section 18 - DLL Handling Errors             */
/*              Errors detected during DLL loading/importing             */
/*************************************************************************/

	ES18_DLLNotFound 					=  -1899,
	ES18_DLLInvalidExport,				/* -1898 */
	ES18_DLLNotCreated,					/* -1897 */
	ES18_DLLNotLoaded,					/* -1896 */


/*************************************************************************/
/*          Error Codes Section 19 - Pointers allocation memory          */
/*              Errors detected during allocation of memory              */
/*************************************************************************/

	ES19_Error 							=  -1999,
	ES19_NullPointer,					/* -1998 */
	ES19_BadPointer,					/* -1997 */

/*************************************************************************/
/*          Error Codes Section 20 - Actisense Production Database       */
/*************************************************************************/

	
	ES20_PartNotFound 				    = -2099,
	ES20_ModelMismatch,				   /* -2098 */
	ES20_SubmodelMismatch,			   /* -2097 */ 
	ES20_SerialNumberNotFound,		   /* -2096 */ 
	ES20_SerialNumberAlreadyAllocated, /* -2095 */ 
	ES20_DeviceNotLocked, 			   /* -2094 */
	ES20_DeviceNotAllocated, 		   /* -2093 */
	ES20_LockedDeviceLeft, 			   /* -2092 */
	ES20_ModelNotCompatible,		   /* -2091 */ 
	ES20_OperatorNotFound,			   /* -2090 */ 
	ES20_ProfileNotFound,			   /* -2089 */ 
	ES20_PartCodeNotFound,			   /* -2088 */ 
	ES20_InvalidRange,				   /* -2087 */ 
	ES20_DatabaseError				   /* -2086 catch all unidentified error from database */

} ARLErrorCodes_t;

#endif /* __ARL_ERRORCODES_H */
