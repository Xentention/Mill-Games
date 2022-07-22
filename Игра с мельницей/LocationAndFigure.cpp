/**************************************************************************
*                                ��4 ���                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ��4. ���. ��������. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : LocationAndFigure.cpp	                                  *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : �.�.���������, �3�-211�-20		                      *
* Modified By   :														  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : ������ ������� Location � Point			              *
*																		  *
**************************************************************************/

#include "Utilities.h"   //������������ ���� � ���������������� ������������
#include "LocationAndFigure.h"

extern HDC hdc;     //�������  �������� ����������

//��������� ��������������� ��� Hide() �������
void HideSky(int X, int Y, int Width, int Height);
void HideLighttoDarkSky(int X, int Y, int Width, int Height);
void HideCrops(int X, int Y, int Width, int Height);

/*----------------------------------------*/
/*        ������ ������ Location          */
/*----------------------------------------*/

//------------------------------------------------
//�����������
Location::Location(int InitX, int InitY) {
	X = InitX;
	Y = InitY;

};	//end Location::Location()

//------------------------------------------------
 //�������� X ���������� �����
int Location::GetX() {	return X;	};	

//------------------------------------------------
 //�������� Y ���������� �����
int Location::GetY() {	return Y;	};

//------------------------------------------------
//���������� X ���������� �����
void Location::SetX(int NewX) { X = NewX; };

//------------------------------------------------
//���������� Y ���������� �����
void Location::SetY(int NewY) { Y = NewY; };

/*----------------------------------------*/
/*        ������ ������ Figure             */
/*----------------------------------------*/

 //--------------------------------------------------------------
//�����������
Figure::Figure(int InitX, int InitY) : Location(InitX, InitY) {
	Visible = false;
}	//end Figure::Figure()

 //--------------------------------------------------------------
//������ ������
void Figure::Hide() {
	if (!Visible) return;

	Visible = false;					//������ �� �����
	int Height = ReturnMaxHeight();		//������ ������ ������
	int Width = ReturnMaxWidth();		//������ ������ ������

	if (WheatLevel > GetY() - Height)				//���� ������ ���� ���������
		HideSky(GetX(), GetY(), Width, Height);		//����������� ����

	if (WheatLevel <= GetY() + Height)				//���� ������ ���� ���������
		HideCrops(GetX(), GetY(), Width, Height);	//����������� ����

}	//end Figure::Hide()

//--------------------------------------------------------------
//����������� ������
void Figure::MoveTo(int NewX, int NewY)	{
	Hide();		//������� ������ ���������
	SetX(NewX);	//�������� �� ����������
	SetY(NewY);
	Show();		//�������� ������ �� ����� �����

}	//end Figure::MoveTo()

/*------------------------------------*/
/* ��������������� ������� ��� Hide() */
/*------------------------------------*/

//--------------------------------------------------------------
//��������� ����
void HideSky(int X, int Y, int Width, int Height) {
	HBRUSH brush = CreateSolidBrush(SkyColor);		//����� ����� ����
	HPEN pen = CreatePen(PS_SOLID, 1, SkyColor);	//����� ����� ����
	SelectObject(hdc, brush);	//�������� �������� �����
	SelectObject(hdc, pen);		//�������� �������� �����

	//����������� ������
	Rectangle(hdc, X - Width, Y - Height, X + Width, Y + Height);
	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

	HideLighttoDarkSky(X, Y, Width, Height);	//����������� ������� ����� ����

}	//end HideSky()

//--------------------------------------------------------------
//��������� ������� ����
void HideLighttoDarkSky(int X, int Y, int Width, int Height) {
	HBRUSH brush = CreateSolidBrush(LightSkyColor);		//����� ����� �������� ����
	HPEN pen = CreatePen(PS_SOLID, 1, LightSkyColor);	//����� ����� �������� ����
	SelectObject(hdc, brush);	//�������� �������� �����
	SelectObject(hdc, pen);		//�������� �������� �����

	//����������� ������� ����
	if (LightSkyLevel <= Y + Height)
		Rectangle(hdc, X - Width, LightSkyLevel, X + Width, Y + Height);

	//��������� �������� �� ����
	if (LightSkyLevel > Y - Height) {
		Rectangle(hdc, X - Width, LightSkyLevel - 3, X + Width, LightSkyLevel - 15);
		Rectangle(hdc, X - Width, LightSkyLevel - 19, X + Width, LightSkyLevel - 29);
		Rectangle(hdc, X - Width, LightSkyLevel - 34, X + Width, LightSkyLevel - 39);
		Rectangle(hdc, X - Width, LightSkyLevel - 45, X + Width, LightSkyLevel - 50);
		Rectangle(hdc, X - Width, LightSkyLevel - 60, X + Width, LightSkyLevel - 64);
		Rectangle(hdc, X - Width, LightSkyLevel - 77, X + Width, LightSkyLevel - 80);
	}

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end HideLighttoDarkSky()

//--------------------------------------------------------------
//��������� ����
void HideCrops(int X, int Y, int Width, int Height) {
	SetBkMode(hdc, OPAQUE);			//��� ����� �� ����������
	SetBkColor(hdc, WheatColor);	//��� ����� ����� �������
	//����� � ������� ����� ������ �������
	HBRUSH brush = CreateHatchBrush(HS_BDIAGONAL, DarkWheatColor);
	//����� ����� �������
	HPEN pen = CreatePen(PS_SOLID, 1, WheatColor);
	SelectObject(hdc, brush);	//�������� �������� �����
	SelectObject(hdc, pen);		//�������� �������� �����

	int UpperLevel = max(Y - Height, WheatLevel);
	//����������� ����
	Rectangle(hdc, X - Width, UpperLevel, X + Width, Y + Height);

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end HideCrops()