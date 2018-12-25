/*************************************************************************/
/**         Active Research Limited 2008 - ANSI C Library Header        **/
/*************************************************************************/

/*************************************************************************
 COPYRIGHT 2007-2008 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : BEMProtocolEnums.h

 DESCRIPTION : Header file for all definitions common to hardware and PC
 			   programs using the BEM Protocol and all linked enumerations

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.000
 Rev Date 	 : 2008-06-04
 Rev Author  : Andy Campbell
 Rev Details : First library release
 -------------------------------------------------------------------------
**************************************************************************/

#ifndef __BEMPROTOCOL_ENUMS_H
#define __BEMPROTOCOL_ENUMS_H
/*************************************************************************
	Dependent Includes :
**************************************************************************/

/*************************************************************************
	Definitions :
**************************************************************************/

/* Message parameter flag values for when a parameter 'should not be changed'
   or 'ignored' (as a following parameter does require change) */
#define DONOT_CHANGE_U8				0xFF
#define DONOT_CHANGE_U16			0xFFFF
#define DONOT_CHANGE_U32			0xFFFFFFFF
#define DONOT_CHANGE_S8				0x7F
#define DONOT_CHANGE_S16			0x7FFF
#define DONOT_CHANGE_S32			0x7FFFFFFF

/* Message parameter flag values for when a parameter 'should be set to the
   factory default value' */
#define USE_DEFAULTS_U8				0xFE
#define USE_DEFAULTS_U16			0xFFFE
#define USE_DEFAULTS_U32			0xFFFFFFFE
#define USE_DEFAULTS_S8				0x7E
#define USE_DEFAULTS_S16			0x7FFE
#define USE_DEFAULTS_S32			0x7FFFFFFE


/* NMEA 2000/J1939 CAN Receive Mask definitions */
typedef enum PGNMask_t {
	/* For PDU1 type messages: PDU Specific = Destination Address */

	/* Match PGN and Exact Source Address Mask.
	   Mask includes the full 26 bits (ignoring 3-bit priority):
	   R, DP, PDU Format, PDU Specific and Source Address bits */
	MATCH_PGN_ADDRESS_MASK = 0x03FFFFFFUL,
	/* Match PGN Mask (allows all Source Addresses).
	   Mask includes the top 18 bits (ignoring 3-bit priority):
	   R, DP, PDU Format & PDU Specific bits. Source Address = 'do not care' */
	MATCH_PGN_MASK         = 0x03FFFF00UL,
	/* Match PDU Format Mask (allows all PDU Specifics & Source Addresses).
	   Mask includes the top 10 bits (ignoring 3-bit priority):
	   R, DP & PDU Format. PDU Specific & Source Address = 'do not care' */
	MATCH_PDU_FORMAT_MASK  = 0x03FF0000UL,
	/* Request the use of CAN Library default Mask */
	USE_DEFAULT_PGN_MASK   = USE_DEFAULTS_U32
	
} PGNMask_t;

/* Delete an entire 'PGN Enable List' ID definitions */
typedef enum PGNEnableList_t {
	/* CAN Rx 'PGN Enable List' */
	ENABLE_LIST_RX = 0,
	/* CAN Tx 'PGN Enable List' */
	ENABLE_LIST_TX = 1,
	/* Both CAN Rx and CAN Tx 'PGN Enable List' */
	ENABLE_LIST_RXTX = 2
	
} PGNEnableList_t;

/* Delete/Enable a 'PGN' ID definitions */
typedef enum PGNEnable_t {
	/* Disable a PGN */
	DISABLE_PGN = 0,
	/* Enable a PGN */
	ENABLE_PGN = 1
	
} PGNEnable_t;

/* Device specific 'Operating Mode' ID definitions */
typedef enum OperatingMode_t
{
	/* -----  All product's initialise mode, then ARLModel ID determines next mode */
	cOM_NGUndefinedMode       = 0,  /* 0 - Undefined Mode (revert to ARLModel ID) */

	/* -----  NGT-1 Operating Modes (1 to 3)  -------------------------- */
	cOM_NGTransferNormalMode  = 1,  /* 1 - Rx & Tx Transfers using BST Protocol */
	cOM_NGTransferRxAllMode   = 2,  /* 2 - Rx All & Tx Transfers using BST Protocol */
	cOM_NGTransferRawMode     = 3,  /* 3 - Raw Rx & Tx Transfers using BST Protocol */
	/* -----  NGW-1 Operating Modes (4 to 4)  -------------------------- */
	cOM_NGTranslateNormalMode = 4   /* 4 - Rx & Tx Translations 0183->2000 & 2000->0183 */

} OperatingMode_t;

#endif
