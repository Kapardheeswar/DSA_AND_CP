//
// Created by kapar on 30-07-2023.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 1e5;

int spf[MAXN + 1]; // spf[i] = smallest prime factor of i
int factorCount[MAXN + 1]; // factorCount[i] = number of factors of i

void sieve() {
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            for (long long j = (long long) i * i; j <= MAXN; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
        }
    }
    factorCount[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        int p = spf[i];
        int q = i / p;
        if (q % p == 0) {
            factorCount[i] = factorCount[q] + 1;
        } else {
            factorCount[i] = factorCount[q] * 2;
        }
    }
}

vector<int> getValidCount(vector<int> keys) {
    sieve();
    vector<int> ans;
    for (auto k: keys) {
        int count = 0;
        for (int i = max(6, k - 100); i <= k; i++) {
            if (factorCount[i] == 3) {
                count++;
            }
        }
        ans.push_back(count + 1);
    }
    return ans;
}


int main() {
    vector<int> validCount = getValidCount({10, 15});
    for (auto i: validCount) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}