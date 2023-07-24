//
// Created by kapar on 22-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

vector<int> adj[MAXN + 5];
int val[MAXN + 5];
int dp[MAXN + 5][2];

void dfs(int u, int parent) {
    dp[u][0] = 0;
    dp[u][1] = val[u];
    for (int v: adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int solve(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += max(dp[i][0], dp[i][1]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    int u, v;
    cin >> u >> v;
    while (u != -1 and v != -1) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        cin >> u >> v;
    }
    dfs(1, 0);
    int ans = solve(n);
    cout << ans << endl;
    return 0;
}