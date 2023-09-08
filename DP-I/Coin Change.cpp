//
// Created by kapar on 17-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

//Recursive Approach
int coinChange(vector<int> coins, int targetSum) {
    if (targetSum <= 0) return 0;
    int ans = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        if (targetSum - coins[i] >= 0) {
            int currAns = coinChange(coins, targetSum - coins[i]);
            ans = min(ans, currAns);
        }
    }
    return ans + 1;
}

//Top Down
int coinChangeTD(vector<int> coins, int targetSum, vector<int>& dp) {
    if (targetSum <= 0) return 0;
    if (dp[targetSum] != 0) return dp[targetSum];
    int ans = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        if (targetSum - coins[i] >= 0) {
            int currAns = coinChangeTD(coins, targetSum - coins[i],dp);
            ans = min(ans, currAns);
        }
    }
    if (ans == INT_MAX) return dp[targetSum] = -1;
    return dp[targetSum] = ans + 1;
}

//Bottom Up Approach
int coinChangeBU(vector<int> coins, int targetSum) {
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


int main() {
    cout << coinChange({1, 5, 7, 10}, 16) << endl;
    cout << coinChangeBU({3,6},10)<<endl;
    vector<int> dp(3, 0);
    cout<<coinChangeTD({3,6},10,dp);
}