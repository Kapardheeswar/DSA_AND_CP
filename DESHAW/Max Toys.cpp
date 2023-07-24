//
// Created by kapar on 21-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
int maxToysHelper(vector<int>prices,int money,int index){
    if(money<=0 or index == prices.size())return 0;
    int ans = INT_MIN;
    if(money-prices[index]>=0){
        int option1 = 1+ maxToysHelper(prices,money-prices[index],index+1);
        ans = max(ans,option1);
    }
    int option2 = maxToysHelper(prices,money,index+1);
    ans = max(ans,option2);
    return ans;
}
int getMaxToys(vector<int>prices,vector<int>brokenToys,int money){
    set<int>temp(prices.begin(),prices.end());
    for(int i:brokenToys){
        int price = prices[i];
        auto f = temp.find(price);
        temp.erase(f);
    }
    prices.clear();
    for(int i:temp) prices.push_back(i);
    return maxToysHelper(prices,money,0);
}
int main(){
    cout<<getMaxToys({7,3,6,8,2,1,4,9,5,10},{},100);
}