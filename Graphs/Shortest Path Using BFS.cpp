//
// Created by kapar on 16-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<int> BFSShortestPath(vector<vector<int>> graph, int source, int destination) {
    int n = graph.size();
    vector<int> ans;
    vector<int> parent(n);
    vector<int> dist(n);
    queue<int> q;
    map<int, bool> m;
    q.push(source);
    m[source] = true;
    dist[source] = 0;
    parent[source] = source;
    while (!q.empty()) {
        int ele = q.front();
        q.pop();
        ans.push_back(ele);
        for (int i: graph[ele]) {
            if (!m[i]) {
                parent[i] = ele;
                dist[i] = dist[ele] + 1;
                q.push(i);
                m[i] = true;
            }
        }
    }
    //Shortest distances for all nodes
    for (int i = 0; i < graph.size(); i++) {
        cout << "Shortest distances from source to " << i << " is: " << dist[i] << endl;
    }
    //shortest path to destination
    if (destination != -1) {
        int temp = destination;
        while (temp != source) {
            cout << temp << " ";
            temp = parent[temp];
        }
    }
    cout << endl;
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
    vector<int> ans = BFSShortestPath(graph, 1, 6);
    for (int i: ans) cout << i << " ";
}
/*
 7
0 1
2 3
1 2
3 5
5 6
4 5
0 4
3 4
-1 -1
 */