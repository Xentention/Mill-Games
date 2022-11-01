/**************************************************************************
*                                ЛР4 ООП                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ЛР4. ООП. Мельница. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : Игра с мельницей.cpp	                                  *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : К.В.Тимошенко, М3О-211Б-20		                      *
* Modified By   :														  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : Функции управления мельницей  					      *
*																		  *
**************************************************************************/

#include "Utilities.h"		//Заголовочный файл с вспомогательными объявлениями
#include "Mills.h"			//Заголовочный файл иерархии мельниц	
#include "Obstacles.h"		//Заголовочный файл иерархии препятствий

//Прототипы используемых функций
void UIFigure(Mill** Mills, Obstacles** Obstacles);			//Управление мельницей
void ServiceInteraction(int& index, Obstacles& Service);	//Взаимодействие с рем. станцией
void InsidePond(int& index, Obstacles& Pond);				//Находимся внутри пруда
void OutsidePond(int& index, Obstacles& Pond);				//Находимся вне пруда


/*-------------------  Управление мельницей ---------------------*/
void UIFigure(Mill** Mills, Obstacles** Obstacles) {
	int NewX, NewY;			//новые координаты фигуры
	int Step = 70;			//Шаг перемещения
	int index = indxMill;	//Начинаем с обычной мельницы

	//получаем начальное положение фигуры
	NewX = Mills[index]->GetX();    
	NewY = Mills[index]->GetY();

	while (true) {	//бесконечный цикл буксировки фигуры
		if (KEY_DOWN(VK_ESCAPE))	//esc
			break;					//конец работы

		//направление движения объекта
		if (KEY_DOWN(VK_LEFT))		//стрелка влево 
			NewX -= Step;

		if (KEY_DOWN(VK_RIGHT))		//стрелка вправо
			NewX += Step;

		if (KEY_DOWN(VK_DOWN))		//стрелка вниз
			NewY += Step;

		if (KEY_DOWN(VK_UP))		//стрелка вверх
			NewY -= Step;

		
		Mills[index]->Hide();
		//Взаимодействие с прудом
		if (Obstacles[indxPond]->ObjectNearby(*Mills[index]))
				InsidePond(index, *Obstacles[indxPond]);
		//На выход из пруда проверяем только водяные мельницы
		else if (index == indxWMill || index == indxWRMill)
			OutsidePond(index, *Obstacles[indxPond]);

		Mills[index]->Hide();
		//Взаимодействие с рем. станцией
		if (Obstacles[indxService]->ObjectNearby(*Mills[index]))
			ServiceInteraction(index, *Obstacles[indxService]);

		Mills[index]->MoveTo(NewX, NewY);	//Обновляем мельницу
		//проверяем состояние 5 раз в сек
		Sleep(200);

	}   //end while

}	//end UIFigure()

/*-------------------  Взаимодействие со станцией ---------------------*/
//Добавляет или убирает крышу
void ServiceInteraction(int& index, Obstacles& Service) {
	//Изменяем индекс текущей мельницы
	index = TransitionMatrix[index][ServiceIsNearby];

	//Перемещаем станцию в случайное место на поле
	Service.MoveTo(rand() % FieldRight, rand() % (FieldBottom - WheatLevel) + WheatLevel);

}	//end ServiceInteraction()

/*-------------------  Находимся внутри пруда ---------------------*/
void InsidePond(int& index, Obstacles& Pond) {
	//Изменяем индекс текущей мельницы на водяную
	index = TransitionMatrix[index][PondIsNearby];
	Pond.Show();

}	//end InsidePond()

/*-------------------  Находимся вне пруда ---------------------*/
void OutsidePond(int& index, Obstacles& Pond) {
	//Изменяем индекс текущей водяной мельницы на обычную
	index = TransitionMatrix[index][NothingNearby];
	Pond.Show();

}	//end OutsidePond()