// PPIView.cpp : implementation of the CPPIView class
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
#include "PPIView.h"
#include "QZoomView.h"
#include ".\ppiview.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPPIView

CPPIView * ptr;
float v_Density = 0.6 , v_CP = 0.5;



IMPLEMENT_DYNCREATE(CPPIView, CScrollView)

BEGIN_MESSAGE_MAP(CPPIView, CScrollView)
	//{{AFX_MSG_MAP(CPPIView)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_BUTTON32771, OnButton32771)
	ON_COMMAND(ID_BUTTON32772, OnButton32772)
	ON_COMMAND(ID_BUTTON32773, OnButton32773)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_COMMAND(ID_FILE_NEW, OnReadDataSet)
	ON_COMMAND(ID_EDIT_CUT, OnRunHeuristic)
	ON_COMMAND(ID_FILE_OPEN, OnDrawGraphButton)
	ON_COMMAND(ID_EDIT_COPY, OnDrawCluster)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPPIView construction/destruction

CPPIView::CPPIView()
{
	// TODO: add construction code here
ptr = this;
once = 0;
zoomX = 100;
zoomY = 100;
startX=100;
startY =100;
scrollX = 1000;
scrollY = 700;
clusterDrawn=0;
}

CPPIView::~CPPIView()
{
}

BOOL CPPIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPPIView drawing

void CPPIView::OnDraw(CDC* pDC)
{
	CPPIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
//	dc= ptr->GetDC();

//	if(once==0)
//		DrawGraph();
//	once++;
	
}

void CPPIView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	//CSize sizeTotal;
	// TODO: calculate the total size of this view
//	sizeTotal.cx =sizeTotal.cy = 100;
//		CSize szDocument = GetTotalSize();
//	SetScrollSizes(MM_TEXT, sizeTotal);

	CSize sizeTotal(800, 1000);
	SetScrollSizes(MM_LOMETRIC, sizeTotal);

//	ReadMatrix();

//	SetZoomMode(ZoomViewZoomIn);

	
//	ZoomTo(200);
//	LPPOINT point;
//	point->x=100;
//	point->y=100;
	
	
//	ZoomIn();//;const LPPOINT pPoint = NULL);

}

/////////////////////////////////////////////////////////////////////////////
// CPPIView printing

BOOL CPPIView::OnPreparePrinting(CPrintInfo* pInfo)
{	
	
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPPIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPPIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPPIView diagnostics

#ifdef _DEBUG
void CPPIView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPPIView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CPPIDoc* CPPIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPPIDoc)));
	return (CPPIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPPIView message handlers

void CPPIView::ReadMatrix()
{

/*	CFile filePtr;
	CString m_FileName = "C:\\Matrix.txt";

	if (!filePtr.Open(m_FileName,CFile::modeRead,NULL) )
	{	 
		printf("Unable to Open file for reading.");
		exit(0);
	}

	DWORD fileLength = filePtr.GetLength();

	// when an enter is found / new line character 13 comes first followed
	// by character 10.
	char buffer[1];
	char readNumbers[6];
	int success=0,space=0,counter=0;
	float actualNumber;
	int index=0;
	int getRC=0;//rows=0,columns=0;
	bool spaceAgain=false;
	int rowsIndex=0,columnsIndex=0;
	// read the first 5 bytes from the file to determine the matrix
	// rows and columns
	while(counter!=fileLength)
	{
		success=filePtr.Read(buffer,1);
		counter++;
		if(buffer[0]==' ' || buffer[0]==13 || buffer[0]==10) 
		{
			space++; 
			if(!spaceAgain)
			{
				index=0; 
				actualNumber=atof(readNumbers);
				// clear readNumber buffer to avoid errneous conversion
				for(int i=0;i<4;i++)
					readNumbers[i]=0;
				//cout<<actualNumber<<"\n";
				if(getRC==0)
					rows=actualNumber;
				else if(getRC==1)
				{
					columns=actualNumber;
					// allocate memory to the matrix at run time.
					matrix = new float*[rows];
					for(int i=0;i<rows;i++)
						matrix[i]=new float[columns];
				
				}
				else
				{ // start collecting matrix numbers
				
					matrix[rowsIndex][columnsIndex++]=actualNumber;
					if(columnsIndex==columns)
						if(rowsIndex < rows)
							{rowsIndex++;columnsIndex=0;}

				}

				getRC++;
				spaceAgain=true;
			}// end of inner if
			
		}// end of outer if
		else
		{	if(index<6)
			{
				readNumbers[index++]=buffer[0];
				spaceAgain=false;
			}// end of if
		}// end of else

	}

// flush the buffer to display remaining data
if(index > 0)
{
			space++; index=0; 
			actualNumber=atoi(readNumbers);
			matrix[rowsIndex][columnsIndex++]=actualNumber;
			//cout<<actualNumber<<"\n";	
}

filePtr.Close();

//DrawGraph();
//MessageBox("Matrix Read.");

*/
}


void CPPIView::DrawGraph()
{
	index = 0;

	CPen blackPen(PS_SOLID,2,RGB(0,0,0));

	dc= ptr->GetDC();

	dc->Rectangle(0,0,1024,800);
	

//	dc->SelectObject(&blackPen);

	srand(time(NULL));

	int check;

	rows = tnodeCount;
	xIndex = new int[tnodeCount];
	yIndex = new int[tnodeCount];

	for(int i=0;i<tnodeCount;i++)
	{

REPEAT:	sx=rand()%750;
		sy=rand()%550;

		check=0;
		for(int j=0;j<index;j++)
		{	if(sx==xIndex[j])
				check++;
			if(sy==yIndex[j])
				check++;
		}
		if(check==2)
			goto REPEAT;

		//dc->Rectangle(sx,sy,sx+5,sy+5);
		xIndex[index] = sx;
		yIndex[index++] = sy;

	}


//CPPIDoc * doc = GetDocument();
//doc-> 
	
//	CSize szSB;
	
//	GetScrollBarSizes(szSB);
//	szSB.cx=300;
//	szSB.cy=800;
//	SetScrollSizes(MM_LOMETRIC,szSB);
//	CSize szDocument = GetTotalSize();
//	SetScrollSizes(MM_TEXT, sizeTotal);

	//CSize sizeTotal(800, 1000);
//	SetScrollSizes(MM_LOMETRIC, szDocument);

}

void CPPIView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

int sucess=0;

for(int i=0;i<tnodeCount;i++)
{
		if(point.x== xIndex[i] && point.y == yIndex[i])
		{	sucess=1;
			break;
		}
}	

if(sucess==1)
{
	CString str;
	str.Format("Node Number = %d",nodeNumbers[i]);
	MessageBox(str);
}
//node=nodeNumbers[i];

//	startX= point.x;
//	startY=point.y;

	CScrollView::OnLButtonDown(nFlags, point);
}

