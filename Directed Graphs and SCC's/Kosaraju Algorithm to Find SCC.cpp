//
// Created by kapar on 29-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> scc;
map<int, bool> visited;

void dfs(vector<vector<int>> graph, int u, vector<int> &component) {
    visited[u] = true;
    component.push_back(u);
    for (auto k: graph[u]) {
        if (!visited[k]) dfs(graph, k, component);
    }
}

void topologicalSort(vector<vector<int>> graph, int u, map<int, bool> &visit, vector<int> &order) {
    visit[u] = true;
    for (auto k: graph[u]) {
        if (!visit[k]) topologicalSort(graph, k, visit, order);
    }
    order.push_back(u);
}

vector<vector<int>> getSCC(int n, const vector<vector<int>> &edges) {
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<vector<int>> reverseGraph(n + 1, vector<int>());
    for (auto vec: edges) {
        int u = vec[0];
        int v = vec[1];
        graph[u].push_back(v);
        reverseGraph[v].push_back(u);
    }
    vector<int> order;
    map<int, bool> visit;
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) topologicalSort(graph, i, visit, order);
    }
    reverse(order.begin(), order.end());
    for (auto k: order) {
        if (!visited[k]) {
            vector<int> component;
            dfs(reverseGraph, k, component);
            scc.push_back(component);
            component.clear();
        }
    }
    return scc;
}

int main() {
    vector<vector<int>> SCC = getSCC(4, {{1, 2},
                                         {2, 3},
                                         {3, 1},
                                         {3, 4}});
    for (auto v: SCC) {
        for (auto k: v) cout << k << " ";
        cout << endl;
    }
}