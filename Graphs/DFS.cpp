//
// Created by kapar on 16-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>> graph, int u, map<int, bool> &visited) {
    visited[u] = true;
    cout << u << " ";
    for (auto i: graph[u]) {
        if (!visited[i]) DFS(graph, i, visited);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>());
    int u, v;
    cin >> u >> v;
    while (u != -1 and v != -1) {
        graph[u].push_back(v);
        graph[v].push_back(u);
        cin >> u >> v;
    }
    map<int, bool> visited;
    DFS(graph, 1, visited);
}