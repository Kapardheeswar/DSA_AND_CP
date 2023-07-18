//
// Created by kapar on 16-06-2023.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,int>> vec[10];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin>>a>>b;
        vec[i].push_back({a,b});
    }
    for (int i = 0; i < n; i++) {
        for (auto p:vec[i]) {
            cout<<p.first<<",";
        }
        cout<<endl;
    }
}
