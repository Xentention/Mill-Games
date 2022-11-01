/**************************************************************************
*                                ��4 ���                                  *
*-------------------------------------------------------------------------*
*                                                                         *
* Project Name  : ��4. ���. ��������. 									  *
* Project Type  : Win32 Console application                               *
* File Name     : Utilities.h	                                          *
* Language      : Visual C++           MS VS 2022                         *
* Programmer(s) : �.�.���������, �3�-211�-20		                      *
* Modified By   :														  *
* Created       : 28 / 03 / 2022                                          *
* Last Revision : 01 / 05 / 2022                                          *
* Comment(s)    : ��������������� ���������� 						      *
*																		  *
**************************************************************************/

#pragma once

#include <Windows.h>

//������ ��� ����������� ���� ������� �������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

/*-----------------------  �������� ���������  -------------------------*/
#define FieldBottom 720						//������ ������� ����
#define FieldRight 1280						//������ ������� ����
#define WheatLevel 3*FieldBottom/5			//������� ���������
#define LightSkyLevel 3*WheatLevel/4		//������� �������� ����

#define SkyColor RGB(129, 184, 202)			//���� ����
#define LightSkyColor RGB(170, 229, 240)	//���� ����� �������� ����
#define WheatColor RGB(255, 178, 78)		//���� �������
#define DarkWheatColor RGB(221, 115, 55)	//���� ������� ������
#define PondColor RGB(90, 188, 216)			//���� �����

#define MillColor RGB(174, 156, 153)		//���� �������� ����� ��������
#define WindshaftColor RGB(142,65, 61)		//���� ���������� ����� ��������
#define RoofColor RGB(171, 93, 93)			//���� ����� ��������

#define PondIsNearby 1						//��� ����, ��� ����� ����
#define ServiceIsNearby 2					//��� ����, ��� ����� ���. �������
#define NothingNearby 0						//��� ����, ��� ������ ����� ���

#define indxMill 0							//������ ������� ��������
#define indxRMill 1							//������ �������� � ������
#define indxWMill 2							//������ ������� ��������
#define indxWRMill 3						//������ ������� �������� � ������

#define indxPond 0							//������ �����
#define indxService 1						//������ ���. �������

const int NumofMills = 4;		//��������, �������� � ������, ������� ��������, ������� �������� � ������
const int NumofObstacles = 2;	//����, ��������� �������
const int NumofCollisions = 3;	//��� �����, ������ �����, ����������� � ���. ��������
const int TransitionMatrix[NumofMills][NumofCollisions] = { {indxMill, indxWMill, indxRMill},
															{indxRMill, indxWRMill, indxMill},
															{indxMill, indxWMill, indxWRMill},
															{indxRMill, indxWRMill, indxWMill} };