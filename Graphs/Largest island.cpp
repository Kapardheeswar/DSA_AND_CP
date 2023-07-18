//
// Created by kapar on 17-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>> graph, int m, int n, int i, int j, vector<vector<bool>> &visited) {
    visited[i][j] = true;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int I_landSize = 1;
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 and ny >= 0 and nx < m and ny < n and graph[nx][ny] == 1 and !visited[nx][ny]) {
            int sizeOfRemainingLand = dfs(graph, m, n, nx, ny, visited);
            I_landSize += sizeOfRemainingLand;
        }
    }
    return I_landSize;
}

int getLargest_iLand(vector<vector<int>> graph) {
    int m = graph.size();
    int n = graph[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int largest = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] and !visited[i][j]) {
                int size = dfs(graph, m, n, i, j, visited);
                if (size > largest) largest = size;
            }
        }
    }
    return largest;
}

int main() {
    vector<vector<int> > grid = {
            {1, 0, 0, 1, 0},
            {1, 0, 1, 0, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 1, 1, 1},
            {1, 0, 1, 1, 0}
    };
    cout << getLargest_iLand(grid) << endl;
//    cout<<largest_island(grid);
}