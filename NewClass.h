#if !defined(AFX_NEWCLASS_H__CD6321A2_4D62_11D9_B5E0_D31A102ADB2C__INCLUDED_)
#define AFX_NEWCLASS_H__CD6321A2_4D62_11D9_B5E0_D31A102ADB2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewClass.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// NewClass view

class NewClass : public CScrollView
{
protected:
	NewClass();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(NewClass)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(NewClass)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~NewClass();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(NewClass)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWCLASS_H__CD6321A2_4D62_11D9_B5E0_D31A102ADB2C__INCLUDED_)
