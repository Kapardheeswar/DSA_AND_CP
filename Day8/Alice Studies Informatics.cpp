//
// Created by kapar on 25-06-2023.
//
#include<bits/stdc++.h>

using namespace std;

int gcd(int A, int B) {
    if (B == 0) return A;
    return gcd(B, A % B);
}

int solve(int l, int r, int x, int y) {
    int count = 0;
    if (y % x != 0) return count;
    for (int i = 1; i <= sqrt(y / x); i++) {
        if ((y / x) % i == 0) {
            int k = i;
            int m = (y / x) / k;
            if (gcd(k, m) == 1) {
                if (((l / x) <= k) && (k <= (r / x)) && ((l / x) <= m) && (m <= (r / x))) {
                    count += 2;
                }
            }
        }
    }
    return count;
}

int main() {
    cout << solve(50, 100, 3, 30);
}