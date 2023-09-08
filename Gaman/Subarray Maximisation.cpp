//
// Created by kapar on 09-08-2023.
//
#include <bits/stdc++.h>

using namespace std;

int getMaxHelper(vector<int> v, int i, int k) {
    if (i == v.size()) return 0;
    int ans = INT_MIN;
    for (int j = i; j < v.size(); j++) {
        int option1 = v[j] - v[i] - k + getMaxHelper(v, j + 1, k);
        int option2 = getMaxHelper(v, j + 1, k);
        ans = max(ans, max(option2, option1));
    }
    return ans;
}

int getMaxHelperTD(vector<int> v, int i, int k, vector<vector<int>> &dp) {
    if (i == v.size())
        return 0;

    if (dp[i][k] != -1)
        return dp[i][k];

    int ans = INT_MIN;
    for (int j = i; j < v.size(); j++) {
        int option1 = v[j] - v[i] - k + getMaxHelperTD(v, j + 1, k, dp);
        int option2 = getMaxHelperTD(v, j + 1, k, dp);
        ans = max(ans, max(option2, option1));
    }

    return dp[i][k] = ans;
}

int getMax(int k, int arr[], int n) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(arr[i]);
    }
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    int x = getMaxHelperTD(v, 0, k,dp);
    for(auto v:dp){
        for(auto k:v)cout<<k<<" ";
        cout<<endl;
    }
    cout<<endl;
    return x;
}

int main() {
    cout << getMaxHelper({4, 2, 3, 7, 5, 6}, 0, 0)<<endl;
    int arr[] = {4,2,3,7,5,6};
    cout<<getMax(0,arr,6);
}