void CPPIView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default


	CScrollView::OnLButtonDblClk(nFlags, point);
}

void CPPIView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	//CClientDC dc(this);

	CScrollView::OnRButtonDown(nFlags, point);
}

void CPPIView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default


	CScrollView::OnRButtonDblClk(nFlags, point);
}

void CPPIView::DrawOnWindow()
{

// draw rectangles
	int sxi,syi,sxj,syj;

	dc= ptr->GetDC();
	dc->Rectangle(0,0,1024,800);


	dc->SetMapMode(MM_ANISOTROPIC);
	dc->SetWindowExt(startX,startY);
	dc->SetViewportExt(zoomX,zoomY);
	POINT point = GetScrollPosition();
	dc->SetViewportOrg(-point.x,-point.y);
	//	dc->SetViewportOrg(0,400);
	
//	CPen blackPen(PS_SOLID,1,RGB(0,0,0));
//	dc->SelectObject(&blackPen);

for(int i=0;i<tnodeCount;i++)
{
		sx=xIndex[i];
		sy=yIndex[i];
		dc->Rectangle(sx,sy,sx+5,sy+5);	
}

// now draw the edges

	for(i=0;i<tnodeCount;i++)
		for(int j=0;j<tnodeCount;j++)
		{	if(i==j)
				break;
			else if (matrix[i][j]==1)
			{	
				sxi = xIndex[i];
				syi = yIndex[i];
				sxj = xIndex[j];
				syj = yIndex[j];
				dc->MoveTo(sxi,syi);
				dc->LineTo(sxj,syj);
			}
		
		}

		
}

 void CPPIView::OnButton32771() 
{
	// TODO: Add your command handler code here
	zoomX+=5;
	zoomY= zoomX;	

	CSize s;
	scrollX+=25;
	scrollY+=25;
	s.cx=scrollX;
	s.cy=scrollY;//zoomX;MM_LOMETRIC
	SetScrollSizes(MM_TEXT,s);

	if(clusterDrawn==0)
		DrawOnWindow();
	else
		DrawClusters();
	

	
}

 void CPPIView::OnButton32772() 
{
	// TODO: Add your command handler code here
	zoomX-=5;
	zoomY=zoomX;

	CSize s;
	scrollX-=25;
	scrollY-=25;
	s.cx = scrollX;
	s.cy = scrollY;//zoomX;MM_LOMETRIC
	SetScrollSizes(MM_TEXT,s);

	if(clusterDrawn==0)
		DrawOnWindow();
	else
		DrawClusters();
}

void CPPIView::OnButton32773() 
{
	// TODO: Add your command handler code here
//	DrawGraph();

//	DrawOnWindow();	

}

void CPPIView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default

//	DrawOnWindow();	
	if(clusterDrawn==0)
		DrawOnWindow();
	else
		DrawClusters();

	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CPPIView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
