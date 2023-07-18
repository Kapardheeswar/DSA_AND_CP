//
// Created by kapar on 18-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

//Recursive
int getMaximumNonAdjacentSum(vector<int> v, int index) {
    if (index >= v.size()) return 0;
    int ans = INT_MIN;
    int option1 = v[index] + getMaximumNonAdjacentSum(v, index + 2);
    int option2 = getMaximumNonAdjacentSum(v, index + 1);
    ans = max(ans, max(option2, option1));
    return ans;
}

//Top Down
int getMaximumNonAdjacentSumTD(vector<int> v, int index, vector<int> &dp) {
    if (index >= v.size()) return 0;
    if (dp[index] != 0) {
        return dp[index];
    }
    int ans = max(v[index] + getMaximumNonAdjacentSumTD(v, index + 2, dp),
                  getMaximumNonAdjacentSumTD(v, index + 1, dp));
    dp[index] = ans;
    return ans;
}

int main() {
    vector<int> v = {6, 10, 12, 7, 9, 14};
    cout << getMaximumNonAdjacentSum(v, 0) << endl;
    vector<int> dp(v.size(), 0);
    cout << getMaximumNonAdjacentSumTD(v, 0, dp);
}