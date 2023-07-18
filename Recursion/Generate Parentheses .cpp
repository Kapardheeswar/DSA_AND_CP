//
// Created by kapar on 05-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
vector<string> brackets;

void getParenthesis(string output, int open, int close, int n, int i) {
    if (i == 2 * n) {
        brackets.push_back(output);
    }
    if (open < n) {
        getParenthesis(output + "(", open + 1, close, n, i + 1);
    }
    if (close < open) {
        getParenthesis(output + ")", open, close + 1, n, i + 1);
    }
}

vector<string> generateParenthesis(int n) {
    getParenthesis("", 0, 0, n, 0);
    return brackets;
}

int main() {
    generateParenthesis(3);
    for (auto s: brackets) {
        cout << s << endl;
    }
}