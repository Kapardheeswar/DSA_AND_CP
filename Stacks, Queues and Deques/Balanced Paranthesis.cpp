//
// Created by kapar on 08-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string s) {
    stack<char> stack;
    int i = 0;
    while (i < s.length()) {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[') stack.push(s[i]);
        else if (s[i] == ')' or s[i] == '}' or s[i] == ']') {
            if (s[i] == ')' and !stack.empty() and stack.top() == '(') stack.pop();
            else if (s[i] == '}' and !stack.empty() and stack.top() == '{') stack.pop();
            else if (s[i] == ']' and !stack.empty() and stack.top() == '[') stack.top();
        }
        i++;
    }
    if (stack.empty()) return true;
    return false;
}

int main() {
    cout << isBalanced("((12*3)-96)");
}
