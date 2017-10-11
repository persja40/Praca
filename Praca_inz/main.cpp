#include "mainwindow.h"
#include <QApplication>

#include "game.h"

int main(int argc, char *argv[])
{
    Game ala;
    for(int i=0;i<10;i++)
        ala.next();
    ala.print();
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
}
