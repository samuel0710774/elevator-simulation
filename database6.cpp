#include "database6.h"
void Database6::step14()
{
    //UPDATE CITYTABLE AS C SET LAT = (@temp:=LAT), LAT = LON, LON = @temp WHERE id&1 = 1;
    order = "UPDATE CITYTABLE AS C SET LAT = (@temp:=LAT), LAT = LON, LON = @temp WHERE id&1 = ";
    if(vs[0]=="od")
        order += "1;";
    else
        order += "0;";
   // qDebug()<<order;
}
void Database6::step15()
{
    //UPDATE CITYTABLE AS C SET LAT = LON WHERE MOD(ID,10) = 6;
    order = "UPDATE CITYTABLE AS C SET LAT = LON WHERE MOD(ID,10) = ";
    order += vs[1] + ";"; //m
  //  qDebug()<<order;
}
void Database6::step16()
{
    QString t0, t1, t2, t3, t4, t5, t6, t7, t8, tmp, o;
    int offset = vs[3].toInt() -1;
    t0 = "select cast(tmp.a1 as char), cast(tmp.a2 as char) from ";
    t1 = "((SELECT a.LAT as a1, a.LON as a2 ";
    tmp = "(SELECT ROUND(LAT,n) AS LAT, ROUND(LON, n) AS LON from CITYTABLE )";
    //99 84 40 18
    tmp.replace(99, 1, vs[2]);
    tmp.replace(84, 1, vs[2]);
    tmp.replace(40, 1, vs[2]);
    tmp.replace(18, 1, vs[2]);

    t2 = "FROM " + tmp + " as a, ";
    t3 = tmp + "as b ";
    t4 = "where a.LAT = b.LON AND a.LON = b.LAT AND a.LAT < a.LON group by a.lat, a.lon order by a.lat, a.lon) UNION (SELECT a.LAT as a1, a.LON as a2  FROM " + tmp + " as a   WHERE a.LAT = a.LON group by a.LAT having count(a.LAT) > 1 order by a.lat)) as tmp order by tmp.a1, tmp.a2 ";
    t5 = " limit " + o.setNum(offset) +", 1;";

    order = t0 + t1 + t2 + t3 + t4 + t5;
   // qDebug()<<tmp<<endl<<order<<endl;
    /*
select cast(tmp.a1 as char), cast(tmp.a2 as char)
from ((SELECT a.LAT as a1, a.LON as a2
FROM (SELECT ROUND(LAT,1) AS LAT, ROUND(LON, 1) AS LON from CITYTABLE)  as a,
    (SELECT ROUND(LAT,1) AS LAT, ROUND(LON, 1) AS LON from CITYTABLE) as b
    where a.LAT = b.LON AND a.LON = b.LAT AND a.LAT < a.LON group by a.lat, a.lon order by a.lat, a.lon)
UNION (SELECT a.LAT as a1, a.LON as a2
    FROM (SELECT ROUND(LAT,1) AS LAT, ROUND(LON, 1) AS LON from CITYTABLE ) as a
    WHERE a.LAT = a.LON group by a.LAT having count(a.LAT) > 1 order by a.lat)) as tmp order by tmp.a1, tmp.a2 limit 1,1;

    */
}

vector<QString>Database6::StringToVectorQString(string s){
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

void Database6::Load_Data(){
    QSqlQuery query;
    query.exec("USE CityDatabase;");
    query.exec("DROP TABLE IF EXISTS CityTable;");
    query.exec("CREATE TABLE IF NOT EXISTS CityTable(id int,country varchar(50),city varchar(60),lat double,lon double,primary key(id));");
    //Demo
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' INTO TABLE CityTable FIELDS TERMINATED BY ',' ENCLOSED BY'\"' LINES TERMINATED BY '\r\n' IGNORE 1 ROWS;");
}
string Database6::solve(string s)
{
    vs = StringToVectorQString(s);
   // qDebug()<<QString::fromStdString(s);
    QString ans;
    QSqlQuery query;
    Load_Data();
    step14();
    query.exec(order);
    step15();
    query.exec(order);

    step16();
    query.exec(order);

    query.first();

    ans = query.value(0).toString() + " " + query.value(1).toString();
    //qDebug()<<order<<"\n"<<ans<<endl;

    if(ans.toStdString().size())
        return ans.toStdString();
    else
        return "NULL";
}
Database6::Database6()
{

}
/*
UPDATE CITYTABLE AS C SET LAT = (@temp:=LAT), LAT = LON, LON = @temp WHERE id&1 = 1;

UPDATE CITYTABLE AS C SET LAT = LON WHERE MOD(ID,10) = 6;

select cast(tmp.a1 as char), cast(tmp.a2 as char)
from ((SELECT a.LAT as a1, a.LON as a2
FROM (SELECT ROUND(LAT,1) AS LAT, ROUND(LON, 1) AS LON from CITYTABLE)  as a,
    (SELECT ROUND(LAT,1) AS LAT, ROUND(LON, 1) AS LON from CITYTABLE) as b
    where a.LAT = b.LON AND a.LON = b.LAT AND a.LAT < a.LON group by a.lat, a.lon order by a.lat, a.lon)
UNION (SELECT a.LAT as a1, a.LON as a2
    FROM (SELECT ROUND(LAT,1) AS LAT, ROUND(LON, 1) AS LON from CITYTABLE ) as a
    WHERE a.LAT = a.LON group by a.LAT having count(a.LAT) > 1 order by a.lat)) as tmp order by tmp.a1, tmp.a2 limit 1,1;

*/
