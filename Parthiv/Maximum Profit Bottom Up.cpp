//
// Created by kapar on 30-07-2023.
//
#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(vector<vector<int>> prices, int k) {
    int n = prices.size(); // number of places to visit
    int m = prices[0].size(); // number of days

    // Initialize the 2D array with 0
    vector<vector<long>> dp(n, vector<long>(m, 0));

    // Fill the last row of the dp array with the prices on the last day
    for (int i = 0; i < n; i++) {
        dp[i][m-1] = prices[i][m-1];
    }

    // Fill the dp array iteratively, starting from the second last day
    for (int j = m-2; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            long ans = INT_MIN;
            for (int p = 1; p <= k; p++) {
                int nextPlaceVisit = i - p;
                if (nextPlaceVisit >= 0 and nextPlaceVisit < n) {
                    ans = max(ans, dp[nextPlaceVisit][j+1] + prices[i][j]);
                }
            }
            for (int p = 1; p <= k; p++) {
                int nextPlaceVisit = i + p;
                if (nextPlaceVisit >= 0 and nextPlaceVisit < n) {
                    ans = max(ans, dp[nextPlaceVisit][j+1] + prices[i][j]);
                }
            }
            dp[i][j] = ans;
        }
    }

    // Find the maximum profit that can be obtained by starting from any place on the first day
    long maxProfit = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxProfit = max(maxProfit, dp[i][0]);
    }
    return maxProfit;
}

int main() {
    vector<vector<int>> prices = {{1, 3, 1},
                                  {2, 1, 3},
                                  {1, 1, 4}};
    vector<vector<int>> prices1 = {{1, 6, 3},
                                   {2, 4, 4},
                                   {3, 3, 1}};
    vector<vector<int>> prices3 = {{1,  3},
                                   {2,  4},
                                   {1,  15},
                                   {1,  1},
                                   {15, 1}};
    cout << getMaximumProfit(prices, 1);
}