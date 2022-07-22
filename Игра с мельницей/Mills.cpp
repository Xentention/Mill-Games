/**************************************************************************
*                                ЛР4 ООП                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ЛР4. ООП. Мельница. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : Mills.cpp	                                              *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : К.В.Тимошенко, М3О-211Б-20		                      *
* Modified By   :														  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : Методы класса Mill и его потомков			              *
*																		  *
**************************************************************************/

#include "Utilities.h"   // Заголовочный файл с вспомогательными объявлениями
#include "Mills.h"

extern HDC hdc;      // объявим  контекст устройства

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Mill              */
/*----------------------------------------*/

 //--------------------------------------------------------------
//конструктор
Mill::Mill(int InitX, int InitY,
		   int InitRadius, int InitHeight,
		   int InitWidth, int InitWheatAmount) : Figure(InitX, InitY) {
	RotorRadius = InitRadius;
	Height = InitHeight;
	Width = InitWidth;

}	//end Mill::Mill()

//--------------------------------------------------------------
//Показать мельницу
void Mill::Show() {
	Visible = true;		//Отметить, как видимую
	DrawBuilding();		//Показать здание
	DrawStorage();		//Показать кладовую
	DrawRotor();		//Показать лопасти
	
}	//end Mill::Show()

//--------------------------------------------------------------
//Показать здание мельницы
void Mill::DrawBuilding() {
	//Зададим ручку и кисть цвета камня
	HBRUSH brush = CreateSolidBrush(MillColor);
	HPEN pen = CreatePen(PS_SOLID, 1, MillColor);
	SelectObject(hdc, brush);	//выбираем заданную кисть
	SelectObject(hdc, pen);		//выбираем заданную ручку

	int X = GetX(), Y = GetY();
	//Рисуем здание мельницы
	Rectangle(hdc, X - Width / 2, Y - Height / 4, X + Width / 2, Y + 3 * Height / 4);

	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

}	//end Mill::DrawBuilding()

//--------------------------------------------------------------
//Показать лопасти мельницы
void Mill::DrawRotor() {
	int X = GetX(), Y = GetY();
	//зададим толщину оси, лопастей и каркаса лопастей
	int HubRad = RotorRadius / 20, BladeWidth = RotorRadius / 5, BladeShaft = RotorRadius / 40;
	//Зададим ручку и кисть цвета дерева
	HBRUSH brush = CreateSolidBrush(WindshaftColor);
	HPEN pen = CreatePen(PS_INSIDEFRAME, 1, WindshaftColor);
	SelectObject(hdc, brush);	//выбираем заданную кисть
	SelectObject(hdc, pen);		//выбираем заданную ручку

	//Рисуем узел вращения
	Ellipse(hdc, X - HubRad, Y - HubRad, X + HubRad, Y + HubRad);

	//Рисуем крестовину
	Rectangle(hdc, X, Y, X - RotorRadius , Y - BladeShaft);
	Rectangle(hdc, X, Y, X + RotorRadius , Y + BladeShaft);
	Rectangle(hdc, X, Y, X + BladeShaft, Y - RotorRadius );
	Rectangle(hdc, X, Y, X - BladeShaft, Y + RotorRadius );
	DeleteObject(brush);	//Удаляем более ненужную кисть

	//Задаем кисть в белую сетку с прозрачным фоном
	SetBkMode(hdc, TRANSPARENT);
	brush = CreateHatchBrush(HS_DIAGCROSS, RGB(255, 255, 255));
	SelectObject(hdc, brush);	//выбираем заданную кисть

	//Рисуем лопасти
	Rectangle(hdc, X - RotorRadius , Y - 2 * BladeShaft, X - RotorRadius / 3, Y + BladeWidth - BladeShaft);
	Rectangle(hdc, X + RotorRadius / 3, Y - BladeWidth + BladeShaft, X + RotorRadius , Y + 2 * BladeShaft);
	Rectangle(hdc, X - BladeWidth + BladeShaft, Y - RotorRadius , X + 2 * BladeShaft, Y - RotorRadius / 3);
	Rectangle(hdc, X - 2 * BladeShaft, Y + RotorRadius , X + BladeWidth - BladeShaft, Y + RotorRadius / 3);

	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

}	//end Mill::DrawRotor()

