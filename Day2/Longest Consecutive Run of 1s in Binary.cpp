//
// Created by kapar on 20-04-2023.
//
#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    priority_queue<int>maxHeap;
    int count=0;
    while (n>0){
        int lastBit=n&1;
        if(lastBit==0){
            maxHeap.push(count);
            count=0;
            n=n>>1;
        }else{
            count+=1;
            n=n>>1;
        }
    }
    maxHeap.push(count);
    return maxHeap.top();
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
}