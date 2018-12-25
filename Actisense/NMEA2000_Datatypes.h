/*************************************************************************/
/**         Active Research Limited 2009 - ANSI C Library Header        **/
/*************************************************************************/
/*************************************************************************
 COPYRIGHT 2007-2009 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : NMEA2000_Datatypes.h

 DESCRIPTION : 
 
 Header file for NMEA 2000 specifying C data structures and definitions
 for all NMEA 2000 based projects

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.000
 Rev Date 	 : 2008-10-14
 Rev Author  : Phil Whitehurst
 Rev Details : First library release
 Rev Number  : 1.023
 Rev Date 	 : 2000-02-04
 Rev Author  : Phil Whitehurst
 Rev Details : Modified length of sN2KMsg_p structure to
               incorporate the new "Capacity" member variable
 -------------------------------------------------------------------------
**************************************************************************/
#ifndef __NMEA2000_DATATYPES_H
#define __NMEA2000_DATATYPES_H


/*************************************************************************
	Dependent Includes :
**************************************************************************/
#include "TypeDefs.h"


/*************************************************************************
	Data types :
**************************************************************************/
#define N2K_MAXLEN_TP 			1785
#define N2K_MAXLEN_FP 			223
/* Re-rounded to next highest unsigned 32 bit variable size for use in 
   time efficient 32 bit algorithms */
#define N2K_MAXLEN_FP_STORE_U32	224
#define N2K_MAXLEN_SF 			8

/*************************************************************************
The main data type used in the actisense comms API : 
defines the parts of an NMEA 2000 message, along with storage specified
to be enough to store a full-length transfer protocol packet.
Note the length of the array is defined as N2K_MAXLEN_TP (a full 1785 bytes) 
so it would not be recommended to use this definition for long-term storage
of NMEA 2000 data!  Use the structure sN2KMsg_p to do this - this way,
message storage space can be made dynamic
**************************************************************************/
typedef struct sN2KMsg {
	u32 Timestamp;
	u32 PGN;
	u8	Priority;
	u8	SrcAddr;
	u8	DestAddr;
	u32	Length;
	u8	Data[N2K_MAXLEN_TP];

} sN2KMsg;

/*************************************************************************
An alternative to the above specification to allow efficient long-term 
storage of NMEA 2000 data - for use within a class library or with a 
memory management system. The pData member should point to free memory of
at least [Length] u8 storage elements.  

Note: The variable Capacity has been added to the basic structure and 
should be used to indicate the size of memory that was reserved for the 
pData store, allowing functions using this structure to keep within the 
legal memory area
**************************************************************************/
typedef struct sN2KMsg_p {
	u32 Timestamp;
	u32 PGN;
	u8	Priority;
	u8	SrcAddr;
	u8	DestAddr;
	u32	Length;
	u8*	pData;
	u32 Capacity;
	
} sN2KMsg_p;


/*************************************************************************
	Documentation : Data types
**************************************************************************/

/*************************************************************************
sN2KMsg / sN2KMsg_p Message structures
--------------------------------------

Timestamp
-----
Data is timestamped as it arrives in the gateway to the nearest millisecond.
This time stamp is represented here as a 32 bit number.
The number is reset every time the gateway is powered up, and will wrap 
around when the gateway has been powered for 2^32 milliseconds 
(approx 49.7 days). This parameter is only used when getting data from the
gateway, it is a "don't care" when writing to the gateway.

PGN
---
A 24-bit number indicating the Parameter Group Number (PGN) of the NMEA
2000® messages.  This is represented in the structure by a 32-bit
integer. The upper 8 bits will always be set to zero when messages are
read and will be ignored when messages are written. 
All valid PGNs are defined in Appendix B of the NMEA 2000® Specification.

Priority
--------
A number in the range 0-7, indicating the priority of the NMEA 2000®
message. A value of 0 indicates the highest priority, while a value of 7
indicates the lowest priority.  
The gateway has a maximum priority preset for each message, so that 
the computer requested priority can be equal to or lower than the gateway
setting for this PGN

SrcAddr 
-------
An 8-bit number indicating the address of the node sending the NMEA
2000® message. 
This parameter is only valid for received messages from the gateway.
When sending messages, the gateway must use the node address claimed by
the gateway on the NMEA 2000® network, and thus the Source address cannot
be modified.

DestAddr
--------
An 8-bit number indicating the address of the node which is the
destination of the NMEA 2000® message. A value of 255 indicates a
globally addressed message (to be received by all nodes).

Length
------
a 32-bit unsigned integer indicating the size in bytes of the message
contained in the buffer pointed to by Data. 
This parameter has max value N2K_MAXLEN_TP (1785), which is the maximum
size of a ISO Transport	Protocol message. For a fast packet message, 
the max is N2K_MAXLEN_FP (223). A single frame message max length is
N2K_MAXLEN_SF (8)

Data (sN2KMsg only)
----------------
An array of unsigned bytes containing the payload of the NMEA 2000®
message.

pData (sN2KMsg_p only )
-----------------------
A pointer to an array of unsigned bytes. The user is responsible for 
assigning the correct length of this array. This array will contain the
payload of the NMEA 2000® message

Capacity (sN2KMsg_p only)
-------------------------
The variable Capacity has been added to the basic structure and should be
used to indicate the size of memory that was reserved for the pData store,
allowing functions using this structure to keep within the legal memory 
area. Because of this, an sN2KMsg_p structure can be assigned to access
an sN2KMsg, but not the reverse (when copying the sN2KMsg variables across,
use N2K_MAXLEN_TP as the Capacity)

**************************************************************************/

#endif /* __NMEA2000_DATATYPES_H */
