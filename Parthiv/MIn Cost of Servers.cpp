//
// Created by kapar on 22-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int minCost(vector<int> a, vector<int> b, int n, int index) {
    if (index == n) return 0;
    int ans = INT_MAX;
    int option1 = a[index] + minCost(a, b, n, index + 1);
    ans = min(ans,option1);
    for (int j = index + 1; j < n; j++) {
        int cost = 0;
        for (int k = index; k <= j; k++) {
            cost += b[k];
        }
        int option2 = cost + minCost(a, b, n, j + 1);
        ans = min(ans,option2);
    }
    return ans;
}
int main(){
    vector<int>a = {1,2,1,3,4,2,1,2,3,1};
    vector<int>b = {5,5,1,1,1,5,5,1,1,1};
    cout<<minCost(a,b,10,0);
}