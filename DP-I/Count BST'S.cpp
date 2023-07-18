//
// Created by kapar on 18-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

//Recursive
int countBST(int n) {
    if (n == 0 or n == 1) return 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int left = countBST(i - 1);
        int right = countBST(n - i);
        ans += left * right;
    }
    return ans;
}

//Top Down
int countBSTTD(int n, vector<int> &dp) {
    if (n == 0 or n == 1) return 1;
    if (dp[n] != 0) return dp[n];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int left = countBSTTD(i - 1, dp);
        int right = countBSTTD(n - i, dp);
        ans += left * right;
    }
    return dp[n] = ans;
}

//Bottom UP
int countBSTBU(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += (dp[j - 1] * dp[i - j]);
        }
    }
    return dp[n];
}

int main() {
    cout << countBST(3) << endl;
    vector<int> dp(4, 0);
    cout << countBSTTD(3, dp) << endl;
    cout << countBSTBU(3);
}