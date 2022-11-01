/**************************************************************************
*                                ��4 ���                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ��4. ���. ��������. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : Main.cpp	                                              *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : �.�.���������, �3�-211�-20							  *
* Comment(s)    : �������� ���������							          *
*																		  *
**************************************************************************/

#include <iostream>
#include <Windows.h>
#include "Utilities.h"		//������������ ���� � ���������������� ������������
#include "Mills.h"			//���������� ���� � ��������� �������
#include "Obstacles.h"		//������������ ���� � ��������� �����������

using namespace std;

void Information();			//���������� � ������ � ���������
void EmptyField();			//���������� ������ ������
void ClearAllSky();			//������ ����
void AllLighttoDarkSky();	//������� ������� ���� � �������
void ClearAllCrops();		//������ ����

//���������� ���������
void UIFigure(Mill** Mills, Obstacles** Obstacles);

HDC hdc;     //�������  �������� ����������

/*-----------------------------------------------------------------*/
/*             � � � � � � � �		� � � � � � � � �              */
/*-----------------------------------------------------------------*/
int main() {
	HWND hwnd = GetConsoleWindow();

	//���� ���������� ����������
	if (hwnd != NULL) {

		hdc = GetWindowDC(hwnd);
		//���� �������� ���������� - ����� ��������
		if (hdc != 0)
		{
			system("color F0");			//����� ���, ������ �����
			setlocale(LC_ALL, "rus");	//������� ���� ������

			Information();				//����� ����������
			system("cls");				//������� ������ �������
			EmptyField();				//������ ����

			int x0 = 400, y0 = 350;						 //��������� ���������� �������

			//���������� �������� �������
			Mill MainMill(x0, y0);						 //�������� 
			RoofedMill MainRMill(x0, y0);				 //�������� � ������
			WaterMill MainWMill(x0, y0);				 //������� �������� 
			WaterRoofedMill MainWRMill(x0, y0);			 //������� �������� � ������

			Mill* Mills[NumofMills]{};								 //������ �������
			Mills[indxMill] = &MainMill;
			Mills[indxRMill] = &MainRMill;
			Mills[indxWMill] = &MainWMill;
			Mills[indxWRMill] = &MainWRMill;

			int pondx = 900, pondy = 600;				 //��������� ���������� �����������
			int servicex = 100, servicey = 500;

			//���������� �������� �����������
			Pond Pond(pondx, pondy);					//����
			ServiceStation Service(servicex, servicey);	//��������� �������

			Obstacles* Obstacles[NumofObstacles]{};						//������ �����������
			Obstacles[indxPond] = &Pond;
			Obstacles[indxService] = &Service;

			//������� ����������� �� �����
			Obstacles[indxPond]->Show();
			Obstacles[indxService]->Show();
			
			UIFigure(Mills, Obstacles);
		}
	}

	return 0;

}	//�����	main()

//������ ������ ������
void EmptyField() {
	ClearAllSky();		//����
	ClearAllCrops();	//����

}	//end EmptyField()

//������ ������ ����
void ClearAllSky() {
	//����� � ���� ����� ����
	HBRUSH brush = CreateSolidBrush(SkyColor);
	HPEN pen = CreatePen(PS_SOLID, 1, SkyColor);
	SelectObject(hdc, brush);	//�������� �������� �����
	SelectObject(hdc, pen);		//�������� �������� �����
	//����������� ����
	Rectangle(hdc, 0, 0, FieldRight, FieldBottom);
	DeleteObject(brush);		//������� ������ �������� �����
	DeleteObject(pen);			//� �����
	AllLighttoDarkSky();		//������ ������� ����

}	//end ClearAllSky()

//������ ������� ����
void AllLighttoDarkSky() {
	//����� � ���� ����� �������� ����
	HBRUSH brush = CreateSolidBrush(LightSkyColor);
	HPEN pen = CreatePen(PS_SOLID, 1, LightSkyColor);
	SelectObject(hdc, brush);	//�������� �������� �����
	SelectObject(hdc, pen);		//�������� �������� �����

	//������ ������� ����� ����
	Rectangle(hdc, 0, LightSkyLevel, FieldRight, FieldBottom);
	//������ ������� �� ����
	Rectangle(hdc, 0, LightSkyLevel - 3, FieldRight, LightSkyLevel - 15);
	Rectangle(hdc, 0, LightSkyLevel - 19, FieldRight, LightSkyLevel - 29);
	Rectangle(hdc, 0, LightSkyLevel - 34, FieldRight, LightSkyLevel - 39);
	Rectangle(hdc, 0, LightSkyLevel - 45, FieldRight, LightSkyLevel - 50);
	Rectangle(hdc, 0, LightSkyLevel - 60, FieldRight, LightSkyLevel - 64);
	Rectangle(hdc, 0, LightSkyLevel - 77, FieldRight, LightSkyLevel - 80);

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end AllLighttoDarkSky()

//������ ����
void ClearAllCrops() {
	SetBkMode(hdc, OPAQUE);			//��� ����� �� ����������
	SetBkColor(hdc, WheatColor);	//��� ����� ����� �������

	//����� � ������� ����� ������ �������
	HBRUSH brush = CreateHatchBrush(HS_BDIAGONAL, DarkWheatColor);

	//����� ����� �������
	HPEN pen = CreatePen(PS_SOLID, 1, WheatColor);
	SelectObject(hdc, brush);		//�������� �������� �����
	SelectObject(hdc, pen);			//�������� �������� �����

	//����������� ����
	Rectangle(hdc, 0, WheatLevel, FieldRight, FieldBottom);

	DeleteObject(brush);	//������� ������ �������� �����
	DeleteObject(pen);		//� �����

}	//end ClearAllCrops()

//����� ���������� �  ������ � ����������
void Information() {
	cout << "� ��������� ������������ 3 �������:\n"
		 << "��������, ������� ������� � �����.\n"
		 << "������� ��������� ��� ������� ����� � ��������,\n"
	 	 << "� � ���� ����� �������� ���������� �������.\n";
	cout << "\n�������� ��������������� ��� ������ �������, Esc - ����� �� ���������.\n";
	cout << "\n������� Enter, ����� ����������:";

	while(true)
		if (KEY_DOWN(VK_RETURN))
			break;

}	//end Information()