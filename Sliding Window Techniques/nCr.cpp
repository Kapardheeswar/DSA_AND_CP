//
// Created by kapar on 26-06-2023.
//
#include <bits/stdc++.h>

#define ll long long
#define int long long
using namespace std;
ll mod = 1e9 + 7;

ll mulm(int x, int y) {
    return (x * y) % mod;
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        res %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return power(x, mod - 2);
}

ll fact(ll n) {
    if (n == 0) return 1;
    return mulm(n, fact(n - 1));
}

ll nCr(ll n, ll r) {
    if (r > n) return 0;
    cout << mulm(fact(n), inv(fact(r))) << endl;
    return mulm(mulm(fact(n), inv(fact(r))), inv(fact(n - r)));
}

int ncr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    return (ncr(n - 1, r - 1) + ncr(n - 1, r)) % mod;
}

ll ncr_dp(int n, int r) {
    ll dp[n + 1][r + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= r; j++) {
            if (j > i) dp[i][j] = 0;
            else if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][r];
}

int32_t main() {
    cout << fact(5) << endl;
    cout << ncr_dp(5, 2);
}