// AnotherView.cpp : implementation file
//

#include "stdafx.h"
#include "PPI.h"
#include "AnotherView.h"
#include "SplitterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//CSplitterDlg d;
/////////////////////////////////////////////////////////////////////////////
// AnotherView

IMPLEMENT_DYNCREATE(AnotherView, CView)

AnotherView::AnotherView()
{

}

AnotherView::~AnotherView()
{
}


BEGIN_MESSAGE_MAP(AnotherView, CView)
	//{{AFX_MSG_MAP(AnotherView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AnotherView drawing

void AnotherView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// AnotherView diagnostics

#ifdef _DEBUG
void AnotherView::AssertValid() const
{
	CView::AssertValid();
}

void AnotherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// AnotherView message handlers
