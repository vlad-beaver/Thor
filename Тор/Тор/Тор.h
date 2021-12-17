#pragma once
#include "CMATRIX.H"
#include "АфинПреобр3.h"
#include "АфинПреобр2.h"
#include "MyGDI.h"
#include "LIB.H"
class Тор
{
public:
	const static int NoVm=16;//число точек в поперечном (малом) круге радиуса r
	const static int NoVb=32;//число малых кругов в большом радиуса R
	const static int NoV=NoVm*NoVb;
	CRectD rs;
	CMatrix Verticles;
	void DrawEnlighted(CDC& dc,CMatrix& PView,CMatrix& PLight,CRect& RW,COLORREF col);
	Тор(void);
	Тор(int ,int );
	~Тор(void);
};

