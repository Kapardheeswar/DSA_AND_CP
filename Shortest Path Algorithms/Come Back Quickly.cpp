//
// Created by kapar on 29-07-2023.
//
#include<bits/stdc++.h>

using namespace std;

int getMinimumRoundDist(vector<vector<pair<int, int>>> graph, vector<int> dist, set<vector<int>> s, int source) {
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
    return dist[source];
}

vector<int> solve(int n, int m, vector<vector<int>> road) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u = road[i][0];
        int v = road[i][1];
        int w = road[i][2];
        graph[u].push_back({v, w});
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        vector<int> dist(n + 1, INT_MAX);
        set<vector<int>> s;
        s.insert({0, i});
        int x = getMinimumRoundDist(graph, dist, s, i);
        if (x == INT_MAX) ans.push_back(-1);
        else ans.push_back(x);
    }
    return ans;
}

int main() {
    int n = 4;
    int m = 4;
    vector<vector<int>>edges = {{1,2,5},{2,3,10},{3,1,15},{4,3,20}};
    vector<int>ans = solve(n,m,edges);
    for(auto i:ans)cout<<i<<" ";
}