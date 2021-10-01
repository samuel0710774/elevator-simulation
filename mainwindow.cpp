#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "building.h"

#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&building,SIGNAL(UpdateGUI()),this, SLOT(slot_update_data()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_runButton_clicked()
{

    int f = ui->comboBox->currentIndex();

    building.run(f,0);
    windata = building.getData();

    ui->testdata->setText(QString::fromStdString(windata.testdata));

    ui->submitdata->setText(QString::fromStdString(windata.submit));

    ui->spendTime->setText(QString::number(windata.spendtime));

    ui->check->setText(QString::number(windata.correct));

}

void MainWindow::connectDB(){
    QSqlDatabase dataBase;
    dataBase = QSqlDatabase::addDatabase("QMYSQL");
    dataBase.setHostName("localhost");//通常是IP位置
    dataBase.setUserName("root");
    dataBase.setPassword("nctuece");
    dataBase.setPort(3306);
    if(dataBase.open()){
        qDebug()<<"Succeed!"<<endl;
    }else{
        qDebug()<<"Error!!"<<endl;
    }
}

void MainWindow::on_get_People_Info_clicked()
{
    ui->destination->setText(QString::number(building.people[ui->comboBox->currentIndex()].getDestination()));
    ui->number_of_people->setText(QString::number(building.people[ui->comboBox->currentIndex()].getNumber()));
}

void MainWindow::on_start_simulate_button_clicked()
{
    building.setJudgeWin_Checkstate(false);
    building.Simulation();
    ui->finish_Label->hide();
}

void MainWindow::slot_update_data(){
    windata = building.getData();
    ui->testdata->setText(QString::fromStdString(windata.testdata));

    ui->submitdata->setText(QString::fromStdString(windata.submit));

    ui->spendTime->setText(QString::number(windata.spendtime));

    ui->check->setText(QString::number(windata.correct));

    //ui->comboBox->setCurrentIndex(windata.nowfloor-1);

    ui->score->setText(QString::number(windata.score));

    ui->nowElavator->display(windata.nowfloor);

    if(windata.nowState){
        ui->people_in_elavator->display(windata.nowPassenger);
    }else{
        ui->people_in_elavator->display(0);
    }

    ui->Distance->display(windata.distance);
    /*if(windata.nowfloor){
        ui->testdata->setText(QString::fromStdString(windata.testdata));

        ui->submitdata->setText(QString::fromStdString(windata.submit));

        ui->spendTime->setText(QString::number(windata.spendtime));

        ui->check->setText(QString::number(windata.correct));

        ui->comboBox->setCurrentIndex(windata.nowfloor-1);

        ui->score->setText(QString::number(windata.score));

        ui->nowElavator->display(windata.nowfloor);
        ui->people_in_elavator->display(windata.nowPassenger);
        ui->Distance->display(windata.distance);
    }else{
        //ui->finish_Label->show();
    }*/
}
