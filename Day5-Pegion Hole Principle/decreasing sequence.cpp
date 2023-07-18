//
// Created by kapar on 12-06-2023.
//
#include<bits/stdc++.h>
using namespace std;
int solve(int l,int r){
    if(r-l+1>l){
        return -1;
    }
    else{
        return r;
    }
}
int main(){
    int t;
    cin>>t;
    while(t){
        int l,r;
        cin>>l>>r;
        cout<<solve(4,6);
        t--;
    }
}