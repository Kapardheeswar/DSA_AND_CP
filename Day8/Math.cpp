//
// Created by kapar on 24-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

pair<int, int> solve(int n) {
    pair<int, int> answer;
    map<int, int> primes;
    int u = INT_MIN;
    int productOfFactors = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            primes[i]++;
            if (u < primes[i]) u = primes[i];
            n /= i;
        }
        if (primes[i] != 0) productOfFactors *= i;
    }
    if (n > 1) {
        primes[n]++;
        productOfFactors *= n;
        if (u < primes[n]) u = primes[n];
    }
    int p = 1;
    int k = 0;
    while (p < u) {
        p *= 2;
        k++;
    }
    answer.first = productOfFactors;
    answer.second = k+1;
    if(u==1) answer.second = 0;
    return answer;
}

int main() {
    int n;
    cin>>n;
    pair<int,int>sol = solve(n);
    cout << sol.first << " " << sol.second << endl;
}
