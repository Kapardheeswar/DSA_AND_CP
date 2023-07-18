//
// Created by kapar on 17-06-2023.
//
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll mod = 1e9 + 7;

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

ll solve(int n) {
    ll ans = 1;
    ll x = power(26, mod - 2);
    ll y = power(25, mod - 2);
    y *= 2;
    y = (y * ((1 - power(x, (n / 2)) + mod) % mod)) % mod;
    ans = (ans + y) % mod;
    if(n%2==0){
        ans=(ans+mod-power(x,n/2))%mod;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    int n;
    while(t!=0){
        cin>>n;
        cout<<solve(n)<<endl;
        t--;
    }
}