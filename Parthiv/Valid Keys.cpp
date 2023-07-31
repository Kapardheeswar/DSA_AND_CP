//
// Created by kapar on 30-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int countFactors(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) count++;
            else count += 2;
        }
    }
    return count;
}
vector<int>getValidCount(vector<long>keys){
    vector<int>ans;
    for(auto k:keys){
        int count = 0;
        for(int i=0;i<=k;i++){
            int factorCount = countFactors(i);
            if(factorCount==3) count++;
        }
        ans.push_back(count);
    }
    return ans;
}
int main() {
    vector<int>validCount = getValidCount({5,11});
    for(auto i:validCount)cout<<i<<" ";
}