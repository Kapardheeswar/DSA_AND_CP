//
// Created by kapar on 17-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int getShortestPathToEnd(vector<vector<int>> graph) {
    int m = graph.size();
    int n = graph[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = graph[0][0];
    set<vector<int>> s;
    s.insert({dist[0][0], 0, 0});
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    while (!s.empty()) {
        auto it = s.begin();
        int currentDist = it->at(0);
        int x = it->at(1);
        int y = it->at(2);
        s.erase(it);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 and ny >= 0 and nx < m and ny < n and currentDist + graph[nx][ny] < dist[nx][ny]) {
                auto it = s.find({dist[nx][ny], nx, ny});
                if (it != s.end()) s.erase(it);
                dist[nx][ny] = currentDist + graph[nx][ny];
                s.insert({dist[nx][ny], nx, ny});
            }
        }
    }
    return dist[m - 1][n - 1];
}

int main() {
    vector<vector<int>> matrix = {
            {31,  100, 65,  12,  18},
            {10,  13,  47,  157, 6},
            {100, 113, 174, 11,  33},
            {88,  124, 41,  20,  140},
            {99,  32,  111, 41,  20}
    };
    cout << getShortestPathToEnd(matrix);
}