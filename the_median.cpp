#include "the_median.h"
#include <QDebug>
#include <QSqlError>



The_Median::The_Median()
{

}
The_Median::~The_Median()
{

}

string The_Median::solve(string s){
    string ans;
        stringstream ss;
        ss<<s;

        QSqlQuery query;
        query.exec("DROP DATABASE IF EXISTS CITYDATABASE;");
        query.exec("CREATE DATABASE CITYDATABASE;");
        query.exec("USE CITYDATABASE;");
        query.exec("DROP TABLE IF EXISTS CITYTABLE;");
        query.exec("CREATE TABLE CITYTABLE (ID INT,COUNTRY VARCHAR (50), CITY VARCHAR (60), LAT DOUBLE, LON DOUBLE,PRIMARY KEY (ID));");
        query.exec("SELECT * FROM CITYTABLE;");
        query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' INTO TABLE CITYTABLE FIELDS TERMINATED BY ',' ENCLOSED BY '\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS;");

        //query.exec("SET SQL_SAFE_UPDATES=0;");

        int a,b,m;
        string a1,a2;
        ss>>a>>b>>a1>>m>>a2;
        if(a1=="lat")
        {
            a1="LAT";
        }
        else
        {
            a1="LON";
        }
        if(a2=="asc")
        {
            a2="ASC";
        }
        else
        {
            a2="DESC";
        }
        //cout<<a<<" "<<b<<" "<<a1<<" "<<m<<" "<<a2<<endl;

        QString q;
        //q.sprintf("SELECT AVG(%s) FROM(SELECT %s FROM (SELECT * FROM (SELECT TT1.%s FROM (SELECT T1.%s FROM (SELECT * FROM (SELECT * FROM (SELECT * FROM CITYTABLE WHERE ID LIKE '%d') AS t1 ORDER BY %s %s) AS t2 LIMIT %d,%d)AS T1) AS TT1 union All SELECT TT2.%s FROM (SELECT T1.%s FROM (SELECT * FROM (SELECT * FROM (SELECT * FROM CITYTABLE WHERE ID LIKE '%%d') AS t1 ORDER BY %s %s) AS t2 LIMIT %d,%d)AS T1 ) AS TT2) AS TT3 ORDER BY %s DESC) AS TT4 LIMIT %d,2)AS TTT;",a1.c_str(),a1.c_str(),a1.c_str(),a1.c_str(),m,a1.c_str(),a2.c_str(),a-1,b-a+1,a1.c_str(),a1.c_str(),m,a1.c_str(),a2.c_str(),a-1,b-a+1,a1.c_str(),b-1);

        q.sprintf("SELECT round(AVG(%s),4) FROM (SELECT ROWNUM,%s FROM (SELECT * FROM(SELECT @i := @i + 1 as ROWNUM ,%s FROM (SELECT * FROM (SELECT * FROM (SELECT * FROM (SELECT * FROM CITYTABLE WHERE ID LIKE '%_%d') AS t1 ORDER BY %s %s) AS t2 LIMIT %d,%d)AS T1 union all (SELECT * FROM (SELECT * FROM (SELECT * FROM (SELECT * FROM CITYTABLE WHERE ID LIKE '%_%d') AS t1a ORDER BY %s %s) AS t2a LIMIT %d,%d) AS T2))AS T ORDER BY %s ASC)AS TT,(select @i := 0)AS TMP)AS TTT GROUP by ROWNUM having ROWNUM=@i/2 or ROWNUM=@i/2+1)AS A;",a1.c_str(),a1.c_str(),a1.c_str(),m,a1.c_str(),a2.c_str(),a-1,b-a+1,m,a1.c_str(),a2.c_str(),a-1,b-a+1,a1.c_str());

        //qDebug()<<q<<endl;
        //query.exec(q);
        query.exec(q);
        query.next();
        //qDebug()<<query.value(0)<<endl;
        double d=query.value(0).toDouble();
        stringstream ds;
        ds<<fixed<<setprecision(4)<<d;
        //ds<<query.value(0).toString().toStdString();
        ans=ds.str();
        if(ds.str()=="0.0000")
            ans="NULL";


        return ans;
}
