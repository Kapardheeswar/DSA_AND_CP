#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> nums) {
    int minSum=0;
    while(nums.size()!=1){
        sort(nums.begin(),nums.end());
        int first=nums.front();
        nums.erase(nums.begin());
        int second=nums.front();
        nums.erase(nums.begin());
        nums.push_back(first+second);
        minSum+=first+second;
    }
    return minSum;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout<<solve(v);
}