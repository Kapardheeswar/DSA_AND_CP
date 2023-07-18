//
// Created by kapar on 18-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
//Recursive
int minArrayJumps(vector<int>v,int index,int element){
    if(index>=v.size()-1){
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= element; i++) {
        int remainingSteps = minArrayJumps(v,index+i,v[i+index]);
        ans = min(ans,remainingSteps+1);
    }
    return ans;
}
//Top Down
int minArrayJumpsTD(vector<int>v,int index,int element,vector<int>&dp){
    if(index>=v.size()-1){
        return 0;
    }
    if(dp[index]!=0) return dp[index];
    int ans = INT_MAX;
    for (int i = 1; i <= element; i++) {
        int remainingSteps = minArrayJumps(v,index+i,v[i+index]);
        ans = min(ans,remainingSteps+1);
    }
    return dp[index]=ans;
}
int main(){
    vector<int>v={3,4,2,1,2,3,7,1,1,2,5};
    cout<<minArrayJumps(v,0,v[0])<<endl;
    vector<int>dp(v.size(),0);
    cout<<minArrayJumpsTD(v,0,v[0],dp);
}