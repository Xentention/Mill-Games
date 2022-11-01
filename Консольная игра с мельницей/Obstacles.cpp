/**************************************************************************
*                                ��4 ���                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ��4. ���. ��������. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : Obstacles.cpp                                           *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : �.�.���������, �3�-211�-20		                      *
* Modified By   :														  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : ������ �����. ������ Obstacle � ��� ��������	          *
*																		  *
**************************************************************************/

#include <Windows.h>
#include "Utilities.h"
#include "Obstacles.h"

extern HDC hdc;      // �������  �������� ����������

/*----------------------------------------*/
/*        ������ ������ Obstacles          */
/*----------------------------------------*/

 //--------------------------------------------------------------
//�����������
Obstacles::Obstacles(int InitX, int InitY) :Figure(InitX, InitY) {
	//��������� ������ ����

};	//end Obstacles::Obstacles()

//--------------------------------------------------------------
//���� �� ����� ������ ������
bool Obstacles::ObjectNearby(Figure& Object) {
	int ObstacleHeight = ReturnMaxHeight();			//������ �����������
	int ObstacleWidth = ReturnMaxWidth();			//������ �����������
	int ObjectHeight = Object.ReturnMaxHeight();	//������ ������
	int ObjectWidth = Object.ReturnMaxWidth();		//������ ������

	//������������ �� �� ������
	int DeltaHeight;
	GetY() >= Object.GetY() ?
		DeltaHeight = (GetY() - ObstacleHeight) - (Object.GetY() + ObjectHeight) :
		DeltaHeight = (Object.GetY() - ObjectHeight) - (GetY() + ObstacleHeight);
	//������������ �� �� ������
	int DeltaWidth;
	GetX() >= Object.GetX() ?
		DeltaWidth = (GetX() - ObstacleWidth) - (Object.GetX() + ObjectWidth) :
		DeltaWidth = (Object.GetX() - ObjectWidth) - (GetX() + ObstacleWidth);

	//����������� true ���� ������� ������������
	if (DeltaHeight < 0 && DeltaWidth < 0)	return true;
	return false;		//����� ������ ����� ���

}	//end Obstacles::ObjectNearby()


/*----------------------------------------*/
/*         ������ ������ Pond             */
/*----------------------------------------*/

 //--------------------------------------------------------------
//�����������
Pond::Pond(int InitX, int InitY, int InitHeight, int InitWidth) : Obstacles(InitX, InitY) {
	Height = InitHeight;
	Width = InitWidth;

}	//end Pond::Pond()

 //--------------------------------------------------------------
//�������� ����
void Pond::Show() {
	Visible = true;
	int X = GetX(), Y = GetY();

	//������� ����� � ����� ����� �����
	HBRUSH brush = CreateSolidBrush(PondColor);
	HPEN pen = CreatePen(PS_SOLID, 1, PondColor);
	SelectObject(hdc, brush);	//�������� �������� �����
	SelectObject(hdc, pen);		//�������� �������� �����

	//������ ���� �����
	Ellipse(hdc, X - Width / 2, Y - Height / 2, X + Width / 2, Y + Height / 2);

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end Pond::Show()

//--------------------------------------------------------------
//������� ������ ������
int Pond::ReturnMaxHeight() {	return Height / 2;	}	

//--------------------------------------------------------------
//������� ������ ������
int Pond::ReturnMaxWidth() {	return Width / 2;	}	


/*-------------------------------------------------*/
/*        ������ ������ ServiceStation             */
/*-------------------------------------------------*/

 //--------------------------------------------------------------
//�����������
ServiceStation::ServiceStation(int InitX, int InitY, int InitSize) : Obstacles(InitX, InitY) {
	Size = InitSize;

}	//end ServiceStation::ServiceStation()

 //--------------------------------------------------------------
//�������� ���. �������
void ServiceStation::Show() {
	Visible = true;
	int X = GetX(), Y = GetY();

	//������� ����� � ����� ����� ������
	HBRUSH brush = CreateSolidBrush(MillColor);
	HPEN pen = CreatePen(PS_SOLID, 1, MillColor);
	SelectObject(hdc, brush);	//�������� �������� �����
	SelectObject(hdc, pen);		//�������� �������� �����
	
	//������ ������
	Rectangle(hdc, X - Size / 2, Y - Size, X + Size / 2, Y + Size);
	DeleteObject(brush);	//������� ������ �������� �����

	//������ ����� �����
	brush = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, brush);	//�������� �������� �����

	//������ ����
	Rectangle(hdc, X - Size / 4, Y - Size / 2 , X + Size / 4, Y);

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end ServiceStation::Show()

//--------------------------------------------------------------
//������� ������ ������
int ServiceStation::ReturnMaxHeight() {		return Size;	}	

//--------------------------------------------------------------
//������� ������ ������
int ServiceStation::ReturnMaxWidth() {	return Size / 2;	}	