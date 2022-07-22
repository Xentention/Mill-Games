/**************************************************************************
*                                ��4 ���                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ��4. ���. ��������. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : LocationAndFigure.h	                                  *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : �.�.���������, �3�-211�-20		                      *
* Modified By   :														  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : ������ Location � Point							      *
*																		  *
**************************************************************************/
#pragma once

/*-----------------------  ����� �������������� -------------------------*/
class Location {
private:
	int X;		//���������� X
	int Y;		//���������� Y

public:
	Location(int InitX, int InitY); 
	int GetX();						//�������� X ���������� �����
	int GetY();						//�������� Y ���������� �����
	void SetX(int NewX);			//���������� � ���������� �����
	void SetY(int NewY);			//���������� Y ���������� �����

};	//end class Location

/*-----------------------  ����������� ����� ������ ------------------------*/
class Figure : public Location {
protected:
	bool Visible;						//����� ������ ��� ���

public:
	Figure(int InitX, int InitY);		
	virtual int ReturnMaxHeight() = 0;	//������ ������
	virtual int ReturnMaxWidth() = 0;	//������ ������
	virtual void Show() = 0;			//�������� ������
	virtual void Hide();				//������ ������
	void MoveTo(int NewX, int NewY);	//����������� ������

};	//end class Figure