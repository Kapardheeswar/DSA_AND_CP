//
// Created by kapar on 17-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>> graph, int u, map<int, bool> &m) {
    m[u] = true;
    int ans = 1;
    for (auto k: graph[u]) {
        if (!m[k]) {
            int size = dfs(graph, k, m);
            ans += size;
        }
    }
    return ans;
}

int getMaxPairs(vector<vector<int>> graph, int n) {
    int ans = (n) * (n - 1) / 2;
    map<int, bool> m;
    for (int i = 0; i < n; i++) {
        if (!m[i]) {
            int sameCountryNum = dfs(graph, i, m);
            ans -= (sameCountryNum) * (sameCountryNum - 1) / 2;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>graph(n);
    int u,v;
    cin>>u>>v;
    while(u!=-1 and v!=-1){
        graph[u].push_back(v);
        graph[v].push_back(u);
        cin>>u>>v;
    }
    cout<<getMaxPairs(graph,n)<<endl;
}
/*
 * 5
0 1
2 3
0 4
-1 -1
 */