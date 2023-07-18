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

void quicksort(vector<int>&arr,int start,int end){
    if(start>=end){
        return;
    }
    int pivot = partition(arr,start,end);
    quicksort(arr,start,pivot-1);
    quicksort(arr,pivot+1,end);
}
int main(){
    vector<int>arr={4,1,3,9,7};
    quicksort(arr,0,arr.size()-1);
    for(auto i:arr){
        cout<<i<<" ";
    }
}