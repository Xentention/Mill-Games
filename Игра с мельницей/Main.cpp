/**************************************************************************
*                                ЛР3 ООП                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ЛР3. ООП. Мельница. 									                  *
* Project Type  : Win32 Console application                               *
* File Name     : Main.cpp	                                              *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : К.В.Тимошенко, М3О-211Б-20							                *
* Comment(s)    : Основная программа							                        *
*																		                                      *
**************************************************************************/

#include <iostream>
#include <Windows.h>
#include "Utilities.h"	  	//Заголовочный файл с вспомогательными объявлениями
#include "Mills.h"			    //Заголочный файл с иерархией мельниц
#include "Obstacles.h"	  	//Заголовочный файл с иерархией препятствий

using namespace std;

void Information();	    		//информация о работе с прогаммой
void EmptyField();	    		//Нарисовать чистый пейзаж
void ClearAllSky();		    	//Чистое небо
void AllLighttoDarkSky(); 	//Переход темного неба в светлое
void ClearAllCrops();		    //Чистое поле

//Управление мельницей
void UIFigure(Mill** Mills, Obstacle** Obstacles);

HDC hdc;     //Объявим  контекст устройства

/*-----------------------------------------------------------------*/
/*             О С Н О В Н А Я		П Р О Г Р А М М А                */
/*-----------------------------------------------------------------*/
int main() {
	HWND hwnd = GetConsoleWindow();

	//если дескриптор существует
	if (hwnd != NULL) {

		hdc = GetWindowDC(hwnd);
		//если контекст существует - можем работать
		if (hdc != 0)
		{
			system("color F0");			  //белый фон, черный текст
			setlocale(LC_ALL, "rus");	//русский язык вывода

			Information();				//вывод информации
			system("cls");				//очистка экрана консоли
			EmptyField();			  	//рисуем поле

			int x0 = 400, y0 = 350;					      	 //Стартовые координаты мельниц

			//Объявление объектов мельниц
			Mill MainMill(x0, y0);						       //Мельница 
			RoofedMill MainRMill(x0, y0);				     //Мельница с крышей
			WaterMill MainWMill(x0, y0);				     //Водяная мельница 
			WaterRoofedMill MainWRMill(x0, y0);			 //Водяная мельница с крышей

			Mill* Mills[4];
			Mills[indxMill] = &MainMill;
			Mills[indxRMill] = &MainRMill;
			Mills[indxWMill] = &MainWMill;
			Mills[indxWRMill] = &MainWRMill;

			int pondx = 900, pondy = 600;				 //Стартовые координаты препятствий
			int servicex = 100, servicey = 500;

			//Объявление объектов препятствий
			Pond Pond(pondx, pondy);
			ServiceStation Service(servicex, servicey);

			Obstacle* Obstacles[2];
			Obstacles[indxPond] = &Pond;
			Obstacles[indxService] = &Service;

			Obstacles[indxPond]->Show();
			Obstacles[indxService]->Show();
			
			UIFigure(Mills, Obstacles);
		}
	}
	return 0;

}	//конец	main()

//Рисуем пустой пейзаж
void EmptyField() {
	ClearAllSky();		//небо
	ClearAllCrops();	//поле

}	//end EmptyField()

//Рисуем пустое небо
void ClearAllSky() {
	//кисть и перо цвета неба
	HBRUSH brush = CreateSolidBrush(SkyColor);
	HPEN pen = CreatePen(PS_SOLID, 1, SkyColor);
	SelectObject(hdc, brush);	    //выбираем заданную кисть
	SelectObject(hdc, pen);		    //выбираем заданную ручку
	//закрашиваем небо
	Rectangle(hdc, 0, 0, FieldRight, FieldBottom);
	DeleteObject(brush);      	//Удаляем больше ненужную кисть
	DeleteObject(pen);	      	//и ручку
	AllLighttoDarkSky();	      //Рисуем светлое небо

}	

//Рисуем светлое небо
void AllLighttoDarkSky() {
	//кисть и перо цвета светлого неба
	HBRUSH brush = CreateSolidBrush(LightSkyColor);
	HPEN pen = CreatePen(PS_SOLID, 1, LightSkyColor);
	SelectObject(hdc, brush);   	//выбираем заданную кисть
	SelectObject(hdc, pen);	    	//выбираем заданную ручку

	//Рисуем светлую часть неба
	Rectangle(hdc, 0, LightSkyLevel, FieldRight, FieldBottom);
	//Рисуем переход на небе
	Rectangle(hdc, 0, LightSkyLevel - 3, FieldRight, LightSkyLevel - 15);
	Rectangle(hdc, 0, LightSkyLevel - 19, FieldRight, LightSkyLevel - 29);
	Rectangle(hdc, 0, LightSkyLevel - 34, FieldRight, LightSkyLevel - 39);
	Rectangle(hdc, 0, LightSkyLevel - 45, FieldRight, LightSkyLevel - 50);
	Rectangle(hdc, 0, LightSkyLevel - 60, FieldRight, LightSkyLevel - 64);
	Rectangle(hdc, 0, LightSkyLevel - 77, FieldRight, LightSkyLevel - 80);

	DeleteObject(brush);	  //Удаляем больше ненужную кисть
	DeleteObject(pen);		  //и ручку

}

//Рисуем поле
void ClearAllCrops() {
	SetBkMode(hdc, OPAQUE);		    	//фон кисти не прозрачный
	SetBkColor(hdc, WheatColor);  	//фон кисти цвета пшеницы

	//Кисть в полоску цвета темной пшеницы
	HBRUSH brush = CreateHatchBrush(HS_BDIAGONAL, DarkWheatColor);

	//Ручка цвета пшеницы
	HPEN pen = CreatePen(PS_SOLID, 1, WheatColor);
	SelectObject(hdc, brush);		//выбираем заданную кисть
	SelectObject(hdc, pen);			//выбираем заданную ручку

	//Закрашиваем поле
	Rectangle(hdc, 0, WheatLevel, FieldRight, FieldBottom);

	DeleteObject(brush);	//Удаляем больше ненужную кисть
	DeleteObject(pen);		//и ручку

}	

//Вывод информации о  работе с программой
void Information() {
	cout << "В программе присутствуют 3 объекта:\n"
		   << "Мельница, станция ремонта и озеро.\n"
		   << "Станция добавляет или удаляет крышу у мельницы,\n"
	 	   << "а в зоне озера мельница становится водяной.\n";
	cout << "\nМельница перетаскивается при помощи стрелок, Esc - выход из программы.\n";
	cout << "\nНажмите Enter, чтобы продолжить:";

	while(true)
	if (KEY_DOWN(VK_RETURN))
		break;

}	
