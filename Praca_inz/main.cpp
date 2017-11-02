#include "mainwindow.h"
#include <QApplication>

#include "game.h"
#include "multigame.h"

int main(int argc, char *argv[])
{
//  Game ala(0);
//  for(int i=0;i<1000;i++)
//      ala.next();
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
	return a.exec();

//  Multigame ala2(11,2000);
//  ala2.play();
}
