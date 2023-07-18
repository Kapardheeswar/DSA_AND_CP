//
// Created by kapar on 13-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {5, 4, 7, 1, 23, 2};
    priority_queue<int, vector<int>, greater<int> > heap;
    for (auto i: v) {
        heap.push(i);
    }
    while (!heap.empty()) {
        cout << heap.top() << " ";
        heap.pop();
    }
}