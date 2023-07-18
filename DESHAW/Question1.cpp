//
// Created by kapar on 15-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> subSets;

void convertIntoSubset(vector<int> v, string s) {
    vector<int> v1;
    for (char ch: s) {
        int idx = ch - '0';
        v1.push_back(v[idx]);
    }
    subSets.push_back(v1);
}

void getSubsets(vector<int>& v, int i, string s) {
    if (i == v.size()) {
        convertIntoSubset(v, s);
        return;
    }
    getSubsets(v, i + 1, s + to_string(i));
    getSubsets(v, i + 1, s);
}

int maxLength(vector<int> v, int maxSum) {
    priority_queue<int> q;
    for (int i = 0; i < subSets.size(); i++) {
        int sum = 0;
        for (auto k: subSets[i]) {
            auto it = find(v.begin(), v.end(), k);
            int idx = it - v.begin();
            sum += idx * subSets[i].size() + k;
        }
        if (sum <maxSum){
            q.push(subSets[i].size());
        }
    }
    return q.top();
}

int main() {
    vector<int> v = {4,3,2,1};
    getSubsets(v, 0, "");
//    for (auto v: subSets) {
//        for (auto i: v) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
    cout<<maxLength(v,33);
}