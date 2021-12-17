// Тор_3D.h : main header file for the Тор_3D application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CТор_3DApp:
// See Тор_3D.cpp for the implementation of this class
//

class CТор_3DApp : public CWinApp
{
public:
	CТор_3DApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

public:
	DECLARE_MESSAGE_MAP()
};

extern CТор_3DApp theApp;
