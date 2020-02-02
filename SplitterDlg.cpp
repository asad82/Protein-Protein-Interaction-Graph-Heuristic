// SplitterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PPI.h"
#include "PPIView.h"
#include "SplitterDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitterDlg

IMPLEMENT_DYNCREATE(CSplitterDlg, CFormView)

CSplitterDlg::CSplitterDlg()
	: CFormView(CSplitterDlg::IDD)
{
	//{{AFX_DATA_INIT(CSplitterDlg)
	m_CP = 0.5f;
	m_Density = 0.6f;
	//}}AFX_DATA_INIT
}

CSplitterDlg::~CSplitterDlg()
{
}

void CSplitterDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSplitterDlg)
	DDX_Text(pDX, IDC_CLUSTERPROPERTY, m_CP);
	DDX_Text(pDX, IDC_DENSITY, m_Density);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSplitterDlg, CFormView)
	//{{AFX_MSG_MAP(CSplitterDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_DRAWGRAPH, OnDrawgraph)
	ON_BN_CLICKED(IDC_READDATA, OnReaddata)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitterDlg diagnostics

#ifdef _DEBUG
void CSplitterDlg::AssertValid() const
{
	CFormView::AssertValid();
}

void CSplitterDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSplitterDlg message handlers
extern CPPIView *ptr;

void CSplitterDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ptr->GetUserInput(m_Density,m_CP);
	ptr->OnRunHeuristic();
}

void CSplitterDlg::OnDrawgraph() 
{
	// TODO: Add your control notification handler code here
ptr->DrawGraph();
ptr->DrawOnWindow();	
}

void CSplitterDlg::OnReaddata() 
{
	// TODO: Add your control notification handler code here
	ptr->OnReadDataSet();	
}
