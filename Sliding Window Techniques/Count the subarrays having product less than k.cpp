//
// Created by kapar on 04-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k) {
    int i = 0;
    int j = 0;
    int currentProduct = 1;
    int count = 0;
    while (j < n) {
        currentProduct *= a[j];

        while (currentProduct >= k and i <= j) {
            currentProduct /= a[i];
            i++;
        }
        count += (j - i) + 1;
        j++;
    }
    return count;
}

int main() {
    vector<int> a = {1, 2, 3, 4};
    cout << countSubArrayProductLessThanK(a, a.size(), 10)<<endl;
}