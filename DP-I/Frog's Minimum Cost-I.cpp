//
// Created by kapar on 18-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
//Recursive
int getMinimumCost(vector<int>costs,int index){
    if(index>=costs.size()-1) return 0;
    int ans = INT_MAX;
    if(index+2<costs.size()){
        int costOne = getMinimumCost(costs,index+1);
        int costTwo = getMinimumCost(costs,index+2);
        int priceOne = abs(costs[index+1]-costs[index]);
        int priceTwo = abs(costs[index+2]-costs[index]);
        ans = min(ans,min(priceOne+costOne,priceTwo+costTwo));
    }else if(index+1<costs.size()){
        int costOne = getMinimumCost(costs,index+1);
        int priceOne = abs(costs[index+1]-costs[index]);
        ans = min(ans,priceOne+costOne);
    }
    return ans;
}
//Top Down
int getMinimumCostTD(vector<int>costs,int index,vector<int>&dp){
    if(index>=costs.size()-1) return 0;
    if(dp[index]!=0) return dp[index];
    int ans = INT_MAX;
    if(index+2<costs.size()){
        int costOne = getMinimumCost(costs,index+1);
        int costTwo = getMinimumCost(costs,index+2);
        int priceOne = abs(costs[index+1]-costs[index]);
        int priceTwo = abs(costs[index+2]-costs[index]);
        ans = min(ans,min(priceOne+costOne,priceTwo+costTwo));
    }else if(index+1<costs.size()){
        int costOne = getMinimumCost(costs,index+1);
        int priceOne = abs(costs[index+1]-costs[index]);
        ans = min(ans,priceOne+costOne);
    }
    return dp[index]=ans;
}
//Bottom UP
int getMinimumCostBU(vector<int>costs){
    int n = costs.size();
    vector<int>dp(n,0);
    dp[1] = abs(costs[0]-costs[1]);
    for (int i = 2; i < n; i++) {
        int option1 = abs(costs[i]-costs[i-1])+dp[i-1];
        int option2 = abs(costs[i]-costs[i-2])+dp[i-2];
        dp[i] = min(option1,option2);
    }
    return dp[n-1];
}
int main(){
    vector<int>costs = {30,10,60,10,60,50};
    vector<int>costs1 = {10,30,40,20};
    cout<<getMinimumCost(costs1,0)<<endl;
    vector<int>dp(costs.size(),0);
    cout<<getMinimumCostTD(costs,0,dp)<<endl;
    cout<<getMinimumCostBU(costs);
}