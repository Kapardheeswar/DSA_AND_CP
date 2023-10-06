//
// Created by kapar on 01-10-2023.
//
#include <bits/stdc++.h>

using namespace std;

int getPthFactor(int n,int p) {
    set<int> s;
    int temp = n;
    for (int i = 1; i <= (temp); i++) {
        if (n % i == 0) {
            s.insert(i);
            s.insert((n / i));
        }
    }
    int count=1;
    while (!s.empty()) {
        auto f = s.begin();
        int x = *f;
        if(count==p){
            return x;
        }
        count++;
        s.erase(f);
    }
    return 0;
}

int main() {
    cout<<getPthFactor(20,3);
    return 0;
}