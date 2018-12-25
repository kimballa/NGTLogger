#ifndef __BST_DATATYPES_H
#define __BST_DATATYPES_H

/*************************************************************************
	Dependent Includes :
**************************************************************************/
#include "TypeDefs.h"

/*************************************************************************
 COPYRIGHT 2007-2009 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : BSTDatatypes.h

 DESCRIPTION : 

 Header file for BST specifying C data structures and definitions
 for all BST based projects

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.000
 Rev Date 	 : 2008-10-14
 Rev Author  : Phil Whitehurst
 Rev Details : First library release
 -------------------------------------------------------------------------
**************************************************************************/

#define cBSTType1MaxLen     (223 + 11)

/*************************************************************************
	Data structures :
**************************************************************************/

/*------------------------------------------------------------------------
	sBSTMsg type :
	Contains BST Message details - proprietary Actisense data format
	This data format is not needed for most API users, as all BST messages
	of interest can be decoded using the set of functions in API_Decode.h
  ------------------------------------------------------------------------*/
/*
	Timestamp
	---------
	Data is timestamped as it arrives at the computer to the nearest millisecond.
	This time stamp is represented here as a 32-bit number.
	The number is taken from the windows system time, so does not represent
	the time that the sentence is received or transmitted by the gateway.
	This value will wrap around every 2^32 milliseconds (approx 49.7 days).

	ID (Refer to BSTProtocol.h)
	--
	A 32-bit number indicating the ID of the sent BST command
	Currently only lower 8-bits are valid - upper 24-bits will always be zero.
	
	Length
	------
	A 32-bit unsigned integer indicating the size in bytes of the message
	contained in the buffer pointed to by Data.
	This parameter has max value cBSTType1MaxLen, which is the maximum size
	of a BST Type 1 Protocol message.

	Data
	-----
	An array of unsigned bytes containing the payload of the BST message.
*/
typedef struct sBSTMsg {
	u32 Timestamp;
	u32 ID;
	u32	Length;
	u8	Data[cBSTType1MaxLen];

} sBSTMsg;


#endif /* __BST_DATATYPES_H */
