#ifndef UTILITIES_H
#define UTILITIES_H


#pragma once

#include <Windows.h>
#include <vector>

//макрос для определения кода нажатой клавиши
//#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*-----------------------  основные директивы  -------------------------*/
#define FieldBottom 720						//Нижняя граница поля
#define FieldRight 1080						//Правая граница поля

#define PondIsNearby 1						//Код того, что рядом пруд
#define ServiceIsNearby 2					//Код того, что рядом рем. станция
#define NothingNearby 0						//Код того, что ничего рядом нет

#define indxMill 0							//Индекс обычной мельницы
#define indxRMill 1							//Индекс мельницы с крышей
#define indxWMill 2							//Индекс водяной мельницы
#define indxRWMill 3						//Индекс водяной мельницы с крышей

#define indxPond 0							//Индекс пруда
#define indxService 1						//Индекс рем. станции

const int NumofMills = 4;		//мельница, мельница с крышей, водяная мельница, водяная мельница с крышей
const int NumofObstacles = 2;	//пруд, ремонтная станция
const int NumofCollisions = 3;	//вне пруда, внутри пруда, столкнулись с рем. станцией
const int TransitionMatrix[NumofMills][NumofCollisions] = { {indxMill, indxWMill, indxRMill},
                                                            {indxRMill, indxRWMill, indxMill},
                                                            {indxMill, indxWMill, indxRWMill},
                                                            {indxRMill, indxRWMill, indxWMill} };
using namespace std;

#endif // UTILITIES_H
