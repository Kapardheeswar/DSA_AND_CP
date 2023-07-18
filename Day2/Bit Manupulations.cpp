#include<bits/stdc++.h>

using namespace std;

int getIthBit(int n, int i) {
    int mask = 1 << i;
    return (mask & n) > 0 ? 1 : 0;
}

int clearIthBit(int n, int i) {
    int mask = ~(1 << i);
    return (mask & n);
}

int setIthBit(int n, int i) {
    int mask = (1 << i);
    return (mask | n);
}

int updateIthBit(int n, int i, int v) {
    int mask = (v << i);
    n = clearIthBit(n, i);
    return (n | mask);
}

int clearLast_i_Bits(int n, int i) {
    int mask = (~0 << i);
    return (n & mask);
}

int clearBitsInRange(int n, int i, int j) {
    int a = (~0 << j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    return (mask & n);
}

int main() {
    int n = 31;
    int i = 1;
    int j = 3;
//    cout << getIthBit(n, i) << endl;
//    cout << clearIthBit(n, i) << endl;
    cout << clearBitsInRange(n, i, j) << endl;
}
