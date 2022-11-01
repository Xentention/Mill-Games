/**************************************************************************
*                                ЛР4 ООП                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ЛР4. ООП. Мельница. 					  *
* Project Type  : Win32 Console application                               *
* File Name     : LocationAndFigure.h	                                  *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : К.В.Тимошенко, М3О-211Б-20		                  *
* Modified By   :							  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : Классы Location и Point				   *
*									  *
**************************************************************************/
#pragma once

/*-----------------------  Класс МЕСТОПОЛОЖЕНИЕ -------------------------*/
class Location {
private:
	int X;		//координата X
	int Y;		//координата Y

public:
	Location(int InitX, int InitY); 
	int GetX();				//получить X координату точки
	int GetY();				//получить Y координату точки
	void SetX(int NewX);			//Установить Х координату точки
	void SetY(int NewY);			//Установить Y координату точки

};	//end class Location

/*-----------------------  Абстрактный класс ФИГУРА ------------------------*/
class Figure : public Location {
protected:
	bool Visible;				//видна фигура или нет

public:
	Figure(int InitX, int InitY);		
	virtual int ReturnMaxHeight() = 0;	//узнать ширину
	virtual int ReturnMaxWidth() = 0;	//узнать высоту
	virtual void Show() = 0;		//показать фигуру
	virtual void Hide();			//скрыть фигуру
	void MoveTo(int NewX, int NewY);	//переместить фигуру

};	//end class Figure
