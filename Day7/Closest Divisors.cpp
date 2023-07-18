//
// Created by kapar on 19-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<int> closestDivisors(int num) {
    vector<int> divs(2, 0);
    int diff = 9999;
    for (int i = 1; i <= sqrt(num + 1); i++) {
        if ((num+1) % i == 0) {
            int j = (num+1) / i;
            if (diff > abs(j - i)) {
                diff = abs(j - i);
                divs[0] = i;
                divs[1] = j;
            }
        }
    }
    for (int i = 1; i <= sqrt(num + 2); i++) {
        if ((num+2) % i == 0) {
            int j = (num+2) / i;
            if (diff > abs(j - i)) {
                diff = abs(j - i);
                divs[0] = i;
                divs[1] = j;
            }
        }
    }
    return divs;
}
int main(){
    vector<int>v = closestDivisors(8);
    for(int k:v){
        cout<<k<<" "<<endl;
    }
}
