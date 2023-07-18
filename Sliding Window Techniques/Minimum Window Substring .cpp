//
// Created by kapar on 02-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

string minimumWindowSubstring(string s, string t) {
    int fs[256] = {0};
    int ft[256] = {0};
    for (int i = 0; i < t.length(); i++) {
        ft[t[i]]++;
    }
    int count = 0;
    int startIndex = 0;
    int minimumWindowLen = INT_MAX;
    int currentWindowLen = 0;
    int minWindowStartIdx = -1;


    for (int i = 0; i < s.length(); i++) {
        fs[s[i]]++;


        if ((ft[s[i]] != 0) and (fs[s[i]] <= ft[s[i]])) {
            count++;
        }

        if (count == t.length()) {
            while ((ft[s[startIndex]] == 0) or (fs[s[startIndex]] > ft[s[startIndex]])) {
                cout << s[startIndex] << endl;
                fs[s[startIndex]]--;
                startIndex++;
            }
            currentWindowLen = i - startIndex + 1;
            if (minimumWindowLen > currentWindowLen) {
                minimumWindowLen = currentWindowLen;
                minWindowStartIdx = startIndex;
            }
        }
    }
    if (minWindowStartIdx == -1) return "";
    return s.substr(minWindowStartIdx, minimumWindowLen);
}

int main() {
    cout << minimumWindowSubstring("ab", "a");
}