//	DrawOnWindow();	
	if(clusterDrawn==0)
		DrawOnWindow();
	else
		DrawClusters();

	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CPPIView::Parser()
{

	CFile filePtr;
	DWORD counter=0;
	CString m_FileName;
//	char *m_FileName;// = "E:\\Ecoli20040104.tab";//20030105.tab";//EColi2004.tab";

	CFileDialog m_ldFile(TRUE);

	if (m_ldFile.DoModal() == IDOK)
	{
		m_FileName=m_ldFile.GetPathName();
		UpdateData(FALSE);
	}

	if (!filePtr.Open(m_FileName,CFile::modeRead,NULL) )
	{	 
		MessageBox("Unable to Open file for reading.");
		return;
	}

	DWORD fileLength = filePtr.GetLength();

	// when an enter is found / new line character 13 comes first followed
	// by character 10.
	char buffer[1];
	int state=0;
	int charNumber=0;
	char nodeName[6];
	int node,check;
	tnodeCount=0;
	// read the file char at a time in a loop
	// state machine will model the problem

	while(counter!=fileLength)
	{

		int bytesRead = filePtr.Read(buffer,1);
		counter++;

		// state4
		if(state==4)
		{	
			nodeName[charNumber++]=buffer[0];
			
			if(buffer[0]=='N')
			{
				state=0;
				nodeName[charNumber-1]='\0';
				charNumber=0;
				node = atoi(nodeName);
				int check=0;
				// check whether node is already present or not
				for(int i=0;i<tnodeCount;i++)
				{	
					if(node == nodeNumbers[i])
						check=1;
				}
				if(check==0)
					nodeNumbers[tnodeCount++] = node;

				for(i=0;i<6;i++)
					nodeName[i]='\0';


			}// end of if on buffer[0] == 'N'


			if(/*charNumber > 6 ||*/ buffer[0]=='E')
			{	state=0;
				charNumber=0;
				for(int i=0;i<6;i++)
					nodeName[i]='\0';

			}

		}// end of if on state4

		// state3
		if(state==3)
		{	if(buffer[0]==':')
			{	state=4; 
				charNumber=0;
			}
			else 
				state = 0;
		}

		// state2
		if(state==2)
		{	if(buffer[0]=='P')
				state=3;
			else 
				state = 0;
		}

		// state1
		if(state==1)
		{	if(buffer[0]=='I')
				state=2;
			else 
				state = 0;
		}

		//state0
		if(buffer[0] == 'D' && state==0)
			state=1;


	}// end of while loop on file

	CString str1;
	str1.Format("Total Nodes are = %d",(tnodeCount));
	MessageBox(str1);

	// allocate space for nodes dynamically.
	matrix = new int *[tnodeCount];
	gDashMatrix = new int *[tnodeCount];
	tempMatrix = new int *[tnodeCount];

	for(int i=0;i<tnodeCount;i++)
	{
		matrix[i] = new int [tnodeCount];
		gDashMatrix[i] = new int [tnodeCount];
		tempMatrix[i] = new int [tnodeCount];
	}

	// initialize the matrix
	for(i=0;i<tnodeCount;i++)
		for(int j=0;j<tnodeCount;j++)
		{	matrix[i][j]=0;
			gDashMatrix[i][j]=0;
			tempMatrix[i][j]=0;
		}

	// extract information about the edges
	filePtr.SeekToBegin();	
	counter=0;
	state=0;
	tedgeCount=0;
	int remNodeIndex1=-1,remNodeIndex2=-1;
	int edge=0,getNode1=0;
	char edgeName[6];
	int linksFound=0;

	while(counter!=fileLength)
	{

		int bytesRead = filePtr.Read(buffer,1);
		counter++;

	
		// state4
		if(state==4)
		{	
			// embedded state 6 for node 2 name
			if(getNode1==2)
				nodeName[charNumber++]=buffer[0];

			if(buffer[0]=='N' && getNode1==2)
			{
				nodeName[charNumber-1]='\0';
				state=0;
				getNode1=0;
				charNumber=0;
				node = atoi(nodeName);
				remNodeIndex2=0;
				for(int i=0;i<=tnodeCount;i++)
					if(nodeNumbers[i]==node)
						remNodeIndex2=i;

				for(i=0;i<6;i++)
					nodeName[i]='\0';

				matrix[remNodeIndex1][remNodeIndex2]=1;
				matrix[remNodeIndex2][remNodeIndex1]=1;
				
				remNodeIndex1=-1;
				remNodeIndex2=-1;
				linksFound++;

			}// end of if on buffer[0] == 'N'

			// embedded state 5 for node 1 name
			if(getNode1==1)
				nodeName[charNumber++]=buffer[0];

			if(buffer[0]=='N' && getNode1==1)
			{				
				nodeName[charNumber-1]='\0';
				state=0;
				getNode1=2;
				charNumber=0;
				node = atoi(nodeName);
				remNodeIndex1=0;
				for(int i=0;i<=tnodeCount;i++)
					if(nodeNumbers[i]==node)
						remNodeIndex1=i;
				
				for(i=0;i<6;i++)
					nodeName[i]='\0';

			}// end of if on buffer[0] == 'N'

			// state4
			if(state==4 && getNode1==0)
				edgeName[charNumber++]=buffer[0];
			
			if(buffer[0]=='E' && state==4 && getNode1==0)
			{
				edgeName[charNumber-1]='\0';
				state=0;
				getNode1=1;
				edge = atoi(edgeName);
				edgeNumbers[tedgeCount++] = edge;
				charNumber=0;
				for(int i=0;i<6;i++)
					edgeName[i]='\0';

			}// end of if on buffer[0] == 'E'




		}// end of if on state4

		// state3
		if(state==3)
		{	if(buffer[0]==':')
			{	state=4; 
				charNumber=0;
			}
			else 
				state = 0;
		}

		// state2
		if(state==2)
		{	if(buffer[0]=='P')
				state=3;
			else 
				state = 0;
		}

		// state1
		if(state==1)
		{	if(buffer[0]=='I')
				state=2;
			else 
				state = 0;
		}

		//state0
		if(buffer[0] == 'D' && state==0)
			state=1;


	}// end of while loop on file


	CString str;
	str.Format("Total edges are = %d",(linksFound));
	MessageBox(str);

	tedgeCount = linksFound;

}// end of function

