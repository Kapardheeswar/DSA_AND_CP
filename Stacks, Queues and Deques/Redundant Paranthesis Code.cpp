//
// Created by kapar on 08-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

bool areBracketsRedundant(string s) {
    stack<char> stack;
    for (char i : s) {
        if (i != ')') stack.push(i);
        else {
            bool operatorFound = false;
            while (!stack.empty() and stack.top() != ')') {
                char ch = stack.top();
                if (ch == '+' or ch == '-' or ch == '*' or ch == '/') operatorFound = true;
                stack.pop();
            }
            stack.top();
            if (!operatorFound) {
                return true;
            }
        }
    }
    return false;
}
int main(){
    cout<<areBracketsRedundant("((a+b))");
}