//
// Created by kapar on 16-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
//Recursive
int minCostOfSubArray(vector<int> v, vector<int> c, int i, int subArrayNum, int kFactor) {
    if (i == v.size()) return 0;
    int ans = INT_MAX;
    for (int j = i; j < v.size(); j++) {
        int vSum = 0;
        for (int k = 0; k <= j; k++) vSum += v[k];
        int cSum = 0;
        for (int k = i; k <= j; k++) cSum += c[k];
        int aSum = (vSum + kFactor * subArrayNum) * cSum;
        int remSum = minCostOfSubArray(v, c, j + 1, subArrayNum + 1, kFactor);
        ans = min(ans, remSum + aSum);
    }
    return ans;
}
//Top Down
int minCostOfSubArrayTD(vector<int> v, vector<int> c, int i, int subArrayNum, int kFactor, vector<vector<int>>&dp) {
    if (i == v.size()) return 0;
    if(dp[i][subArrayNum]!=0) {
        return dp[i][subArrayNum];
    }
    int ans = INT_MAX;
    for (int j = i; j < v.size(); j++) {
        int vSum = 0;
        for (int k = 0; k <= j; k++) vSum += v[k];
        int cSum = 0;
        for (int k = i; k <= j; k++) cSum += c[k];
        int aSum = (vSum + kFactor * subArrayNum) * cSum;
        int remSum = minCostOfSubArrayTD(v, c, j + 1, subArrayNum + 1, kFactor,dp);
        ans = min(ans, remSum + aSum);
    }
    return dp[i][subArrayNum]=ans;
}

int main() {
    cout << minCostOfSubArray({3, 1, 4}, {2, 3, 3}, 0, 1, 1)<<endl;
    vector<vector<int>>dp(4,vector<int>(4,0));
    cout<<minCostOfSubArrayTD({3, 1, 4}, {2, 3, 3}, 0, 1, 1,dp)<<endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}