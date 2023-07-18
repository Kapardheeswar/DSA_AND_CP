//
// Created by kapar on 12-06-2023.
//
#include<bits/stdc++.h>

using namespace std;

string greyCode() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n >= 130) {
        return "Yes";
    } else {
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k+1; l < n; l++) {
                        if((v[i]^v[j]^v[k]^v[l])==0 ){
                            return "Yes";
                        }
                    }
                }
            }
        }
    }
    return "No";
}

int main() {
    cout<<greyCode();
}
