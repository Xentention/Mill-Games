/**************************************************************************
*                                ЛР4 ООП                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ЛР4. ООП. Мельница. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : Obstacles.cpp                                           *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : К.В.Тимошенко, М3О-211Б-20		                      *
* Modified By   :														  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : Методы абстр. класса Obstacle и его потомков	          *
*																		  *
**************************************************************************/

#include <Windows.h>
#include "Utilities.h"
#include "Obstacles.h"

extern HDC hdc;      // объявим  контекст устройства

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Obstacles          */
/*----------------------------------------*/

 //--------------------------------------------------------------
//конструктор
Obstacles::Obstacles(int InitX, int InitY) :Figure(InitX, InitY) {
	//формально пустое тело

};	//end Obstacles::Obstacles()

//--------------------------------------------------------------
//Есть ли рядом другой объект
bool Obstacles::ObjectNearby(Figure& Object) {
	int ObstacleHeight = ReturnMaxHeight();			//Высота препятствия
	int ObstacleWidth = ReturnMaxWidth();			//Ширина препятствия
	int ObjectHeight = Object.ReturnMaxHeight();	//Высота фигуры
	int ObjectWidth = Object.ReturnMaxWidth();		//Ширина фигуры

	//Пересекается ли по высоте
	int DeltaHeight;
	GetY() >= Object.GetY() ?
		DeltaHeight = (GetY() - ObstacleHeight) - (Object.GetY() + ObjectHeight) :
		DeltaHeight = (Object.GetY() - ObjectHeight) - (GetY() + ObstacleHeight);
	//Пересекается ли по ширине
	int DeltaWidth;
	GetX() >= Object.GetX() ?
		DeltaWidth = (GetX() - ObstacleWidth) - (Object.GetX() + ObjectWidth) :
		DeltaWidth = (Object.GetX() - ObjectWidth) - (GetX() + ObstacleWidth);

	//Воздвращаем true если объекты пересекаются
	if (DeltaHeight < 0 && DeltaWidth < 0)	return true;
	return false;		//иначе фигуры рядом нет

}	//end Obstacles::ObjectNearby()


/*----------------------------------------*/
/*         МЕТОДЫ КЛАССА Pond             */
/*----------------------------------------*/

 //--------------------------------------------------------------
//конструктор
Pond::Pond(int InitX, int InitY, int InitHeight, int InitWidth) : Obstacles(InitX, InitY) {
	Height = InitHeight;
	Width = InitWidth;

}	//end Pond::Pond()

 //--------------------------------------------------------------
//показать пруд
void Pond::Show() {
	Visible = true;
	int X = GetX(), Y = GetY();

	//Зададим ручку и кисть цвета пруда
	HBRUSH brush = CreateSolidBrush(PondColor);
	HPEN pen = CreatePen(PS_SOLID, 1, PondColor);
	SelectObject(hdc, brush);	//выбираем заданную кисть
	SelectObject(hdc, pen);		//выбираем заданную ручку

	//рисуем овал пруда
	Ellipse(hdc, X - Width / 2, Y - Height / 2, X + Width / 2, Y + Height / 2);

	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

}	//end Pond::Show()

//--------------------------------------------------------------
//Вернуть высоту фигуры
int Pond::ReturnMaxHeight() {	return Height / 2;	}	

//--------------------------------------------------------------
//Вернуть ширину фигуры
int Pond::ReturnMaxWidth() {	return Width / 2;	}	


/*-------------------------------------------------*/
/*        МЕТОДЫ КЛАССА ServiceStation             */
/*-------------------------------------------------*/

 //--------------------------------------------------------------
//конструктор
ServiceStation::ServiceStation(int InitX, int InitY, int InitSize) : Obstacles(InitX, InitY) {
	Size = InitSize;

}	//end ServiceStation::ServiceStation()

 //--------------------------------------------------------------
//показать рем. станцию
void ServiceStation::Show() {
	Visible = true;
	int X = GetX(), Y = GetY();

	//Зададим ручку и кисть цвета Здания
	HBRUSH brush = CreateSolidBrush(MillColor);
	HPEN pen = CreatePen(PS_SOLID, 1, MillColor);
	SelectObject(hdc, brush);	//выбираем заданную кисть
	SelectObject(hdc, pen);		//выбираем заданную ручку
	
	//Рисуем здание
	Rectangle(hdc, X - Size / 2, Y - Size, X + Size / 2, Y + Size);
	DeleteObject(brush);	//Удаляем больше ненужную кисть

	//Задаем синюю кисть
	brush = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, brush);	//выбираем заданную кисть

	//Рисуем окно
	Rectangle(hdc, X - Size / 4, Y - Size / 2 , X + Size / 4, Y);

	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

}	//end ServiceStation::Show()

//--------------------------------------------------------------
//Вернуть высоту фигуры
int ServiceStation::ReturnMaxHeight() {		return Size;	}	

//--------------------------------------------------------------
//Вернуть ширину фигуры
int ServiceStation::ReturnMaxWidth() {	return Size / 2;	}	
int ServiceStation::ReturnMaxWidth() {	return Size / 2;	}	
