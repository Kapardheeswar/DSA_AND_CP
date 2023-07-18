//
// Created by kapar on 17-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

// Recursive Approach
int countWays(int n, int k) {
    if (n == 0)return 1;
    if (n < 0) return 0;
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += countWays(n - i, k);
    }
    return ans;
}

//Top Down DP Approach
int countWaysTD(int n, int k, vector<int> &dp) {
    if (n == 0)return 1;
    if (n < 0) return 0;
    if (dp[n] != 0) return dp[n];
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += countWaysTD(n - i, k,dp);
    }
    return dp[n] = ans;
}

//Bottom Up Approach
int countWaysBU(int n, int k) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

int main() {
    cout << countWays(7, 3) << endl;
    vector<int> dp(7, 0);
    cout << countWaysTD(7, 3, dp) << endl;
    cout << countWaysBU(7, 3);
}