//
// Created by kapar on 22-04-2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> findSubsets(vector<int> arr) {
    vector<vector<int>> subsets;
    int n = arr.size();
    for (int i = 0; i < pow(2, n); i++) {
        vector<int> subset;
        int number = i;
        int lastBitPosition = 0;
        while (number > 0) {
            int lastBit = (number & 1);
            if (lastBit) {
                subset.push_back(arr.at(lastBitPosition));
            }
            lastBitPosition++;
            number >>= 1;
        }
        subsets.push_back(subset);
    }
    return subsets;
}

int main() {
    vector<int> vec = {1,2,3};
    vector<vector<int>>subsets=findSubsets(vec);
    for (vector<int> k:subsets) {
        for (int i:k) {
            cout<<i<<",";
        }
        cout<<endl;
    }
}
