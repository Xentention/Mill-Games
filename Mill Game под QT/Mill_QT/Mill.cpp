#include "Mill.h"

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Mill              */
/*----------------------------------------*/

//--------------------------------------------------------------
//конструктор
Mill::Mill(int startX, int startY) : Figure(0, startX, startY) {
    index = indxMill;
    Height = 190;
    Width = 100;
    MillBuildingImg = new QPixmap(":/recources/images/millbuilding.png");
    MillRotorImg = new QPixmap(":/recources/images/millrotor.png");

    this->setPos(startX, startY);

}   //end Mill::Mill()

//--------------------------------------------------------------
//Показать мельницу
void Mill::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    DrawBuilding(painter);
    DrawRotor(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}   //end Mill::paint()

//--------------------------------------------------------------
//Показать здание мельницы
void Mill::DrawBuilding(QPainter *painter){
    QRect Rect = MillBuildingImg->rect();
    painter->translate(10, 40);
    painter->setBrush(QPixmap(*MillBuildingImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(Rect);
    painter->translate(-10, -40);

}   //end Mill::DrawBuilding()

//--------------------------------------------------------------
//Показать лопасти мельницы
void Mill::DrawRotor(QPainter *painter){
    QRect Rect = MillRotorImg->rect();
    painter->setBrush(QBrush(*MillRotorImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(Rect);

}   //end Mill::DrawRotor()

//--------------------------------------------------------------
//деструктор
Mill::~Mill() {
   //формально пустое тело

}   //end Mill::~Mill()



/*----------------------------------------*/
/*       МЕТОДЫ КЛАССА RoofedMill         */
/*----------------------------------------*/

 //--------------------------------------------------------------
//конструктор
RoofedMill::RoofedMill(int startX, int startY) : Mill(startX, startY) {
    index = indxRMill;
    Height = 190;
    Width = 100;
    MillBuildingImg = new QPixmap(":/recources/images/millbuilding.png");
    MillRotorImg = new QPixmap(":/recources/images/millrotor.png");
    MillRoofImg = new QPixmap(":/recources/images/millroof.png");

    this->setPos(startX, startY);

}   //end RoofedMill::RoofedMill()

//--------------------------------------------------------------
//Показать мельницу
void RoofedMill::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    DrawBuilding(painter);
    DrawRoof(painter);
    DrawRotor(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}   //end RoofedMill::paint()

//--------------------------------------------------------------
//Показать здание мельницы
void RoofedMill::DrawBuilding(QPainter *painter){
    QRect Rect = MillBuildingImg->rect();
    painter->translate(10, 40);
    painter->setBrush(QPixmap(*MillBuildingImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(Rect);
    painter->translate(-10, -40);

}   //end RoofedMill::DrawBuilding()

//--------------------------------------------------------------
//Показать крышу мельницы
void RoofedMill::DrawRoof(QPainter *painter){
    QRect Rect = MillRoofImg->rect();
    painter->translate(10, 12);
    painter->setBrush(QPixmap(*MillRoofImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(Rect);
    painter->translate(-10, -12);

}   //end RoofedMill::DrawRoof()

//--------------------------------------------------------------
//Показать лопасти мельницы
void RoofedMill::DrawRotor(QPainter *painter){
    QRect Rect = MillRotorImg->rect();
    painter->setBrush(QBrush(*MillRotorImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(Rect);

}   //end RoofedMill::DrawRotor()

//--------------------------------------------------------------
//деструктор
RoofedMill::~RoofedMill() {
   //формально пустое тело

}   //end RoofedMill::~RoofedMill()


/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА WaterMill         */
/*----------------------------------------*/

 //--------------------------------------------------------------
//конструктор
WaterMill::WaterMill(int startX, int startY) : Mill(startX, startY) {
    index = indxWMill;
    Height = 128;
    Width = 128;
    MillBuildingImg = new QPixmap(":/recources/images/watermillbuilding.png");
    MillRotorImg = new QPixmap(":/recources/images/watermillrotor.png");

    this->setPos(startX, startY);

}   //end WaterMill::WaterMill()


//--------------------------------------------------------------
//Показать мельницу
void WaterMill::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    DrawBuilding(painter);
    DrawRotor(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}   //end WaterMill::paint()

//--------------------------------------------------------------
//Показать здание мельницы
void WaterMill::DrawBuilding(QPainter *painter){
    QRect Rect = MillBuildingImg->rect();
    painter->setBrush(QPixmap(*MillBuildingImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(Rect);

}   //end WaterMill::DrawBuilding()

//--------------------------------------------------------------
//Показать лопасти мельницы
void WaterMill::DrawRotor(QPainter *painter){
    QRect Rect = MillRotorImg->rect();
    painter->translate(64, 64);
    painter->setBrush(QBrush(*MillRotorImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(Rect);
    painter->translate(-64, -64);

}   //end WaterMill::DrawRotor()

//--------------------------------------------------------------
//деструктор
WaterMill::~WaterMill() {
   //формально пустое тело

}   //end WaterMill::~WaterMill()()


/*----------------------------------------*/
/*     МЕТОДЫ КЛАССА RoofedWaterMill      */
/*----------------------------------------*/

 //--------------------------------------------------------------
//конструктор
RoofedWaterMill::RoofedWaterMill(int startX, int startY) : WaterMill(startX, startY) {
    index = indxRWMill;
    Height = 184;
    Width = 128;
    MillBuildingImg = new QPixmap(":/recources/images/watermillbuilding.png");
    MillRotorImg = new QPixmap(":/recources/images/watermillrotor.png");
    MillRoofImg = new QPixmap(":/recources/images/watermillroof.png");

    this->setPos(startX, startY);

}   //end RoofedWaterMill::RoofedWaterMill()


//--------------------------------------------------------------
//Показать водяную мельницу с крышей
void RoofedWaterMill::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    DrawBuilding(painter);
    DrawRoof(painter);
    DrawRotor(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}   //end RoofedWaterMill::RoofedWaterMill()

//--------------------------------------------------------------
//Показать здание
void RoofedWaterMill::DrawBuilding(QPainter *painter){
    QRect Rect = MillBuildingImg->rect();
    painter->translate(0, 56);
    painter->setBrush(QPixmap(*MillBuildingImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(Rect);
    painter->translate(0, -56);

}   //end RoofedWaterMill::DrawBuilding()

//--------------------------------------------------------------
//Показать крышу
void RoofedWaterMill::DrawRoof(QPainter *painter){
    QRect Rect = MillRoofImg->rect();
    painter->setBrush(QPixmap(*MillRoofImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(Rect);

}   //end RoofedWaterMill::DrawRoof()

//--------------------------------------------------------------
//Показать лопасти мельницы
void RoofedWaterMill::DrawRotor(QPainter *painter){
    QRect Rect = MillRotorImg->rect();
    painter->translate(64, 120);
    painter->setBrush(QBrush(*MillRotorImg));
    painter->setPen(Qt::NoPen);
    painter->drawRect(Rect);
    painter->translate(-64, -120);

}   //end RoofedWaterMill::DrawRotor()

//--------------------------------------------------------------
//деструктор
RoofedWaterMill::~RoofedWaterMill() {
   //формально пустое тело

}   //end RoofedWaterMill::~RoofedWaterMill()
