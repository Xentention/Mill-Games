#include "Widget.h"
#include "ui_widget.h"

//--------------------------------------------------------------
//Конструктор
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget) {
    ui->setupUi(this);
    this->resize(FieldRight,FieldBottom);                                                   //Задаем размеры виджета
    this->setFixedSize(FieldRight,FieldBottom);                                             //Фиксируем размеры виджета
    this->setWindowIcon(QIcon(":/recources/images/millrotor.png"));                         //Задаем иконку приложения
    this->setStyleSheet("background-image: url(:/recources/images/backgroundimg.png);");    //Задаем фон

    scene = new QGraphicsScene();                                                           //Инициализируем графическую сцену

    ui->graphicsView->setScene(scene);                                                      //Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);                   //Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);                 //Отключаем скроллбар по горизонтали

    scene->setSceneRect(0, 0, FieldRight-1, FieldBottom-1);                                 //Устанавливаем область графической сцены

    score = 0;  //Счет очков

    //ОБЪЯВЛЕНИЕ ПРЕПЯТСТВИЙ
    //Стартовые координаты
    int PondX = 530, PondY = 300;
    int ServiceX = 800, ServiceY = 100;

    //Объявление объектов препятствий
    ServiceStation *MainService = new ServiceStation(ServiceX, ServiceY);   //Рем. станция
    Pond *MainPond = new Pond(PondX, PondY);                                //Пруд

    //Заполняем вектор препятствий
    Obstacles.push_back(MainPond);      //Пруд
    Obstacles.push_back(MainService);   //Ремонтная станция

    //Добавляем препятствия на сцену
    for(int i=0; i<NumofObstacles; i++){
        scene->addItem(Obstacles[i]);
    }

    //ОБЪЯВЛЕНИЕ МЕЛЬНИЦ
    //Стартовые координыты
    int x0=200, y0=150;

    //Объявление объектов мельниц
    Mill *MainMill = new Mill(x0, y0);                           //Мельница
    RoofedMill *MainRMill = new RoofedMill(x0, y0);				 //Мельница с крышей
    WaterMill *MainWMill = new WaterMill(x0, y0);				 //Водяная мельница
    RoofedWaterMill *MainRWMill = new RoofedWaterMill(x0, y0);	 //Водяная мельница с крышей

    //Заполняем вектор мельниц
    Mills.push_back(MainMill);      //Мельница
    Mills.push_back(MainRMill);     //Мельница с крышей
    Mills.push_back(MainWMill);     //Водяная мельница
    Mills.push_back(MainRWMill);    //Водяна мельница с крышей

    //Добавляем мельницы на сцену
    for(int i=0; i<NumofMills; i++){
        scene->addItem(Mills[i]);
        Mills[i]->hide();
    }

    //Начинаем с обычной мельницы
    indexCurrentMill = indxMill;
    Mills[indexCurrentMill]->show();

   //таймер 5 раз/сек
    timer = new QTimer();
    connect(timer, &QTimer::timeout, Mills[indexCurrentMill], &Mill::slotMoveGameObject);
    timer->start(100);

    //Раз в секунду создаем новый стог
    QTimer *timerCreateWheat = new QTimer();
    connect(timerCreateWheat, &QTimer::timeout, this, &Widget::slotCreateWheat);
    timerCreateWheat->start(1000);

    //Связываем сигналы найденных объектов с удалением стогов сена и изменением состояния мельницы
    for(int i=0; i<NumofMills; i++){
        connect(Mills[i], &Figure::signalFoundObstacle, this, &Widget::slotDeleteWheat);
        connect(Mills[i], &Figure::signalFoundObstacle, this, &Widget::slotChangeMill);
    }


}   //end Widget::Widget()

//--------------------------------------------------------------
//Слот изменения игровой мельницы после препятствия
void Widget::slotChangeMill(QGraphicsItem *obstacle){
    int collision = NothingNearby;              //Предполагаем, что столкновения не было

    //Проверяем все препятствия
    for(int i=0; i < NumofObstacles; i++){
        if(Obstacles[i] == obstacle) {      //Если столкновение произошло
            Obstacles[i]->UpdateState();    //Обновляем состояние препятствия
            if(i == indxPond)               //Если столкнулись с прудом
                collision = PondIsNearby;
            if(i == indxService)            //Если столкнулись с рем. станцией
                collision = ServiceIsNearby;
            }

        //Нет необходимости обновлять мельницу
        if(collision == PondIsNearby && (indexCurrentMill == indxWMill || indexCurrentMill == indxRWMill))
            continue;
        if(collision == NothingNearby && (indexCurrentMill == indxMill || indexCurrentMill == indxRMill))
            continue;

        //Дисконнектим текущую мельницу от игрового слота
        disconnect(timer, &QTimer::timeout, Mills[indexCurrentMill], &Mill::slotMoveGameObject);
        //Записываем ее координаты
        int PrevX = Mills[indexCurrentMill]->x(),
            PrevY = Mills[indexCurrentMill]->y();
        Mills[indexCurrentMill]->hide();        //Скрываем эту мельницу

        //Перемещаем соответствующую мельницу на новые координаты
        indexCurrentMill = TransitionMatrix[indexCurrentMill][collision];
        Mills[indexCurrentMill]->setPos(PrevX, PrevY);
        Mills[indexCurrentMill]->show();        //Выводим эту мельницу на экран
        //Подключаем новую мельницу к игровому слоту
        connect(timer, &QTimer::timeout, Mills[indexCurrentMill], &Mill::slotMoveGameObject);
    }

}   //end Widget::slotChangeMill()

//--------------------------------------------------------------
//Добавление стогов пшеницы на поле
void Widget::slotCreateWheat() {
    Wheat *wheat = new Wheat();         //Создаём стог
    scene->addItem(wheat);              //Помещаем его в сцену
    wheat->setPos(rand() % FieldRight, rand() % FieldBottom);
    WheatList.append(wheat);            //Добавляем в список

}   //end Widget::slotCreateWheat()

//--------------------------------------------------------------
//Удаление собранных стогов
void Widget::slotDeleteWheat(QGraphicsItem *item) {
    foreach (QGraphicsItem *wheat, WheatList) {
        if(wheat == item){
            scene->removeItem(wheat);      //Удаляем со сцены
            WheatList.removeOne(item);     //Удаляем из списка
            delete wheat;                  //Удаляем сам объект

            ui->GameScore->display(++score);    //Увеличиваем счетчик очков
        }
    }
}   //end Widget::slotDeleteWheat()

//--------------------------------------------------------------
//Деструктор
Widget::~Widget() {
    delete ui;
}

