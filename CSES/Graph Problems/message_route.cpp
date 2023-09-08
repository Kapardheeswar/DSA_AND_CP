//
// Created by kapar on 19-08-2023.
//
#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> graph;
vector<int> parent;

int shortestPath(int n) {
    parent.resize(n + 1, -1);
    vector<int> dist(n + 1, -1);
    dist[1] = 0;
    set<pair<int, int>> s;
    s.insert({dist[0], 1});
    while (!s.empty()) {
        auto f = s.begin();
        int distTillNow = f->first;
        int u = f->second;
        s.erase(f);
        for (auto ele: graph[u]) {
            if (dist[ele] == -1 or distTillNow + 1 < dist[ele]) {
                f = s.find({dist[ele], ele});
                if (f != s.end())s.erase(f);
                dist[ele] = distTillNow + 1;
                parent[ele] = u;
                s.insert({dist[ele], ele});
            }
        }
    }
    return parent[n];
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    int u, v;
    while (m) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        m--;
    }
    int p = shortestPath(n);
    if (p == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        stack<int> s;
        s.push(n);
        int currParent = parent[n];
        while (currParent != 1) {
            s.push(currParent);
            currParent = parent[currParent];
        }
        cout<<s.size()+1<<endl;
        cout << 1 << " ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }
}