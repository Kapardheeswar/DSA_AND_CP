//
// Created by kapar on 18-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

//Recursive
int countSubsequence(string s1, string s2, int i, int j) {
    if (i == s1.size() and j == s2.size()) return 1;
    if (i == s1.size()) return 0;
    if (s1[i] != s2[j]) {
        return countSubsequence(s1, s2, i + 1, j);
    }
    int option1 = countSubsequence(s1, s2, i + 1, j + 1);
    int option2 = countSubsequence(s1, s2, i + 1, j);
    return option1 + option2;
}

//Top Down
int countSubsequenceTD(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    if ((i == s1.size() and j == s2.size()) or j == s2.size()) return 1;
    if (i == s1.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i] != s2[j]) {
        return dp[i][j] = countSubsequenceTD(s1, s2, i + 1, j, dp);
    }
    int option1 = countSubsequenceTD(s1, s2, i + 1, j + 1, dp);
    int option2 = countSubsequenceTD(s1, s2, i + 1, j, dp);
    return dp[i][j] = option1 + option2;
}

int main() {
    string s1 = "ABCDCECC";
    string s2 = "ABC";
    cout << countSubsequence(s1, s2, 0, 0) << endl;
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    cout << countSubsequenceTD(s1, s2, 0, 0, dp) << endl;
    for (auto v: dp) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
}