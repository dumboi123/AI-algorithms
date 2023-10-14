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

bool increaseRight(const Line &a,const Line &b){
    return a.rightP < b.rightP ;
}

bool increaseLength(const Line &a,const Line &b){
    return abs(a.rightP - a.leftP) < abs(b.rightP - b.leftP) ;
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

void Greedy_1_2_3(vector<Line> &LineList, bool (*condition)(const Line &, const Line &)){
    sort(LineList.begin(), LineList.end(),condition);

    vector<Line> newList;
    newList.push_back(LineList[0]);
    for (int i = 1; i < LineList.size(); i++)
    {
        bool cons = true;
        for ( auto x : newList)
        {
            if(LineList[i].leftP >= x.leftP && LineList[i].leftP <= x.rightP){
                cons = false;
                break;
            }
            else if(LineList[i].rightP >= x.leftP && LineList[i].rightP <= x.rightP){
                cons = false;
                break;
            }
            else if(LineList[i].leftP <= x.leftP && LineList[i].rightP >= x.rightP){
                cons = false;
                break;
            }
        }
        if(cons) newList.push_back(LineList[i]);
    }
    for (int i = 0; i < newList.size(); i++)
    {
        cout<< newList[i].leftP<<", "<<newList[i].rightP<<endl;
    }
    
    cout<<newList.size();  
}

int main(){
    int n;
    vector<Line> LineList;
    ifstream ifs("line1.txt");
    ifs >> n;
    readFile(LineList,n,ifs);
    //choose your type of algorithm:
    //Greedy_1 => increaseLeft
    //Greedy_2 => increaseLength
    //Greedy_3 => increaseRight
    Greedy_1_2_3(LineList,increaseRight);
}