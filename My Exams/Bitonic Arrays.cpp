//
// Created by kapar on 26-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> bitonicArrays(int n) {
    vector<vector<int>> ans;
    ans.push_back({1});
    int currIdx = 0;
    int currLen = ans[currIdx].size();
    while (currLen + 2 <= n) {
        int mid = currLen / 2;
        int newEle = ans[currIdx][mid] + 1;
        vector<int> temp;
        for (int i = 0; i <= mid; i++) {
            temp.push_back(ans[currIdx][i]);
        }
        while (newEle > 0) {
            temp.push_back(newEle);
            newEle--;
        }
        ans.push_back(temp);
        temp.clear();
        currLen += 2;
        currIdx++;
    }
    return ans;
}
int getMin(vector<int>v){
    vector<vector<int>>arrays = bitonicArrays(v.size());
    int vSum = 0;
    for(auto i:v)vSum+=i;
    int minDiff = INT_MAX;
    for(auto vec:arrays){
        int cSum = 0;
        for(auto i:vec) cSum+=i;
        if(vSum>cSum and vSum-cSum<minDiff) minDiff = vSum-cSum;
    }
    return minDiff;
}
int main() {
    vector<vector<int>> v = bitonicArrays(5);
    for (auto vec: v) {
        for (auto i: vec) cout << i << " ";
        cout << endl;
    }
    cout<<getMin({1,2,2,2,1})<<endl;
    cout<<getMin({3,3,3,3,3});
}