//
// Created by kapar on 02-07-2023.
//
#include<bits/stdc++.h>
using namespace std;
int longestUniqueSubstring(string s){
    int i=0;
    int j=0;
    int currentWindowLength = 0;
    int maxWindowLength = 0;
    int startingWindow = 0;
    unordered_map<char,int>m;
    while(j<s.length()){

        if(m.count(s[j]) and m[s[j]]>=i){
            i = m[s[j]]+1;
            // element i to j-1
            currentWindowLength = (j-1)-(i)+(1);
        }

        m[s[j]]=j;
        j++;
        currentWindowLength++;

        if(currentWindowLength>maxWindowLength){
            maxWindowLength = currentWindowLength;
            startingWindow = i;
        }
    }

    return maxWindowLength;
}

int main(){
    cout<<longestUniqueSubstring("abcdeba");
}