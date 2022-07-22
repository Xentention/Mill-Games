#pragma once
#ifndef MILL_H
#define MILL_H
#include "Utilities.h"
#include "Figure.h"
#include <QPixmap>

/*-----------------------  Класс ИНТЕРФЕЙС МЕЛЬНИЦЫ ------------------------*/
class IMill {
protected:
    //необходимые для мельницы методы
    virtual void DrawBuilding(QPainter *painter) = 0;
    virtual void DrawRotor(QPainter *painter) = 0;

};

/*-----------------------  Класс МЕЛЬНИЦА ----------------------------------*/
class Mill : public Figure, public IMill {
   ///Q_OBJECT
private:
    QPixmap *MillBuildingImg;
    QPixmap *MillRotorImg;

protected:
    void DrawBuilding(QPainter *painter);
    void DrawRotor(QPainter *painter);


public:
    //конструктор с параметрами по умолчанию
    Mill(int startX, int startY);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual ~Mill();

};

/*-----------------------  Класс МЕЛЬНИЦА С КРЫШЕЙ ----------------------------------*/
class RoofedMill : public Mill {
    ///Q_OBJECT
private:
    QPixmap *MillBuildingImg;
    QPixmap *MillRotorImg;
    QPixmap *MillRoofImg;

protected:
    void DrawBuilding(QPainter *painter);
    void DrawRotor(QPainter *painter);
    void DrawRoof(QPainter *painter);

public:
    //конструктор с параметрами по умолчанию
    RoofedMill(int startX, int startY);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual ~RoofedMill();

};

/*-----------------------  Класс ВОДЯНАЯ МЕЛЬНИЦА ----------------------------------*/
class WaterMill : public Mill {
    ///Q_OBJECT
private:
    QPixmap *MillBuildingImg;
    QPixmap *MillRotorImg;

protected:
    void DrawBuilding(QPainter *painter);
    void DrawRotor(QPainter *painter);


public:
    //конструктор с параметрами по умолчанию
    WaterMill(int startX, int startY);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual ~WaterMill();

};

/*-----------------------  Класс ВОДЯНАЯ МЕЛЬНИЦА С КРЫШЕЙ ----------------------------------*/
class RoofedWaterMill : public WaterMill {
    ///Q_OBJECT
private:
    QPixmap *MillBuildingImg;
    QPixmap *MillRotorImg;
    QPixmap *MillRoofImg;

protected:
    void DrawBuilding(QPainter *painter);
    void DrawRotor(QPainter *painter);
    void DrawRoof(QPainter *painter);


public:
    //конструктор с параметрами по умолчанию
    RoofedWaterMill(int startX, int startY);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual ~RoofedWaterMill();

};

#endif // MILL_H

