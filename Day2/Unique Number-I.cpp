//
// Created by kapar on 20-04-2023.
//
#include <bits/stdc++.h>
using namespace std;
int uniqueNumber(vector<int> arr){
    int XOR=0;
    for (int ele:arr) {
        XOR=XOR^ele;
    }
    return XOR;
}
int main(){
    vector<int> arr={1,3,5,3,1};
    cout<<uniqueNumber(arr)<<endl;
}