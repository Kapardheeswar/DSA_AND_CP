//
// Created by kapar on 05-07-2023.
//
#include<bits/stdc++.h>
using namespace std;
vector<string> digitToLetters = {
        "",     // 0
        "",     // 1
        "ABC",  // 2
        "DEF",  // 3
        "GHI",  // 4
        "JKL",  // 5
        "MNO",  // 6
        "PQRS", // 7
        "TUV",  // 8
        "WXYZ"  // 9
};
vector<string>combinations;
void getCombinations(string output,int i,string digits){
    if(i==digits.length()){
        combinations.push_back(output);
    }
    int currentNumber = digits[i]-'0';
    if(currentNumber==0 or currentNumber==1){
        getCombinations(output,i+1,digits);
    }
    for (int j = 0; j < digitToLetters[currentNumber].length(); j++) {
        getCombinations(output+digitToLetters[currentNumber][j],i+1,digits);
    }
}
vector<string> letterCombinations(string digits) {
    getCombinations("",0,digits);
    return combinations;
}
int main(){
    vector<string>sets= letterCombinations("2");
    for (auto s:sets) {
        cout<<s<<endl;
    }
}