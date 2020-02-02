// PPIDoc.cpp : implementation of the CPPIDoc class
//
/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website		         : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

#include "stdafx.h"
#include "PPI.h"

#include "PPIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPPIDoc

IMPLEMENT_DYNCREATE(CPPIDoc, CDocument)

BEGIN_MESSAGE_MAP(CPPIDoc, CDocument)
	//{{AFX_MSG_MAP(CPPIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPPIDoc construction/destruction

CPPIDoc::CPPIDoc()
{
	// TODO: add one-time construction code here

}

CPPIDoc::~CPPIDoc()
{
}

BOOL CPPIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPPIDoc serialization

void CPPIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPPIDoc diagnostics

#ifdef _DEBUG
void CPPIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPPIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPPIDoc commands
