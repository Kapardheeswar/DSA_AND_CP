//
// Created by kapar on 05-07-2023.
//
#include <bits/stdc++.h>
using namespace std;

int MaxValue(vector<int> v,int s,int e,int chance,int aSum,int bSum){
    if(s==e){
        return aSum;
    }
    if(chance==1){
        int firstValue = MaxValue(v,s+1,e,2,aSum+v[s],bSum);
        int lastValue = MaxValue(v,s,e-1,2,aSum+v[e],bSum);
        return max(firstValue,lastValue);
    }
    if(chance==2){
        int firstValue = MaxValue(v,s+1,e,1,aSum,bSum+v[s]);
        int lastValue = MaxValue(v,s,e-1,1,aSum,bSum+v[e]);
        return max(firstValue,lastValue);
    }
    return aSum;
}
int main(){
    cout<<MaxValue({1,2,3,4},0,3,1,0,0);
}