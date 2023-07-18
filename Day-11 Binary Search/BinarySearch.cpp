//
// Created by kapar on 04-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
int searchElement(vector<int>v,int k){
    int s = 0;
    int e = v.size()-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(v[mid]==k){
            return mid;
        }
        else if(k>v[mid]){
            s = mid+1;
        }
        else {
            e = mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int>v={1,2,3,4,6};
    cout<<searchElement(v,6);
}