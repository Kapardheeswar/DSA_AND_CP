//
// Created by kapar on 22-04-2023.
//
#include<bits/stdc++.h>
using namespace std;
void getAnswer(int &value,int left,int right){
    if(left<right+1){
        value&=left;
        getAnswer(value,left+1,right);
    }
}
int rangeBitwiseAnd(int left, int right) {
    int value=-1;
    getAnswer(value,left,right);
    return value;
}
int main(){
    int left,right;
    cin>>left>>right;
    cout<<rangeBitwiseAnd(left,right);
}