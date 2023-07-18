//
// Created by kapar on 05-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int countWays(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}

int main() {
    cout << countWays(4);
}