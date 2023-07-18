//
// Created by kapar on 16-06-2023.
//
#include<bits/stdc++.h>

using namespace std;
#define int long long

int solve(int n, int m, vector<int> a) {
    int product = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            product *= abs(a[j] - a[i]);
            product %= m;
        }
    }
    return product;
}

int32_t main() {
    cout << solve(2, 10, {8, 5});
}