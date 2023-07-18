//
// Created by kapar on 17-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

//Recursive
int maxProfit(vector<int> prices, int n) {
    if (n <= 0) return 0;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        int profitFromRemainingCut = maxProfit(prices, n - i - 1);
        ans = max(ans, prices[i] + profitFromRemainingCut);
    }
    return ans;
}

//Top Down
int maxProfitTD(vector<int> prices, int n, vector<int> &dp) {
    if (n <= 0) return 0;
    if (dp[n] != 0) return dp[n];
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        int profitFromRemainingCut = maxProfit(prices, n - i - 1);
        ans = max(ans, prices[i] + profitFromRemainingCut);
    }
    return dp[n] = ans;
}

//Bottom Up
int maxProfitBU(vector<int>prices,int n){
    vector<int>dp(n+1);
    dp[0]=0;
    for (int len = 1; len <= n; len++) {
        int ans = INT_MIN;
        for (int i = 0; i < len; i++) {
            int currProfit = dp[len-i-1];
            ans = max(ans,prices[i]+currProfit);
        }
        dp[len] = ans;
    }
    return dp[n];
}

int main() {
    cout << maxProfit({1, 5, 8, 9, 10, 17, 17, 20}, 8)<<endl;
    vector<int>dp(9,0);
    cout<<maxProfitTD({1, 5, 8, 9, 10, 17, 17, 20},8,dp)<<endl;
    cout<<maxProfitBU({1, 5, 8, 9, 10, 17, 17, 20},8);

}