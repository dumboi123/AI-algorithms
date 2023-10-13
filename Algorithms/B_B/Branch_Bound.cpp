#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include<fstream>

using namespace std;

int n; 
int** graph; 
int *bestPath= new int[n*n];
int bestCost = INT_MAX; 

void ReadFile(int **a, int n, ifstream &ifs){
    for(int i=0;i<n;i++){
        for (int j = 0; j < n; j++)
            ifs >>a[i][j];        
    }
}

void tspBranchAndBound(int currentCity,int *path, bool *visited, int cost, int level) {
    if (level == n) {
        cost+=graph[currentCity][0];
        if (cost < bestCost) {
            bestCost = cost;
            copy(path, path + n, bestPath);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            path[level] = i;

            if (cost + graph[currentCity][i] < bestCost) {
                tspBranchAndBound(i,path, visited, cost + graph[currentCity][i], level + 1);
            }            
            visited[i] = false;
        }
    }
}

int main() {
    ifstream ifs("tsp_20vertex.txt");
    ifs >> n;

    bool *visited = new bool[n*n];
    graph = new int*[n];
    for(int i=0;i<n;i++){
        graph[i] = new int [n];
    }

    ReadFile(graph,n,ifs);
    cout<<n<<endl;
    int *path = new int[n];
    visited[0] = true;
    path[0] = 0;
    tspBranchAndBound(0,path, visited, 0, 1);

    cout << "Minimum cost: " << bestCost << endl;
    cout << "Optimal path: ";
    for (int i = 0; i < n; i++) {
        cout << bestPath[i] << " ";
    }
    cout << bestPath[0] << endl;

    for(int i=0;i<n;i++){
        delete[] graph[i];
    } 
    delete[] graph;

    ifs.close();
    return 0;
}