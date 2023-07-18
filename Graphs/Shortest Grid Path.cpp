//
// Created by kapar on 17-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int getShortestGridPath(vector<vector<int>> graph, int i, int j, vector<vector<bool>> visited) {
    int m = graph.size();
    int n = graph[0].size();
    if (i >= graph.size() and j >= graph[0].size()) return 0;
    if (i == graph.size() - 1 and j == graph[0].size() - 1) return graph[i][j];
    visited[i][j] = true;
    int ans = INT_MAX;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 and ny >= 0 and nx < m and ny < n and !visited[nx][ny]) {
            int currAns = getShortestGridPath(graph, nx, ny, visited);
            ans = min(ans, currAns + graph[i][j]);
        }
    }
    visited[i][j] = false;
    return ans;
}

int main() {
//    vector<vector<int>> matrix = {
//            {31,  100, 64,  12,  18},
//            {10,  13,  47,  157, 6},
//            {100, 113, 174, 11,  33},
//            {88,  124, 41,  20,  140},
//            {99,  32,  111, 41,  20}
//    };
//    vector<vector<int>> matrix = {{1, 2, 3},
//                                  {4, 5, 6},
//                                  {7, 8, 9}};
    vector<vector<int>> matrix = {{1, 3},
                                  {4, 2}};
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
    cout << getShortestGridPath(matrix, 0, 0, visited);
}