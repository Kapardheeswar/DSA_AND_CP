//
// Created by kapar on 19-06-2023.
//
#include<bits/stdc++.h>

using namespace std;
#define ll long long
int N = 100000;

void primeSieve(vector<int> &sieve) {
    sieve[1] = sieve[0] = 0;
    for (ll i = 2; i <= N; i++) {
        if (sieve[i]) {
            for (ll j = i * i; j <= N; j = j + i) {
                sieve[j] = 0;
            }
        }
    }
}

int solve(int n, vector<int> s) {
    int count = 0;
    for (int i = 2; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == 1 && s[j] == 1 && s[i + j] == 1) {
                if (i + j <= n)count++;
            }
        }
    }
    return count;
}

int main() {
    vector<int> sieve(N, 1);
    primeSieve(sieve);
    cout << solve(123, sieve) << endl;
}