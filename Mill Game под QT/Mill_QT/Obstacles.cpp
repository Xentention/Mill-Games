#include "Obstacles.h"


/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Obstacle          */
/*----------------------------------------*/

//--------------------------------------------------------------
//конструктор
Obstacle::Obstacle(int startX, int startY) : Figure(0, startX, startY) {
        this->setPos(startX, startY);

}   //end Obstacle::Obstacle()

//--------------------------------------------------------------
//деструктор
Obstacle::~Obstacle() {
   //формально пустое тело

}   //end Obstacle::~Obstacle()


/*----------------------------------------*/
/*          МЕТОДЫ КЛАССА Pond            */
/*----------------------------------------*/

//--------------------------------------------------------------
//конструктор
Pond::Pond(int startX, int startY) : Obstacle(startX, startY) {
    index = indxService;
    PondImg = new QPixmap(":/recources/images/pond.png");
    Height = PondImg->height();
    Width = PondImg->width();

    this->setPos(startX, startY);

}   //end Pond::Pond()

//--------------------------------------------------------------
//Показать мельницу
void Pond::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QRect Rect = PondImg->rect();
    painter->setBrush(QBrush(*PondImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(Rect);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}   //end  Pond::paint()

//--------------------------------------------------------------
//изменение состояния объекта
void Pond::UpdateState(){
    //формально пустое тело

}   //end Pond::UpdateState()

//--------------------------------------------------------------
//деструктор
Pond::~Pond() {
   //формально пустое тело

}   //end Pond::~Pond()


/*----------------------------------------*/
/*      МЕТОДЫ КЛАССА ServiceStation      */
/*----------------------------------------*/

//--------------------------------------------------------------
//конструктор
ServiceStation::ServiceStation(int startX, int startY) : Obstacle(startX, startY) {
    index = indxService;
    ServiceStationImg = new QPixmap(":/recources/images/servicestation.png");
    Height = ServiceStationImg->height();
    Width = ServiceStationImg->width();

    this->setPos(startX, startY);

}   //end ServiceStation::ServiceStation()

//--------------------------------------------------------------
//Показать мельницу
void ServiceStation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QRect Rect = ServiceStationImg->rect();
    painter->setBrush(QBrush(*ServiceStationImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(Rect);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}   //end ServiceStation::paint()

//--------------------------------------------------------------
//изменение состояния объекта
void ServiceStation::UpdateState(){
    int NewX = rand() % (FieldRight - Width),
        NewY = rand() % (FieldBottom - Height);
    this->setPos(NewX, NewY);

}   //end ServiceStation::UpdateState()

//--------------------------------------------------------------
//деструктор
ServiceStation::~ServiceStation() {
   //формально пустое тело

}   //end ServiceStation::~ServiceStation()
