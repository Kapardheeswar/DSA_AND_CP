#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if ((n & n - 1) == 0 && ((1431655765 & n) == n)) {
        cout << "Power of Four\n";
    } else {
        cout << "Not Power of Four\n";
    }
}