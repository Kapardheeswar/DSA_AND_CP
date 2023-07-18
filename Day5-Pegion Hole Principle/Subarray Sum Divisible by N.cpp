//
// Created by kapar on 16-06-2023.
//
#include <bits/stdc++.h>

using namespace std;
int k;
int n;
int sz;
int counter = 0;

void subArraySum() {
    cin >> k;
    cin >> n;
    int sum = 0;
    vector<int> v(k);
    vector<int> mods(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        sum += v[i];
        mods[i] = sum % n;
    }
    for (int mod: mods) {
        if (mod == 0) {
            counter++;
        }
    }
    for (int i = 0; i < mods.size(); i++) {
        for (int j = i + 1; j < mods.size(); j++) {
            if (mods[i] == mods[j] != 0) {
                counter++;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t != 0) {
        subArraySum();
        cout << counter;
        cout << endl;
        counter = 0;
        t--;
    }
}