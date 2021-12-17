#include "StdAfx.h"
#include "���.h"


void ���::DrawEnlighted(CDC& dc,CMatrix& PView,CMatrix& PLight,CRect& RW,COLORREF col){
	try{
		CPen* pn=new CPen(PS_NULL,0,RGB(0,0,0));
		dc.SelectObject(pn);
		double R=GetRValue(col),G=GetGValue(col),B=GetBValue(col);
		double Kd=1,Ks=1,I=1,Lights=0;
		//�������������� ����������� ��������� ����������� � ���������
		CMatrix ViewCart=SphereToCart(PView);
		//�������������� ����������� ��������� ��������� ����� � ���������
		CMatrix LightCart=SphereToCart(PLight);
		//������� ��������� �� ������� ��������� � ������� (���->���)
		CMatrix MV=CreateViewCoord(PView(0),PView(1),PView(2));
		//������� ��������� �� ������� � �������(���->���)
		CMatrix K=SpaceToWindow(rs,RW);
		//����� � ���
		CMatrix ViewVert(4,NoV);
		//����� � ���
		CPoint MasVert[NoV];
		for(int i=0;i<NoV;i++){
			CMatrix V=MV*Verticles.GetCol(i);	//�������� ���->���
			V(2)=1;
			CMatrix W=K*V.GetCol(0,0,2);		//�������� ���->���
			double v0=V(0),v1=V(1),v2=V(2);
			double w0=W(0),w1=W(1),w2=W(2);
			for(int j=0;j<3;j++){
				ViewVert(j,i)=W(j);
			}
			MasVert[i].x=W(0);
			MasVert[i].y=W(1);
		}
		CMatrix VE(3),R1(3),R2(3),V1(3),V2(3),VN(3);
		double sm;

		int j1=(PView(1)/180*NoVb/2);
		if(j1>=NoVb)j1=0;
		int j0=j1+NoVb/2;
		if(j0>NoVb)j0-=NoVb;
		if(PView(2)>180){
			j0+=NoVb/2;
			if(j0>=NoVb)j0-=NoVb;
			j1+=NoVb/2;
			if(j1>=NoVb)j1-=NoVb;
		}

		for(int jr=j0,jl=j0;;jr++,jl--){//����� �������� �����
			if(jr>=NoVb)
				jr=0;
			int lr=jr+1;//����� ���������� ������ �����
			if(lr>=NoVb)
				lr=0;
			int i0=(PView(2)/180*NoVm/2),i1=i0-1;
			if(i1<0)i1=NoVm-1;
			for(int i=i0;;i++){//����� ����� ������
				if(i>=NoVm)i=0;
				int k=i+1;//����� ��������� ����� ������ �����
				if(k>=NoVm)k=0;
				R1=Verticles.GetCol(i+jr*NoVm,0,2);//������� ����� �� ����� �����
				R2=Verticles.GetCol(k+jr*NoVm,0,2);//��������� ����� �� ����� �����
				VE=Verticles.GetCol(i+lr*NoVm,0,2);//����� �� ��������� ����� �����
				V1=R2-R1;V2=VE-R1;
				VN=VectorMult(V2,V1);//������ �������
				sm=ScalarMult(VN,ViewCart);
				if(sm>=0){//�������� ��������� �����
					if(ScalarMult(VN,LightCart)>=0){
						//������ ������������ ��� ������������ ������ ���������
						Lights=(double)I*Kd*cosViV2(VN,LightCart);
					}
					else Lights=0;
					//���������� ��������
					CPoint* p=new CPoint[4];
					p[0]=MasVert[k+jr*NoVm];
					p[1]=MasVert[i+jr*NoVm];
					p[2]=MasVert[i+lr*NoVm];
					p[3]=MasVert[k+lr*NoVm];
					CBrush* br=new CBrush(RGB(R*Lights,G*Lights,B*Lights));
					dc.SelectObject(br);
					dc.Polygon(p,4);
					delete br;
				}
				if(i==i1)break;
			}
			//
			if(jl>=NoVb)jl=0;
			if(jl<0)
				jl=NoVb-1;
			int ll=jl+1;//����� ���������� ������ �����
			if(ll>=NoVb)
				ll=0;
			i0=(PView(2)/180*NoVm/2);
			i1=i0-1;
			if(i1<0)i1=NoVm-1;
			for(int i=i0;;i++){//����� ����� ������
				if(i>=NoVm)i=0;
				int k=i+1;//����� ��������� ����� ������ �����
				if(k>=NoVm)k=0;
				R1=Verticles.GetCol(i+jl*NoVm,0,2);//������� ����� �� ����� �����
				R2=Verticles.GetCol(k+jl*NoVm,0,2);//��������� ����� �� ����� �����
				VE=Verticles.GetCol(i+ll*NoVm,0,2);//����� �� ��������� ����� �����
				V1=R2-R1;V2=VE-R1;
				VN=VectorMult(V2,V1);//������ �������
				sm=ScalarMult(VN,ViewCart);
				if(sm>=0){//�������� ��������� �����
					if(ScalarMult(VN,LightCart)>=0){
						//������ ������������ ��� ������������ ������ ���������
						Lights=(double)I*Kd*cosViV2(VN,LightCart);
						//������ ������������ ��� ���������� ������ ���������
					}
					else Lights=0;
					//���������� ��������
					CPoint* p=new CPoint[4];
					p[0]=MasVert[k+jl*NoVm];
					p[1]=MasVert[i+jl*NoVm];
					p[2]=MasVert[i+ll*NoVm];
					p[3]=MasVert[k+ll*NoVm];
					CBrush* br=new CBrush(RGB(R*Lights,G*Lights,B*Lights));
					dc.SelectObject(br);
					dc.Polygon(p,4);
					delete br;
				}
				if(i==i1)break;
			}
			if(jr==j1)break;
		}
		delete pn;
	}
	catch(...){

	}
}

���::���(void)
{
	Verticles.RedimMatrix(4,NoV);
	int R=60,r=20,i=0;
	//��������� ��������� ����� ���� � ����������� �� ��������
	for(double beta=-pi;beta<=pi-pi/NoVb;beta+=pi/NoVb*2){//����� �������� �����
		for(double alpha=0;alpha<pi*2-pi/NoVm;alpha+=pi/NoVm*2){//����� ����� ������
			Verticles(0,i)=(R+r*cos(alpha))*cos(beta);
			Verticles(1,i)=(R+r*cos(alpha))*sin(beta);
			Verticles(2,i)=r*sin(alpha);
			Verticles(3,i)=1;
			i++;
		}
	}
	rs=CRectD(-100,-100,100,100);
}

���::���(int R,int r)
{
	Verticles.RedimMatrix(4,NoV);
	int i=0;
	//��������� ��������� ����� ���� � ����������� �� �������� ��������
	for(double beta=-pi;beta<=pi-pi/NoVb;beta+=pi/NoVb*2){//����� �������� �����
		for(double alpha=0;alpha<pi*2-pi/NoVm;alpha+=pi/NoVm*2){//����� ����� ������
			Verticles(0,i)=(R+r*cos(alpha))*cos(beta);
			Verticles(1,i)=(R+r*cos(alpha))*sin(beta);
			Verticles(2,i)=r*sin(alpha);
			Verticles(3,i)=1;
			i++;
		}
	}
	rs=CRectD(-100,-100,100,100);
}

���::~���(void)
{
}