void CPPIView::OnReadDataSet() 
{
	// TODO: Add your command handler code here
	Parser();
	
}

void CPPIView::OnRunHeuristic() 
{
	// TODO: Add your command handler code here
	//Randomly filling the Matrix
	int NbrsIndex = 0;
	int CstrNodesCounter = 0; //Total Nodes in Cluster
	
	NodeWeightStore = new int [tnodeCount];
	NodeDegree = new int [tnodeCount];
	EdgeWeightStore = new int *[tnodeCount];
//	EdgeWeightStoreTemp = new int *[tnodeCount];

	for(int i=0;i<tnodeCount;i++)
	{
		EdgeWeightStore[i] = new int [tnodeCount];
//		EdgeWeightStoreTemp[i] = new int [tnodeCount];
	}
	// initialize the arrays
	for(i=0;i<tnodeCount;i++)
	{
		NodeWeightStore[i] = 0;
		NodeDegree[i] = 0;
	}

	for (i = 0; i < tnodeCount; i++)
		for (int j = 0; j < tnodeCount; j++)
			EdgeWeightStore[i][j] = 0; // Initializing to 0	
	

	// Determining Each vertex Degree
		NodesDegree();

	// Determining Each Edge Weight
		EdgeWeights();	

	// Determining Each Vertex Weight
		NodeWeights();



	// Selecting highest weight node
		const int SZ = 500;
		int cluster[SZ];
		int clusterIndex=0;

		int HNbrNodeNo = 0;
		int HstNbr = 0;

		int hNW = NodeWeightStore[0]; //Node Weight
		int hNbrNode = 0;
		cluster[clusterIndex] = 0;

		for (i = 1;  i < tnodeCount; i++)
		{
			if(hNW < NodeWeightStore[i])
			{
				hNW = NodeWeightStore[i]; // should be gr8r then 0
				cluster[clusterIndex] = i;
			}
		}
		// else select highest node degree
		if ( hNW == 0)
		{

			hNW = NodeDegree[0]; 
			for (i = 1;  i < tnodeCount; i++)
			{
				if(hNW < NodeDegree[i])
				{	
					hNW = NodeDegree[i]; // should be gr8r then 0
					cluster[clusterIndex] = i;
				}
			}
			
			
		}// end of if
		clusterIndex++;

// put a loop over the cluster which starts from a single node and grows to form a
		// cluster.
int findNeighbours=0;
int clusterNegIndex=0;
int * clusterNeighbours;
int neighboursPriority[SZ]={0};
int * neighboursEdges;
int neighbourNode , clusNode;
int test=0;
int firstTime = 0;
float densityofCluster =0,densityofClusterTemp=0;
int edgesInCluster =0, edgesInClusterTemp=0;
int remLastClusterNegIndex=0;
// junk
int tempclusterNeighbours[SZ];

clusterNeighbours = new int [SZ];
neighboursEdges = new int [SZ];

clusterNegIndex=0;
// initialize the arrays with zero
for(int clear =0;clear<SZ;clear++)
{
	neighboursPriority[clear] =0;
	neighboursEdges[clear] =0;
}
	// start of for loop on the cluster
		for( i=0;i<clusterIndex;i++)
		{

			findNeighbours = cluster[i];

			for(int j=0;j<tnodeCount;j++)
			{
				if(matrix[findNeighbours][j]==1)
				{
					test=0;
					for(int w=0;w<clusterIndex;w++)
					{
						if(j==cluster[w])
						{	
							test=1;
							break;
						}
					}
					// if test 1 do not add the node to the cluster neighbours
					if(test==0)
					{   tempclusterNeighbours[clusterNegIndex] = j; 
						clusterNeighbours[clusterNegIndex++] = j;
						
					}
					if(clusterIndex==499)
						int noop =0;
				}// end of if

			}// end of for loop on j


		// compute the priorities of the neighbours that you have found
			
			for(int p=0;p<clusterNegIndex;p++)
			{
				neighbourNode = clusterNeighbours[p];
				neighboursPriority[p]=0;
				neighboursEdges[p]=0;
				
				for(int q=0;q<clusterIndex;q++)
				{
					clusNode = cluster[q];
					if(matrix[neighbourNode][clusNode]==1)
					{
						neighboursPriority[p]+=EdgeWeightStore[neighbourNode][clusNode];
						neighboursEdges[p]+=1;
					}// end of if

				}// end of inner for loop

			}// end of for loop on p
			//remLastClusterNegIndex = clusterNegIndex -1;
			
			// sort the neighbours based on edge weight with cluster
			clusterNeighbours=InsertionSort(neighboursEdges,clusterNegIndex,clusterNeighbours);
			clusterNeighbours=InsertionSort(neighboursPriority,clusterNegIndex,clusterNeighbours);

//			neighboursEdges=InsertionSortEdges(neighboursEdges,clusterNegIndex,clusterNeighbours);


			densityofCluster =  ( (float)edgesInCluster / (float)(clusterIndex*(float)(clusterIndex-1) /2 ) );
			int proposedClusterNode=clusterNeighbours[clusterNegIndex -1];
			int countEdges=0;
			for(int r=0;r<clusterIndex;r++)
			{
				if(matrix[proposedClusterNode][cluster[r]]==1)
					countEdges++;

			}
			
			if(countEdges==0)
				int noop =0;

			edgesInClusterTemp +=countEdges; 
			densityofClusterTemp =  ((float) edgesInClusterTemp / ((float)(clusterIndex+1)*(float)(clusterIndex) /2 ) );

			
			if(densityofClusterTemp > v_Density || firstTime ==0)
			{			
					int checkConectivity= densityofClusterTemp * (clusterIndex ); // -1+1
					if( countEdges >= checkConectivity || firstTime ==0)
					{
						float cp = ((float)edgesInClusterTemp/ (float)(densityofCluster * clusterIndex));
						if(cp >= v_CP || firstTime == 0)
						{															
							cluster[clusterIndex++] = clusterNeighbours[clusterNegIndex -1];
							firstTime = 1;							
							edgesInCluster +=countEdges;   
							densityofCluster = ((float) edgesInCluster / (float)(clusterIndex*((float)clusterIndex-1) /2 ) );							
							clusterNegIndex--; // remove the node from the neighbours which is now part of cluster
							

							if(clusterIndex == 499)
								int noop =0;
							
						
						} // end of statement


					}// end of if statement

			}
			else
			{	
				edgesInClusterTemp -=countEdges; 

			}
			
			




		}// end of outer most for loop


//		CString str;
//		str.Format("Nodes In Cluster = %d----Density of Cluster = %f------- Edges In Cluster =%d",clusterIndex,densityofCluster,edgesInCluster);
//		MessageBox(str);

//*******************************************************************//
	totalClusters=0;
	int bypass=0;
	CString str;
	int countIterations=0;

//	memcpy(gDashMatrix,matrix,sizeof(matrix));
	for(int b=0;b<tnodeCount;b++)
		for(int c=0;c<tnodeCount;c++)
			gDashMatrix[b][c]=matrix[b][c];

	for(clear=0;clear<1000;clear++)
		allClusterIndex[clear]=0;


Label:
		memcpy(tempMatrix,matrix,sizeof(matrix));

		if(clusterIndex > 1)
			for(int t=0;t<clusterIndex;t++)
				allClusters[totalClusters][allClusterIndex[totalClusters]++] = cluster[t];
		
		if(clusterIndex > 1)
		{	totalClusters++;
			
//			str.Format("Nodes In Cluster = %d----Density of Cluster = %f------- Edges In Cluster =%d",clusterIndex,densityofCluster,edgesInCluster);
//			MessageBox(str);
			countIterations = 0;

		}
		
		countIterations++;
		if(countIterations==200)
		{	bypass++; 
		//goto Escape;
		}
		
		
		for(int g=0;g<clusterIndex;g++)
		{			
			for(int h=0;h<tnodeCount;h++)
			{
				if(gDashMatrix[cluster[g]][h]==1)
				{
					// now check whether h is part of cluster or not
					// if not remove its edges
					int record=0;
					for(int u=0;u<clusterIndex;u++)
					{
						if(cluster[u]==h)
							record++;
					}
					if(record==0)
					{ // remove the edges as node not part of cluster
						gDashMatrix[cluster[g]][h]=0;
						gDashMatrix[h][cluster[g]]=0;

					}

				}
			
			}
			
		}

		clusterIndex=0;

		// Determining Each vertex Degree
		NodesDegree();
		// check whether the  highest node degree is zero or not
		hNW = NodeDegree[0]; 
		for (i = 1;  i < tnodeCount; i++)
		{
			if(hNW < NodeDegree[i])
			{	
				hNW = NodeDegree[i]; // should be gr8r then 0
			}
		}

		if(hNW!=0)
		{
			// compute the edge weights for G dash
			EdgeWeights();	
			// compute the node weights for G dash
			NodeWeights();
			
			// find the heighest node weight
			hNW = NodeWeightStore[0]; //Node Weight
			hNbrNode = 0;
			cluster[clusterIndex] = 0;

			for (i = 1;  i < tnodeCount; i++)
			{
				if(hNW < NodeWeightStore[i])
				{
					hNW = NodeWeightStore[i]; // should be gr8r then 0
					cluster[clusterIndex] = i;
				}
			}
			// else select highest node degree
			if ( hNW == 0)
			{

				hNW = NodeDegree[0]; 
				for (i = 1;  i < tnodeCount; i++)
				{
					if(hNW < NodeDegree[i])
					{	
						hNW = NodeDegree[i]; // should be gr8r then 0
						cluster[clusterIndex] = i;
					}
				}
				
				
			}// end of if
			clusterIndex++;

			// now generate the neighbours in G dash and sort them
			findNeighbours=0;
			clusterNegIndex=0;
			test=0;
			firstTime = 0;
			densityofCluster =0;densityofClusterTemp=0;
			edgesInCluster =0;edgesInClusterTemp=0;
			remLastClusterNegIndex=0;
			
			
			delete [] clusterNeighbours;
			delete [] neighboursEdges;

			clusterNeighbours = new int [SZ];
			neighboursEdges = new int [SZ];

			// initialize the arrays with zero
			for(int clear =0;clear<SZ;clear++)
			{
				neighboursPriority[clear] =0;
				neighboursEdges[clear] =0;
			}

			
			// start of for loop on the cluster first node and grow on ward
			for( i=0;i<clusterIndex;i++)
			{

				findNeighbours = cluster[i];

				for(int j=0;j<tnodeCount;j++)
				{
					if(gDashMatrix[findNeighbours][j]==1)
					{
						test=0;
						for(int w=0;w<clusterIndex;w++)
						{
							if(j==cluster[w])
							{	
								test=1;
								break;
							}
						}
						// if test 1 do not add the node to the cluster neighbours
						if(test==0)
						{   tempclusterNeighbours[clusterNegIndex] = j; 
							clusterNeighbours[clusterNegIndex++] = j;
							
						}
						if(clusterIndex==499)
							int noop =0;
					}// end of if

				}// end of for loop on j


			// compute the priorities of the neighbours that you have found
				
				for(int p=0;p<clusterNegIndex;p++)
				{
					neighbourNode = clusterNeighbours[p];
					neighboursPriority[p]=0;
					neighboursEdges[p]=0;
					
					for(int q=0;q<clusterIndex;q++)
					{
						clusNode = cluster[q];
						if(gDashMatrix[neighbourNode][clusNode]==1)
						{
							neighboursPriority[p]+=EdgeWeightStore[neighbourNode][clusNode];
							neighboursEdges[p]+=1;
						}// end of if

					}// end of inner for loop

				}// end of for loop on p
				//remLastClusterNegIndex = clusterNegIndex -1;
				
				// sort the neighbours based on edge weight with cluster
				clusterNeighbours=InsertionSort(neighboursEdges,clusterNegIndex,clusterNeighbours);
				clusterNeighbours=InsertionSort(neighboursPriority,clusterNegIndex,clusterNeighbours);
			
				densityofCluster =  ( (float)edgesInCluster / (float)(clusterIndex*(float)(clusterIndex-1) /2 ) );
				if(clusterNegIndex==0)
					break;
				int proposedClusterNode=clusterNeighbours[clusterNegIndex -1];
				int countEdges=0;
				for(int r=0;r<clusterIndex;r++)
				{
					if(gDashMatrix[proposedClusterNode][cluster[r]]==1)
						countEdges++;

				}
				
				if(countEdges==0)
					int noop =0;

				edgesInClusterTemp +=countEdges; 
				densityofClusterTemp =  ((float) edgesInClusterTemp / ((float)(clusterIndex+1)*(float)(clusterIndex) /2 ) );

				//if(countEdges!=0)
				if(densityofClusterTemp > v_Density || firstTime ==0)
				{			
						int checkConectivity= densityofClusterTemp * (clusterIndex ); // -1+1
						if( countEdges >= checkConectivity || firstTime ==0)
						{
							float cp = ((float)edgesInClusterTemp/ (float)(densityofCluster * clusterIndex));
							if(cp >= v_CP || firstTime == 0)
							{															
								cluster[clusterIndex++] = clusterNeighbours[clusterNegIndex -1];
								firstTime = 1;							
								edgesInCluster +=countEdges;   
								densityofCluster = ((float) edgesInCluster / (float)(clusterIndex*((float)clusterIndex-1) /2 ) );							
								clusterNegIndex--; // remove the node from the neighbours which is now part of cluster
								if(clusterNegIndex ==0)
									break;

								if(clusterIndex == 499)
									int noop =0;
								
							
							} // end of statement


						}// end of if statement

				}
				else
				{	
					edgesInClusterTemp -=countEdges; 

				}
				
				
			}// end of outer most for loop


//		str.Format("Nodes In Cluster = %d----Density of Cluster = %f------- Edges In Cluster =%d",clusterIndex,densityofCluster,edgesInCluster);
//		MessageBox(str);

		// now subtract the current cluster from the tempMatrix and find the 
		// neighbours in the graph again
/*		for(int g=0;g<clusterIndex;g++)
		{			
			for(int h=0;h<tnodeCount;h++)
			{
				if(tempMatrix[cluster[g]][h]==1)
				{
					// now check whether h is part of cluster or not
					// if not remove its edges
					int record=0;
					for(int u=0;u<clusterIndex;u++)
					{
						if(cluster[u]==h)
							record++;
					}
					if(record==0)
					{ // remove the edges as node not part of cluster
						tempMatrix[cluster[g]][h]=0;
						tempMatrix[h][cluster[g]]=0;

					}

				}
			
			}
			
		}

*/
// for global lookup
//***********************************************************************//

			// start of for loop on the cluster first node and grow on ward
clusterNegIndex=0;

			for( i=0;i<clusterIndex;i++)
			{

				findNeighbours = cluster[i];

				for(int j=0;j<tnodeCount;j++)
				{
					if(matrix[findNeighbours][j]==1)
					{
						test=0;
						for(int w=0;w<clusterIndex;w++)
						{
							if(j==cluster[w])
							{	
								test=1;
								break;
							}
						}
						// if test 1 do not add the node to the cluster neighbours
						if(test==0)
						{   tempclusterNeighbours[clusterNegIndex] = j; 
							clusterNeighbours[clusterNegIndex++] = j;
							
						}
						//if(clusterIndex==499)
						//	int noop =0;
					}// end of if

				}// end of for loop on j


			// compute the priorities of the neighbours that you have found
				
				for(int p=0;p<clusterNegIndex;p++)
				{
					neighbourNode = clusterNeighbours[p];
					neighboursPriority[p]=0;
					neighboursEdges[p]=0;
					
					for(int q=0;q<clusterIndex;q++)
					{
						clusNode = cluster[q];
						if(matrix[neighbourNode][clusNode]==1)
						{
							neighboursPriority[p]+=EdgeWeightStore[neighbourNode][clusNode];
							neighboursEdges[p]+=1;
						}// end of if

					}// end of inner for loop

				}// end of for loop on p
				//remLastClusterNegIndex = clusterNegIndex -1;
				
				// sort the neighbours based on edge weight with cluster
				clusterNeighbours=InsertionSort(neighboursEdges,clusterNegIndex,clusterNeighbours);
				clusterNeighbours=InsertionSort(neighboursPriority,clusterNegIndex,clusterNeighbours);
			
				densityofCluster =  ( (float)edgesInCluster / (float)(clusterIndex*(float)(clusterIndex-1) /2 ) );
				if(clusterNegIndex==0)
					goto Escape;
					//	break;
				int proposedClusterNode=clusterNeighbours[clusterNegIndex -1];
				int countEdges=0;
				for(int r=0;r<clusterIndex;r++)
				{
					if(matrix[proposedClusterNode][cluster[r]]==1)
						countEdges++;

				}
				
				if(countEdges==0)
					int noop =0;

				edgesInClusterTemp +=countEdges; 
				densityofClusterTemp =  ((float) edgesInClusterTemp / ((float)(clusterIndex+1)*(float)(clusterIndex) /2 ) );

				//if(countEdges!=0)
				if(densityofClusterTemp > v_Density)
				{			
						int checkConectivity= densityofClusterTemp * (clusterIndex ); // -1+1
						if( countEdges >= checkConectivity)
						{
							float cp = ((float)edgesInClusterTemp/ (float)(densityofCluster * clusterIndex));
							if(cp >= v_CP)
							{															
								cluster[clusterIndex++] = clusterNeighbours[clusterNegIndex -1];
								firstTime = 1;							
								edgesInCluster +=countEdges;   
								densityofCluster = ((float) edgesInCluster / (float)(clusterIndex*((float)clusterIndex-1) /2 ) );							
								clusterNegIndex--; // remove the node from the neighbours which is now part of cluster
								if(clusterNegIndex ==0)
									break;

								//if(clusterIndex == 499)
								//	int noop =0;
								
							
							} // end of statement


						}// end of if statement

				}
				else
				{	
					edgesInClusterTemp -=countEdges; 

				}

			}// end of outer most for loop
		
		}// end of if heighest node degree becomes zero it will exit
		else
			bypass++;

Escape:
if(bypass==0)
	goto Label;


		str.Format("Total Clusters = %d",totalClusters);
		MessageBox(str);



}// end of function


