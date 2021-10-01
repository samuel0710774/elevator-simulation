#include "database1.h"
#include<sstream>
#include <QDebug>
#include <QSqlError>


Database1::Database1()
{

}
void Database1::step7()
{
    order = "SELECT count(City) - count(DISTINCT City) FROM citytable  WHERE CITY regexp '^[3]' and CITY regexp '[^aeiou]$' and  LAT > 2 and LON < 1;";
    order.replace(134, 1, vs[2]);
    order.replace(122, 1, vs[1]);
    order.replace(79, 1, vs[0]);
   // qDebug()<<order;
    //SELECT count(City) - count(DISTINCT City) FROM citytable  WHERE CITY regexp '^[nz]' and CITY regexp '[^aeiou]$' and  LAT > 121.5 and LON < 25.3;
}
void Database1::step8()
{
    order = "UPDATE citytable SET LAT = LAT * 3, LON = LON * 2  WHERE (ID&1) = 0;";
    if(vs[5]=="od")
        order.replace(66, 1, "1");
    else
        order.replace(66, 1, "0");

    order.replace(48, 1, vs[4]);
    order.replace(33, 1, vs[3]);
   //  qDebug()<<order;
    //UPDATE citytable SET LAT = LAT * 121.5, LON = LON * 25.3  WHERE (ID&1) = 0;
}
void Database1::step9()
{
    order = "SELECT ROUND(sum(tmp.LAT), s), ROUND(sum(tmp.LON), s), MAX(CHAR_LENGTH(tmp.City))-MIN(CHAR_LENGTH(tmp.City)) FROM (select * FROM citytable where (ID&1) = e ORDER BY CHAR_LENGTH(CITY) d, CITY desc LIMIT 0,m ) AS tmp;";
    /* SELECT ROUND(sum(tmp.LAT), 3), ROUND(sum(tmp.LON), 3), MAX(CHAR_LENGTH(tmp.City))-MIN(CHAR_LENGTH(tmp.City)) FROM (select * FROM citytable where (ID&1) = 0 ORDER BY
    CHAR_LENGTH(CITY) desc, CITY desc LIMIT 0,5 ) AS tmp ; */
    // 204 183 154 51 27
    order.replace(204, 1, vs[6]);

    if(vs[8]=="asc")
        order.replace(183, 1, "asc");
    else
        order.replace(183, 1, "desc");

    if(vs[7]=="even")
        order.replace(154, 1, "0");
    else
        order.replace(154, 1, "1");


    order.replace(51, 1, vs[9]);
    order.replace(27, 1, vs[9]);
   // qDebug()<<order<<endl;

}

vector<QString>StringToVectorQString(string s){
    vector<QString>v;
    stringstream ss;
    ss<<s;
    string str;
    QString q_str;
    while(ss>>str)
    {
        q_str = QString::fromStdString(str);
        v.push_back(q_str);
    }
    return v;
}

void Load_Data(){
    QSqlQuery query;
    query.exec("USE CityDatabase;");
    query.exec("DROP TABLE IF EXISTS CityTable;");
    query.exec("CREATE TABLE IF NOT EXISTS CityTable(id int,country varchar(50),city varchar(60),lat double,lon double,primary key(id));");
    //Demo
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' INTO TABLE CityTable FIELDS TERMINATED BY ',' ENCLOSED BY'\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS;");
}

string Database1::solve(string s)
{
    QString ans;
    QSqlQuery query;

    Load_Data();
    vs = StringToVectorQString(s);

    order.clear();
    step7();
    query.exec(order);
    query.first();
    ans = query.value(0).toString() + " ";

    step8();
    query.exec(order);


    step9();
    query.exec(order);
    query.exec(order);
    query.first();
    ans += query.value(0).toString() + " " + query.value(1).toString() + " " + query.value(2).toString();

    if(ans.toStdString().size())
        return ans.toStdString();
    else
        return "NULL";

}
