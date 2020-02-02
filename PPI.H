// PPI.h : main header file for the PPI application
//

#if !defined(AFX_PPI_H__D0681725_4D08_11D9_B5E0_8AF3938BC62C__INCLUDED_)
#define AFX_PPI_H__D0681725_4D08_11D9_B5E0_8AF3938BC62C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPPIApp:
// See PPI.cpp for the implementation of this class
//

class CPPIApp : public CWinApp
{
public:
	CPPIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPPIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPPIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPI_H__D0681725_4D08_11D9_B5E0_8AF3938BC62C__INCLUDED_)