//--------------------------------------------------------------
//Показать склад
void Mill::DrawStorage() {
	int X = GetX(), Y = GetY();
	SetBkMode(hdc, OPAQUE);				//фон кисти не прозрачный
	SetBkColor(hdc, WheatColor);		//фон кисти цвета крыши

	//Зададим ручку и кисть цвета пшеницы
	HBRUSH brush = CreateHatchBrush(HS_DIAGCROSS, DarkWheatColor);
	HPEN pen = CreatePen(PS_INSIDEFRAME, 3, DarkWheatColor);
	SelectObject(hdc, brush);			//выбираем заданную кисть
	SelectObject(hdc, pen);				//выбираем заданную ручку

	Ellipse(hdc, X - Width, Y + 3 * Height / 4, X - Width / 2, Y + (3 * Height / 4) - 2 * RotorRadius / 5);

	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

	//Зададим ручку и кисть цвета дерева
	brush = CreateSolidBrush(WindshaftColor);
	pen = CreatePen(PS_SOLID, 1, WindshaftColor);
	SelectObject(hdc, brush);	//выбираем заданную кисть
	SelectObject(hdc, pen);		//выбираем заданную ручку

	//Нарисуем склад
	Rectangle(hdc, X - Width, Y + 3 * Height / 4, X - Width / 2, Y + (3 * Height / 4) - RotorRadius / 5);
	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

}	//end Mill::DrawStorage()

//--------------------------------------------------------------
//Вернуть высоту фигуры
int Mill::ReturnMaxHeight()	{	return max(RotorRadius, Height);	}	

//--------------------------------------------------------------
//Вернуть ширину фигуры
int Mill::ReturnMaxWidth()	{	return max(RotorRadius, Width);		}	

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА RoofedMill        */
/*----------------------------------------*/

//--------------------------------------------------------------
RoofedMill::RoofedMill(int InitX, int InitY) : Mill(InitX, InitY) {
	//формально пустое тело

}	//end RoofedMill::RoofedMill()

//--------------------------------------------------------------
//Показать мельницу
void RoofedMill::Show() {
	DrawRoof();						//Нарисовать крышу
	Mill::Show();					//Нарисовать мельницу методом предка

}	//end RoofedMill::Show()

//--------------------------------------------------------------
//Нарисовать крышу
void RoofedMill::DrawRoof()	{
	int X = GetX(), Y = GetY();
	SetBkMode(hdc, OPAQUE);			//фон кисти не прозрачный
	SetBkColor(hdc, RoofColor);		//фон кисти цвета крыши

	//Зададим ручку и кисть цвета крыши
	HBRUSH brush = CreateHatchBrush(HS_HORIZONTAL, RGB(131, 76, 87));
	HPEN pen = CreatePen(PS_INSIDEFRAME, 1, RoofColor);
	SelectObject(hdc, brush);		//выбираем заданную кисть
	SelectObject(hdc, pen);			//выбираем заданную ручку

	POINT roof[3];					//Задаем крышу треугольной
	roof[0].x = X - Width / 2;		//координаты вершин
	roof[0].y = Y - Height / 4;		//треугольной крыши
	roof[1].x = X + Width / 2;
	roof[1].y = Y - Height / 4;
	roof[2].x = X;
	roof[2].y = Y - Height / 2;
	Polygon(hdc, roof, 3);	//Рисуем треугольник

	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

}	//end RoofedMill::DrawRoof()

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА WaterMill         */
/*----------------------------------------*/

//конструктор
WaterMill::WaterMill(int InitX, int InitY) : Mill(InitX, InitY) {
	Width = Height;		//Здание квадратное

}	//end WaterMill::WaterMill

//--------------------------------------------------------------
//Вернуть высоту фигуры
int WaterMill::ReturnMaxHeight() {	return max(RotorRadius, 7 * Height / 8);	}	

//--------------------------------------------------------------
//Вернуть ширину фигуры
int WaterMill::ReturnMaxWidth() {	return max(RotorRadius, Width);		}

//--------------------------------------------------------------
//Показать мельницу
void WaterMill::Show() {
	Visible = true;		//Отметить, как видимую
	DrawBuilding();		//Показать здание
	DrawStorage();		//Показать кладовую
	DrawRotor();		//Показать лопасти

}	//end WaterMill::Show()

//--------------------------------------------------------------
//Показать здание мельницы
void WaterMill::DrawBuilding() {
	//Зададим ручку и кисть цвета камня
	HBRUSH brush = CreateSolidBrush(MillColor);
	HPEN pen = CreatePen(PS_SOLID, 1, MillColor);
	SelectObject(hdc, brush);	//выбираем заданную кисть
	SelectObject(hdc, pen);		//выбираем заданную ручку

	int X = GetX(), Y = GetY();
	//Рисуем здание мельницы
	Rectangle(hdc, X - Width / 2, Y - Height / 2, X + Width / 2, Y + Height / 2);

	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

}	//end WaterMill::DrawBuilding()

