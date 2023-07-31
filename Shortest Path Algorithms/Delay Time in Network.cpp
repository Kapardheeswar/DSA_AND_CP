//
// Created by kapar on 29-07-2023.
//
#include<bits/stdc++.h>

using namespace std;

int networkDelayTime(vector<vector<int>> times, int n, int k) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto vec: times) {
        int u = vec[0];
        int v = vec[1];
        int w = vec[2];
        graph[u].push_back({v, w});
    }
    set<vector<int>> s;
    vector<int> dist(graph.size(), INT_MAX);
    dist[k] = 0;
    s.insert({dist[k], k});
    while (!s.empty()) {
        auto it = s.begin();
        int distTillNow = it->at(0);
        int u = it->at(1);
        s.erase(it);
        for (auto vp: graph[u]) {
            int v = vp.first;
            int w = vp.second;
            if (distTillNow + w < dist[v]) {
                auto f = s.find({dist[v], v});
                if (f != s.end()) s.erase(f);
                dist[v] = distTillNow + w;
                s.insert({dist[v], v});
            }
        }
    }

    int maxTime = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (i != k) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
    }
    return maxTime;
}

int main() {
    int n = 4;
    int k = 2;
    vector<vector<int>> times = {{2, 1, 1},
                                 {2, 3, 1},
                                 {3, 4, 1}};
    cout << networkDelayTime(times, n, k);
}