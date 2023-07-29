//
// Created by kapar on 26-07-2023.
//
#include<bits/stdc++.h>

using namespace std;

vector<int> solve(int n, vector<vector<int>> arr) {
    vector<vector<int>> graph(n + 1);
    map<int, int> indegree;
    for (auto vec: arr) {
        int u = vec[0];
        int v = vec[1];
        graph[u].push_back(v);
        indegree[v]++;
    }
    set<int> s;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) s.insert(i);
    }
    while (!s.empty()) {
        auto it = s.begin();
        int x = *it;
        s.erase(it);
        ans.push_back(x);
        for (auto k: graph[x]) {
            indegree[k]--;
            if (indegree[k] == 0) s.insert(k);
        }
    }
    if (ans.size() != n) return {};
    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> arr = {{2, 1},
                               {3, 4},
                               {2, 4}};
    vector<int> perm = solve(n, arr);
    for (auto i: perm)cout << i << " ";
}
