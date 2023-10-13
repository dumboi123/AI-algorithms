// GREEDY TRAVELING SALESMAN
#include<iostream>
#include<fstream>
#include <algorithm>
using namespace std;

int n,m,cost,temp,bestCost,TrueBestCost = INT_MAX;
int **graph;
int *Path, *TruePath;
bool *visited;

void ReadFile(int **a, int n, ifstream &ifs){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ifs>> a[i][j];    
}
void WriteFile( int **a, int n, ofstream &ofs){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            ofs<< a[i][j] <<" ";
        ofs<<endl;  
    }  
}

void GTS_1(int level, int **a, int *Path, bool *visited, int currentCity, int &bestCost){
    
    fill(visited,visited+n+1, false);
    fill(Path,Path+n+1, false);
    int firstcity = currentCity;
    Path[0]=currentCity; 
    while (level!=n)
    {
        visited[currentCity] = true;
        temp=0;
        cost = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {   
                if(cost > a[currentCity][i])
                {
                    cost = a[currentCity][i];
                    temp = i;
                }
            }
        }
        currentCity=temp;
        bestCost+=cost;
        Path[level]=currentCity;
        level+=1;
    }
    Path[n]=firstcity;
    bestCost+=a[currentCity][firstcity];
}

void GTS_2(int *StartCity){
    for (int i = 0; i < m; i++)
    {
        int bestCostPerCity = 0;
        GTS_1(1,graph,Path,visited,StartCity[i],bestCostPerCity);
        if (TrueBestCost>bestCostPerCity)
        {
            TrueBestCost = bestCostPerCity;
            copy(Path, Path + n + 1,TruePath);
        }
    }
}

int main(){
    ifstream ifs("GTS2b.txt");
    // ofstream ofs("result.txt");
    ifs>>n>>m;
    bestCost=0;
    int *StartCity = new int[10];
    Path = new int[n+1];
    visited = new bool[n];
    graph = new int*[n];
    for (int i = 0; i < n; i++)
        graph[i] = new int[n];
    TruePath = new int[n+1];
    for (int i = 0; i < m; i++)
    {
        ifs>>StartCity[i];
        StartCity[i]-=1;
    }
    ReadFile(graph,n,ifs);
    // WriteFile(graph,n,ofs);

    // GTS_1(1,graph,Path,visited,m-1,bestCost);
    // // // for (int i = 0; i < n+1; i++)
    // // //     cout<<Path[i]<<" ";
    // cout<<"\nBest Cost: "<<bestCost;

    
    GTS_2(StartCity);
    // for (int i = 0; i < n+1; i++)
    //     cout<<TruePath[i]<<" ";
    cout<<"\nBest Cost: "<<TrueBestCost;

    for (int i = 0; i < n; i++)
        delete[] graph[i];
    delete[] graph;
    delete[] Path;
    delete[] visited;
    delete[] TruePath;

    ifs.close();
    return 0;
}