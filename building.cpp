#include "building.h"

#include <QDebug>
#include <cmath>

Building::Building()
{

    floor[0]=  Floor(new Closest_Pair());
    floor[1]=  Floor(new Mine());
    floor[2]=  Floor(new Get_signature());
    floor[3]=  Floor(new Shy_game());
    floor[4]=  Floor(new Fibonacci());
    floor[5]=  Floor(new Maxroot());
    floor[6]=Floor(new FindStructuresOfTree()); //有問題!!!!!!
    //6 Find structure of the tree
    floor[7]=  Floor(new Factorial());
    floor[8]=Floor(new ShortestSummationDistance());
    floor[9]=  Floor(new Add1());
    floor[10]= Floor(new DBP());
    floor[11]= Floor(new Mario());
    floor[12]= Floor(new Escape());
    floor[13]= Floor(new Substract1());
    floor[14]= Floor(new Period_string());
    floor[15]= Floor(new Large_Factorial());
    floor[16]= Floor(new Sum_hex());
    floor[17]= Floor(new Longest_Common_Substring());
    floor[18]= Floor(new Get_Solution());
    floor[19]= Floor(new Longest_Peek_Palindrome());
    floor[20]= Floor(new Maze());//有問題
    floor[21]= Floor(new Database1());
    //22 Manhattan Distance         (Mysql)
    floor[23] = Floor(new The_Median());
    floor[24] = Floor(new Easy_City2());
    //25 Longest/Shortest distance  (Mysql)
    floor[26] = Floor(new Database6());


    judgeWindow.show();
    judgeWindow.setSeed(0);
    int n=judgeWindow.getConditionNum();

    getInitialCondition(n);
    initializePoeple();

    //for timer for simulation
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()) ,this, SLOT(update()));

    operation_path.open("Schedule.txt");

}

Building::~Building(){
    operation_path.close();
}

void Building::run(int f,int state){
    int times;

    data.testdata = judgeWindow.getData(f,state,times);

    if(data.testdata=="GIVEUP"){
        data.submit = "";
    }else{
        for(int i=0;i<times;i++){
            data.submit = floor[f].p->solve(data.testdata);
        }
        //data.submit = floor[f].p->solve(data.testdata);
    }

    data.correct=judgeWindow.submitData(data.submit,f);
    data.spendtime = judgeWindow.getSpendTime();
    data.score = judgeWindow.getScore();
}

void Building::connectDB(){
    dataBase = QSqlDatabase::addDatabase("QMYSQL");
    dataBase.setHostName("localhost");
    dataBase.setUserName("root");
    dataBase.setPassword("nctuece");
    dataBase.setPort(3306);
    if(dataBase.open()){
        qDebug()<<"Succeed!"<<endl;
    }else{
        qDebug()<<"Error!!"<<endl;
    }
}

void Building::getInitialCondition(int initial){
    query = new QSqlQuery();

    query->exec("USE FINAL;");
    query->exec("SHOW tables;");

    // select nth initial condition
    query->exec("select * from Initial_Condition");
    QString command = "select * from Initial_Condition WHERE Id LIKE ";
    command+= "'%000";
    if(initial<10){
        command+="0";
    }
    command+=QString::number(initial);
    command+="%'";

    query->exec(command);
}

