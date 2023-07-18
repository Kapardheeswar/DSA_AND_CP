//
// Created by kapar on 11-06-2023.
//
#include<bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res *= a, res %= 9;
        a *= a;
        a %= 9;
        b = b >> 1;
    }
    return res;
}
long long solve(int a,int n){
    long long ans = power(a,n);
    if(ans==0){
        return 9;
    }
    return ans;
}
int main(){
    cout<<solve(5,2);

}