// ���_3D.h : main header file for the ���_3D application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// C���_3DApp:
// See ���_3D.cpp for the implementation of this class
//

class C���_3DApp : public CWinApp
{
public:
	C���_3DApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

public:
	DECLARE_MESSAGE_MAP()
};

extern C���_3DApp theApp;
