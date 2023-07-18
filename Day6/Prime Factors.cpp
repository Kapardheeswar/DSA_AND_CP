//
// Created by kapar on 17-06-2023.
//
#include<bits/stdc++.h>
using namespace std;
void primeFact(int n){
    ofstream output_file("output.txt");
    for (int i = 2; i*i < n; i++) {
        if(n%i==0){
            int cnt=0;
            while (n%i==0){
                cnt++;
                n/=i;
            }
            output_file<<i<<"^"<<cnt<<",";
        }
    }
    if(n!=1){
        output_file<<n<<"^"<<"1"<<" ";
    }
    output_file.close();
}
int main(){
    primeFact(99);
}
