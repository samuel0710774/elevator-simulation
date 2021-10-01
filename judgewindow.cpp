#include "judgewindow.h"
#include "ui_judgewindow.h"

#include <QDebug>
#include <QSqlError>
#include <math.h>

JudgeWindow::JudgeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JudgeWindow)
{
    ui->setupUi(this);

    //Set random seed Today we set 0
    setSeed(0);

    //create database and load data
    connectDB();
    getInitialCondition();

    for (int i=0;i<27;i++) {
        ui->gridLayout_2->addWidget(&check[i][0],i,0);
        check[i][0].setCheckState(Qt::Checked);
        ui->gridLayout_4->addWidget(&label[i][0],i,0);
        label[i][0].setText(QString::number(i+1));
        for (int j=0;j<4;j++) {
            ui->gridLayout->addWidget(&showline[i][j],i,j);
        }
    }

    for(int i=0;i<27;i++){
        check[20][0].setCheckState(Qt::Checked);
        check[21][0].setCheckState(Qt::Checked);
        check[22][0].setCheckState(Qt::Checked);
        check[25][0].setCheckState(Qt::Checked);
        check[26][0].setCheckState(Qt::Checked);
        check[i][0].setStyleSheet("QCheckBox::indicator { width:20px; height: 20px; }");
    }


    //ui->Upload->setDisabled(true);
    ui->st1_ID->setText("0710774");
    ui->st2_ID->setText("0710766");
    ui->st1_Name->setText("楊士賢");
    ui->st2_Name->setText("陳詮翰");

    result.open("time.txt");
    score = 0;
    costtime = 0;
    distance = 0;
    prev_floor=0;
    Win_Lost = 0;
    //qDebug

    for(int i=0;i<27;i++){
        correct_answer[i]=0;
        question_num[i]=0;
        total_costTime[i]=0;
        total_Score[i]=0;
        floornextdata[i]=0;
        if(i<21){
            floordatatimes[i] = 10; //for 一般問題
        }else{
            floordatatimes[i] = 1;  //for mysql
        }
    }
}

JudgeWindow::~JudgeWindow()
{
    result.close();
    delete ui;
}

void JudgeWindow::connectDB(){
    dataBase = QSqlDatabase::addDatabase("QMYSQL");
    dataBase.setHostName("localhost");
    dataBase.setUserName("root");
    dataBase.setPassword("N126111653");
    dataBase.setPort(3306);
    if(dataBase.open()){
        qDebug()<<"Succeed!"<<endl;
    }else{
        qDebug()<<"Error!!"<<endl;
    }
}

void JudgeWindow::updatenextdata(int floor){
    floornextdata[floor]++;
}

void JudgeWindow::getInitialCondition(){
    query = new QSqlQuery();

    // create database, table, load file

    query->exec("CREATE DATABASE IF NOT EXISTS FINAL;");
    query->exec("USE FINAL;");

    //Construct testData's Table
    query->exec("DROP TABLE testData;");
    query->exec("DROP TABLE Initial_Condition;");
    query->exec("CREATE TABLE IF NOT EXISTS testData(Id varchar(8) primary key, Floor int,Question TEXT,Answer TEXT);");
    query->exec("LOAD DATA infile 'C://ProgramData//MySQL//MySQL Server 8.0//Uploads//testdata_1225.csv' INTO TABLE testData FIELDS TERMINATED BY ',' enclosed by '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS;");//?qDebug()<<"CORRECT":qDebug()<<query->lastError();


    //Construct Initial Condition's Table
    query->exec("CREATE TABLE IF NOT EXISTS Initial_Condition(Id varchar(8) primary key, Nowfloor int,Destination int,Number int);");
    query->exec("LOAD DATA infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/simple_initial_condition.csv' INTO TABLE Initial_Condition FIELDS TERMINATED BY ',' enclosed by '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS;");

}


