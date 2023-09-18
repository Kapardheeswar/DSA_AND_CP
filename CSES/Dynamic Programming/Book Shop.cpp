//
// Created by kapar on 10-09-2023.
//
#include <bits/stdc++.h>

using namespace std;

int getMaxPagesBU(int n, int x, vector<int> prices, vector<int> pages) {
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            int inc = 0, exc = 0;
            if (j >= prices[i - 1]) {
                inc = pages[i - 1] + dp[i - 1][j - prices[i - 1]];
            }
            exc = dp[i - 1][j];
            dp[i][j] = max(inc, exc);
        }
    }
    return dp[n][x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    vector<int> pages(n);
    for (int i = 0; i < n; i++)cin >> pages[i];
    cout << getMaxPagesBU(n, x, prices, pages);
}