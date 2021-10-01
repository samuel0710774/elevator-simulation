#ifndef JUDGEWINDOW_H
#define JUDGEWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>

//for timer
#include <QElapsedTimer>    //QElapsedTimer(Elapsed(), nsecsElapsed())
#include <QThread>

//for data base
#include <qsqldatabase.h>
#include <qsqlquery.h>


// for Output file
#include <fstream>
#include <iomanip>

#include "data.h"
#include "people.h"


namespace Ui {
class JudgeWindow;
}

class JudgeWindow : public QWidget
{
    Q_OBJECT
    QLineEdit showline[27][4];
    QCheckBox check[27][1];
    QLabel label[27][1];


public:
    explicit JudgeWindow(QWidget *parent = nullptr);
    ~JudgeWindow();

    // for database
    void connectDB();
    void getInitialCondition();
    void initializePoeple();

    //Upload data
    void connect_TA_DB();


    string getData(int floor,int b,int &);//input 0-26
    bool submitData(string,int);
    void setSeed(int seed){srand(seed);}
    qint64 getSpendTime(){return costtime;}
    int getW_L(){ return Win_Lost;}
    int getConditionNum();//return 1-300
    int getDistance(){return distance;}
    void scheduleEnd();
    int getScore(){return score;}
    void setPrevFloor(int f){ prev_floor = f;}

    //Get which test data to load in
    void updatenextdata(int);
    int getnextdata(int floor){return floornextdata[floor];}


    //UpdateGUI
    void UpdateGUI(int,int,int); //floor/number/destination
    void setCheck_state(bool);

    People people[27];
    vector<int>schedule;

private slots:
    void on_Upload_clicked();

private:
    Ui::JudgeWindow *ui;

    //For Data Base
    QSqlDatabase dataBase;
    QSqlQuery *query;

    //For second Database
    QSqlDatabase dataBaseTA;
    QSqlQuery *queryTA;

    string ans;
    ofstream result;
    qint64 costtime;
    int score;
    int distance;
    int prev_floor;
    int Win_Lost;
    QElapsedTimer timer;
    int correct_answer[27];
    int question_num[27];
    int total_costTime[27];
    long long total_Score[27];
    int floornextdata[27];

    //Run the same data for N time
    int floordatatimes[27];
};

#endif // JUDGEWINDOW_H
