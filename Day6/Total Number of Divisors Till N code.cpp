//
// Created by kapar on 17-06-2023.
//
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ifstream input_file("input.txt");
    ofstream output_file("output.txt");
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int n;
    input_file >> n;
    int ans=0;
    int m = primes.size();
    for (int i = 1; i < (1 << m); i++) {
        int lcm =1;
        int number = i;
        int lastBitPos = 0;
        while (number) {
            if (number & 1) {
//                output_file << primes[lastBitPos]<<" ";
                lcm *= primes[lastBitPos];
            }
            number >>= 1;
            lastBitPos++;
        }
//        output_file<<endl;
        if( __builtin_popcount(i)%2==0){
            ans -= (n/lcm);
        }else{
            ans += (n/lcm);
        }

    }
    output_file<<ans;
    input_file.close();
    output_file.close();
}