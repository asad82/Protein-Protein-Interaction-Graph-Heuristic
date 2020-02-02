// PPIDoc.h : interface of the CPPIDoc class
//
/////////////////////////////////////////////////////////////////////////////
/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website		         : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

#if !defined(AFX_PPIDOC_H__D068172B_4D08_11D9_B5E0_8AF3938BC62C__INCLUDED_)
#define AFX_PPIDOC_H__D068172B_4D08_11D9_B5E0_8AF3938BC62C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPPIDoc : public CDocument
{
protected: // create from serialization only
	CPPIDoc();
	DECLARE_DYNCREATE(CPPIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPPIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPPIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPPIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPIDOC_H__D068172B_4D08_11D9_B5E0_8AF3938BC62C__INCLUDED_)
