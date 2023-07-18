//
// Created by kapar on 15-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
int getSum(vector<int>arr,int i,int j){
    int currSum = 0;
    for(int k=i;k<=j;k++){
        currSum+=arr[k];
    }
    return currSum;
}
int getLongestSubarray(vector<int>arr,int k){
    priority_queue<int>q;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i; j < arr.size(); j++) {
            int sum = getSum(arr,i,j);
            if(sum==k) q.push(j-i+1);
        }
    }
    return q.top();
}
int main(){
    vector<int>arr={ 0,-2,1,2,3,4,5,15,10,5 };
    cout<<getLongestSubarray(arr,15);
}