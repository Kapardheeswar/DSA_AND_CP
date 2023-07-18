//
// Created by kapar on 11-06-2023.
//
#include<bits/stdc++.h>

using namespace std;
long long int mod = 1e9 + 7;

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res *= a, res %= mod;
        a *= a;
        a %= mod;
        b = b >> 1;
    }
    return res;
}

long long locker(int n) {
    if (n % 3 == 0) {
        return power(3, n / 3) % mod;
    } else if (n % 3 == 1) {
        return (power(3, ((n - 1) / 3) - 1) * 4) % mod;
    } else {
        return (power(3, (n - 2) / 3) * 2) % mod;
    }
}

int main() {
    int n;
    cin>>n;
    while(n!=0){
        int k;
        cin>>k;
        cout<<locker(k);
        n--;
    }
    return 0;
}