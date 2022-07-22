/**************************************************************************
*                                ��4 ���                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ��4. ���. ��������. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : ���� � ���������.cpp	                                  *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : �.�.���������, �3�-211�-20		                      *
* Modified By   :														  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : ������� ���������� ���������  					      *
*																		  *
**************************************************************************/

#include "Utilities.h"		//������������ ���� � ���������������� ������������
#include "Mills.h"			//������������ ���� �������� �������	
#include "Obstacles.h"		//������������ ���� �������� �����������

//��������� ������������ �������
void UIFigure(Mill** Mills, Obstacles** Obstacles);			//���������� ���������
void ServiceInteraction(int& index, Obstacles& Service);	//�������������� � ���. ��������
void InsidePond(int& index, Obstacles& Pond);				//��������� ������ �����
void OutsidePond(int& index, Obstacles& Pond);				//��������� ��� �����


/*-------------------  ���������� ��������� ---------------------*/
void UIFigure(Mill** Mills, Obstacles** Obstacles) {
	int NewX, NewY;			//����� ���������� ������
	int Step = 70;			//��� �����������
	int index = indxMill;	//�������� � ������� ��������

	//�������� ��������� ��������� ������
	NewX = Mills[index]->GetX();    
	NewY = Mills[index]->GetY();

	while (true) {	//����������� ���� ���������� ������
		if (KEY_DOWN(VK_ESCAPE))	//esc
			break;					//����� ������

		//����������� �������� �������
		if (KEY_DOWN(VK_LEFT))		//������� ����� 
			NewX -= Step;

		if (KEY_DOWN(VK_RIGHT))		//������� ������
			NewX += Step;

		if (KEY_DOWN(VK_DOWN))		//������� ����
			NewY += Step;

		if (KEY_DOWN(VK_UP))		//������� �����
			NewY -= Step;

		
		Mills[index]->Hide();
		//�������������� � ������
		if (Obstacles[indxPond]->ObjectNearby(*Mills[index]))
				InsidePond(index, *Obstacles[indxPond]);
		//�� ����� �� ����� ��������� ������ ������� ��������
		else if (index == indxWMill || index == indxWRMill)
			OutsidePond(index, *Obstacles[indxPond]);

		Mills[index]->Hide();
		//�������������� � ���. ��������
		if (Obstacles[indxService]->ObjectNearby(*Mills[index]))
			ServiceInteraction(index, *Obstacles[indxService]);

		Mills[index]->MoveTo(NewX, NewY);	//��������� ��������
		//��������� ��������� 5 ��� � ���
		Sleep(200);

	}   //end while

}	//end UIFigure()

/*-------------------  �������������� �� �������� ---------------------*/
//��������� ��� ������� �����
void ServiceInteraction(int& index, Obstacles& Service) {
	//�������� ������ ������� ��������
	index = TransitionMatrix[index][ServiceIsNearby];

	//���������� ������� � ��������� ����� �� ����
	Service.MoveTo(rand() % FieldRight, rand() % (FieldBottom - WheatLevel) + WheatLevel);

}	//end ServiceInteraction()

/*-------------------  ��������� ������ ����� ---------------------*/
void InsidePond(int& index, Obstacles& Pond) {
	//�������� ������ ������� �������� �� �������
	index = TransitionMatrix[index][PondIsNearby];
	Pond.Show();

}	//end InsidePond()

/*-------------------  ��������� ��� ����� ---------------------*/
void OutsidePond(int& index, Obstacles& Pond) {
	//�������� ������ ������� ������� �������� �� �������
	index = TransitionMatrix[index][NothingNearby];
	Pond.Show();

}	//end OutsidePond()