#pragma once
#include "CMATRIX.H"
#include "����������3.h"
#include "����������2.h"
#include "MyGDI.h"
#include "LIB.H"
class ���
{
public:
	const static int NoVm=16;//����� ����� � ���������� (�����) ����� ������� r
	const static int NoVb=32;//����� ����� ������ � ������� ������� R
	const static int NoV=NoVm*NoVb;
	CRectD rs;
	CMatrix Verticles;
	void DrawEnlighted(CDC& dc,CMatrix& PView,CMatrix& PLight,CRect& RW,COLORREF col);
	���(void);
	���(int ,int );
	~���(void);
};

