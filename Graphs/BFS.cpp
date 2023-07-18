//
// Created by kapar on 16-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<int> BFS(vector<vector<int>> graph, int source) {
    int n = graph.size();
    vector<int> ans;
    queue<int> q;
    map<int, bool> m;
    q.push(source);
    while (!q.empty()) {
        int ele = q.front();
        q.pop();
        if (!m[ele]) {
            m[ele] = true;
            ans.push_back(ele);
        }
        for (int i: graph[ele]) {
            if (!m[i]) {
                q.push(i);
            }
        }
    }
    return ans;
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
    vector<int> ans = BFS(graph, 1);
    for (int i: ans) cout << i << " ";
}
/*
 7
0 1
1 2
2 3
3 5
5 6
4 5
0 4
3 4
-1 -1
 */