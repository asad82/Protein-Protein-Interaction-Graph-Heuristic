// DisplayDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PPI.h"
#include "DisplayDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DisplayDialog

IMPLEMENT_DYNCREATE(DisplayDialog, CFormView)

DisplayDialog::DisplayDialog()
	: CFormView(DisplayDialog::IDD)
{
	//{{AFX_DATA_INIT(DisplayDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

DisplayDialog::~DisplayDialog()
{
}

void DisplayDialog::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DisplayDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DisplayDialog, CFormView)
	//{{AFX_MSG_MAP(DisplayDialog)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DisplayDialog diagnostics

#ifdef _DEBUG
void DisplayDialog::AssertValid() const
{
	CFormView::AssertValid();
}

void DisplayDialog::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// DisplayDialog message handlers
