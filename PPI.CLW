; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPPIView
LastTemplate=CView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PPI.h"
LastPage=0

ClassCount=9
Class1=CPPIApp
Class2=CPPIDoc
Class3=CPPIView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=CSplitterDlg
Class7=NewClass
Class8=DisplayDialog
Class9=AnotherView
Resource3=IDD_DIALOG1

[CLS:CPPIApp]
Type=0
HeaderFile=PPI.h
ImplementationFile=PPI.cpp
Filter=N

[CLS:CPPIDoc]
Type=0
HeaderFile=PPIDoc.h
ImplementationFile=PPIDoc.cpp
Filter=N

[CLS:CPPIView]
Type=0
HeaderFile=PPIView.h
ImplementationFile=PPIView.cpp
Filter=C
LastObject=ID_EDIT_COPY
BaseClass=CScrollView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=PPI.cpp
ImplementationFile=PPI.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_BUTTON32771
Command10=ID_BUTTON32772
Command11=ID_BUTTON32773
Command12=ID_BUTTON32774
CommandCount=12

[DLG:IDD_DIALOG1]
Type=1
Class=CSplitterDlg
ControlCount=8
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_DENSITY,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CLUSTERPROPERTY,edit,1350631552
Control6=IDC_READDATA,button,1342242816
Control7=IDC_DRAWGRAPH,button,1342242816
Control8=IDC_STATIC,button,1342177287

[CLS:CSplitterDlg]
Type=0
HeaderFile=SplitterDlg.h
ImplementationFile=SplitterDlg.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_BUTTON1
VirtualFilter=VWC

[CLS:NewClass]
Type=0
HeaderFile=NewClass.h
ImplementationFile=NewClass.cpp
BaseClass=CScrollView
Filter=C

[CLS:DisplayDialog]
Type=0
HeaderFile=DisplayDialog.h
ImplementationFile=DisplayDialog.cpp
BaseClass=CFormView
Filter=D

[CLS:AnotherView]
Type=0
HeaderFile=AnotherView.h
ImplementationFile=AnotherView.cpp
BaseClass=CView
Filter=C

