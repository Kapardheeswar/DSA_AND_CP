//
// Created by kapar on 31-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
#define INF 1000

vector<vector<int>> floydWarshall(vector<vector<int>> adjacencyMatrix) {
    vector<vector<int>> dist(adjacencyMatrix);
    int n = dist.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<int>> adjMat = {{0,   INF, -2, INF},
                                  {4,   0,   3,  INF},
                                  {INF, INF, 0,  2},
                                  {INF, -1, INF, 0}};
    vector<vector<int>> dist = floydWarshall(adjMat);
    for (auto v: dist) {
        for (auto k: v)cout << k << " ";
        cout << endl;
    }
}