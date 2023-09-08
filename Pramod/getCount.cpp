//
// Created by kapar on 02-08-2023.
//
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int getCount(vector<int>v){
    set<vector<int>>s;
    sort(v.begin(),v.end());
    int biggestNumber = v[v.size()-1];
    for (int i = 0; i <= biggestNumber+1; i++) {
        vector<int>temp;
        vector<int>vec = v;
        for (int j = 0; j < vec.size(); j++) {
            if(vec[j]>=i){
                vec[j]--;
            }
        }
        sort(vec.begin(),vec.end());
        s.insert(vec);
    }
    return s.size()%mod;
}
int main(){
    cout<<getCount({1,2});
}