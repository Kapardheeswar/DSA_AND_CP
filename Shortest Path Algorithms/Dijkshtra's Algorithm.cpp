//
// Created by kapar on 29-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int getShortestPathWithDijkshtra(vector<vector<pair<int, int>>> graph, int source, int dest) {
    vector<int> dist(graph.size(), INT_MAX);
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({dist[source], source});
    while (!s.empty()) {
        auto it = s.begin();
        s.erase(it);
        int distTillNow = it->first;
        int nodeValue = it->second;
        for (auto p: graph[nodeValue]) {
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
    return dist[dest];
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n);
    int u, v, w;
    cin >> u >> v >> w;
    while (u != -1 and v != -1 and w != -1) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        cin >> u >> v >> w;
    }
    cout << getShortestPathWithDijkshtra(graph, 0, 4);
}
/*
5
0 1 1
1 2 1
0 2 4
0 3 7
3 2 2
3 4 3
-1 -1 -1
 */