//
// Created by kapar on 03-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

bool compare(string x, string y) {
    return x + y < y + x;
}

int main(){
    vector<string>v={"a","ab","aba"};
    sort(v.begin(),v.end(), compare);
    for(auto s:v){
        cout<<s;
    }
}