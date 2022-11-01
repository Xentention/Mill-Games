/**************************************************************************
*                                ЛР4 ООП                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ЛР4. ООП. Мельница. 					  *
* Project Type  : Win32 Console application                               *
* File Name     : Mills.h	                                          *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : К.В.Тимошенко, М3О-211Б-20		                  *
* Modified By   :							  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : Класс Mill и его потомки 				  *
*									  *
**************************************************************************/
#pragma once

#include "LocationAndFigure.h"

/*-----------------------  Класс ИНТЕРФЕЙС МЕЛЬНИЦЫ ------------------------*/
class IMill {
public:
	//необходимые для мельницы методы
	virtual void DrawBuilding() = 0;	//рисует здание мельницы
	virtual void DrawRotor() = 0;		//рисует лопасти мельницы
	virtual void DrawStorage() = 0;		//рисует кладовую зерна

};	//end class IMill

/*-----------------------  Класс МЕЛЬНИЦА ----------------------------------*/
class Mill : public Figure, public IMill {
protected:
	unsigned int RotorRadius;			//длина лопастей
	unsigned int Height;				//высота здания мельницы
	unsigned int Width;					//ширина здания мельницы

	virtual void DrawBuilding();		//рисует здание мельницы
	virtual void DrawRotor();			//рисует лопасти мельницы
	virtual void DrawStorage();			//рисует кладовую зерна


public:
	//конструктор с параметрами по умолчанию
	Mill(int InitX = 400, int InitY = 300,
		int InitRadius = 100, int InitHeight = 150,
		int InitWidth = 80, int InitWheatAmount = 0);

	virtual int ReturnMaxHeight();		//Узнаем общую высоту мельницы (переопр.)
	virtual int ReturnMaxWidth();		//Узнаем общую ширину мельницы (переопр.)
	virtual void Show();				//Показать мельницу (переопр.)

};	//end class Mill

/*-----------------------  Класс МЕЛЬНИЦА С КРЫШЕЙ --------------------------*/
class RoofedMill :public Mill {
protected:
	void DrawRoof();								//Рисует крышу мельницы

public:
	//конструктор с параметрами по умолчанию
	RoofedMill(int InitX, int InitY);

	virtual void Show() override;					//Показать мельницу (переопр.)

};	//end class RoofedMill

/*-----------------------  Класс ВОДЯНАЯ МЕЛЬНИЦА ------------------------*/
class WaterMill :public Mill {
protected:
	void DrawBuilding();	//рисует здание мельницы
	void DrawRotor();		//рисует лопасти мельницы
	void DrawStorage();		//рисует кладовую зерна

public:
	//конструктор с параметрами по умолчанию
	WaterMill(int InitX, int InitY);

	virtual int ReturnMaxHeight() override;	//Узнаем общую высоту мельницы
	virtual int ReturnMaxWidth() override;	//Узнаем общую ширину мельницы
	virtual void Show() override;			//Показать мельницу (переопр.)

};	//end class WaterMill

/*-------------------  Класс ВОДЯНАЯ МЕЛЬНИЦА С КРЫШЕЙ --------------------*/
class WaterRoofedMill :public WaterMill {
protected:
	void DrawRoof();						//Рисует крышу мельницы

public:
	//конструктор с параметрами по умолчанию
	WaterRoofedMill(int InitX, int InitY);

	virtual void Show() override;			//Показать мельницу (переопр.)

};	//end class WaterRoofedMill
