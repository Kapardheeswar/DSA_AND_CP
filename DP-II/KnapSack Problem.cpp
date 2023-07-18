//
// Created by kapar on 18-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

//Recursion
int getMaxProfit(vector<int> weights, vector<int> prices, int limit, int index) {
    if (limit <= 0 or index == weights.size()) return 0;
    int ans = INT_MIN;
    if (limit - weights[index] >= 0) {
        int option1 = prices[index] + getMaxProfit(weights, prices, limit - weights[index], index + 1);
        ans = max(ans, option1);
    }
    int option2 = getMaxProfit(weights, prices, limit, index + 1);
    ans = max(ans, option2);
    return ans;
}

//Top Down
int getMaxProfitTD(vector<int> weights, vector<int> prices, int limit, int index, vector<vector<int>> &dp) {
    if (limit <= 0 or index == weights.size()) return 0;
    if (dp[index][limit] != 0) return dp[index][limit];
    int ans = INT_MIN;
    if (limit - weights[index] >= 0) {
        int option1 = prices[index] + getMaxProfitTD(weights, prices, limit - weights[index], index + 1, dp);
        ans = max(ans, option1);
    }
    int option2 = getMaxProfitTD(weights, prices, limit, index + 1, dp);
    ans = max(ans, option2);
    return dp[index][limit] = ans;
}

int main() {
    vector<int> weights = {2, 7, 3, 4};
    vector<int> prices = {5, 20, 20, 10};
    cout << getMaxProfit(weights, prices, 11, 0) << endl;
    //DP contains weights rows and limit+1 cols
    vector<vector<int>> dp(weights.size(), vector<int>(12, 0));
    cout << getMaxProfitTD(weights, prices, 11, 0, dp)<<endl;
    for(auto v:dp){
        for(auto i:v) cout<<i<<" ";
        cout<<endl;
    }
}