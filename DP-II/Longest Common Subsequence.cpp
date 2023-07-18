//
// Created by kapar on 18-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

//Recursive
int LCS(string a, string b, int i, int j) {
    if (i == a.length() or j == b.length()) return 0;
    int ans = INT_MIN;
    if (a[i] == b[j]) ans = max(ans, 1 + LCS(a, b, i + 1, j + 1));
    else {
        int option1 = LCS(a, b, i + 1, j);
        int option2 = LCS(a, b, i, j + 1);
        ans = max(ans, max(option1, option2));
    }
    return ans;
}

//Top Down
int LCSTD(string a, string b, int i, int j, vector<vector<int>> &dp) {
    if (i == a.length() or j == b.length()) return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MIN;
    if (a[i] == b[j]) {
        ans = max(ans, 1 + LCSTD(a, b, i + 1, j + 1, dp));
    } else {
        int option1 = LCSTD(a, b, i + 1, j, dp);
        int option2 = LCSTD(a, b, i, j + 1, dp);
        ans = max(ans, max(option1, option2));
    }
    return dp[i][j] = ans;
}

int main() {
    string s1 = "ABCD";
    string s2 = "ABEDG";
    int n = s1.length();
    int m = s2.length();
    cout << LCS(s1, s2, 0, 0) << endl;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << LCSTD(s1, s2, 0, 0, dp) << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}