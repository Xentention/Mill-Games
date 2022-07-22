#ifndef WIDGET_H
#define  WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QTimer>
#include "Utilities.h"
#include "Mill.h"
#include "Obstacles.h"
#include "Wheat.h"


namespace Ui {
class Widget;

}

//класс ОКНО
class Widget : public QWidget {
  // Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    virtual ~Widget();

private:
    int             indexCurrentMill;       //индекс текущей мельницы
    Ui::Widget      *ui;
    QGraphicsScene  *scene;                 //графическая сцена
    QTimer          *timer;                 //игровой таймер

    vector <Mill*> Mills;                   //вектор игровых мельниц
    vector <Obstacle*> Obstacles;           //вектор препятствий

    QList<QGraphicsItem *> WheatList;       //Список со всеми стогами, присутствующими в игре
    double score;                           //Счетчик очков

private slots:
    void slotChangeMill(QGraphicsItem *obstacle);   //Слот изменения мельницы
    void slotCreateWheat();                         //Слот создания стогов сена
    void slotDeleteWheat(QGraphicsItem *item);      //Слот удаления стога
};

#endif // WIDGET_H
