#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

// 3 machines can do job whenever they free -> find the longest time finished
void readFile(vector<int> &a, int n, ifstream &ifs){
    int value =0;
    for (int i = 0; i < n; i++){
        ifs>>value;
        a.push_back(value);
    }       
}

void Schedule(vector<int> &joblist){
    vector<int> TimeMachines(3,0);
    for (int i = 0; i < joblist.size(); i++)
    {
        int AddressMin =0;
        for (int j = 1; j < 3; j++)
        {
            if(TimeMachines[j]<TimeMachines[AddressMin])
                AddressMin = j;
        }
        TimeMachines[AddressMin] += joblist[i];
    }
    int MaxTimeFinished = *std::max_element(TimeMachines.begin(),TimeMachines.end());
    cout << MaxTimeFinished;
}

int main(){
    int n;
    vector<int> jobslist;
    ifstream ifs("schedulea.txt");
    ifs >> n;
    readFile(jobslist,n,ifs);
    Schedule(jobslist);
}