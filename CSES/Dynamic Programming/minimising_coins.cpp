//
// Created by kapar on 26-08-2023.
//
#include <bits/stdc++.h>

using namespace std;
#define int long long

int getMinimumCoins(vector<int> coins, int targetSum) {
    vector<int> dp(targetSum + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= targetSum; i++) {
        dp[i] = INT_MAX;
        for (int c: coins) {
            if (i - c >= 0 and dp[i - c] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    if (dp[targetSum] == INT_MAX) return -1;
    return dp[targetSum];
}

signed main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        coins.push_back(k);
    }
    cout << getMinimumCoins(coins, sum);
}