//
// Created by kapar on 25-06-2023.
//
#include<bits/stdc++.h>
using namespace std;
int gcd(int A, int B) {
    if(B==0) return A;
    return gcd(B,A%B);
}
int solve(int a,int b){
    if(gcd(a,b)!=1){
        a/=gcd(a,b);
        cout<<a<<"test"<<endl;
        if(gcd(a,b)!=1) return solve(a,b);
    }
    return a;
}
int main(){
    cout<<solve(24,36)<<endl;
}