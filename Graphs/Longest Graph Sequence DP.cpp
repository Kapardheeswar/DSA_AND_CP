//
// Created by kapar on 17-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

void
dfs(vector<vector<int>> graph, vector<vector<int>> &cache, int m, int n, int i, int j, vector<vector<bool>> &visited) {
    visited[i][j] = true;
    int ans = 1;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 and ny >= 0 and nx < m and ny < n and graph[i][j] < graph[nx][ny]) {
            if (visited[nx][ny]) {
                ans = max(ans, cache[nx][ny] + 1);
            } else {
                dfs(graph, cache, m, n, nx, ny, visited);
                ans = max(ans, cache[nx][ny] + 1);
            }
        }
    }
    cache[i][j] = ans;
    return;
}

int getLongestGraphSequence(vector<vector<int>> graph) {
    int m = graph.size();
    int n = graph[0].size();
    int size = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> cache(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(graph, cache, m, n, i, j, visited);
                size = max(size, cache[i][j]);
            }
        }
    }
    return size;
}

int main() {
    vector<vector<int>> graph = {
            {0, 2,  4,  3,  2},
            {7, 6,  5,  5,  1},
            {8, 9,  7,  18, 14},
            {5, 10, 11, 12, 13}
    };
    cout << getLongestGraphSequence(graph);
}
