#include "Figure.h"
#include "Utilities.h"

//--------------------------------------------------------------
//конструктор
Figure::Figure(QGraphicsObject *parent, int startX, int startY) : QGraphicsObject(parent) {
    this->setPos(startX, startY);

}   //end Figure::Figure()

//--------------------------------------------------------------
//прямоугольник, в кот-й заключена фигура
QRectF Figure::boundingRect() const  {
    return QRectF(0, 0, Width, Height); 

}   //end Figure::boundingRect()

//--------------------------------------------------------------
//Вернуть индекс фигуры
int Figure::GetIndex() {   return index;  }

//--------------------------------------------------------------
//Вернуть высоту фигуры
int Figure::ReturnHeight()	{	return Height;	}

//--------------------------------------------------------------
//Вернуть ширину фигуры
int Figure::ReturnWidth()	{	return Width;		}

//--------------------------------------------------------------
//игровой слот
void Figure::slotMoveGameObject() {
    int Step = 50;  //Шаг перемещения

    //Перемещаем фигуру в соответствии с полученным кодом WinAPI нажатой клавиши
    if(GetAsyncKeyState(VK_LEFT)){          //стрелка влево
        setPos(x()-Step, y());
        //emit signalChangeMill(this->GetIndex());
        Sleep(200);
    }
    if(GetAsyncKeyState(VK_RIGHT)){         //стрелка вправо
        setPos(x()+Step, y());
        Sleep(200);
    }
    if(GetAsyncKeyState(VK_UP)){            //стрелка вверх
        setPos(x(), y()-Step);
        Sleep(200);
    }
    if(GetAsyncKeyState(VK_DOWN)){          //стрелка вниз
        setPos(x(), y()+Step);
        Sleep(200);
    }

    //Если объект выходит за заданные границы сцены, то возвращаем его назад
    if(this->x() < 0){
        this->setX(0);                    //Слева
    }
    if(this->x() > FieldRight-Width){
        this->setX(FieldRight-Width);     //Справа
    }

    if(this->y() < 0){
        this->setY(0);                    //Сверху
    }
    if(this->y() > FieldBottom-Height){
        this->setY(FieldBottom-Height);   //Снизу
    }

    CheckCollisions();      //Проверяем возможные столкновения

}   //end void Figure::slotMoveGameObject()

//--------------------------------------------------------------
//проверка на столкновение с другими объектами
void Figure::CheckCollisions(){
    //Собираем в список все графические объекты, которые находятся в области фигуры
    QList<QGraphicsItem*> foundobstacles = scene()->items(QPolygonF() << mapToScene(boundingRect()));
    //Сигнал всегда подается для самой фигуры
    foreach(QGraphicsItem *obstacle, foundobstacles)
        emit signalFoundObstacle(obstacle);     //Подаем сигнал о столкновении

}    //end Figure::CheckCollisions()

//--------------------------------------------------------------
//деструктор
Figure::~Figure(){
    //формально пустое тело

}   //end Figure::~Figure()
