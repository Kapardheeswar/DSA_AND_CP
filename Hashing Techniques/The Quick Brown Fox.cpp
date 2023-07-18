//
// Created by kapar on 15-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int getMinBars(string s, map<string, int> m, int i) {
    if (i == s.length()) return 0;
    string currentString = "";
    int ans = INT_MAX;
    for (int j = i; j < s.length(); j++) {
        currentString += s[j];
        if (m[currentString] == 1) {
            int remainingAns = getMinBars(s, m, j + 1);
            if (remainingAns != -1) {
                ans = min(ans, 1 + remainingAns);
            }
        }
    }
    if (ans == INT_MAX) return -1;
    return ans;
}

int main() {
    string s = "thequickbrownfox";
    vector<string> v = {"the", "quickbrown", "fox", "quick", "brown"};
    map<string, int> m;
    for (auto s: v)m[s]++;
    cout<<getMinBars(s,m,0)-1;
}