string JudgeWindow::getData(int floor, int b,int &datatimes){
    //qDebug()<<"floor"<<floor;

    int x;              //for get the number of test data
    QString command;    //get the command line

    if(b){
        people[floor].setNumber(people[floor].getNumber()-1);
        showline[floor][0].setText(QString::number(people[floor].getNumber()));
    }else{
        people[floor].setArrNum(people[floor].getArrNum()-1);
        showline[floor][1].setText(QString::number(people[floor].getArrNum()));
    }

    question_num[floor]++;

    //count distance
    //distance+=abs(floor-prev_floor);
    //setPrevFloor(floor);

    // Set the times for the question to be run
    datatimes = floordatatimes[floor];


    /*//get random ID number of test data
    command = "SELECT * FROM final.testdata where Floor = ";
    command+=QString::number(floor+1);
    command+=";";
    query->exec(command);

    int num=0;
    while(query->next()){//得到每層樓測資的個數
        num++;
    }

    //Get random data
    x = rand()%num;*/

    x = getnextdata(floor);//是否需要加一

    //Get Answer Command Line
    command = "SELECT * FROM final.testdata where Floor = ";
    command+=QString::number(floor+1);
    command+=" and id like '%000";
    if(x<10)
        command+="0";

    command+=QString::number(x);
    command+="%';";

    query->exec(command);

    while (query->next()) {
        ans = query->value(3).toString().toStdString();
    }

    // Check if give up the question
    if(check[floor][0].isChecked()){
        timer.start();
        return "GIVEUP";
    }

    //Get question command Line
    string question;
    command = "SELECT * FROM final.testdata where Floor = ";
    command+=QString::number(floor+1);
    command+=" and id like '%000";
    if(x<10)
        command+="0";

    command+=QString::number(x);
    command+="%'";
    query->exec(command);

    //question = query->value(2).toString().toStdString();
    while (query->next()) {
        question = query->value(2).toString().toStdString();
    }

    timer.start();
    return question;
}

bool JudgeWindow::submitData(string test,int floor){
    costtime = timer.nsecsElapsed();
    costtime /= floordatatimes[floor];

    long long bonus = pow(2,getnextdata(floor));
    updatenextdata(floor);

    //qDebug()<<QString::fromStdString(test);

    if(ans.compare(test)==0){
        total_Score[floor]+=10000000000+bonus;
        correct_answer[floor]++;
        total_costTime[floor]+=costtime;
        showline[floor][2].setText(QString::number(total_costTime[floor]));
        showline[floor][3].setText(QString::number(total_Score[floor]));
        return true;
    }else{
        return false;
    }
}

int JudgeWindow::getConditionNum(){

    // select nth initial condition
    query->exec("select * from Initial_Condition");
    //int random_initial_condition = rand()%300+1;
    int initial_con=1;
    QString command = "select * from Initial_Condition WHERE Id LIKE ";
    command+= "'%000";
    if(initial_con<10){
        command+="0";
    }
    command+=QString::number(initial_con);
    command+="%'";

    query->exec(command);
    initializePoeple();

    return initial_con;
}

void JudgeWindow::initializePoeple(){
    int i = 0;

    while(query->next()){
        people[i].setNumber(query->value(3).toInt());
        people[i].setDestination(query->value(2).toInt());
        i++;
    }

    for(int i=0;i<27;i++){
        showline[i][0].setText(QString::number(people[i].getNumber()));                            //Wait to leave
        showline[people[i].getDestination()-1][1].setText(QString::number(people[i].getNumber())); //arrive people
        showline[i][2].setText(QString::number(getSpendTime()));
        showline[i][3].setText(QString::number(getW_L()));
        people[people[i].getDestination()-1].setArrNum(people[i].getNumber());
    }
}

