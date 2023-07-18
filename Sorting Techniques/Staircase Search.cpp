//
// Created by kapar on 03-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

pair<int, int> search(int m, int n, vector<vector<int>> v, int k) {
    //write your code here.
    int i = m - 1;
    int j = 0;
    while (i >= 0 and j < n) {
        if (v[i][j] == k) {
            return {i, j};
        } else if (v[i][j] < k) {
            j++;
        } else {
            i--;
        }
    }
    return {i,j};
}
int main(){
    vector<vector<int>>v={{1,4,9},{2,5,10},{6,7,11}};
    pair<int,int>p = search(3,3,v,10);
    cout<<p.first<<" "<<p.second<<endl;
}
