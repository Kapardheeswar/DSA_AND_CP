//
// Created by kapar on 03-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr,int start,int end){
    int i = start-1;
    int pivot = arr[end];
    for (int j = start; j < end; j++) {
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}

int quickSelect(vector<int>&arr,int s,int e,int k){
    int p = partition(arr,s,e);
    if(k==p) return arr[p];
    else if(k>p) return quickSelect(arr,p+1,e,k);
    else return quickSelect(arr,s,p-1,k);
}
int main(){
    vector<int>arr={5,4,3,2,18,9};
    cout<<quickSelect(arr,0,arr.size()-1,0);
}