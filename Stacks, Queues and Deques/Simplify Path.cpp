//
// Created by kapar on 10-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

void reverseStack(stack<char> stack) {
    if (stack.empty()) return;
    char ch = stack.top();
    stack.pop();
    reverseStack(stack);
    cout << ch << " ";
}

string simplifyPath(string path) {
    //complete this code return the simplified path
    vector<string> v;
    int i = 0;
    while (i < path.length()) {
        if (path[i] == '/') {
            string s = "";
            i++;
            while (i < path.length() and path[i] != '/') {
                s = s + path[i];
                i++;
            }
            v.push_back(s);
            i--;
        }
        i++;
    }
    for (auto s: v) {
        cout << s << " ";
    }
    cout << endl;
    deque<string> dq;
    for (int j = 0; j < v.size(); j++) {
        if (v[j] == "." or v[j]=="") {
            continue;
        } else if (v[j] == "..") {
            if (!dq.empty()) {
                dq.pop_back();
            }
        } else {
            dq.push_back(v[j]);
        }
    }
    string str = "/";
    for (auto d: dq) {
        if (d != "") {
            str += d;
            str += "/";
        }
    }
    str.pop_back();
    if(str=="")str="/";
    return str;
}

int main() {
    cout << simplifyPath("/a//b////c/d//././/..");
}