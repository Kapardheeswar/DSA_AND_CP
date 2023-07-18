//
// Created by kapar on 14-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<string> getAllConsecutiveSubstrings(string s) {
    vector<string> ans;
    int cnt = 1;
    while (cnt <= s.length()) {
        for (int i = 0; i < s.length(); i++) {
            int startIdx = i;
            int endIdx = i + cnt - 1;
            if (endIdx < s.length()) {
                string S = "";
                for (int j = startIdx; j <= endIdx; j++) {
                    S += s[j];
                }
                ans.push_back(S);
            }
        }
        cnt++;
    }
    return ans;
}
int getAnagramsCount(vector<string>v){
    map<map<char,int>,int> map1;
    for(auto s:v){
        map<char,int> map2;
        for(char ch:s){
            map2[ch]++;
        }
        map1[map2]++;
    }
    int cnt=0;
    for(auto p:map1){
        if(p.second>=2){
            int n = p.second;
            cnt+=((n)*(n-1))/2;
        }
    }
    return cnt;
}
int main(){
    vector<string>v = getAllConsecutiveSubstrings("abba");
    for(auto s:v) cout<<s<<" ";
    cout<<endl;
    cout<<getAnagramsCount(v);
}