//
// Created by kapar on 18-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

//Recursive
int getMaxProfitFromSellingWines(vector<int> costs, int year, int start, int end) {
    if (start > end) return 0;
    int ans = INT_MIN;
    int option1 = costs[start] * year + getMaxProfitFromSellingWines(costs, year + 1, start + 1, end);
    int option2 = costs[end] * year + getMaxProfitFromSellingWines(costs, year + 1, start, end - 1);
    ans = max(ans, max(option2, option1));
    return ans;
}

//Top Down
int getMaxProfitFromSellingWinesTD(vector<int> costs, int year, int start, int end, vector<vector<int>> &dp) {
    if (start > end) return 0;
    if (dp[start][end] != 0) return dp[start][end];
    int ans = INT_MIN;
    int option1 = costs[start] * year + getMaxProfitFromSellingWinesTD(costs, year + 1, start + 1, end, dp);
    int option2 = costs[end] * year + getMaxProfitFromSellingWinesTD(costs, year + 1, start, end - 1, dp);
    ans = max(ans, max(option2, option1));
    return dp[start][end] = ans;
}

int main() {
    vector<int> costs = {2, 3, 5, 1, 4};
    cout << getMaxProfitFromSellingWines(costs, 1, 0, costs.size() - 1) << endl;
    vector<vector<int>> dp(costs.size(), vector<int>(costs.size(), 0));
    cout<<getMaxProfitFromSellingWinesTD(costs,1,0,costs.size()-1,dp)<<endl;
    for (int i = 0; i < costs.size(); i++) {
        for (int j = 0; j < costs.size(); j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}