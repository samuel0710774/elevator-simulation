#ifndef BUILDING_H
#define BUILDING_H
//#include "judge.h"
#include "judgewindow.h"
#include "data.h"
#include "problemset.h"
#include "floor.h"
#include "add1.h"
#include "prime.h"
#include "shy_game.h"
#include "longest_pair.h"
#include "fibonacci.h"
#include "closest_pair.h"
#include "Mine.h"
#include "factorial.h"
#include "people.h"
#include "scheduler.h"
#include "Period_string.h"
#include "Sum_hex.h"
#include "DBP.h"
#include "substract1.h"
#include "maze.h"
#include "large_factorial.h"
#include "Mario.h"
#include "Maxroot.h"
#include "Get_signature.h"
#include "findstructuresoftree.h"
#include "get_solution.h"
#include "shortestsummationdistance.h"
#include "escape.h"
#include "longest_common_substring.h"
#include "longest_peek_palindrome.h"
#include "easy_city2.h"
#include "the_median.h"
#include "database1.h"
#include "database6.h"

//for data base
#include <qsqldatabase.h>
#include <qsqlquery.h>

//for Timer of simulation
//#include <QtGlobal>
//#include <QElapsedTimer>    //QElapsedTimer(Elapsed(), nsecsElapsed())
//#include <QThread>
#include <QTimer>
#include <QDebug>

//Ouput file
#include <fstream>
#include <iomanip>

class Building:public QObject
{
    Q_OBJECT
public:
    Building();
    ~Building();
    void run(int,int);
    Data getData(){return data; }

    // for database
    void connectDB();
    void getInitialCondition(int);
    void initializePoeple();

    //for simulation
    void setJudgeWin_Checkstate(bool);
    void Simulation();
    unsigned long long getIndex(){return scheduler.getIndex();}
    vector<pair<int,int>> sortsort_by_dis(vector<pair<int,int>>,int);

    //for output operation path file
    void make_file(int,int,int);


    Floor floor[30];
    People people[27];

private:
    QSqlDatabase dataBase;
    QSqlQuery *query;
    JudgeWindow judgeWindow;
    Data data;  
    QTimer *timer;
    Scheduler scheduler;
    ofstream operation_path;


public slots:
    void update();
signals:
     void UpdateGUI();
};

#endif // BUILDING_H
