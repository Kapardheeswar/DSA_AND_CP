//
// Created by kapar on 29-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(vector<vector<int>> roads, int n) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto vec: roads) {
        int u = vec[0];
        int v = vec[1];
        int w = vec[2];
        graph[u].push_back({v, w});
        graph[v].push_back({u,w});
    }
    set<vector<int>> s;
    vector<int> dist(graph.size(), INT_MAX);
    vector<vector<int>> paths(graph.size());
    for (int i = 0; i < graph.size(); i++) {
        paths[i].push_back(i);
    }
    dist[1] = 0;
    s.insert({dist[1], 1});
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
                vector<int> newV = {v};
                for (auto integer: paths[u]) {
                    newV.push_back(integer);
                }
                paths[v] = newV;
                s.insert({dist[v], v});
            }
        }
    }
    reverse(paths[n].begin(),paths[n].end());
    return paths[n];
}
int main(){
    vector<int>path = shortestPath({{1,2,2},{2, 5, 5},{2, 3, 4},{1, 4, 1},{4, 3, 3},{3, 5, 1}},5);
    for(auto i:path) cout<<i<<" ";
}