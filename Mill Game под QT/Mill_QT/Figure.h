#pragma once
#ifndef FIGURE_H
#define FIGURE_H
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QPainter>
#include "Utilities.h"

/*-----------------------  Абстрактный класс ФИГУРА ------------------------*/
class Figure : public QGraphicsObject {
     Q_OBJECT
protected:
    int index;                  //Индекс фигуры
    int Width,                  //Общая ширина фигуры
        Height;                 //Общая высота фигуры

    void CheckCollisions();     //Проверка столкновений объектов

public:
     Figure(QGraphicsObject *parent = 0, int startX = 400, int startY = 300);		//конструктор класса
    virtual ~Figure();


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

    QRectF boundingRect() const;
    virtual int GetIndex();
    virtual int ReturnHeight();
    virtual int ReturnWidth();

public slots:
    void slotMoveGameObject(); // Слот, который отвечает за обработку перемещения

signals:
    void signalFoundObstacle(QGraphicsItem *obstacle);
    void signalChangeMill(int index);


};
#endif
