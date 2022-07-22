/**************************************************************************
*                                ��4 ���                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ��4. ���. ��������. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : Mills.h	                                              *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : �.�.���������, �3�-211�-20		                      *
* Modified By   :														  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : ����� Mill � ��� ������� 							      *
*																		  *
**************************************************************************/
#pragma once

#include "LocationAndFigure.h"

/*-----------------------  ����� ��������� �������� ------------------------*/
class IMill {
public:
	//����������� ��� �������� ������
	virtual void DrawBuilding() = 0;	//������ ������ ��������
	virtual void DrawRotor() = 0;		//������ ������� ��������
	virtual void DrawStorage() = 0;		//������ �������� �����

};	//end class IMill

/*-----------------------  ����� �������� ----------------------------------*/
class Mill : public Figure, public IMill {
protected:
	unsigned int RotorRadius;			//����� ��������
	unsigned int Height;				//������ ������ ��������
	unsigned int Width;					//������ ������ ��������

	virtual void DrawBuilding();		//������ ������ ��������
	virtual void DrawRotor();			//������ ������� ��������
	virtual void DrawStorage();			//������ �������� �����


public:
	//����������� � ����������� �� ���������
	Mill(int InitX = 400, int InitY = 300,
		int InitRadius = 100, int InitHeight = 150,
		int InitWidth = 80, int InitWheatAmount = 0);

	virtual int ReturnMaxHeight();		//������ ����� ������ �������� (�������.)
	virtual int ReturnMaxWidth();		//������ ����� ������ �������� (�������.)
	virtual void Show();				//�������� �������� (�������.)

};	//end class Mill

/*-----------------------  ����� �������� � ������ --------------------------*/
class RoofedMill :public Mill {
protected:
	void DrawRoof();								//������ ����� ��������

public:
	//����������� � ����������� �� ���������
	RoofedMill(int InitX, int InitY);

	virtual void Show() override;					//�������� �������� (�������.)

};	//end class RoofedMill

/*-----------------------  ����� ������� �������� ------------------------*/
class WaterMill :public Mill {
protected:
	void DrawBuilding();	//������ ������ ��������
	void DrawRotor();		//������ ������� ��������
	void DrawStorage();		//������ �������� �����

public:
	//����������� � ����������� �� ���������
	WaterMill(int InitX, int InitY);

	virtual int ReturnMaxHeight() override;	//������ ����� ������ ��������
	virtual int ReturnMaxWidth() override;	//������ ����� ������ ��������
	virtual void Show() override;			//�������� �������� (�������.)

};	//end class WaterMill

/*-------------------  ����� ������� �������� � ������ --------------------*/
class WaterRoofedMill :public WaterMill {
protected:
	void DrawRoof();						//������ ����� ��������

public:
	//����������� � ����������� �� ���������
	WaterRoofedMill(int InitX, int InitY);

	virtual void Show() override;			//�������� �������� (�������.)

};	//end class WaterRoofedMill