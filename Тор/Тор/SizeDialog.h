#pragma once
#include "afxwin.h"
#include "resource.h"

// SizeDialog dialog

class SizeDialog : public CDialog
{
	DECLARE_DYNAMIC(SizeDialog)

public:
	SizeDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~SizeDialog();

	virtual void OnFinalRelease();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };
	int R,r;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit Redit;
	CEdit redit;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	int GetR();
	int Getr();
};
