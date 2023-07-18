//
// Created by kapar on 17-06-2023.
//
#include <bits/stdc++.h>

using namespace std;
#define ll long long
int N = 1000000;

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
int countPrimes(vector<int> sieve,int n){
    int count=0;
    for (int i = 2; i <n; i++) {
        if(sieve[i]) count++;
    }
    return count;
}
int main() {
    ofstream output_file("output.txt");
    vector<int> sieve(N, 1);
    primeSieve(sieve);
    for (int i = 0; i < 50; i++) {
        if (sieve[i]) {
            output_file << i << " ";
        }
    }
    output_file<<endl;
    output_file<<countPrimes(sieve,10)<<endl;
    output_file.close();
}
