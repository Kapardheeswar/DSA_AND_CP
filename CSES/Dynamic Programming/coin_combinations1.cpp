//
// Created by kapar on 04-09-2023.
//
#include <bits/stdc++.h>

using namespace std;
#define int long long
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
int mod = 1e9 + 7;

int getCombinations(vector<int> coins, int n, int x) {
    int dp[1000002]={0};
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (auto coin: coins) {
            if (i >= coin) {
                dp[i] = (dp[i] + dp[i - coin])%mod;
            }
        }
    }
    return dp[x] % mod;
}

signed main() {
    fastio;
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << getCombinations(coins, n, x);
}
