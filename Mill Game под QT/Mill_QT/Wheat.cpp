#include "Wheat.h"

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Wheat             */
/*----------------------------------------*/

//--------------------------------------------------------------
//конструктор
Wheat::Wheat(QGraphicsObject *parent)
    : QGraphicsObject(parent) {

    WheatImg = new QPixmap(":/recources/images/wheat.png");
}

//--------------------------------------------------------------
//Показать стог сена
void Wheat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QRectF RectF = boundingRect();
    painter->setBrush(QBrush(*WheatImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(RectF);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}   //end Wheat::paint()

//--------------------------------------------------------------
//прямоугольник, в кот-й заключена фигура
QRectF Wheat::boundingRect() const  {
    return QRectF(0, 0, WheatImg->width(), WheatImg->height());   /// Ограничиваем область, в которой лежит треугольник

}   //end Figure::boundingRect()

Wheat::~Wheat(){

}
