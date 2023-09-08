//
// Created by kapar on 08-09-2023.
//
#include <bits/stdc++.h>

using namespace std;

int wordBreak(vector<string> words, int index, string str) {
    if (index == str.size()) return 1;
    string temp = "";
    for (int j = index; j < str.size(); j++) {
        temp += str[j];
        if (find(words.begin(), words.end(), temp) != words.end()) {
            if (wordBreak(words, j + 1, str)) return 1;
        }
    }
    return 0;
}

int main() {
    vector<string> words = {"leet", "code"};
    cout << wordBreak(words, 0, "leetcode");
}