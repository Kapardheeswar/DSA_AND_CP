//
// Created by kapar on 05-09-2023.
//
#include <bits/stdc++.h>

using namespace std;
#define int long long
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
int mod = 1e9 + 7;

int getCombinations(vector<int> &coins, int n, int x) {
    vector<int> dp(x + 2, 0);
    dp[0] = 1;
    sort(coins.begin(), coins.end());
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= x; j++) {
            if (j >= coins[i]) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
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
    if (x == 0)cout << 0 << endl;
    cout << getCombinations(coins, n, x);
}