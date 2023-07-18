//
// Created by kapar on 12-06-2023.
//
#include <bits/stdc++.h>

using namespace std;
#define int long long int
int k, n;
vector<int> b, c;
int mod = 1e9;

struct Mat {
    vector<vector<int>> m;
    int n;

    explicit Mat(int n) {
        this->n = n;
        m.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = 0;
            }
        }
    }

    void identity() {
        for (int i = 0; i < n; i++) {
            m[i][i] = 1;
        }
    }

    Mat operator*(const Mat &a) const {
        Mat res(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < n; l++) {
                    res.m[i][j] += m[i][l] * a.m[l][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }

    void printMat() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int seq() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        b.push_back(num);
    }
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        c.push_back(num);
    }
    Mat res(k);
    res.identity();
    Mat t(k);
    for (int i = 0; i < k; i++) {
        t.m[0][i] = c[i];
    }
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (i == j + 1) {
                t.m[i][j] = 1;
            }
        }
    }
    cin >> n;
    if (n <= k) {
        return b[n - 1];
    }
    n -= k;
    while (n) {
        if (n & 1) res = res * t;
        t = t * t;
        n >>= 1;
    }
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += b[k - i - 1] * res.m[0][i];
    }
    return (sum + mod) % mod;
}

int32_t main() {
    int t;
    cin >> t;
    while (t) {
        cout << seq() << endl;
        b.clear();
        c.clear();
        t--;
    }
}