void Building::initializePoeple(){



    //Version 2 不暴力但解不出來////////////////////////////////////////////////////////////////////////////


    int i = 0;
    int temp[27][2];           //储存1~27樓各樓層等待人數/目標樓層
    int elevator_people=0;  //判斷電梯現在裡面有幾人
    int People_in=0;         //判斷多少人進到電梯
    bool flag[27];          //判斷1~27樓是否還有人在電梯
    bool end = true;        //判斷電梯是否已經跑完了
    bool in_out;
    int from=0;
    int to=0;
    bool up_down[27];       //用來判斷該樓層的人是要往上還是往下



    while(query->next()){
        people[i].setNumber(query->value(3).toInt());
        people[i].setDestination(query->value(2).toInt()-1);    // 0~26

        temp[i][0] = people[i].getNumber();
        temp[i][1] = people[i].getDestination();

        if(temp[i][0]){
            flag[i]=false;//初始化
        }
        if((people[i].getDestination()-i)>0){
           up_down[i]=true;
        }else{
            up_down[i]=false;
        }
        i++;
    }

    //vector<pair<int,int>>dest_num;

    int min_distance=100000;
    int floor_to_go_1st=0;

    for(int count=0;count<27;count++){
        //-------------------------------------------------------------
        int temp2[27][2];           //储存1~27樓各樓層等待人數/目標樓層
        int elevator_people2=0;  //判斷電梯現在裡面有幾人
        int People_in2=0;         //判斷多少人進到電梯
        bool flag2[27];          //判斷1~27樓是否還有人在電梯
        bool end2 = true;        //判斷電梯是否已經跑完了
        //bool in_out2;
        int from2;
        int to2=0;

        from2=count;
        int distance=0;


        //qDebug()<<"NOW floor: "<<count;
        for(int i=0;i<27;i++){

            temp2[i][0] = people[i].getNumber();
            temp2[i][1] = people[i].getDestination();
            //qDebug()<<"People"<<temp2[i][0];
            if(temp2[i][0]){
                flag2[i]=false;//初始化
            }
        }

        while (end2) {
            while(elevator_people2<10 && temp2[from2][0]){
                temp2[from2][0]--;
                elevator_people2++;
                People_in2++;
            }

            distance+=abs(temp2[from2][1]-from2);   // 算距離
            //qDebug()<<"dest:"<<temp[from2][1]<<" from: "<<from2;

            from2 = temp2[from2][1];
            to2 = temp2[from2][1];

            int min_floor2;//用來篩選最近的樓層
            if(temp2[from2][0]==0){   //如果到該樓層，去找最近且還有人的樓層
                min_floor2=27;

                for(int i=0;i<26;i++){
                    if(i!=from2 && temp2[i][0]){
                        if(abs(i-from2)<min_floor2){
                            min_floor2=i;
                        }
                    }
                }
                distance+=abs(from2-min_floor2);
                from2=min_floor2;
            }
            People_in2=0;
            elevator_people2=0;

            //終止條件
            for(int i=0;i<27;i++){
                if(temp2[i][0]){
                    end2=true;
                    break;
                }else{
                    end2=false;
                }
            }
            /*if(min_floor2==27){
                end2=false;
            }*/
        }

        if(distance<min_distance){
            floor_to_go_1st=count;
        }
        //qDebug()<<"Distance:"<<distance;
    }
    //qDebug()<<"Floor to go first="<<floor_to_go_1st;
//**********************************************************************


    //from=floor_to_go_1st;
    while (end) {
        while(elevator_people<10 && temp[from][0]){
            temp[from][0]--;
            elevator_people++;
            People_in++;
        }

        scheduler.push_nowFloor(from);
        scheduler.push_state(1);
        scheduler.push_passenger_num(People_in);
        from = temp[from][1];
        to = temp[from][1];
        scheduler.push_nowFloor(from);
        scheduler.push_state(0);
        scheduler.push_passenger_num(People_in);

        int min_floor;//用來篩選最近的樓層
        if(temp[from][0]==0){   //如果到該樓層，去找最近且還有人的樓層
            min_floor=27;

            for(int i=0;i<26;i++){
                if(i!=from && temp[i][0]){
                    if(abs(i-from)<min_floor){
                        min_floor=i;
                    }
                }
            }
            //qDebug()<<"From the floor: "<<from<<" to Minimum_floor: "<<min_floor<<" Up_down";
            //up_down[from]?qDebug()<<"<<from_UP":qDebug()<<"from_Down";

            //up_down[min_floor]?qDebug()<<"<<Min_UP":qDebug()<<"Min_Down";
            from=min_floor;
        }
        People_in=0;
        elevator_people=0;

        //終止條件
        for(int i=0;i<27;i++){
            if(temp[i][0]){
                end=true;
                break;
            }
        }
        if(min_floor==27){
            end=false;
        }
    }
    /*i=0;

    //Creat schedule

    int buffer=0;

    while (end) {
        while (elevator_people<10 && temp[26][0]) {
            elevator_people++;
            temp[i][0]--;
            People_in++;
            if(temp[i][0]<1 && elevator_people<10){ //電梯還沒坐滿，但該樓層已經沒有人
                scheduler.push_nowFloor(i);
                scheduler.push_state(1);
                scheduler.push_passenger_num(People_in);
                in_out=true; //進去
                //qDebug()<<"Floor: "<<i+1;
                //qDebug()<<" 1.電梯還沒坐滿，但該樓層已經沒有人";
                //qDebug()<<"Floor: "<<i<<" Number: "<<elevator_people;
                //dest_num.push_back(make_pair(temp[i][1],elevator_people));
                //scheduler.push_passenger_num(elevator_people);
                //qDebug()<<"number"<<elevator_people;
                dest_num.push_back(make_pair(temp[i][1],People_in));//共有幾人(elevator_people)，要到目的地(temp[i][1])
                //qDebug()<<"Floor:"<<i+1<<"number in: "<<People_in;
                People_in=0;//Update
                flag[i]=true;   //i樓已經沒人了11
                if(i!=26){
                    i++;
                }
                //i++;            //進到下一樓
                //scheduler.push_nowFloor(i);
                buffer++;
            }else if(temp[i][0]>0 && elevator_people==10){  //外面還有人但電梯已經坐滿了
                scheduler.push_nowFloor(i);
                scheduler.push_state(1);
                scheduler.push_passenger_num(People_in);
                buffer++;
                dest_num.push_back(make_pair(temp[i][1],People_in));//共有幾人(elevator_people)，要到目的地(temp[i][1])
                //qDebug()<<"Floor:"<<i+1<<"number in: "<<People_in;
                //People_in=0;
            }
        }

        //qDebug()<<"Floor: "<<i+1;
        //qDebug()<<" 2.電梯坐滿了，準被放人";
        if(buffer==1){
            //出來咯~
            scheduler.push_passenger_num(dest_num[0].second);
            scheduler.push_nowFloor(temp[i][1]);
            scheduler.push_state(0);
            //scheduler.push_passenger_num(elevator_people);
        }else if(buffer>1){
            //dest_num=sort_by_dis(dest_num,i);
            sort(dest_num.begin(),dest_num.end());
            for(int j=0;j<buffer;j++){
                scheduler.push_nowFloor(dest_num[j].first);
                scheduler.push_passenger_num(dest_num[j].second);
                scheduler.push_state(0);
            }
        }

        //scheduler.push_state(1);
        buffer=0;
        dest_num.clear();
        for(int j=0;j<27;j++){
            if(!flag[j]){
                end=true;
            }else{
                end=false;
            }
        }
        People_in=0;
        elevator_people=0;
    }*/

    //Version 1 暴力解
    /*int i = 0;
    int temp[27],elevator_people=0; //for scheduler

    while(query->next()){
        people[i].setNumber(query->value(3).toInt());
        people[i].setDestination(query->value(2).toInt()-1);
        cout<<"floor: "<<i<<" ||waiting: "<<people[i].getNumber()<<"||Destination: "<<people[i].getDestination()<<endl;
        temp[i] = people[i].getNumber();
        i++;
    }

    i=0;
    //Creat schedule
    scheduler.push_nowFloor(0);
    while (i<=26) {
                                      //載第一批人
        while (elevator_people<10&&temp[i]) {
            elevator_people++;
            temp[i]--;
            if(temp[i]<1){  // 此樓人數已經載完但電梯還有空間時
                scheduler.push_passenger_num(elevator_people);
                scheduler.push_nowFloor(people[i].getDestination());
                scheduler.push_state(1);
                //人滿惹，該出乃惹
                scheduler.push_passenger_num(elevator_people);
                scheduler.push_state(0);
                elevator_people=0;
                i++;
                if(i<27){
                    scheduler.push_nowFloor(i);
                }

            }
        }

        if(i<27){
            //人還沒載完，但電梯已經沒空間時
            scheduler.push_state(1);                                 //
            scheduler.push_passenger_num(elevator_people);          //elevator_people = 10
            scheduler.push_nowFloor(people[i].getDestination());
            // 人滿了，該出乃惹
            scheduler.push_passenger_num(elevator_people);
            scheduler.push_nowFloor(i);
            scheduler.push_state(0);
            elevator_people=0;
        }
    }*/
    for(unsigned long long i=0;i<scheduler.get_nowFloor_vecSize();i++){
        scheduler.updateEnd();
    }


    //scheduler.nowFloor_List();
}

