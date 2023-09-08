//
// Created by kapar on 16-08-2023.
//
#include <bits/stdc++.h>

using namespace std;

int minCacheSizeForHits(vector<string> requests, int k) {
    int n = requests.size();
    for (int cacheSize = 1; cacheSize <= n; ++cacheSize) {
        unordered_set<string> cache;
        int distinctItems = 0;

        for (int i = 0; i < n; ++i) {
            if (cache.find(requests[i]) == cache.end()) {
                ++distinctItems;
                cache.insert(requests[i]);
            }

            if (i >= cacheSize && cache.find(requests[i - cacheSize]) != cache.end()) {
                cache.erase(requests[i - cacheSize]);
            }

            if (distinctItems >= k) {
                return cacheSize;
            }
        }
    }

    return -1;
}

int main() {
    vector<string> requests = {"item1", "item1", "item3", "item1", "item3"};
    int k = 1;
    cout<<minCacheSizeForHits(requests, k);
    return 0;
}
