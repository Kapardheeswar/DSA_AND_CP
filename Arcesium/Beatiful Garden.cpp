//
// Created by kapar on 23-08-2023.
//
#include <bits/stdc++.h>
using namespace std;
int getMinimum(int n,vector<int>heights){
    int ans=0;
    for (int i = 1; i < n; i++) {
        if(heights[i]>heights[i-1]){
            ans+=heights[i]-heights[i-1];
            heights[i]=heights[i-1];
        }
    }
    return ans;
}
int main(){
    cout<<getMinimum(2,{2,3});
}