vector<pair<int,int>> Building::sortsort_by_dis(vector<pair<int,int>>a,int floor){
    vector<pair<int,int>> b;

    unsigned long long i=a.size();
    int max=0;
    unsigned long long flag=0;
    while (i) {
        for(unsigned long long j=0;j<a.size();j++){
            if(abs(a[j].first-floor)>max){
               flag=j;
               max=abs(a[j].first-floor);
            }
        }
        b.push_back(make_pair(a[flag].first,a[flag].second));
        max=0;
        i--;
        a[flag].first = floor;
    }
    return b;
}

void Building::setJudgeWin_Checkstate(bool flag){
    judgeWindow.setCheck_state(flag);
}

void Building::Simulation(){
     timer->start(100);
     timer->setSingleShot(true);
}

void Building::update(){
    data.nowfloor = scheduler.getNowFloor();
    data.nowState = scheduler.getNowState();
    data.nowPassenger = scheduler.getPassenger();

    data.distance += abs(data.pre_floor-data.nowfloor);
    data.pre_floor = data.nowfloor;

    if(getIndex()<scheduler.get_nowFloor_vecSize()){
        make_file(data.nowfloor,data.nowState,data.nowPassenger);
        for(int i=0;i<data.nowPassenger;i++){

            run(data.nowfloor,data.nowState);
        }
        timer->start(100);
    }else{
        timer->stop();
        setJudgeWin_Checkstate(true);
        judgeWindow.scheduleEnd();
    }
    scheduler.updateIndex();
    //data.distance = judgeWindow.getDistance();
    //timer->start(100);
    emit this->UpdateGUI();
}

void Building::make_file(int floor,int state,int number){
    operation_path<<setw(2)<<floor+1<<" | "<<state<<" | "<<number<<endl;
}



