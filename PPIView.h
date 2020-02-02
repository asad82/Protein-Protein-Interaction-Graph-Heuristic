// PPIView.h : interface of the CPPIView class
//
/////////////////////////////////////////////////////////////////////////////
/***************************************************************************
copyright            : (C) Asad Ali
email                : asad_82@yahoo.com
website		         : sites.google.com/site/asad82
***************************************************************************/
// Programmed by Asad Ali

#include "ppidoc.h"

#if !defined(AFX_PPIVIEW_H__D068172D_4D08_11D9_B5E0_8AF3938BC62C__INCLUDED_)
#define AFX_PPIVIEW_H__D068172D_4D08_11D9_B5E0_8AF3938BC62C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QZoomView.h"

class CPPIView : public CScrollView//QZoomView //CScrollView
{
public: // create from serialization only
	CPPIView();
	DECLARE_DYNCREATE(CPPIView)

// Attributes
public:
	CPPIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPPIView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPPIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
public:
	//{{AFX_MSG(CPPIView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButton32771();
	afx_msg void OnButton32772();
	afx_msg void OnButton32773();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnReadDataSet();
	afx_msg void OnRunHeuristic();
	afx_msg void OnDrawGraphButton();
	afx_msg void OnDrawCluster();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void ReadMatrix();

public:
	void DrawClusters();
	 void GetUserInput(float density,float cp);
	 void PassData(int density);
	 void NodesDegree();
	 void NodeWeights();
	 void EdgeWeights();
	 void Parser();
	 void DrawOnWindow();
	 void DrawGraph();
	 int * InsertionSort(int *data,int datalength,int * clusNeghbour);
	 int * InsertionSortEdges(int *data,int datalength,int * clusNeghbour);
	 int ** matrix;
	 int ** gDashMatrix;
	 int ** tempMatrix;
	 int rows,columns;
	 int once;
	 int index;
	 int sx,sy;	
	 int *xIndex,*yIndex;
	 CDC *dc;
	 int zoomX,zoomY;
	 int startX,startY;
	 int scrollX,scrollY;

	 int nodeNumbers[1000];
	 int tnodeCount;
	 int edgeNumbers[2000];
	 int tedgeCount ;
	 int ** EdgeWeightStore,*NodeWeightStore;
	 int * NodeDegree;
	 int allClusters[1000][500];
	 int allClusterIndex[1000];
	 int totalClusters;
	 int clusterDrawn;
	 int colorR[1000],colorB[1000],colorG[1000];
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in PPIView.cpp
inline CPPIDoc* CPPIView::GetDocument()
   { return (CPPIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPIVIEW_H__D068172D_4D08_11D9_B5E0_8AF3938BC62C__INCLUDED_)
