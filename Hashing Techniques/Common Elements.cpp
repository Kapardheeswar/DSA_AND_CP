//
// Created by kapar on 13-07-2023.
//
#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2){
    vector<int>ans;
    unordered_map<int,bool>m;
    for (int i = 0; i < v1.size(); i++) {
        m[v1[i]] = true;
    }
    for (int i = 0; i < v2.size(); i++) {
        if(m[v2[i]]) ans.push_back(v2[i]);
    }
    return ans;
}