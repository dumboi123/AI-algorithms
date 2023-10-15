#include <iostream>
#include <vector>
#include <algorithm>
#include<fstream>
using namespace std;

int N; // Số lượng đỉnh
vector<vector<int>> adjacencyMatrix; // Ma trận kề

void ReadFile(vector<vector<int>> &a, int n, ifstream &ifs){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            ifs>>a[i][j];
    }
}

// Đếm số lượng màu đã được sử dụng cho một đỉnh
int countUsedColors(int v, vector<int>& colors) {
    vector<bool> used(N, false); // Đánh dấu các màu đã được sử dụng

    for (int i = 0; i < N; i++) {
        if (adjacencyMatrix[v][i] == 1 && colors[i] != -1) {
            used[colors[i]] = true;
        }
    }

    int count = 0;
    for (bool isUsed : used) {
        if (isUsed) {
            count++;
        }
    }

    return count;
}

// Tìm đỉnh có DSAT lớn nhất (Degree of Saturation)
int findVertexWithMaxDSAT(vector<int>& colors) {
    int maxDSAT = -1;
    int vertex = -1;

    for (int i = 0; i < N; i++) {
        if (colors[i] == -1) {
            int dsat = countUsedColors(i, colors);
            if (dsat > maxDSAT) {
                maxDSAT = dsat;
                vertex = i;
            }
        }
    }

    return vertex;
}

// Tô màu đồ thị bằng thuật toán DSATUR
void colorGraphDSATUR(vector<int>& colors) {
    colors[0] = 0; // Gán màu 0 cho đỉnh đầu tiên

    for (int i = 1; i < N; i++) {
        int vertex = findVertexWithMaxDSAT(colors);

        vector<bool> usedColors(N, false); // Đánh dấu các màu đã được sử dụng

        for (int j = 0; j < N; j++) {
            if (adjacencyMatrix[vertex][j] == 1 && colors[j] != -1) {
                usedColors[colors[j]] = true;
            }
        }

        int color;
        for (color = 0; color < N; color++) {
            if (!usedColors[color]) {
                colors[vertex] = color;
                break;
            }
        }

        if (color == N) {
            colors[vertex] = N; // Màu mới
        }
    }
}

int main() {
    ifstream ifs("test.txt");
    ifs>>N;
    adjacencyMatrix.resize(N, vector<int>(N, 0));

    ReadFile(adjacencyMatrix,N,ifs);

    vector<int> colors(N, -1); // Mảng lưu màu của các đỉnh

    colorGraphDSATUR(colors);

    for (int i = 0; i < N; i++) {
        cout << "Apex " << i << ": Color " << colors[i] << endl;
    }
    ifs.close();
    return 0;
}
