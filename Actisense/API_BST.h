#ifndef __API_BST_H
#define __API_BST_H

/*************************************************************************
	Dependent Includes :
**************************************************************************/
#include "TypeDefs.h"
#include "BSTDatatypes.h"
#include "API_DLL.h"

/*************************************************************************
 COPYRIGHT 2007-2009 ACTISENSE - ACTIVE RESEARCH LTD. ALL RIGHTS RESERVED

 FILENAME	 : API_BST.h

 DESCRIPTION : Refer to Actisense Comms SDK User Manual for details

 REVISIONS   :
 -------------------------------------------------------------------------
 Rev Number  : 1.003
 Rev Date 	 : 2008-03-28
 Rev Author  : Phil Whitehurst
 Rev Details : First added to library
 -------------------------------------------------------------------------
**************************************************************************/

/*************************************************************************
API Functions :
**************************************************************************/
ACTISENSECOMMS_API int __stdcall ACommsBST_Write (int Handle, sBSTMsg *msg);
ACTISENSECOMMS_API int __stdcall ACommsBST_Read  (int Handle, sBSTMsg *msg);
ACTISENSECOMMS_API int __stdcall ACommsBST_GetRxQSize (int Handle, size_t *BufferSize);
ACTISENSECOMMS_API int __stdcall ACommsBST_FlushRx (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsBST_FlushTx (int Handle);
ACTISENSECOMMS_API int __stdcall ACommsBST_SetRxCallback (int Handle, void (__stdcall *pFunc)(void*), void*p);

#endif /* __API_BST_H */
