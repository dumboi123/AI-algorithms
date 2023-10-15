#include<iostream>
#include<vector>
#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;

struct Line
{
    int leftP;
    int rightP;
};

bool increaseLeft(const Line &a,const Line &b){
    return a.leftP < b.leftP ;
}

void readFile(vector<Line> &a, int n, ifstream &ifs){
    Line value;
    for (int i = 0; i < n; i++)
    {
        ifs>>value.leftP;
        ifs>>value.rightP;
        a.push_back(value);
    }
}

void Schedule_finish_jobs(vector<Line> &LineList){
    sort(LineList.begin(), LineList.end(),increaseLeft);
    vector<Line> newlist;
    int finish_time =0, ontimejob =0;
    for (int i = 0; i < LineList.size(); i++)
    {
        finish_time += LineList[i].leftP;
        if (finish_time <= LineList[i].rightP){
            newlist.push_back(LineList[i]);
            ontimejob++; 
        }
                  
    } 
    cout<<"Number of Jobs finished on time : "<<ontimejob<<endl;
    for (int i = 0; i < newlist.size(); i++)
    {
        cout<< newlist[i].leftP <<" "<<newlist[i].rightP<<endl;
    }
    
   
}

int main(){
    int n;
    vector<Line> LineList;
    ifstream ifs("schedule1.txt");
    ifs >> n;
    readFile(LineList,n,ifs);
    Schedule_finish_jobs(LineList);
    ifs.close();
    return 0;
}