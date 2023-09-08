//
// Created by kapar on 05-09-2023.
//
#include <bits/stdc++.h>

using namespace std;

int minSteps(int n, vector<int> &dp) {
    if (n <= 0) return dp[n] = 0;
    if (dp[n] != -1)return dp[n];
    int ans = INT_MAX;
    int temp = n;
    while (n) {
        int rem = n % 10;
        if (rem > 0) {
            int subProblem = minSteps(temp - rem, dp);
            ans = min(ans, subProblem + 1);
        }
        n = n / 10;
    }
    return dp[temp] = ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << minSteps(n, dp);
}