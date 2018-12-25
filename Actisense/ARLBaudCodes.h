/*************************************************************************/
/**         Active Research Limited 2008 - ANSI C Library Module        **/
/*************************************************************************/

/*************************************************************************
 COPYRIGHT 2006-2008 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : ARLBaudCodes.h

 DESCRIPTION : ARL definition for Hardware-Protocol enumeration code and
               Baud Rate enumeration codes

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.000
 Rev Date 	 : 2006-02-11
 Rev Author  : Andy Campbell & Phil Whitehurst
 Rev Details : First library release
 -------------------------------------------------------------------------
 Rev Number  : 1.001
 Rev Date 	 : 2008-04-10
 Rev Author  : Phil Whitehurst
        Split off function defs, as not need by Actisense Comms Library
        placed in secondary file ARLBaudCodesHelper.h for reference
 -------------------------------------------------------------------------
 Rev Number  : 1.010
 Rev Date 	 : 2009-11-02
 Rev Author  : Andy Campbell
        Created new constant defines (that begin with 'c') and the new
        Hardware-Protocol enumerations that are used inconjunction with
        the Baud codes to completely identify a hardware port.
 -------------------------------------------------------------------------
**************************************************************************/

#ifndef __ARL_BAUDCODES_H
#define __ARL_BAUDCODES_H
/*************************************************************************
	Dependent Includes :
**************************************************************************/
#include "Typedefs.h"


/*************************************************************************/
/*              Hardware-Protocol code definitions              */
/*************************************************************************/

/* --------------  Serial Hardware-Protocol enumerations  -------------- */
/* DO NOT CHANGE ORDER of these defines :
   Must only add additional codes to the end of section */
#define	cHP_SerialNMEA0183			0       /* 0x00 to 0x1F */
#define	cHP_SerialBST 				1

/* ----------------  CAN Hardware-Protocol enumerations  --------------- */
/* DO NOT CHANGE ORDER of these defines :
   Must only add additional codes to the end of section */
#define	cHP_CanNMEA2000	    		32      /* 0x20 to 0x3F */
#define	cHP_CanJ1939     			33

/* -------------  Ethernet Hardware-Protocol enumerations  ------------- */
/* DO NOT CHANGE ORDER of these defines :
   Must only add additional codes to the end of section */
#define	cHP_EthernetBST			    64      /* 0x40 to 0x5F */

/* Size requirements of an array encompassing these values */
#define cALL_HardProtocolSize       5


/*************************************************************************/
/*             Communication Port Baud rate code definitions             */
/*************************************************************************/

/* --------------  Serial (RS485/RS422/RS232) Baud rates  -------------- */
/* DO NOT CHANGE ORDER of these defines
   Must only add additional PC and MicroController codes to "UNDEFINED" */
/* New PC Baud rates - for all new references (codes 0 to 12) */
#define	cPC_1200Baud 				0
#define	cPC_2400Baud				1
#define	cPC_4800Baud				2
#define	cPC_9600Baud 				3
#define	cPC_19200Baud				4
#define	cPC_38400Baud 				5
#define	cPC_57600Baud				6
#define	cPC_115200Baud				7
#define	cPC_230400Baud				8
#define	cPC_460800Baud				9
#define	cPC_921600Baud				10
#define cPC_Undefined1Baud			11
#define cPC_Undefined2Baud			12
/* New Micro-Controller Baud rates - for all new refeences (codes 13 to 20) */
#define	cMC_31250Baud 				13
#define	cMC_62500Baud				14
#define	cMC_125000Baud				15
#define	cMC_250000Baud				16
#define	cMC_500000Baud				17
#define	cMC_1000000Baud 			18
#define cMC_Undefined1Baud			19
#define cMC_Undefined2Baud			20

#define cMaxSerialBaud				cMC_Undefined2Baud
/* Size requirements of an array encompassing these values */
#define cPC_SerialBaudSize			(cPC_921600Baud - cPC_1200Baud + 1)
#define cMC_SerialBaudSize			(cMC_1000000Baud - cMC_31250Baud + 1)
#define cALL_SerialBaudSize			(cMC_Undefined2Baud - cPC_1200Baud + 1)

/* Old PC Baud rates - DO NOT USE for new references */
#define	PC_1200_BAUD 				0
#define	PC_2400_BAUD				1
#define	PC_4800_BAUD				2
#define	PC_9600_BAUD 				3
#define	PC_19200_BAUD				4
#define	PC_38400_BAUD 				5
#define	PC_57600_BAUD				6
#define	PC_115200_BAUD				7
#define	PC_230400_BAUD				8
#define	PC_460800_BAUD				9
#define	PC_921600_BAUD				10
#define PC_UNDEFINED1				11
#define PC_UNDEFINED2				12
/* Old Micro-Controller Baud rates - DO NOT USE for new references */
#define	MC_31250_BAUD 				13
#define	MC_62500_BAUD				14
#define	MC_125000_BAUD				15
#define	MC_250000_BAUD				16
#define	MC_500000_BAUD				17
#define	MC_1000000_BAUD				18
#define MC_UNDEFINED1				19
#define MC_UNDEFINED2				20

#define MAX_SBAUD_CODE				MC_UNDEFINED2
/* Size requirements of an array encompassing these values */
#define PC_SBAUDCODE_LEN			(PC_921600_BAUD - PC_1200_BAUD + 1)
#define MC_SBAUDCODE_LEN			(MC_1000000_BAUD - MC_31250_BAUD + 1)
#define ALL_SBAUDCODE_LEN			(MC_UNDEFINED2 - PC_1200_BAUD + 1)
/* --------------------------------------------------------------------- */

/* ---------------  CAN Bus (J1939/NMEA 2000) Baud rates  -------------- */
/* DO NOT CHANGE ORDER of these defines
   Must only add additional codes to the end of the current list */
/* New CAN Baud codes - for all new references (codes 0 to 10) */
#define cCAN_10KBaud				0
#define cCAN_25KBaud				1
#define cCAN_50KBaud				2
#define cCAN_100KBaud				3
#define cCAN_125KBaud				4
#define cCAN_250KBaud				5
#define cCAN_500KBaud				6
#define cCAN_1MBaud			        7

#define cMaxCANBaud 				cCAN_1MBaud
/* Size requirements of an array encompassing these values */
#define cALL_CANBaudSize 			(cCAN_1MBaud - cCAN_10KBaud + 1)

/* Old CAN Baud codes - DO NOT USE for new references */
#define CAN_10000_BAUD				0
#define CAN_25000_BAUD				1
#define CAN_50000_BAUD				2
#define CAN_100000_BAUD				3
#define CAN_125000_BAUD				4
#define CAN_250000_BAUD				5
#define CAN_500000_BAUD				6
#define CAN_1000000_BAUD			7

#define MAX_CBAUD_CODE				CAN_1000000_BAUD
/* Size requirements of an array encompassing these values */
#define ALL_CBAUDCODE_LEN			(CAN_1000000_BAUD - CAN_10000_BAUD + 1)
/* --------------------------------------------------------------------- */

#endif /* __ARLBAUDCODES_H */

