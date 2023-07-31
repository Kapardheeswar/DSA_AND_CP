//
// Created by kapar on 29-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<int> bellManFord(vector<vector<int>> edges, int n, int source) {
    vector<int> dist(n + 1, INT_MAX);
    dist[source] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto vec: edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            if (dist[u] != INT_MAX and dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }
    for (auto vec: edges) {
        int u = vec[0];
        int v = vec[1];
        int w = vec[2];
        if (dist[u] != INT_MAX and dist[u] + w < dist[v]) {
            cout << "Found Negative Weight Cycle" << endl;
            exit(0);
        }
    }

    return dist;
}

int main() {
    vector<int> dist = bellManFord({{1, 2, 3},
                                    {2, 3, 4},
                                    {1, 3, -10}}, 3, 1);
    for (int i = 1; i <= 3; i++)cout << dist[i] << " ";
}