//
// Created by kapar on 23-09-2023.
//
#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> &graph, int u, int parent, int color, vector<int> &colors, vector<int> &visited) {
    visited[u] = 1;
    colors[u] = color;
    for (auto k: graph[u]) {
        if (u == parent) continue;
        else {
            if (colors[k] == 0) if (!dfs(graph, k, u, color xor 3, colors, visited)) return false;
            if (colors[k] == colors[u]) return false;
        }
    }
    return true;
}

bool colorNodes(vector<vector<int>> &graph, vector<int> &colors) {
    vector<int> visited(graph.size(), 0);
    for (int i = 1; i < graph.size(); i++) {
        if (!visited[i]) if (!dfs(graph, i, -1, 1, colors, visited)) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    int k1, k2;
    int cnt = 0;
    while (cnt < m) {
        cin >> k1 >> k2;
        graph[k1].push_back(k2);
        graph[k2].push_back(k1);
        cnt++;
    }
    vector<int> colors(n + 1);
    if (colorNodes(graph, colors)) {
        for (int i = 1; i < colors.size(); i++) cout << colors[i] << " ";
    } else {
        cout << "IMPOSSIBLE";
    }
}