void CPPIView::NodesDegree() 
{
	// TODO: Add your command handler code here

	for ( int i = 0; i < tnodeCount; i++)
		NodeDegree[i] = 0;

	for ( i = 0; i < tnodeCount; i++)
	{
		for (int j = 0; j < tnodeCount; j++)
		{
			if (matrix[i][j] == 1)
				NodeDegree[i]++;
		}
		
	}

	// make the degree zero for a node which is now part of some cluster
	for(int k=0;k<tnodeCount;k++)
	{	for(i=0;i<totalClusters;i++)
		{
			for(int j=0;j<allClusterIndex[i];j++)
			{
				if(k==allClusters[i][j])
					NodeDegree[k]=0;
			}
		}
	}


}// end of function



void CPPIView::EdgeWeights() 
{
	// TODO: Add your command handler code here

	int EdgeWeightCounter;
	int StoreCounter = 0;
	int *FNode,*SNode;
	int fIndex=0,sIndex =0;
	int donot=0;

	FNode = new int [tnodeCount];
	SNode = new int [tnodeCount];

	for ( int i = 0; i < tnodeCount; i++)
		for( int j = 0; j < tnodeCount; j++)
		{
			fIndex=0;sIndex=0;
			if(matrix[i][j] == 1) // 0 and 1
			{
				donot = 0;
				EdgeWeightCounter = 0;
				for(int u=0;u<totalClusters;u++)
				{
					for(int v=0;v<allClusterIndex[u];v++)
					{
						if(i==allClusters[u][v] || j==allClusters[u][v])
							donot=1;
					}
				}
				
				if(donot==0)
				{

				
				// Storing nodes neighbours
				for ( int x = 0; x < tnodeCount; x++)
					if( x == j || x == i);
					else
					{
						if (matrix[i][x] == 1)
							FNode[fIndex++] = x; 
						if (matrix[j][x] == 1)
							SNode[sIndex++] = x; 

					}

				for ( x = 0; x < fIndex; x++)
					for ( int y = 0; y < sIndex; y++)
					{
						if ( FNode[x] == SNode[y])
						{
							EdgeWeightCounter++;
							break;
						}
					}

				} // end of if by donot

				
				// Storing each Edge's weight at its original location
				EdgeWeightStore[i][j] = EdgeWeightCounter;
				EdgeWeightStore[j][i] = EdgeWeightCounter;
				
//				EdgeWeightStoreTemp[i][j] = EdgeWeightCounter;


		
			}
		}
	

}// end of function


