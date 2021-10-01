CREATE DATABASE IF NOT EXISTS  aoopstudent;
USE aoopstudent;
DROP TABLE if exists floorscore;
DROP TABLE IF EXISTS totalpath;
CREATE TABLE IF NOT EXISTS floorscore(stud_id1 char(7),stud_name1 varchar(5),stud_id2 char(7),stud_name2 varchar(5),floor int,timespent bigint,pass int,totalques int,totalscore bigint);
CREATE TABLE IF NOT EXISTS totalpath(stud_id1 char(7),stud_name1 varchar(5),stud_id2 char(7),stud_name2 varchar(5),pathlen int);

INSERT INTO floorscore(stud_id1,stud_name1,stud_id2,stud_name2,floor,timespent,pass,totalques,totalscore)
VALUES('0710774','楊士賢','0710768','陳詮翰',1,19999999,10,10,10000);
INSERT INTO totalpath(stud_id1,stud_name1,stud_id2,stud_name2,pathlen)
VALUE('0710774','楊士賢','0710786','陳詮翰',517);
SHOW tables;
