#include<iostream>
#include<fstream>
using namespace std;

void ReadFile(int **a, int n, ifstream &ifs){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            ifs>>a[i][j];
    }
}

bool ColorAble(int n,int v, int color, int *colors, int **graph) {
    for (int i = 0; i < n; i++) {
        //xét kề + màu các đỉnh xung quanh
        //nếu kề + chưa có màu
        if (graph[v][i] == 1 && colors[i] == color) {
            return false;
        }
    }
    return true;
}

void Coloring(int **graph,int n) {
    int*colors = new int [n];
    fill(colors,colors+n, -1); 

    colors[0] = 1; 
    int maxColor = 1;

    for (int i = 1; i < n; i++) {//quét từng đỉnh
        for (int color = 1; color <= maxColor + 1; color++) {//quét từng màu cho 1 đỉnh
            if (ColorAble(n, i, color, colors, graph)) {//quét check màu các đỉnh xung quanh
                colors[i] = color;
                if (color > maxColor) {
                    maxColor = color;
                }
                break;
            }
        }
    }

    cout<<maxColor<<endl;

    for (int i = 0; i < n; i++)
        cout<<colors[i]<<" ";

    delete[] colors;

}


int main()
{   
    ifstream ifs("test.txt");
    int n;
    ifs>>n;
    int **graph = new int*[n];
    for (int i = 0; i < n; i++)
        graph[i] = new int[n];

    ReadFile(graph,n,ifs);

    Coloring(graph,n);
    for (int i = 0; i < n; i++)
        delete[] graph[i];
    delete[] graph;
} 
