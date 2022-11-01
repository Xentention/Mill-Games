/**************************************************************************
*                                ЛР4 ООП                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ЛР4. ООП. Мельница. 					 *
* Project Type  : Win32 Console application                               *
* File Name     : Utilities.h	                                          *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : К.В.Тимошенко, М3О-211Б-20		                 *
* Modified By   :							 *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : Вспомогательные объявления 				  *
*									  *
**************************************************************************/

#pragma once

#include <Windows.h>

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*-----------------------  основные директивы  -------------------------*/
#define FieldBottom 720						//Нижняя граница поля
#define FieldRight 1280						//Правая граница поля
#define WheatLevel 3*FieldBottom/5			//Уровень горизонта
#define LightSkyLevel 3*WheatLevel/4		//Уровень светлого неба

#define SkyColor RGB(129, 184, 202)			//Цвет неба
#define LightSkyColor RGB(170, 229, 240)	//Цвет более светлого неба
#define WheatColor RGB(255, 178, 78)		//Цвет пшеницы
#define DarkWheatColor RGB(221, 115, 55)	//Цвет пшеницы темнее
#define PondColor RGB(90, 188, 216)			//Цвет пруда

#define MillColor RGB(174, 156, 153)		//Цвет каменной части мельницы
#define WindshaftColor RGB(142,65, 61)		//Цвет деревянной части мельницы
#define RoofColor RGB(171, 93, 93)			//Цвет крыши мельницы

#define PondIsNearby 1						//Код того, что рядом пруд
#define ServiceIsNearby 2					//Код того, что рядом рем. станция
#define NothingNearby 0						//Код того, что ничего рядом нет

#define indxMill 0							//Индекс обычной мельницы
#define indxRMill 1							//Индекс мельницы с крышей
#define indxWMill 2							//Индекс водяной мельницы
#define indxWRMill 3						//Индекс водяной мельницы с крышей

#define indxPond 0							//Индекс пруда
#define indxService 1						//Индекс рем. станции

const int NumofMills = 4;		//мельница, мельница с крышей, водяная мельница, водяная мельница с крышей
const int NumofObstacles = 2;	//пруд, ремонтная станция
const int NumofCollisions = 3;	//вне пруда, внутри пруда, столкнулись с рем. станцией
const int TransitionMatrix[NumofMills][NumofCollisions] = { {indxMill, indxWMill, indxRMill},
							     {indxRMill, indxWRMill, indxMill},
							     {indxMill, indxWMill, indxWRMill},
							     {indxRMill, indxWRMill, indxWMill} };
