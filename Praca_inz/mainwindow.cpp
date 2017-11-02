#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <memory>
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    nr_rounds= 0;
    nr_players= 0;
    fun= 0;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Run_clicked()
{
    //Make simulation
    const int g= nr_rounds;
    const int p= nr_players;
    vector<unique_ptr<Game>> tab;
    cout<<"fun: "<<fun<<endl;
    for(int i=0; i<p;i++)
        tab.push_back(make_unique<Game>(fun));
    for(int j=0; j<g;j++)
        for(auto& i:tab)
            i->next();
    cout<<"FINISH"<<endl;
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
