//
// Created by kapar on 17-06-2023.
//
#include<bits/stdc++.h>

using namespace std;

int numDivisible(int l, int r, vector<int> arr) {
    int n = r - l + 1;
    int m = arr.size();
    int ans = 0;
    for (int i = 1; i < (1 << m); i++) {
        int lcm = 1;
        int number = i;
        int lastBitPos = 0;
        while (number) {
            if (number & 1) {
//                output_file << primes[lastBitPos]<<" ";
                lcm = lcm * arr[lastBitPos] / (__gcd(lcm, arr[lastBitPos]));
            }
            number >>= 1;
            lastBitPos++;
        }
//        output_file<<endl;
        if (__builtin_popcount(i) % 2 == 0) {
            ans -= (n / lcm);
        } else {
            ans += (n / lcm);
        }
    }
    return ans;
}

int main() {
    ofstream output_file("output.txt");
    output_file << numDivisible(579000, 987654, {1, 2}) << endl;
    output_file.close();
}

