//
// Created by kapar on 22-04-2023.
//
#include <bits/stdc++.h>

using namespace std;

int hammingDistance(int x, int y) {
    int count = 0;
    while (x > 0 || y > 0) {
        int xLastBit = x & 1;
        int yLastBit = y & 1;
        if (xLastBit != yLastBit) count += 1;
        x = x >> 1;
        y = y >> 1;
    }
    return count;
}

vector<vector<int>> getPairs(vector<int> arr) {
    vector<vector<int>> subsets;
    int n = arr.size();
    for (int i = 0; i < (1 << n); i++) {
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
        if (subset.size() == 2) subsets.push_back(subset);
    }
    return subsets;
}

int getTotalHammingDistance(vector<vector<int>> pairs) {
    int totalHammingDist = 0;
    for (vector<int> pair: pairs) {
        totalHammingDist += hammingDistance(pair.at(0), pair.at(1));
    }
    return totalHammingDist;
}

int totalHammingDistance(vector<int> nums) {
    int ans = 0, n = nums.size();
    for (int i = 0; i < 32; ++i) {
        int k = (1 << i);
        int ones = 0, zeroes = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] & k) { ones++; }
            else { zeroes++; }
        }
        ans += ones * zeroes;
    }
    return ans;
}

int main() {
    vector<int> vec = {4, 14, 2, 1};
    vector<vector<int>> subsets = getPairs(vec);
    for (vector<int> k: subsets) {
        for (int i: k) {
            cout << i << ",";
        }
        cout << endl;
    }
    cout << getTotalHammingDistance(subsets) << endl;
    cout << totalHammingDistance(vec);
}
