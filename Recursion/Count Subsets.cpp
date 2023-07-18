//
// Created by kapar on 05-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

//Recursion
int countSubsets(vector<int> arr, int i, int targetSum) {
    if (i == arr.size()) {
        if (targetSum == 0) {
            return 1;
        }
        return 0;
    }
    int include = countSubsets(arr, i + 1, targetSum - arr[i]);
    int exclude = countSubsets(arr, i + 1, targetSum);
    return include + exclude;
}

//Top Down
int countSubsetsTD(vector<int> arr, int i, int targetSum, vector<vector<int>> &dp) {
    if (targetSum < 0) {
        return 0;
    }
    if (i == arr.size()) {
        if (targetSum == 0) {
            return 1;
        }
        return 0;
    }
    if (dp[i][targetSum] != -1) return dp[i][targetSum];
    int include = countSubsetsTD(arr, i + 1, targetSum - arr[i],dp);
    int exclude = countSubsetsTD(arr, i + 1, targetSum,dp);
    return dp[i][targetSum] = include + exclude;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << countSubsets(arr, 0, 5)<<endl;
    vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
    cout<<countSubsetsTD(arr,0,5,dp)<<endl;
    for (auto v: dp) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
}