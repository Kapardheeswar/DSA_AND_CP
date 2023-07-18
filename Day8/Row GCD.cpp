//
// Created by kapar on 25-06-2023.
//
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcdOfVectors(vector<int>terms){
    int result = gcd(terms[0],terms[1]);
    for (int i = 2; i < terms.size(); i++) {
        result = gcd(result,terms[i]);
    }
    return result;
}

vector<int>solve(int n,int m, vector<int> a, vector<int> b){
    vector<int>results;
    vector<int>terms;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            terms.push_back(a[j]+b[i]);
        }
        results.push_back(gcdOfVectors(terms));
        terms.clear();
    }
    return results;
}

int main() {
    cout << gcdOfVectors({6, 9, 12, 15}) << endl;  // output: 3
    cout << gcdOfVectors({10, 11, 22, 33, 44}) << endl;  // output: 1
    vector<int> results = solve(4,4,{1, 25, 121, 169},{1, 2, 7, 23});
    for (auto k:results) {
        cout<<k<<",";
    }
    return 0;
}