/**************************************************************************
*                                ��4 ���                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ��4. ���. ��������. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : Mills.cpp	                                              *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : �.�.���������, �3�-211�-20		                      *
* Modified By   :														  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : ������ ������ Mill � ��� ��������			              *
*																		  *
**************************************************************************/

#include "Utilities.h"   // ������������ ���� � ���������������� ������������
#include "Mills.h"

extern HDC hdc;      // �������  �������� ����������

/*----------------------------------------*/
/*        ������ ������ Mill              */
/*----------------------------------------*/

 //--------------------------------------------------------------
//�����������
Mill::Mill(int InitX, int InitY,
		   int InitRadius, int InitHeight,
		   int InitWidth, int InitWheatAmount) : Figure(InitX, InitY) {
	RotorRadius = InitRadius;
	Height = InitHeight;
	Width = InitWidth;

}	//end Mill::Mill()

//--------------------------------------------------------------
//�������� ��������
void Mill::Show() {
	Visible = true;		//��������, ��� �������
	DrawBuilding();		//�������� ������
	DrawStorage();		//�������� ��������
	DrawRotor();		//�������� �������
	
}	//end Mill::Show()

//--------------------------------------------------------------
//�������� ������ ��������
void Mill::DrawBuilding() {
	//������� ����� � ����� ����� �����
	HBRUSH brush = CreateSolidBrush(MillColor);
	HPEN pen = CreatePen(PS_SOLID, 1, MillColor);
	SelectObject(hdc, brush);	//�������� �������� �����
	SelectObject(hdc, pen);		//�������� �������� �����

	int X = GetX(), Y = GetY();
	//������ ������ ��������
	Rectangle(hdc, X - Width / 2, Y - Height / 4, X + Width / 2, Y + 3 * Height / 4);

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end Mill::DrawBuilding()

//--------------------------------------------------------------
//�������� ������� ��������
void Mill::DrawRotor() {
	int X = GetX(), Y = GetY();
	//������� ������� ���, �������� � ������� ��������
	int HubRad = RotorRadius / 20, BladeWidth = RotorRadius / 5, BladeShaft = RotorRadius / 40;
	//������� ����� � ����� ����� ������
	HBRUSH brush = CreateSolidBrush(WindshaftColor);
	HPEN pen = CreatePen(PS_INSIDEFRAME, 1, WindshaftColor);
	SelectObject(hdc, brush);	//�������� �������� �����
	SelectObject(hdc, pen);		//�������� �������� �����

	//������ ���� ��������
	Ellipse(hdc, X - HubRad, Y - HubRad, X + HubRad, Y + HubRad);

	//������ ����������
	Rectangle(hdc, X, Y, X - RotorRadius , Y - BladeShaft);
	Rectangle(hdc, X, Y, X + RotorRadius , Y + BladeShaft);
	Rectangle(hdc, X, Y, X + BladeShaft, Y - RotorRadius );
	Rectangle(hdc, X, Y, X - BladeShaft, Y + RotorRadius );
	DeleteObject(brush);	//������� ����� �������� �����

	//������ ����� � ����� ����� � ���������� �����
	SetBkMode(hdc, TRANSPARENT);
	brush = CreateHatchBrush(HS_DIAGCROSS, RGB(255, 255, 255));
	SelectObject(hdc, brush);	//�������� �������� �����

	//������ �������
	Rectangle(hdc, X - RotorRadius , Y - 2 * BladeShaft, X - RotorRadius / 3, Y + BladeWidth - BladeShaft);
	Rectangle(hdc, X + RotorRadius / 3, Y - BladeWidth + BladeShaft, X + RotorRadius , Y + 2 * BladeShaft);
	Rectangle(hdc, X - BladeWidth + BladeShaft, Y - RotorRadius , X + 2 * BladeShaft, Y - RotorRadius / 3);
	Rectangle(hdc, X - 2 * BladeShaft, Y + RotorRadius , X + BladeWidth - BladeShaft, Y + RotorRadius / 3);

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end Mill::DrawRotor()

//--------------------------------------------------------------
//�������� �����
void Mill::DrawStorage() {
	int X = GetX(), Y = GetY();
	SetBkMode(hdc, OPAQUE);				//��� ����� �� ����������
	SetBkColor(hdc, WheatColor);		//��� ����� ����� �����

	//������� ����� � ����� ����� �������
	HBRUSH brush = CreateHatchBrush(HS_DIAGCROSS, DarkWheatColor);
	HPEN pen = CreatePen(PS_INSIDEFRAME, 3, DarkWheatColor);
	SelectObject(hdc, brush);			//�������� �������� �����
	SelectObject(hdc, pen);				//�������� �������� �����

	Ellipse(hdc, X - Width, Y + 3 * Height / 4, X - Width / 2, Y + (3 * Height / 4) - 2 * RotorRadius / 5);

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

	//������� ����� � ����� ����� ������
	brush = CreateSolidBrush(WindshaftColor);
	pen = CreatePen(PS_SOLID, 1, WindshaftColor);
	SelectObject(hdc, brush);	//�������� �������� �����
	SelectObject(hdc, pen);		//�������� �������� �����

	//�������� �����
	Rectangle(hdc, X - Width, Y + 3 * Height / 4, X - Width / 2, Y + (3 * Height / 4) - RotorRadius / 5);
	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end Mill::DrawStorage()

//--------------------------------------------------------------
//������� ������ ������
int Mill::ReturnMaxHeight()	{	return max(RotorRadius, Height);	}	

//--------------------------------------------------------------
//������� ������ ������
int Mill::ReturnMaxWidth()	{	return max(RotorRadius, Width);		}	

/*----------------------------------------*/
/*        ������ ������ RoofedMill        */
/*----------------------------------------*/

//--------------------------------------------------------------
RoofedMill::RoofedMill(int InitX, int InitY) : Mill(InitX, InitY) {
	//��������� ������ ����

}	//end RoofedMill::RoofedMill()

//--------------------------------------------------------------
//�������� ��������
void RoofedMill::Show() {
	DrawRoof();						//���������� �����
	Mill::Show();					//���������� �������� ������� ������

}	//end RoofedMill::Show()

//--------------------------------------------------------------
//���������� �����
void RoofedMill::DrawRoof()	{
	int X = GetX(), Y = GetY();
	SetBkMode(hdc, OPAQUE);			//��� ����� �� ����������
	SetBkColor(hdc, RoofColor);		//��� ����� ����� �����

	//������� ����� � ����� ����� �����
	HBRUSH brush = CreateHatchBrush(HS_HORIZONTAL, RGB(131, 76, 87));
	HPEN pen = CreatePen(PS_INSIDEFRAME, 1, RoofColor);
	SelectObject(hdc, brush);		//�������� �������� �����
	SelectObject(hdc, pen);			//�������� �������� �����

	POINT roof[3];					//������ ����� �����������
	roof[0].x = X - Width / 2;		//���������� ������
	roof[0].y = Y - Height / 4;		//����������� �����
	roof[1].x = X + Width / 2;
	roof[1].y = Y - Height / 4;
	roof[2].x = X;
	roof[2].y = Y - Height / 2;
	Polygon(hdc, roof, 3);	//������ �����������

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end RoofedMill::DrawRoof()

/*----------------------------------------*/
/*        ������ ������ WaterMill         */
/*----------------------------------------*/

//�����������
WaterMill::WaterMill(int InitX, int InitY) : Mill(InitX, InitY) {
	Width = Height;		//������ ����������

}	//end WaterMill::WaterMill

//--------------------------------------------------------------
//������� ������ ������
int WaterMill::ReturnMaxHeight() {	return max(RotorRadius, 7 * Height / 8);	}	

//--------------------------------------------------------------
//������� ������ ������
int WaterMill::ReturnMaxWidth() {	return max(RotorRadius, Width);		}

//--------------------------------------------------------------
//�������� ��������
void WaterMill::Show() {
	Visible = true;		//��������, ��� �������
	DrawBuilding();		//�������� ������
	DrawStorage();		//�������� ��������
	DrawRotor();		//�������� �������

}	//end WaterMill::Show()

//--------------------------------------------------------------
//�������� ������ ��������
void WaterMill::DrawBuilding() {
	//������� ����� � ����� ����� �����
	HBRUSH brush = CreateSolidBrush(MillColor);
	HPEN pen = CreatePen(PS_SOLID, 1, MillColor);
	SelectObject(hdc, brush);	//�������� �������� �����
	SelectObject(hdc, pen);		//�������� �������� �����

	int X = GetX(), Y = GetY();
	//������ ������ ��������
	Rectangle(hdc, X - Width / 2, Y - Height / 2, X + Width / 2, Y + Height / 2);

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end WaterMill::DrawBuilding()

//--------------------------------------------------------------
//�������� ������� ��������
void WaterMill::DrawRotor() {
	int X = GetX(), Y = GetY();
	//������� ������� ���, �������� � ����� ������� ��������
	int HubRad = RotorRadius / 20, BladeWidth = RotorRadius / 10, BladeShaft = Height / 2;
	//������� ����� � ����� ����� ������
	HPEN pen = CreatePen(PS_INSIDEFRAME, BladeWidth, WindshaftColor);
	SelectObject(hdc, pen);		//�������� �������� �����
	HBRUSH brush = (HBRUSH)::GetStockObject(NULL_BRUSH);
	SelectObject(hdc, brush);	//�������� �������� �����

	//������ �������
	Ellipse(hdc, X - BladeShaft, Y - BladeShaft, X + BladeShaft, Y + BladeShaft);
	//������ ���� ��������
	Ellipse(hdc, X - BladeWidth, Y - BladeWidth, X + BladeWidth, Y + BladeWidth);
	DeleteObject(brush);	//������� ������ �������� �����

	brush = CreateSolidBrush(WindshaftColor);
	SelectObject(hdc, brush);	//�������� �������� �����
	//������ ����������
	Rectangle(hdc, X, Y, X - BladeShaft - HubRad, Y - HubRad);
	Rectangle(hdc, X, Y, X + BladeShaft + HubRad, Y + HubRad);
	Rectangle(hdc, X, Y, X + HubRad, Y - BladeShaft - HubRad);
	Rectangle(hdc, X, Y, X - HubRad, Y + BladeShaft + HubRad);
	DeleteObject(brush);	//������� ������ �������� �����

	DeleteObject(pen);		//� �����

}	//end WaterMill::DrawRotor()

//--------------------------------------------------------------
//�������� �����
void WaterMill::DrawStorage() {
	int X = GetX(), Y = GetY();
	SetBkMode(hdc, OPAQUE);				//��� ����� �� ����������
	SetBkColor(hdc, WheatColor);		//��� ����� ����� �����

	//������� ����� � ����� ����� �������
	HBRUSH brush = CreateHatchBrush(HS_DIAGCROSS, DarkWheatColor);
	HPEN pen = CreatePen(PS_INSIDEFRAME, 3, DarkWheatColor);
	SelectObject(hdc, brush);			//�������� �������� �����
	SelectObject(hdc, pen);				//�������� �������� �����

	Ellipse(hdc, X - Width, Y + (Height / 2), X - Width / 2, Y + (Height / 2) - 2 * RotorRadius / 5);

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

	//������� ����� � ����� ����� ������
	brush = CreateSolidBrush(WindshaftColor);
	pen = CreatePen(PS_SOLID, 1, WindshaftColor);
	SelectObject(hdc, brush);	//�������� �������� �����
	SelectObject(hdc, pen);		//�������� �������� �����

	//�������� �����
	Rectangle(hdc, X - Width, Y + (Height / 2), X - Width / 2, Y + (Height / 2) - RotorRadius / 5);
	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end WaterMill::DrawStorage()

/*----------------------------------------------*/
/*        ������ ������ WaterRoofedMill         */
/*----------------------------------------------*/

WaterRoofedMill::WaterRoofedMill(int InitX, int InitY) : WaterMill(InitX, InitY) {
	//��������� ������ ����

}	//end WaterRoofedMill::WaterRoofedMill()

//--------------------------------------------------------------
//�������� ��������
void WaterRoofedMill::Show() {
	DrawRoof();				//������ �����
	WaterMill::Show();		//������ �������� �� ������

}	//end WaterRoofedMill::Show()

//--------------------------------------------------------------
//���������� �����
void WaterRoofedMill::DrawRoof()	{
	int X = GetX(), Y = GetY();
	SetBkMode(hdc, OPAQUE);			//��� ����� �� ����������
	SetBkColor(hdc, RoofColor);		//��� ����� ����� �����

	//������� ����� � ����� ����� �����
	HBRUSH brush = CreateHatchBrush(HS_HORIZONTAL, RGB(131, 76, 87));
	HPEN pen = CreatePen(PS_INSIDEFRAME, 3, RoofColor);
	SelectObject(hdc, brush);		//�������� �������� �����
	SelectObject(hdc, pen);			//�������� �������� �����

	POINT roof[3];					//������ ����� �����������
	roof[0].x = X - Width / 2;		//���������� ������
	roof[0].y = Y - Height / 2;		//����������� �����
	roof[1].x = X + Width / 2;
	roof[1].y = Y - Height / 2;
	roof[2].x = X;
	roof[2].y = Y - 3*Height/4;
	Polygon(hdc, roof, 3);	//������ �����������

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end WaterRoofedMill::DrawRoof()