/**************************************************************************
*                                ��4 ���                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ��4. ���. ��������. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : Obstacles.h                                             *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : �.�.���������, �3�-211�-20		                      *
* Modified By   :														  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : ����������� ����� Obstacles � ��� ������� 		      *
*																		  *
**************************************************************************/
#pragma once

#include "LocationAndFigure.h"

/*--------------------  ����������� ����� ����������� ---------------------*/
class Obstacles : public Figure {
public:
	//�����������
	Obstacles(int InitX, int InitY);

	bool ObjectNearby(Figure& Object);	//���� �� ������ �����

};	//end class Obstacles

/*-----------------------  ����� ���� -------------------------*/
class Pond : public Obstacles {
private:
	unsigned int Height;		//������ �����
	unsigned int Width;			//������ �����

public:
	//����������� � ����������� �� ���������
	Pond(int InitX, int InitY, int InitHeight = 300, int InitWidth = 600);

	virtual void Show();						//�������� ���� (�������.)
	virtual int ReturnMaxHeight();				//������ ������ ����� (�������.)
	virtual int ReturnMaxWidth();				//������ ������ ����� (�������.)

};	//end class Pond

/*-----------------------  ����� ��������� ������� -------------------------*/
class ServiceStation : public Obstacles {
private:
	unsigned int Size;

public:
	//����������� � ����������� �� ���������
	ServiceStation(int InitX, int InitY, int InitSize = 100);

	virtual void Show();				//�������� ���. ������� (�������.)
	virtual int ReturnMaxHeight();		//������ ������ ������� (�������.)
	virtual int ReturnMaxWidth();		//������ ������ ������� (�������.)

};	//end class ServiceStation