/*************************************************************************/
/**         Active Research Limited 2008 - ANSI C Library Header        **/
/*************************************************************************/
/*************************************************************************
 COPYRIGHT 2007-2008 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : NMEA0183_Datatypes.h

 DESCRIPTION :

 Header file for NMEA 0183 specifying C data structures and definitions
 for all NMEA 0183 based projects

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.000
 Rev Date 	 : 2008-11-11
 Rev Author  : Phil Whitehurst
 Rev Details : First library release
 -------------------------------------------------------------------------
**************************************************************************/
#ifndef __NMEA0183_DATATYPES_H
#define __NMEA0183_DATATYPES_H


/*************************************************************************
Dependent Includes :
**************************************************************************/
#include "TypeDefs.h"


/*************************************************************************
Enumerators & Defines :
**************************************************************************/

/*************************************************************************
NMEA0183_MAXLEN
---------------
Maximum length of NMEA 0183 data that can be handled by the library.
Should be a maximum of 79 characters between "$" or "!" and the terminating
<CR><LF>, or 82 in total, but some NMEA instruments are breaking this rule,
so the specification here has been set with a "safety margin".

Data originating from Actisense products will adhere strictly to the NMEA
0183 specifications.

The number here is the total characters including the NMEA start delimiter
and the "C" style NULL terminator.  The <CR> and <LF> are removed by the
input parser.
*************************************************************************/
#define NMEA0183_MAXLEN 		300


/*************************************************************************
The main data type used in actisense comms API :
defines the parts of an NMEA 0183 message, along with storage specified
to be enough to store a full-length transfer protocol packet.
Note the definition NMEA0183_MAXLEN is a full 200 bytes, so it is not
recommended to use this definition for long-term storage of NMEA 0183 data!
Use the structure sN2KMsg_p to do this.
**************************************************************************/
typedef struct sN183Msg {
	u32  Timestamp;
	u32  Size;
	char Data[NMEA0183_MAXLEN];

} sN183Msg;


/*************************************************************************
An alternative to the above specification to allow efficient long-term
storage of NMEA 0183 data - for use within a class library or with a
memory management system. The pData member should point to free memory of
at least [Capacity] u8 storage elements
**************************************************************************/
typedef struct sN183Msg_p {
	u32  Timestamp;
	u32	 Size;
	char *pData;
	u32	 Capacity;

} sN183Msg_p;


/*************************************************************************
Documentation : Data types
**************************************************************************/

/*************************************************************************

sN183Msg / sN183Msg_p Message structures
------------------------------------------------

Timestamp
---------
Data is timestamped as it arrives to the nearest millisecond.
This time stamp is represented here as a 32 bit number.
In a device, this number would be the system clock and would
reset every time the device is powered up, and will wrap around
when the device has been powered for 2^32 milliseconds (approx 49.7 days).
In PC applications, it will be the PC Tick count.
This parameter is a "don't care" when writing to a device.

Capacity
--------
a 32-bit unsigned integer indicating the maximum size in bytes
of a message that can be contained in the buffer

Size
----
a 32-bit unsigned integer indicating the size in bytes of the message
contained in the buffer pointed to by Data.

Data (sN183Msg)
-------------------
An array of unsigned bytes containing the payload of the NMEA 0183
message

pData (sN183Msg_p)
----------------------
A pointer to an array of unsigned bytes.  The user is responsible for
assigning the correct length of this array.  This array will
contain the payload of the NMEA 0183 message

**************************************************************************/

#endif /* __NMEA0183_DATATYPES_H */