//--------------------------------------------------------------
//Показать лопасти мельницы
void WaterMill::DrawRotor() {
	int X = GetX(), Y = GetY();
	//зададим толщину оси, лопастей и длину каркаса лопастей
	int HubRad = RotorRadius / 20, BladeWidth = RotorRadius / 10, BladeShaft = Height / 2;
	//Зададим ручку и кисть цвета дерева
	HPEN pen = CreatePen(PS_INSIDEFRAME, BladeWidth, WindshaftColor);
	SelectObject(hdc, pen);		//выбираем заданную ручку
	HBRUSH brush = (HBRUSH)::GetStockObject(NULL_BRUSH);
	SelectObject(hdc, brush);	//выбираем заданную кисть

	//Рисуем лопасти
	Ellipse(hdc, X - BladeShaft, Y - BladeShaft, X + BladeShaft, Y + BladeShaft);
	//Рисуем узел вращения
	Ellipse(hdc, X - BladeWidth, Y - BladeWidth, X + BladeWidth, Y + BladeWidth);
	DeleteObject(brush);	//Удаляем больше ненужную кисть

	brush = CreateSolidBrush(WindshaftColor);
	SelectObject(hdc, brush);	//выбираем заданную кисть
	//Рисуем крестовину
	Rectangle(hdc, X, Y, X - BladeShaft - HubRad, Y - HubRad);
	Rectangle(hdc, X, Y, X + BladeShaft + HubRad, Y + HubRad);
	Rectangle(hdc, X, Y, X + HubRad, Y - BladeShaft - HubRad);
	Rectangle(hdc, X, Y, X - HubRad, Y + BladeShaft + HubRad);
	DeleteObject(brush);	//Удаляем больше ненужную кисть

	DeleteObject(pen);		//и ручку

}	//end WaterMill::DrawRotor()

//--------------------------------------------------------------
//Показать склад
void WaterMill::DrawStorage() {
	int X = GetX(), Y = GetY();
	SetBkMode(hdc, OPAQUE);				//фон кисти не прозрачный
	SetBkColor(hdc, WheatColor);		//фон кисти цвета крыши

	//Зададим ручку и кисть цвета пшеницы
	HBRUSH brush = CreateHatchBrush(HS_DIAGCROSS, DarkWheatColor);
	HPEN pen = CreatePen(PS_INSIDEFRAME, 3, DarkWheatColor);
	SelectObject(hdc, brush);			//выбираем заданную кисть
	SelectObject(hdc, pen);				//выбираем заданную ручку

	Ellipse(hdc, X - Width, Y + (Height / 2), X - Width / 2, Y + (Height / 2) - 2 * RotorRadius / 5);

	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

	//Зададим ручку и кисть цвета дерева
	brush = CreateSolidBrush(WindshaftColor);
	pen = CreatePen(PS_SOLID, 1, WindshaftColor);
	SelectObject(hdc, brush);	//выбираем заданную кисть
	SelectObject(hdc, pen);		//выбираем заданную ручку

	//Нарисуем склад
	Rectangle(hdc, X - Width, Y + (Height / 2), X - Width / 2, Y + (Height / 2) - RotorRadius / 5);
	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

}	//end WaterMill::DrawStorage()

/*----------------------------------------------*/
/*        МЕТОДЫ КЛАССА WaterRoofedMill         */
/*----------------------------------------------*/

WaterRoofedMill::WaterRoofedMill(int InitX, int InitY) : WaterMill(InitX, InitY) {
	//формально пустое тело

}	//end WaterRoofedMill::WaterRoofedMill()

//--------------------------------------------------------------
//Показать мельницу
void WaterRoofedMill::Show() {
	DrawRoof();				//Рисуем крышу
	WaterMill::Show();		//Рисуем мельницу из предка

}	//end WaterRoofedMill::Show()

//--------------------------------------------------------------
//Нарисовать крышу
void WaterRoofedMill::DrawRoof()	{
	int X = GetX(), Y = GetY();
	SetBkMode(hdc, OPAQUE);			//фон кисти не прозрачный
	SetBkColor(hdc, RoofColor);		//фон кисти цвета крыши

	//Зададим ручку и кисть цвета крыши
	HBRUSH brush = CreateHatchBrush(HS_HORIZONTAL, RGB(131, 76, 87));
	HPEN pen = CreatePen(PS_INSIDEFRAME, 3, RoofColor);
	SelectObject(hdc, brush);		//выбираем заданную кисть
	SelectObject(hdc, pen);			//выбираем заданную ручку

	POINT roof[3];					//Задаем крышу треугольной
	roof[0].x = X - Width / 2;		//координаты вершин
	roof[0].y = Y - Height / 2;		//треугольной крыши
	roof[1].x = X + Width / 2;
	roof[1].y = Y - Height / 2;
	roof[2].x = X;
	roof[2].y = Y - 3*Height/4;
	Polygon(hdc, roof, 3);	//Рисуем треугольник

	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

}	//end WaterRoofedMill::DrawRoof()