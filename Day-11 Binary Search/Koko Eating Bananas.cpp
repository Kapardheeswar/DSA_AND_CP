//
// Created by kapar on 07-09-2023.
//
#include <bits/stdc++.h>
using namespace std;
int canEat(vector<int>bananas,int k,int n,int h){
    int currHour = 0;
    for (int i = 0; i < n; i++) {
        if(bananas[i]<k){
            currHour++;
            if(currHour>h) return 0;
            continue;
        }
        else{
            int tempHour = 0;
            int tempBananas = 0;
            while(tempBananas<bananas[i]){
                tempBananas+=k;
                tempHour++;
            }
            currHour+=tempHour;
            if(currHour>h)return 0;
        }
    }
    return 1;
}
int main(){
//    vector<int>bananas = {3,6,7,11};
    vector<int>bananas = {30,11,23,4,20};
    int h=5;
    sort(bananas.begin(),bananas.end());
    int start = bananas[0];
    int end = bananas[bananas.size()-1];
    int ans = bananas[0];
    while(start<=end){
        int mid = (start+end)/2;
        int check = canEat(bananas,mid,bananas.size(),h);
        if(check){
            end = mid-1;
            ans = mid;
        }
        else{
            start = mid+1;
        }
    }
    cout<<ans;
}