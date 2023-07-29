//
// Created by kapar on 26-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
map<int, bool> visited;
vector<int> order;

void topologicalSort(vector<vector<int>> graph, int u) {
    visited[u] = true;
    for (auto v: graph[u]) {
        if (!visited[v]) topologicalSort(graph, v);
    }
    order.push_back(u);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>());
    int u, v;
    cin >> u >> v;
    while (u != -1 and v != -1) {
        graph[u].push_back(v);
        cin >> u >> v;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) topologicalSort(graph, i);
    }
    reverse(order.begin(), order.end());
    for (auto i: order)cout << i << " ";
}
/*
 * 5
1 2
1 5
2 5
2 4
3 1
3 2
-1 -1
 */