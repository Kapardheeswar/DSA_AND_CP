//
// Created by kapar on 17-09-2023.
//
#include <bits/stdc++.h>

using namespace std;

int getMaxSum(vector<int> v, int index) {
    if (index >= v.size())return 0;
    int option1 = v[index] + getMaxSum(v, index + 2);
    int option2 = getMaxSum(v, index + 1);
    return max(option1, option2);
}

int getMaxSumDP(vector<int> v, int index, vector<int> &dp) {
    if (index >= v.size()) return 0;
    if (dp[index] != 0)return dp[index];
    return dp[index] = max(getMaxSumDP(v, index + 2, dp) + v[index], getMaxSumDP(v, index + 1, dp));
}

int getMaxSumBU(vector<int> v) {
    vector<pair<int, int>> dp(v.size(), {0, 0});
    dp[0].second = 0;
    dp[0].first = v[0];
    for (int i = 1; i < v.size(); i++) {
        dp[i].first = dp[i - 1].second + v[i];
        dp[i].second = max(dp[i - 1].first, dp[i - 1].second);
    }
    return max(dp[v.size()-1].first,dp[v.size()-1].second);
}

int main() {
    vector<int> v = {5, 5, 10, 100, 10, 5};
    cout << getMaxSum(v, 0) << endl;
    vector<int> dp(v.size() + 1, 0);
    cout << getMaxSumDP(v, 0, dp)<<endl;
    cout<<getMaxSumBU(v);
}