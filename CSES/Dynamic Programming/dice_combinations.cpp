//
// Created by kapar on 26-08-2023.
//
#include <bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
#define int long long
int getCombinations(int n, vector<int> &dp) {
    if (n <= 0) return dp[n] = 0;
    if (n == 1) return dp[n] = 1;
    if (dp[n] != -1)return dp[n];
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        if (n - i >= 0) {
            if ((n - i) != 0) {
                ans = ans + getCombinations(n - i, dp);
            } else {
                ans = ans + getCombinations(n - i, dp) + 1;
            }
        }
    }
    return dp[n] = ans % mod;
}

signed main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << getCombinations(n, dp) << endl;
}