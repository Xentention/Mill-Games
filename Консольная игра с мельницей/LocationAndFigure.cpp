/**************************************************************************
*                                ЛР4 ООП                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ЛР4. ООП. Мельница. 					  *
* Project Type  : Win32 Console application                               *
* File Name     : LocationAndFigure.cpp	                                  *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : К.В.Тимошенко, М3О-211Б-20		                  *
* Modified By   :							  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : Методы классов Location и Point			  *
*																		  *
**************************************************************************/

#include "Utilities.h"  	 //Заголовочный файл с вспомогательными объявлениями
#include "LocationAndFigure.h"

extern HDC hdc;  		   //объявим  контекст устройства

//прототипы вспомогательных для Hide() функций
void HideSky(int X, int Y, int Width, int Height);
void HideLighttoDarkSky(int X, int Y, int Width, int Height);
void HideCrops(int X, int Y, int Width, int Height);

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Location          */
/*----------------------------------------*/

//------------------------------------------------
//конструктор
Location::Location(int InitX, int InitY) {
	X = InitX;
	Y = InitY;

};	//end Location::Location()

//------------------------------------------------
 //получить X координату точки
int Location::GetX() {	return X;	};	

//------------------------------------------------
 //получить Y координату точки
int Location::GetY() {	return Y;	};

//------------------------------------------------
//установить X координату точки
void Location::SetX(int NewX) { X = NewX; };

//------------------------------------------------
//установить Y координату точки
void Location::SetY(int NewY) { Y = NewY; };

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Figure             */
/*----------------------------------------*/

 //--------------------------------------------------------------
//конструктор
Figure::Figure(int InitX, int InitY) : Location(InitX, InitY) {
	Visible = false;
}	//end Figure::Figure()

 //--------------------------------------------------------------
//Скрыть фигуру
void Figure::Hide() {
	if (!Visible) return;

	Visible = false;			//Больше не видна
	int Height = ReturnMaxHeight();		//Узнаем высоту фигуры
	int Width = ReturnMaxWidth();		//Узнаем ширину фигуры

	if (WheatLevel > GetY() - Height)			//Если фигура выше горизонта
		HideSky(GetX(), GetY(), Width, Height);		//Закрашиваем небо

	if (WheatLevel <= GetY() + Height)			//Если фигура ниже горизонта
		HideCrops(GetX(), GetY(), Width, Height);	//Закрашиваем поле

}	//end Figure::Hide()

//--------------------------------------------------------------
//переместить фигуру
void Figure::MoveTo(int NewX, int NewY)	{
	Hide();		//сделать фигуру невидимой
	SetX(NewX);	//поменять ее координаты
	SetY(NewY);
	Show();		//показать фигуру на новом месте

}	//end Figure::MoveTo()

/*------------------------------------*/
/* Вспомогательные функции для Hide() */
/*------------------------------------*/

//--------------------------------------------------------------
//Закрасить небо
void HideSky(int X, int Y, int Width, int Height) {
	HBRUSH brush = CreateSolidBrush(SkyColor);		//ручка цвета неба
	HPEN pen = CreatePen(PS_SOLID, 1, SkyColor);		//кисть цвета неба
	SelectObject(hdc, brush);	//выбираем заданную кисть
	SelectObject(hdc, pen);		//выбираем заданную ручку

	//Закрашиваем фигуру
	Rectangle(hdc, X - Width, Y - Height, X + Width, Y + Height);
	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

	HideLighttoDarkSky(X, Y, Width, Height);	//Закрашиваем светлую часть неба

}	//end HideSky()

//--------------------------------------------------------------
//Закрасить светлое небо
void HideLighttoDarkSky(int X, int Y, int Width, int Height) {
	HBRUSH brush = CreateSolidBrush(LightSkyColor);		//кисть цвета светлого неба
	HPEN pen = CreatePen(PS_SOLID, 1, LightSkyColor);	//ручка цвета светлого неба
	SelectObject(hdc, brush);	//выбираем заданную кисть
	SelectObject(hdc, pen);		//выбираем заданную ручку

	//Закрашиваем светлое небо
	if (LightSkyLevel <= Y + Height)
		Rectangle(hdc, X - Width, LightSkyLevel, X + Width, Y + Height);

	//Обновляем градиент на небе
	if (LightSkyLevel > Y - Height) {
		Rectangle(hdc, X - Width, LightSkyLevel - 3, X + Width, LightSkyLevel - 15);
		Rectangle(hdc, X - Width, LightSkyLevel - 19, X + Width, LightSkyLevel - 29);
		Rectangle(hdc, X - Width, LightSkyLevel - 34, X + Width, LightSkyLevel - 39);
		Rectangle(hdc, X - Width, LightSkyLevel - 45, X + Width, LightSkyLevel - 50);
		Rectangle(hdc, X - Width, LightSkyLevel - 60, X + Width, LightSkyLevel - 64);
		Rectangle(hdc, X - Width, LightSkyLevel - 77, X + Width, LightSkyLevel - 80);
	}

	DeleteObject(brush);		//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

}	//end HideLighttoDarkSky()

//--------------------------------------------------------------
//Закрасить поле
void HideCrops(int X, int Y, int Width, int Height) {
	SetBkMode(hdc, OPAQUE);			//фон кисти не прозрачный
	SetBkColor(hdc, WheatColor);	//фон кисти цвета пшеницы
	//Кисть в полоску цвета темной пшеницы
	HBRUSH brush = CreateHatchBrush(HS_BDIAGONAL, DarkWheatColor);
	//Ручка цвета пшеницы
	HPEN pen = CreatePen(PS_SOLID, 1, WheatColor);
	SelectObject(hdc, brush);	//выбираем заданную кисть
	SelectObject(hdc, pen);		//выбираем заданную ручку

	int UpperLevel = max(Y - Height, WheatLevel);
	//Закрашиваем поле
	Rectangle(hdc, X - Width, UpperLevel, X + Width, Y + Height);

	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

}	//end HideCrops()
