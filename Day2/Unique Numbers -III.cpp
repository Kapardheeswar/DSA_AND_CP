//
// Created by kapar on 20-04-2023.
//
#include <bits/stdc++.h>

using namespace std;

void updateSum(vector<int> &sumArray, int x) {
    for (int i = 0; i < 32; ++i) {
        int bit = x & (1 << i);
        if (bit) sumArray.at(i)++;
    }
}

int uniqueNumber(vector<int> arr) {
    vector<int> sumArray(32, 0);
    for (int k: arr) {
        updateSum(sumArray, k);
    }
    for (int i = 0; i < 32; ++i) {
        sumArray.at(i) = sumArray.at(i) % 3;
    }
    int num = 0;
    for (int i = 0; i < 32; ++i) {
        num += sumArray.at(i) * (1 << i);
    }
    return num;
}

int main() {
    vector<int> vec = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4};
    cout << uniqueNumber(vec) << endl;
}