//
// Created by kapar on 13-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<int> sortKSortedArrays(vector<vector<int>> v) {
    vector<int> ans;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    // element, elementIdx, arrIdx
    for (int i = 0; i < v.size(); i++) {
        q.push({v[i][0], 0, i});
    }
    while (!q.empty()) {
        auto s = q.top();
        q.pop();
        int element = s[0];
        int eleIdx = s[1];
        int arrIdx = s[2];
        ans.push_back(element);
        if (eleIdx + 1 < v[arrIdx].size()) {
            int nextEle = v[arrIdx][eleIdx + 1];
            q.push({nextEle, eleIdx + 1, arrIdx});
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> v = {{4, 5,  7},
                             {1, 2},
                             {9, 11, 15}};
    vector<int> ans = sortKSortedArrays(v);
    for (auto i: ans) {
        cout << i << " ";
    }
}