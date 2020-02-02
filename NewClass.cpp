// NewClass.cpp : implementation file
//

#include "stdafx.h"
#include "PPI.h"
#include "NewClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// NewClass

IMPLEMENT_DYNCREATE(NewClass, CScrollView)

NewClass::NewClass()
{
}

NewClass::~NewClass()
{
}


BEGIN_MESSAGE_MAP(NewClass, CScrollView)
	//{{AFX_MSG_MAP(NewClass)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// NewClass drawing

void NewClass::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void NewClass::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// NewClass diagnostics

#ifdef _DEBUG
void NewClass::AssertValid() const
{
	CScrollView::AssertValid();
}

void NewClass::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// NewClass message handlers
