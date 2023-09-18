//
// Created by kapar on 17-09-2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> stack;
    for (int it: asteroids) {
        int flag = 1;
        while (!stack.empty() and (stack.top() > 0 and it < 0)) {
            if (abs(stack.top()) < abs(it)) {
                stack.pop();
                continue;
            } else if (abs(stack.top()) == abs(it)) stack.pop();
            flag = 0;
            break;
        }
        if (flag) stack.push(it);
    }
    vector<int> ans(stack.size());
    for (int i = ans.size() - 1; i >= 0; i--) {
        ans[i] = stack.top();
        stack.pop();
    }
    return ans;
}

int main() {
    vector<int> v = {5, 10, -5};
    v = asteroidCollision(v);
    for (auto k: v) {
        cout << k << " ";
    }
}