void JudgeWindow::UpdateGUI(int floor, int number,int state){

    if(state){
        people[floor].setNumber(people[floor].getNumber()-number);
    }else{
        people[floor].setArrNum(people[floor].getArrNum()-number);
    }

    if(!check[floor][0].isChecked()){
        showline[floor][2].setText(QString::number(total_costTime[floor]));
    }

    if(state){
        showline[floor][0].setText(QString::number(people[floor].getNumber()));
    }else{
        showline[floor][1].setText(QString::number(people[floor].getArrNum()));
    }
}

void JudgeWindow::setCheck_state(bool flag){
    if(!flag){
        for(int i=0;i<27;i++){
            check[i]->setDisabled(true);
        }
    }else{
        for(int i=0;i<27;i++){
            check[i]->setDisabled(false);
        }
    }
}

void JudgeWindow::scheduleEnd(){
    for(int i=0;i<27;i++){
        result<<setw(2)<<i+1<<" | "<<setw(15)<<total_costTime[i]<<" | "<<setw(2)<<correct_answer[i]<<" | "<<question_num[i]<<endl;
    }
    ui->Upload->setEnabled(true);
   // dataBase.close();
}

void JudgeWindow::connect_TA_DB(){

    //dataBase.close();
    dataBaseTA = QSqlDatabase::addDatabase("QMYSQL");
    dataBaseTA.setHostName("140.113.146.126");
    dataBaseTA.setUserName("aoopstudent");
    dataBaseTA.setPassword("tsaimother");
    dataBaseTA.setPort(3306);
    if(dataBaseTA.open()){
        qDebug()<<"Succeed!";
    }else{
        qDebug()<<"Error!!";
    }
}

void JudgeWindow::on_Upload_clicked()
{

    dataBase.close();
    dataBaseTA = QSqlDatabase::addDatabase("QMYSQL");
    dataBaseTA.setHostName("140.113.146.126");
    dataBaseTA.setUserName("aoopstudent");
    dataBaseTA.setPassword("tsaimother");
    dataBaseTA.setPort(3306);
    if(dataBaseTA.open()){
        qDebug()<<"Succeed!";
    }else{
        qDebug()<<"Error!!";
    }
    //connect_TA_DB();

    queryTA = new QSqlQuery();

    queryTA->exec("USE aoopstudentuse;")?qDebug()<<"CORRECT":qDebug()<<queryTA->lastError();



    string st1_id,st2_id,st1_name,st2_name;

    st1_id = ui->st1_ID->text().toStdString();
    st2_id = ui->st2_ID->text().toStdString();
    st1_name=ui->st1_Name->text().toStdString();
    st2_name=ui->st2_Name->text().toStdString();

    QString command;

    //Uload id/name/floor/timespent/correct_ans_total_que/score
    for(int i=0;i<27;i++){
        QString command="INSERT INTO floorscore(stud_id1,stud_name1,stud_id2,stud_name2,floor,timespent,pass,totalques,totalscore) VALUES('";
        command+=QString::fromStdString(st1_id);
        command+="','";
        command+=QString::fromStdString(st1_name);
        command+="','";
        command+=QString::fromStdString(st2_id);
        command+="','";
        command+=QString::fromStdString(st2_name);
        command+="',";
        command+=QString::number(i+1);
        command+=",";
        command+=QString::number(total_costTime[i]);
        command+=",";
        command+=QString::number(correct_answer[i]);
        command+=",";
        command+=QString::number(question_num[i]);
        command+=",";
        command+=QString::number(total_Score[i]);
        command+=");";
        //qDebug()<<command;
        queryTA->exec(command);//?qDebug()<<"CORRECT":qDebug()<<queryTA->lastError();
    }
    command="INSERT INTO totalpath(stud_id1,stud_name1,stud_id2,stud_name2,pathlen) VALUE(";
    command+=QString::fromStdString("'"+st1_id+"','"+st1_name+"','"+st2_id+"','"+st2_name+"',");
    command+=QString::number(distance);
    command+=");";
    //qDebug()<<command;
    queryTA->exec(command);//?qDebug()<<"CORRECT":qDebug()<<queryTA->lastError();
}


