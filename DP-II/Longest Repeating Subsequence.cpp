//
// Created by kapar on 18-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int LCS(string a, string b, int i, int j) {
    if (i == a.length() or j == b.length()) return 0;
    int ans = INT_MIN;
    if (i!=j and a[i] == b[j]) ans = max(ans, 1 + LCS(a, b, i + 1, j + 1));
    else {
        int option1 = LCS(a, b, i + 1, j);
        int option2 = LCS(a, b, i, j + 1);
        ans = max(ans, max(option1, option2));
    }
    return ans;
}

int main() {
    string s = "axxxy";
    cout << LCS(s, s, 0, 0);
}