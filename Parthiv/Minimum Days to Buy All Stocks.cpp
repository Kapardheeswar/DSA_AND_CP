//
// Created by kapar on 31-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int minDays(vector<int> qty, map<int, vector<int>> saleDays, int index, int money, int dayIndex) {
    if (index == qty.size()) return 0;
    int ans = INT_MAX;
    vector<int> currentDayStocks = saleDays[dayIndex];
    auto f = find(currentDayStocks.begin(), currentDayStocks.end(), index);
    if (f != currentDayStocks.end()) {
        for (int i = 1; i <= money; i++) {
            if (qty[index] >= i) {
                qty[index] -= i;
                int subProblem = i + minDays(qty, saleDays, index + 1, money - i, dayIndex + i);
                qty[index] += i;
                ans = min(ans, subProblem);
            }
        }
    }
    if (money >= 2) {
        for (int i = 2; i <= money; i *= 2) {
            if(qty[index]*2>=i){
                qty[index] -= i;
                int subProblem = i + minDays(qty, saleDays, index + 1, money - i, dayIndex + i);
                qty[index] += i;
                ans = min(ans, subProblem);
            }
        }
    }
    return ans;
}
int main(){
    vector<vector<int>>saleDays = {{1,3},{2,2},{0,4},{0,1},{0,4},{1,2}};
    map<int,vector<int>>m;
    for(auto v:saleDays){
        m[v[0]].push_back(v[1]);
    }
    cout<<minDays({1,2,0,2,0},m,0,1,0);
}

