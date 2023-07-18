//
// Created by kapar on 04-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

float getSquareRoot(int n, int p) {
    int s = 0;
    int e = n;
    float ans = 0;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (mid * mid == n) {
            return mid;
        } else if (mid * mid <= n) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    float inc = 0.1;
    for (int i = 0; i < p; i++) {
        while(ans*ans<=n){
            ans+=inc;
        }
        ans-=inc;
        inc/=10;
    }
    return ans;
}
int main(){
    cout<<getSquareRoot(50,5);
}