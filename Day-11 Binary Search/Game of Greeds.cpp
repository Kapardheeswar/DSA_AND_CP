//
// Created by kapar on 05-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
bool k_partition(vector<int>c,int mid,int k){
    int currentSum = 0;
    int partitions=0;
    for (int i = 0; i < c.size(); i++) {
        if(currentSum+c[i]>=mid){
            partitions++;
            currentSum=0;
        }
        else{
            currentSum+=c[i];
        }
    }
    return partitions>=k;
}
int main(){
    vector<int>c={1,2,3,4};
    int k=3;
    int s = 0;
    int e = 0;
    for (int k:c) {
        e+=k;
    }
    int ans;
    while(s<=e){
        int mid = (s+e)/2;
        bool isK_PartitionPossible = k_partition(c,mid,k);
        if(isK_PartitionPossible){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    cout<<ans<<endl;
}