//
// Created by kapar on 18-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
//Recursive
int LIS(vector<int> nums, int i, int prev) {
    if (i == nums.size()) return 0;
    int include = 0, exclude = 0;
    if (prev < nums[i]) {
        include = 1 + LIS(nums, i+1, nums[i]);
    }
    exclude = LIS(nums, i+1, prev);
    return max(include, exclude);
}
//Bottom UP
int LIS(vector<int>v){
    vector<int>dp(v.size(),1);
    int len=1;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if(v[i]>v[j]){
                dp[i] = max(dp[i],1+dp[j]);
                len = max(len,dp[i]);
            }
        }
    }
    return len;
}
int main(){
    vector<int>v = {50,4,10,8,30,100};
    cout<<LIS(v)<<endl;
    cout<<LIS(v,0,-1);
}