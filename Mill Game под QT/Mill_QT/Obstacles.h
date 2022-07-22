#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "Utilities.h"
#include "Figure.h"


/*-----------------------  Абстрактный класс ПРЕПЯТСТВИЯ -------------------------*/
class Obstacle : public Figure {
    ///Q_OBJECT
public:
    Obstacle(int StartX, int StartY);
    virtual void UpdateState() = 0;     //Обновить состояние объекта

    virtual ~Obstacle();

};

/*-----------------------  Класс РЕМОНТНАЯ СТАНЦИЯ -------------------------------*/
class ServiceStation : public Obstacle {
    ///Q_OBJECT
private:
    QPixmap *ServiceStationImg;

public:
    ServiceStation(int StartX, int StartY);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void UpdateState();

    virtual ~ServiceStation();

};

/*-----------------------  Класс ПРУД ----------------------------------*/
class Pond : public Obstacle {
    ///Q_OBJECT
private:
    QPixmap *PondImg;
public:
    Pond(int StartX, int StartY);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void UpdateState();

    virtual ~Pond();
};

#endif // OBSTACLES_H
