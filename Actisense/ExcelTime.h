/*************************************************************************/
/**         Active Research Limited 2008 - ANSI C Library Header        **/
/*************************************************************************/

/*************************************************************************
COPYRIGHT 2007-2008 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

FILENAME	 : ExcelTime.h

DESCRIPTION : 
 
Header file handling excel time data structures

REVISIONS   :
-------------------------------------------------------------------------
Rev Number  : 1.000
Rev Date 	: 2008-06-03
Rev Author  : Phil Whitehurst
Rev Details : First library release
-------------------------------------------------------------------------
**************************************************************************/
#ifndef __EXCELTIME_H
#define __EXCELTIME_H

typedef struct sExcelDate {
	int	DateExcel;	/* Date (in EXCEL format) */
	int	Day;
	int	Month;
	int	Year;

} sExcelDate;

typedef struct sExcelTime {
	int	TimeExcel;	/* Time (in EXCEL format) */
	int	Hour;
	int	Min;
	int	Sec;

} sExcelTime;

#endif /* __EXCELTIME_H */
