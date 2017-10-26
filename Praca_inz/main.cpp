#include "mainwindow.h"
#include <QApplication>

#include "game.h"

int main(int argc, char *argv[])
{
//    Game ala;
//    for(int i=0;i<100;i++)
//        ala.next();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
