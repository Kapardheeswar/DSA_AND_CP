//
// Created by kapar on 10-07-2023.
//
#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> v) {
//Write your code here. Do not modify the function or parameters.
    deque<int>dq;
    vector<int>ans;
    for(int i=v.size()-1;i>=0;i--){
        int j = i;
        int cnt = 1;
        while(j>=0 and v[j]<=v[i]) {
            cnt++;
            j--;
        }
        cnt--;
        dq.push_front(cnt);
    }
    for(auto i:dq){
        ans.push_back(i);
    }
    return ans;
}
int main(){
    stockSpan({100, 80, 60, 70, 60, 75, 85});
}