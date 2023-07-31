//
// Created by kapar on 30-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

long getMaximumProfitHelper(vector<vector<int>> prices, int placeVisit, int dayCount, int k, int m, int n) {
    if (dayCount == m) return 0;
    long ans = INT_MIN;
    for (int i = 1; i <= k; i++) {
        int nextPlaceVisit = placeVisit - i;
        if (nextPlaceVisit >= 0 and nextPlaceVisit < n) {
            long option1 = getMaximumProfitHelper(prices, nextPlaceVisit, dayCount + 1, k, m, n);
            ans = max(ans, option1 + prices[placeVisit][dayCount]);
        }
    }
    for (int i = 1; i <= k; i++) {
        int nextPlaceVisit = placeVisit + i;
        if (nextPlaceVisit >= 0 and nextPlaceVisit < n) {
            long option2 = getMaximumProfitHelper(prices, nextPlaceVisit, dayCount + 1, k, m, n);
            ans = max(ans, option2 + prices[placeVisit][dayCount]);
        }
    }
    return ans;
}

long getMaximumProfit(vector<vector<int>> profit, int k) {
    long maxProfit = INT_MIN;
    for (int i = 0; i < profit.size(); i++) {
        maxProfit = max(maxProfit, getMaximumProfitHelper(profit, i, 0, k, profit[0].size(), profit.size()));
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
    cout << getMaximumProfit(prices3, 3);
}