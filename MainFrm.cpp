// MainFrm.cpp : implementation of the CMainFrame class
//
/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website		         : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

#include "stdafx.h"
#include "PPI.h"
#include "ppiview.h"

#include "SplitterDlg.h"
#include "MainFrm.h"
#include "anotherview.h"
//#include "zoom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_BUTTON32771, OnButton32771)
	ON_COMMAND(ID_BUTTON32772, OnButton32772)
	ON_UPDATE_COMMAND_UI(ID_BUTTON32771, OnUpdateButton32771)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


//int zoomX=100,zoomY=100;

void CMainFrame::OnButton32771() 
{
	// TODO: Add your command handler code here
//	zoomX+=100;
//	zoomY=zoomX;
	
}

void CMainFrame::OnButton32772() 
{
	// TODO: Add your command handler code here
//	zoomX-=100;
//	zoomY= zoomX;
	MessageBox("hello");
}


void CMainFrame::OnUpdateButton32771(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//pCmdUI->

}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_splitter.CreateStatic ( this, 1, 2 ) ;

	m_splitterdyn.Create ( &m_splitter, 2, 1, CSize ( 1, 1 ), pContext ) ;
	m_splitter.SetColumnInfo ( 0, 800, 1 ) ;
	m_splitter.CreateView ( 0, 1, RUNTIME_CLASS ( CSplitterDlg ), CSize ( 200, 500 ), pContext ) ;

	
	return true;//rameWnd::OnCreateClient(lpcs, pContext);
}
