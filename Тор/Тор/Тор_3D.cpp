// Тор_3D.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Тор_3D.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CТор_3DApp

BEGIN_MESSAGE_MAP(CТор_3DApp, CWinApp)
END_MESSAGE_MAP()


// CТор_3DApp construction

CТор_3DApp::CТор_3DApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CТор_3DApp object

CТор_3DApp theApp;


// CТор_3DApp initialization

BOOL CТор_3DApp::InitInstance()
{
	CWinApp::InitInstance();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// create and load the frame with its resources
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);






	// The one and only window has been initialized, so show and update it
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	// call DragAcceptFiles only if there's a suffix
	//  In an SDI app, this should occur after ProcessShellCommand
	return TRUE;
}

