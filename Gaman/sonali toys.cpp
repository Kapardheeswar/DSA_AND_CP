//
// Created by kapar on 18-08-2023.
//
#include <bits/stdc++.h>
using namespace std;

int findMinElementsToRemove(vector<int> nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] >= nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLength = *max_element(dp.begin(), dp.end());

    return n - maxLength;
}
int main(){
    cout<<findMinElementsToRemove({4,3,2,1});
}