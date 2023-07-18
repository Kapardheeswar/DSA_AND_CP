//
// Created by kapar on 20-04-2023.
//
#include<bits/stdc++.h>

using namespace std;
int getIthBit(int n, int i) {
    int mask = 1 << i;
    return (mask & n) > 0 ? 1 : 0;
}
int findPos(int n) {
    int p = 0;
    while ((n & 1) != 1) {
        p++;
        n = n >> 1;
    }
    return p;
}

vector<int> uniqueNumbers(vector<int> arr) {
    vector<int>ans;
    int cumulativeXor = 0;
    for (int ele: arr) {
        cumulativeXor = cumulativeXor ^ ele;
    }
    int position = findPos(cumulativeXor);
    vector<int>v1;
    vector<int>v2;
    for (int ele:arr){
        int bit= getIthBit(ele,position);
        if(bit==1) v1.push_back(ele);
        else v2.push_back(ele);
    }
    cumulativeXor=0;
    for (int ele:v1) {
        cumulativeXor = cumulativeXor ^ ele;
    }
    ans.push_back(cumulativeXor);
    cumulativeXor=0;
    for (int ele:v2) {
        cumulativeXor = cumulativeXor ^ ele;
    }
    ans.push_back(cumulativeXor);
    return ans;
};

int main() {
    vector<int> vec = {1,3,5,4,3,1,5,7};
    vector<int> ans = uniqueNumbers(vec);
    for (int ele:ans) {
        cout<<ele<<","<<endl;
    }
}
