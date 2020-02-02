#if !defined(AFX_ANOTHERVIEW_H__494626A6_8F68_46C8_B7DE_AA137787A65C__INCLUDED_)
#define AFX_ANOTHERVIEW_H__494626A6_8F68_46C8_B7DE_AA137787A65C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnotherView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AnotherView view

class AnotherView : public CView
{
protected:
	AnotherView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(AnotherView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AnotherView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~AnotherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(AnotherView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANOTHERVIEW_H__494626A6_8F68_46C8_B7DE_AA137787A65C__INCLUDED_)
