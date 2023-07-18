//
// Created by kapar on 13-06-2023.
//
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int holidayCost(int u, int parent, vector<pair<int, int>> adj[], ll &ans, int n) {
    int currentTreeSize = 1;
    for (auto p: adj[u]) {
        int v = p.first;
        int weight = p.second;
        if (v == parent) continue;
        int childTreeSize = holidayCost(v, u, adj, ans, n);
        int edgeContribution = 2 * min(childTreeSize, n - childTreeSize) * weight;
        ans += edgeContribution;
        currentTreeSize += childTreeSize;
    }
    return currentTreeSize;
}

int main() {
    int n = 4;
    vector<pair<int, int>> adj[10005];
    adj[1] = {{2, 3}};
    adj[2] = {{1, 3},
              {3, 2}};
    adj[3] = {{2, 2},
              {4, 2}};
    adj[4] = {{3, 2}};
    ll ans = 0;
    holidayCost(1, -1, adj, ans, n);
    cout << ans << endl;
}

