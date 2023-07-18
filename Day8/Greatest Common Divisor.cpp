//
// Created by kapar on 25-06-2023.
//
#include <bits/stdc++.h>
using namespace std;
int gcd(int A, int B) {
    if(B==0) return A;
    return gcd(B,A%B);
}
int GCD_II(int a,string b){
    int n = b.size();
    int val=0;
    for (int i = 0; i < n; i++) {
        val = (val*10+(b[i]-'0'))%a;
    }
    int gcd2 = gcd(a,val);
    return gcd2;
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        string b;
        cin >> a >> b;
        int mod = 0;
        for (int j = 0; j < b.length(); j++)
        {
            mod = (mod * 10 + (b[j] - '0')) % a;
        }
        cout << gcd(a, mod) << endl;
    }
}