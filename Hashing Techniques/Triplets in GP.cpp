//
// Created by kapar on 14-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
int getTripletsCount(vector<int>v,int r){
    map<int,int>left;
    map<int,int>right;
    for(auto i:v) right[i]++;
    int cnt = 0;
    for (auto i:v) {
        int leftFrequency = left[i/r];
        int rightFrequency = right[i*r];
        cnt += leftFrequency*rightFrequency;
        if(right[i]!=0){
            right[i]--;
            left[i]++;
        }
    }
    return cnt;
}
int main(){
    cout<<getTripletsCount({1,16,4,16,64,16},4);
}