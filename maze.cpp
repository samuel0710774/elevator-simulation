#include "maze.h"
#include <QDebug>

class node{
public:
    int x,y;
    int dir;
    node(int i,int j){
        x=i;
        y=j;
        dir=0;
    }
    ~node(){
        x=0;
        y=0;
        dir=0;
    }
};


Maze::Maze()
{
    M=0;
    N=0;
}

Maze::~Maze(){

}


string Maze::solve(string s){
    char c;
    path.clear();

    QDebug debug = qDebug();

    vector<char>v;
    stringstream ss;
    ss<<s;


    ss>>M;
    ss>>N;



    /*while (ss>>c) {
        v.push_back(c);
    }*/
    //cout<<v.size()<<endl;

    //cout<<"M: "<<M<<"\nN: "<<N<<endl;

    maze = new char *[N];
    for(int i=0;i<N;i++){
        maze[i] = new char [M];
    }

    ans = new char *[N];
    for(int i=0;i<N;i++){
        ans[i] = new char [M];
    }
    visited = new bool *[N];
    for(int i=0;i<N;i++){
        visited[i] = new bool [M];
    }


    debug<<"Question: "<<endl;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ss>>ans[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(ans[i][j]=='2'){
                visited[i][j]=true;
            }else{
                visited[i][j]=false;
            }
            maze[i][j]=ans[i][j];
            //debug<<ans[i][j];
        }
        //debug<<endl;
    }



    /*try {
        //memset(visited,false,sizeof(visited)); throw "memset Wrong!!";
    } catch (const char * s) {
        debug<<QString::fromStdString(s)<<endl;
    }*/

    int start_x,start_y;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(maze[i][j]=='S'){
                start_x=i;
                start_y=j;
            }
            if(maze[i][j]=='E'){
                fx=i;
                fy=j;
            }
        }
    }


    if(isReachable(&maze,&visited,start_x,start_y,&ans)){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                path+=ans[i][j];
                path+=" ";
            }
        }
        //debug<<endl<<"Answer: "<<endl;
        /*for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                debug<<path[i*M+j];
            }
            debug<<endl;
        }*/
    }else{
        debug<<"Rought cannot found!!!"<<endl;
        path="Wrong!";
    }




    for(int i=0;i<N;i++){
        delete [] maze[i];
    }
    delete []maze;
    for(int i=0;i<N;i++){
        delete [] ans[i];
    }
    delete [] ans;
    for(int i=0;i<N;i++){
        delete [] visited[i];
    }
    delete []visited;




    return path;
}


bool Maze::isReachable(char ***maze,bool ***visited,int start_x,int start_y,char ***ans)
{

    qDebug()<<"x: "<<fx<<"y: "<<fy;
    int i = start_x, j = start_y;

    stack<node> s;

    node temp(i, j);

    s.push(temp);

    while (!s.empty()) {


        temp = s.top();
        //qDebug()<<"Now pos:("<<temp.x<<","<<temp.y<<")";
        int d = temp.dir;
        i = temp.x;
        j = temp.y;

        if(temp.dir+1<5){
            temp.dir++;
        }else{
            temp.dir=0;
        }

        s.pop();
        s.push(temp);

        if (i == fx and j == fy) {
            (*ans)[i][j]='E';
            (*ans)[start_x][start_y]='S';
            while (!s.empty()) {
                s.pop();
            }
            return true;
        }
        // 1.向右
        if (d == 0) {
            if (j + 1 < M and (*maze)[i][j + 1]!='2' and !(*visited)[i][j + 1]) {
                node temp1(i, j + 1);       //生成一個node(新的路徑生成)
                (*visited)[i][j + 1] = true;   //表示已經走過
                s.push(temp1);
                (*ans)[temp1.x][temp1.y] = '1';
            }
        }
        // 2.向下
        else if (d == 1) {
            if (i + 1 < N and (*maze)[i + 1][j]!='2' and !(*visited)[i + 1][j]) {
                node temp1(i + 1, j);
                (*visited)[i + 1][j] = true;
                s.push(temp1);
                (*ans)[temp1.x][temp1.y] = '1';
            }
        }
        // 3.向左
        else if (d == 2) {
            if (j - 1 >= 0 and (*maze)[i][j - 1]!='2' and !(*visited)[i][j - 1]) {
                node temp1(i, j - 1);
                (*visited)[i][j - 1] = true;
                s.push(temp1);
                (*ans)[temp1.x][temp1.y] = '1';
            }
        }
        // 4.向上
        else if(d == 3) {
            if (i - 1 >=0 and (*maze)[i - 1][j]!='2' and !(*visited)[i - 1][j]) {
                node temp1(i - 1, j);
                (*visited)[i - 1][j] = true;
                s.push(temp1);
                (*ans)[temp1.x][temp1.y] = '1';
            }
        }
        else {
            (*visited)[temp.x][temp.y] = false;
            s.pop();
            (*ans)[temp.x][temp.y] = '0';
        }
    }

    return false;
}
