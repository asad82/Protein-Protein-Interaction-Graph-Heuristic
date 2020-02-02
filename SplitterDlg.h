#if !defined(AFX_SPLITTERDLG_H__CD6321A1_4D62_11D9_B5E0_D31A102ADB2C__INCLUDED_)
#define AFX_SPLITTERDLG_H__CD6321A1_4D62_11D9_B5E0_D31A102ADB2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SplitterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSplitterDlg form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CSplitterDlg : public CFormView
{
protected:
	CSplitterDlg();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSplitterDlg)

// Form Data
public:
	//{{AFX_DATA(CSplitterDlg)
	enum { IDD = IDD_DIALOG1 };
	float	m_CP;
	float	m_Density;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSplitterDlg();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CSplitterDlg)
	afx_msg void OnButton1();
	afx_msg void OnDrawgraph();
	afx_msg void OnReaddata();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITTERDLG_H__CD6321A1_4D62_11D9_B5E0_D31A102ADB2C__INCLUDED_)
