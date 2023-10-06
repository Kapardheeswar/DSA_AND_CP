//
// Created by kapar on 17-06-2023.
//
#include<bits/stdc++.h>
using namespace std;
void primeFact(int n){
    for (int i = 2; i*i < n; i++) {
        if(n%i==0){
            int cnt=0;
            while (n%i==0){
                cnt++;
                n/=i;
            }
            cout<<i<<"^"<<n<<",";
        }
    }
    if(n!=1){
        cout<<n<<"^"<<"1"<<" ";
    }
}
int main(){
    primeFact(99);
}
