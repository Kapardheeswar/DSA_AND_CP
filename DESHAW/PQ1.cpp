//
// Created by kapar on 20-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
void permutations(string s1,string s2,int i,string& min){
    if(i==s1.length()){
        if(s1>s2 && s1<min){
            min = s1;
        }
        return;
    }
    for (int j = i; j < s1.length(); j++) {
        swap(s1[i],s1[j]);
        permutations(s1,s2,i+1,min);
        swap(s1[i],s1[j]);
    }
}
string num(string s1,string s2){
    sort(s1.begin(),s1.end(),greater<char>());
    if(s1.length()<s2.length() or s1<s2) return "-1";
    string min = s1;
    permutations(s1,s2,0,min);
    if(min == to_string(INT_MAX)) return "-1";
    return min;
}
int main(){
    cout<<num("012345","012345");
}