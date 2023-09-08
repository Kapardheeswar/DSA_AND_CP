//
// Created by kapar on 18-08-2023.
//
#include <bits/stdc++.h>

using namespace std;

int getCountFromDFS(vector<vector<int>> graph, int u, map<int, bool> visited, map<int, int> freq, int k) {
    visited[u] = true;
    int ans = 1;
    for (auto e: graph[u]) {
        if (freq[e] >= k and !visited[e]) {
            ans = 1 + getCountFromDFS(graph, e, visited, freq, k);
        }
    }
    return ans;
}

vector<int> getSessionCount(int n, int m, int k, vector<vector<int>> friends) {
    vector<int> ans;
    map<int, int> freq;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int friend1 = friends[i][0];
        int friend2 = friends[i][1];
        freq[friend1]++;
        freq[friend2]++;
        graph[friend1].push_back(friend2);
        graph[friend2].push_back(friend1);
        if (freq[friend1] >= k) {
            int count = getCountFromDFS(graph, friend1, {}, freq, k);
            if (count >= k) ans.push_back(count);
            else ans.push_back(0);
        } else if (freq[friend2] >= k) {
            int count = getCountFromDFS(graph, friend2, {}, freq, k);
            if (count >= k) ans.push_back(count);
            else ans.push_back(0);
        } else ans.push_back(0);
    }
    return ans;
}

int main() {
    int n, m, k;
    n = 4;
    m = 3;
    k = 2;
    vector<vector<int>> friends = {{1, 2},
                                   {3, 2},
                                   {1, 3}};
    vector<int> v = getSessionCount(n, m, k, friends);
    for (auto e: v)cout << e << " ";
}