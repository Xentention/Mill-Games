#include "Widget.h"

#include <QApplication>
Widget *MainWidget;

int main(int argc, char *argv[]) {
    QApplication MillGame(argc, argv);
    MainWidget = new Widget;
    MainWidget->show();
    return MillGame.exec();
}
