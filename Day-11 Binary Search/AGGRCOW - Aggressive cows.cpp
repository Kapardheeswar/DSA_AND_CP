//
// Created by kapar on 04-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

bool canPlace(int n, int b, vector<int> v, int sep) {
    int placedBirds = 1;
    int currentLocation = v[0];
    for (int i = 0; i < n - 1; i++) {
        int location = v[i];
        if (location - currentLocation >= sep) {
            placedBirds++;
            currentLocation = v[i];
            if (placedBirds == b) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> v = {1, 4, 2, 8, 9};
    int b = 3;
    sort(v.begin(), v.end());
    int s = 0;
    int e = v.size() - 1;
    int ans = 0;
    while (s <= e) {
        int mid = (s + e) / 2;
        bool isPlaced = canPlace(v.size(), b, v, mid);
        if (isPlaced) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    cout << ans;
}