void CPPIView::NodeWeights() 
{
	// TODO: Add your command handler code here

	for ( int i = 0; i < tnodeCount; i++)
		for (int j = 0; j < tnodeCount; j++)
		{
			NodeWeightStore[i] += EdgeWeightStore[i][j];
			
		}
	

}// end of function


void CPPIView::OnDrawGraphButton() 
{
	// TODO: Add your command handler code here
	DrawGraph();
	DrawOnWindow();	
	
}

void CPPIView::PassData(int density)
{

}



int * CPPIView::InsertionSort(int *randomData, int m_DataLength,int * clusNeighbour)
{

int marker1=1;
int marker2=0,number,temp,set=0;

	while(marker1<m_DataLength)
	{
		if(randomData[marker1]<randomData[marker1-1])
			{ 
			  temp=randomData[marker1];
			  marker2=marker1-1;
			  set=1;
			} // end of if

		while(randomData[marker2]>temp && marker2>=0 && set==1)
			{      
			   number=clusNeighbour[marker2];
			   clusNeighbour[marker2]=clusNeighbour[marker2+1];
			   clusNeighbour[marker2+1]=number;          

			   number=randomData[marker2];
			   randomData[marker2]=randomData[marker2+1];
			   randomData[marker2+1]=number;          

			   marker2--;
			}// end of inner while
		
		set=0;
		marker1++;
	} // end of outer while



return clusNeighbour;

}// end of function

