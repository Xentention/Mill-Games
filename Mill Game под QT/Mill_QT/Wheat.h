#ifndef WHEAT_H
#define WHEAT_H
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QPainter>
#include "Utilities.h"

/*-----------------------  Класс ПШЕНО ----------------------------------*/
class Wheat :  public QGraphicsObject {
    Q_OBJECT
public:
    Wheat(QGraphicsObject *parent = nullptr);
    ~Wheat();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
     QPixmap *WheatImg;
};

#endif // WHEAT_H
