/**************************************************************************
*                                ЛР4 ООП                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ЛР4. ООП. Мельница. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : Obstacles.h                                             *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : К.В.Тимошенко, М3О-211Б-20		                      *
* Modified By   :														  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : Абстрактный класс Obstacles и его потомки 		      *
*																		  *
**************************************************************************/
#pragma once

#include "LocationAndFigure.h"

/*--------------------  Абстрактный класс ПРЕПЯТСТВИЯ ---------------------*/
class Obstacles : public Figure {
public:
	//конструктор
	Obstacles(int InitX, int InitY);

	bool ObjectNearby(Figure& Object);	//есть ли фигура рядом

};	//end class Obstacles

/*-----------------------  Класс ПРУД -------------------------*/
class Pond : public Obstacles {
private:
	unsigned int Height;		//высота пруда
	unsigned int Width;			//ширина пруда

public:
	//конструктор с параметрами по умолчанию
	Pond(int InitX, int InitY, int InitHeight = 300, int InitWidth = 600);

	virtual void Show();						//Показать пруд (переопр.)
	virtual int ReturnMaxHeight();				//Узнаем высоту пруда (переопр.)
	virtual int ReturnMaxWidth();				//Узнаем ширину пруда (переопр.)

};	//end class Pond

/*-----------------------  Класс РЕМОНТНАЯ СТАНЦИЯ -------------------------*/
class ServiceStation : public Obstacles {
private:
	unsigned int Size;

public:
	//конструктор с параметрами по умолчанию
	ServiceStation(int InitX, int InitY, int InitSize = 100);

	virtual void Show();				//Показать рем. станцию (переопр.)
	virtual int ReturnMaxHeight();		//Узнаем высоту станции (переопр.)
	virtual int ReturnMaxWidth();		//Узнаем ширину станции (переопр.)

};	//end class ServiceStation
