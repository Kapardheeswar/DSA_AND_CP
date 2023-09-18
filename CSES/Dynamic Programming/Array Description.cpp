//
// Created by kapar on 10-09-2023.
//
#include <bits/stdc++.h>

#define int long long
using namespace std;
int mod = 1e9 + 7;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)cin >> arr[i];
    vector<vector<int>> noOfArrays(n + 1, vector<int>(m + 1, 0));
    if (arr[0] != 0) noOfArrays[0][arr[0]] = 1;
    else {
        for (int i = 1; i <= m; i++) {
            noOfArrays[0][i] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; j++) {
                if (j - 1 >= 1) {
                    noOfArrays[i][j] = (noOfArrays[i][j] + noOfArrays[i - 1][j - 1]) % mod;
                }
                noOfArrays[i][j] = (noOfArrays[i][j] + noOfArrays[i - 1][j]) % mod;
                if (j + 1 <= m) {
                    noOfArrays[i][j] = (noOfArrays[i][j] + noOfArrays[i - 1][j + 1]) % mod;
                }
            }
        } else {
            if (arr[i] - 1 >= 1) noOfArrays[i][arr[i]] = (noOfArrays[i][arr[i]] + noOfArrays[i - 1][arr[i] - 1]) % mod;
            noOfArrays[i][arr[i]] = (noOfArrays[i][arr[i]] + noOfArrays[i - 1][arr[i]]) % mod;
            if (arr[i] + 1 <= m) noOfArrays[i][arr[i]] = (noOfArrays[i][arr[i]] + noOfArrays[i - 1][arr[i] + 1]) % mod;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += noOfArrays[n - 1][i];
        ans %= mod;
    }
    cout << ans;
}