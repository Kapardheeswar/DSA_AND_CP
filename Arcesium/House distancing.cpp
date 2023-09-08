//
// Created by kapar on 20-08-2023.
//
#include <bits/stdc++.h>

using namespace std;

bool canWePlace(int l, int n, int dist) {
    int houseCount = 1;
    int currIndex = 0;
    while (currIndex < l) {
        houseCount++;
        currIndex += dist;
    }
    if (houseCount >= n)return true;
    return false;
}

int main() {
    int l, n;
    cin >> l >> n;
    int lo = 0;
    int hi = n - 1;
    int ans = 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        bool isPossible = canWePlace(l, n, mid);
        if (isPossible) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
}