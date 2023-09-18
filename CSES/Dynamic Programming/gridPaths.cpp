//
// Created by kapar on 10-09-2023.
//
#include <bits/stdc++.h>

using namespace std;
int mod = 1e9+7;
int getTotalGridPaths(vector<vector<char>> grid, int n) {
    if(grid[0][0]=='*') return 0;
    vector<vector<int>> totalPaths(n, vector<int>(n, 0));
    totalPaths[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i==0 and j==0) continue;
            if (grid[i][j] != '*') {
                if (i == 0 and j != 0) {
                    totalPaths[i][j] = totalPaths[i][j - 1]%mod;
                } else if (j == 0 and i != 0) {
                    totalPaths[i][j] = totalPaths[i - 1][j]%mod;
                } else {
                    totalPaths[i][j] = (totalPaths[i - 1][j] + totalPaths[i][j - 1])%mod;
                }
            }
        }
    }
    return totalPaths[n - 1][n - 1]%mod;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << getTotalGridPaths(grid, n);
}