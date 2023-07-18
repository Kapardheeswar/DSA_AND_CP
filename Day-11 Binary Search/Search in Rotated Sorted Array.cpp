//
// Created by kapar on 04-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size()-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[s]<=nums[mid]){
            if(target>=nums[s] and target<=nums[mid]){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        else{
            if(target>=nums[mid] and target<=nums[e]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int>v = {4,5,6,7,0,1,2};
    cout<<search(v,0);
}