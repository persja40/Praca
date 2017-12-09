#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    nr_rounds= 0;
    nr_players= 0;
    fun= 0;
    delay= 0;
    cancel= false;
    busy= false;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    //kill();
    delete ui;
}

void MainWindow::on_pushButton_Run_clicked()
{
    QtConcurrent::run(
            [&]()->void{
                ui->pushButton_Run->setEnabled(false);
                const int g= nr_rounds;
                const int p= nr_players;
                const int f= fun;
                vector<unique_ptr<Game>> tab;
                std::default_random_engine generator;
                std::uniform_int_distribution<int> distribution(0,255);
                auto r= bind(distribution, generator);
                clear_vectors();
                chrono::milliseconds d(delay);
                beginsp.resize(p);
                endsp.resize(p);
                for(int i=0; i<p;i++){
                    tab.push_back(make_unique<Game>(f));
                    colorsp.push_back(make_tuple( r(), r(), r() ));
                    beginsp[i].resize(g);
                    endsp[i].resize(g);
                }
                for(int j=0; j<g;j++){
                    while(!points.try_lock());
                    for(int i=0; i<p;i++){
                        if(cancel){
                            busy= false;
                            throw 1;
                        }
                        beginsp[i].push_back(tab[i]->next());
                        endsp[i].push_back(tab[i]->prelast());
                    }
                    points.unlock();
                    emit copy();
                    this_thread::sleep_for(d);
                }
                busy= false;
                ui->pushButton_Run->setEnabled(true);
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

/*
void MainWindow::on_pushButton_Clear_clicked()
{
    kill();
}

void MainWindow::kill(){
    QtConcurrent::run(
            [&]()->void{
                ui->pushButton_Run->setEnabled(false);
                ui->pushButton_Clear->setEnabled(false);

                //emit clear
                ui->pushButton_Run->setEnabled(true);
                ui->pushButton_Clear->setEnabled(true);
            });
}

void MainWindow::on_pushButton_Debug_clicked()
{
    cout<<"DEBUG"<<endl;
}
*/

void MainWindow::clear_vectors(){
    beginsp.clear();
    endsp.clear();
    colorsp.clear();
}
