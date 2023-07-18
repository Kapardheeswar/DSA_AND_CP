//
// Created by kapar on 31-05-2023.
//
#include<bits/stdc++.h>
using namespace std;
long long int mod = 1e7+9;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b = b >> 1;
    }
    return res;
}

string solve(int a, int b, int c) {
    int x = power(a, c);
    cout << x;
    cout << endl;
    int y = power(b, c);
    cout << y;
    if (x > y) return ">";
    else if (y > x) return "<";
    else return "=";
}

int main() {
//    int a, b, c;
//    cin >> a >> b >> c;
//    string s = solve(a, b, c);
//    cout << s;
cout<<power(2,2);
}