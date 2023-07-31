//
// Created by kapar on 31-07-2023.
//
#include<bits/stdc++.h>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int k) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i <= k; i++) {
        vector<int> temp(dist);
        for (auto flight: flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            if (dist[u] != INT_MAX) {
                temp[v] = min(temp[v], dist[u] + w);
            }
        }
        dist = temp;
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() {
    cout << findCheapestPrice(3, {{0, 1, 100},
                                  {1, 2, 100},
                                  {0, 2, 500}}, 0, 2, 1);
}