//******************* End of Insertion Sort *************************//

int * CPPIView::InsertionSortEdges(int *randomData, int m_DataLength,int * clusNeighbour)
{

int marker1=1;
int marker2=0,number,temp,set=0;

	while(marker1<m_DataLength)
	{
		if(randomData[marker1]<randomData[marker1-1])
			{ 
			  temp=randomData[marker1];
			  marker2=marker1-1;
			  set=1;
			} // end of if

		while(randomData[marker2]>temp && marker2>=0 && set==1)
			{      
			   number=randomData[marker2];
			   randomData[marker2]=randomData[marker2+1];
			   randomData[marker2+1]=number;          

			   marker2--;
			}// end of inner while
		
		set=0;
		marker1++;
	} // end of outer while



return randomData;

}// end of function


void CPPIView::GetUserInput(float density,float cp)
{

	v_Density = density;
	v_CP = cp;
	MessageBox("Density Copied to View");
}

void CPPIView::DrawClusters()
{
	srand(time(NULL));

	if(clusterDrawn==0)
	{
		for(int t=0;t<totalClusters;t++)
		{
			colorR[t]=rand()%255;			
			colorG[t]=rand()%255;			
			colorB[t]=rand()%255;			
		}
	}
	
	clusterDrawn=1;	
	
	dc = ptr->GetDC();
	dc->Rectangle(0,0,1024,800);

	
	dc->SetMapMode(MM_ANISOTROPIC);
	dc->SetWindowExt(startX,startY);
	dc->SetViewportExt(zoomX,zoomY);
	POINT point = GetScrollPosition();
	dc->SetViewportOrg(-point.x,-point.y);
//	DrawOnWindow();

				for(int u=0;u<totalClusters;u++)
				{
					CBrush paintBackground(RGB(colorR[u],colorG[u],colorB[u]));
					dc->SelectObject(&paintBackground);
					
					for(int v=0;v<allClusterIndex[u];v++)
					{
						for(int i=0;i<tnodeCount;i++)
						{
							if(i==allClusters[u][v])
							{
								sx=xIndex[i];
								sy=yIndex[i];
								dc->Rectangle(sx,sy,sx+5,sy+5);
								
							}

						}
						
					}

				}

// nullify this code if time expires for submission
int sxj,syj,sxi,syi;

				for(u=0;u<totalClusters;u++)
				{
					//
					CPen pen(PS_SOLID,1,RGB(colorR[u],colorG[u],colorB[u]));
					dc->SelectObject(&pen);
					
					for(int w=0;w<allClusterIndex[u];w++)
					{
						for(int v=0;v<allClusterIndex[u];v++)
						{
							if(matrix[allClusters[u][w]][allClusters[u][v]]==1)
							{
								sxi = xIndex[allClusters[u][w]];
								syi = yIndex[allClusters[u][w]];
								sxj = xIndex[allClusters[u][v]];
								syj = yIndex[allClusters[u][v]];
								dc->MoveTo(sxi,syi);
								dc->LineTo(sxj,syj);

							}

						}

					}
				}



}// end of file

void CPPIView::OnDrawCluster() 
{
	// TODO: Add your command handler code here
	//clusterDrawn=1;
	DrawClusters();
}
