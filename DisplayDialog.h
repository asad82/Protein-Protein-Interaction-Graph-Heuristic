#if !defined(AFX_DISPLAYDIALOG_H__9C4DB7A1_5494_4F27_83BA_94B245763ADB__INCLUDED_)
#define AFX_DISPLAYDIALOG_H__9C4DB7A1_5494_4F27_83BA_94B245763ADB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DisplayDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DisplayDialog form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class DisplayDialog : public CView
{
protected:
	DisplayDialog();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(DisplayDialog)

// Form Data// _UNKNOWN_RESOURCE_ID_
public:
	//{{AFX_DATA(DisplayDialog)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DisplayDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~DisplayDialog();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(DisplayDialog)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISPLAYDIALOG_H__9C4DB7A1_5494_4F27_83BA_94B245763ADB__INCLUDED_)
