//
// Created by kapar on 03-07-2023.
//
#include<bits/stdc++.h>

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
pair<int, int> subarraySorting(vector<int> a) {
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function
    vector<int> arr=a;
    quicksort(arr,0,arr.size()-1);
    int left=-1;
    for (int i = 0; i < a.size(); i++) {
        if(a[i]!=arr[i]){
            left=i;
            break;
        }
    }
    int right =-1;
    for (int i = a.size()-1; i >=0; i--) {
        if(a[i]!=arr[i]){
            right=i;
            break;
        }
    }
    return {left,right};
}
int main(){
    vector<int>v={0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};
    pair<int,int>p = subarraySorting(v);
    cout<<p.first<<" "<<p.second<<endl;
}