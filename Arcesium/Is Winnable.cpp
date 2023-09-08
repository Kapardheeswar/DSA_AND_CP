//
// Created by kapar on 20-08-2023.
//
#include <bits/stdc++.h>

using namespace std;

int countSubsets(vector<int> &balls, int sum, int index) {
    if (index >= balls.size()) {
        if (sum == 0) return 1;
        return 0;
    }
    int inc = countSubsets(balls, sum - balls[index], index + 1);
    int exc = countSubsets(balls, sum, index + 1);
    return inc + exc;
}

bool isSubsetSum(vector<int> set, int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;
    if (set[n - 1] > sum) return isSubsetSum(set, n - 1, sum);
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

bool isWinnable(vector<int> balls) {
    int sum = 0;
    for (auto k: balls)sum += k;
    if (sum % 2 != 0) return false;
//    int count = countSubsets(balls, sum / 2, 0);
    bool isPossible = isSubsetSum(balls, balls.size(), sum / 2);
    if (isPossible) return true;
    return false;
}

int main() {
    bool isPossible = isWinnable({1, 1,2,2});
    if (isPossible)cout << "YES" << endl;
    else cout << "NO" << endl;
}