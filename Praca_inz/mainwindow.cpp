#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <thread>
#include <qtconcurrentrun.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    nr_rounds= 0;
    nr_players= 0;
    fun= 0;
    delay= 0;
    cancel=false;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    cancel= true;
    delete ui;
}

void MainWindow::on_pushButton_Run_clicked()
{
    QtConcurrent::run(
            [&]()->void{
                const int g= nr_rounds;
                const int p= nr_players;
                vector<unique_ptr<Game>> tab;
                chrono::milliseconds d(delay);
                cout<<"fun: "<<fun<<endl;
                for(int i=0; i<p;i++)
                tab.push_back(make_unique<Game>(fun));
                for(int j=0; j<g;j++){
                    for(auto& i:tab){
                        if(cancel)
                            throw 1;
                        i->next();
                    }
                    this_thread::sleep_for(d);
                }
                cout<<"FINISH"<<endl;
            });
}

void MainWindow::on_spinBox_Players_valueChanged(int arg1)
{
    nr_players= arg1;
}

void MainWindow::on_spinBox_Rounds_valueChanged(int arg1)
{
    nr_rounds= arg1;
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    fun= currentRow;
}

void MainWindow::on_spinBox_Delay_valueChanged(int arg1)
{
    delay= arg1;
}

void MainWindow::on_pushButton_Clear_clicked()
{
    QtConcurrent::run(
            [&]()->void{
                cancel= true;
                this_thread::sleep_for(1.1s);
                cancel= false;
            });
}
