//
// Created by kapar on 22-04-2023.
//
#include <bits/stdc++.h>

using namespace std;

int findTriplets(vector<int> arr) {
    unordered_map<int, int> hash;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val = arr.at(i) & arr.at(j);
            if (hash.find(val) != hash.end()) {
                hash[val]++;
            } else {
                hash.insert({val, 1});
            }
        }
    }
    for (auto pair: hash) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    int triplesCount = 0;
    for (int k: arr) {
        for (auto itr: hash) {
            if ((k & itr.first) == 0) {
                triplesCount += itr.second;
            }
        }
    }
    return triplesCount;
}

int countTriplets(vector<int> nums) {
    unordered_map<int, int> store;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = nums[i] & nums[j];
            store[val]++;
        }
    }
    for (auto pair: store) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto itr: store) {
            if ((itr.first & nums[i]) == 0) {
                ans += itr.second;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> vec = {2, 1, 3};
    cout << findTriplets(vec) << endl;
    cout << countTriplets(vec);
}
