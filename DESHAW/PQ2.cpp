//
// Created by kapar on 20-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int shortestDist(vector<vector<pair<int, int>>> graph, int source, int target) {
    vector<int> dist(graph.size(), INT_MAX);
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({dist[source], source});
    while (!s.empty()) {
        auto it = s.begin();
        int u = it->second;
        int distTillNow = it->first;
        for (auto p: graph[u]) {
            int v = p.first;
            int w = p.second;
            if (distTillNow + w < dist[v]) {
                auto f = s.find({dist[v], v});
                if (f != s.end()) s.erase(f);
                dist[v] = distTillNow + w;
                s.insert({dist[v], v});
            }
        }
    }
    return dist[target];
}

