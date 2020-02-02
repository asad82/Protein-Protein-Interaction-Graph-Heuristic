// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////
/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website		         : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

#if !defined(AFX_MAINFRM_H__D0681729_4D08_11D9_B5E0_8AF3938BC62C__INCLUDED_)
#define AFX_MAINFRM_H__D0681729_4D08_11D9_B5E0_8AF3938BC62C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
//CSplitterWnd SplitterWindow;
CSplitterWnd m_splitter ;
CSplitterWnd m_splitterdyn ;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnButton32771();
	afx_msg void OnButton32772();
	afx_msg void OnUpdateButton32771(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__D0681729_4D08_11D9_B5E0_8AF3938BC62C__INCLUDED_)
