//
// Created by kapar on 18-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

//Recursive
int getCount(string str, int index, string s, int n) {
    if (index == str.length()) {
        if (s == "") return 0;
        int ans = 0;
        for (char ch: s) {
            int x = ch - '0';
            ans = ans * 10 + x;
        }
        if (ans % n == 0) return 1;
        return 0;
    }
    int inc = getCount(str, index + 1, s + str[index], n);
    int exc = getCount(str, index + 1, s, n);
    return inc + exc;
}

//Top Down
int getCountTD(string str, int index, string s, int n, vector<int> &dp) {
    if (index == str.length()) {
        if (s == "") return 0;
        int ans = 0;
        for (char ch: s) {
            int x = ch - '0';
            ans = ans * 10 + x;
        }
        if (ans % n == 0) return 1;
        return 0;
    }
    if (dp[index] != -1) return dp[index];
    int inc = getCountTD(str, index + 1, s + str[index], n, dp);
    int exc = getCountTD(str, index + 1, s, n, dp);
    return dp[index] = inc + exc;
}

int main() {
    cout << getCount("1234", 0, "", 4) << endl;
    cout << getCount("330", 0, "", 6) << endl;
    cout << getCount("676", 0, "", 6)<<endl;
    string s = "330";
    vector<int>dp(s.length()+1,-1);
    cout<<getCountTD(s,0,"",6,dp)<<endl;
    for (int i:dp) {
        cout<<i<<" ";
    }
}