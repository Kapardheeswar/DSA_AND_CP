//
// Created by kapar on 19-08-2023.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<vector<int>> dfsSets;

void dfs(vector<int>& visited, vector<int>& dfsSet, int u) {
    visited[u] = 1;
    dfsSet.push_back(u);
    for (auto ele : graph[u]) {
        if (!visited[ele]) {
            dfs(visited, dfsSet, ele);
        }
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n+1);

    int u, v;
    while (m) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        m--;
    }

    vector<int> visited(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> dfsSet;
            dfs(visited, dfsSet, i);
            dfsSets.push_back(dfsSet);
        }
    }

    int size = dfsSets.size();
    cout << size - 1 << endl;
    for (int i = 0; i < size - 1; i++) {
        cout << dfsSets[i][0] << " " << dfsSets[i + 1][0] << endl;
    }

    return 0;
}
