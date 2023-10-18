#include <iostream>
#include<fstream>
using namespace std;

void readFile(int **a, int n, ifstream &ifs){
    for (int  i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ifs >> a[i][j];           
}

void writeFile(int **a, int n, ofstream &ofs){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
         ofs<<a[i][j]<<" ";
    ofs<<endl;
    }    
}

void GTS(int **a, int n, int &Total){
    bool *visited = new bool[n];
    fill(visited,visited+n+1, false);

    for (int i = 0; i < n; i++)
    {
        int max =INT_MIN;
        int temp =0;
        for (int j = 0; j < n; j++)
        {
            if(!visited[j]){
                if (max < a[i][j])
                {
                    max = a[i][j];
                    temp =j;
                }                
            }
        }
        visited[temp]=true;
        Total+=max;
    }
    delete[] visited;
}

int main(){
    int **a, n, Total=0;
    ifstream ifs("Assignmenta.txt"); 
    //ofstream ofs;
    ifs >>n;
    a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    readFile(a,n,ifs);

    GTS(a,n,Total);
    cout<<Total;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    ifs.close();
    return 0;
}