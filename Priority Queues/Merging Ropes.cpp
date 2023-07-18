//
// Created by kapar on 13-07-2023.
//
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v = {5,3,2,1,6};
    priority_queue<int,vector<int>,greater<int>>minHeap(v.begin(),v.end());
    while (minHeap.size()!=1){
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        minHeap.push(first+second);
    }
    cout<<minHeap.top()<<endl;
}