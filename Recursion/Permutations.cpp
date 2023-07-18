//
// Created by kapar on 05-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
set<string> permutations;
void getPermutations(string input,int i){
    if(i==input.length()){
        permutations.insert(input);
    }
    for (int k = i; k < input.length(); k++) {
        swap(input[i],input[k]);
        getPermutations(input,i+1);
        swap(input[i],input[k]);
    }
}
vector<string> findSortedPermutations(string s){
    getPermutations(s,0);
    vector<string>v(permutations.begin(),permutations.end());
    return v;
}

int main(){
    vector<string>v = findSortedPermutations("acb");
    for(auto s:v){
        cout<<s<<endl;
    }
}