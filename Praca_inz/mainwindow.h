#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
  void on_pushButton_Run_clicked();

  void on_spinBox_Players_valueChanged(int arg1);

  void on_spinBox_Rounds_valueChanged(int arg1);

  void on_listWidget_currentRowChanged(int currentRow);

  void on_spinBox_Delay_valueChanged(int arg1);

  void on_pushButton_Clear_clicked();

private:
    Ui::MainWindow *ui;
    int nr_players;
    int nr_rounds;
    int fun;
    int delay;
    volatile bool cancel;
};

#endif // MAINWINDOW_H
