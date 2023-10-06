//
// Created by kapar on 17-09-2023.
//
#include <bits/stdc++.h>

using namespace std;
int ans = 0;

void getMaxProfit(vector<int> stocks, int index, int coolDown, bool isStockBought, int currMoney, int k) {
    if (index == stocks.size()) {
        if (ans <= currMoney) ans = currMoney;
        return;
    }
    if (coolDown > 0) {
        return getMaxProfit(stocks, index + 1, coolDown - 1, isStockBought, currMoney, k);
    }
    if (!isStockBought) {
        getMaxProfit(stocks, index + 1, coolDown, true, currMoney - stocks[index], k);
        getMaxProfit(stocks, index + 1, coolDown, false, currMoney, k);
        return;
    } else {
        getMaxProfit(stocks, index + 1, k, false, currMoney + stocks[index], k);
        getMaxProfit(stocks, index + 1, coolDown, true, currMoney, k);
        return;
    }
}

int getMaxProfit(vector<int> &stocks, int index, int coolDown, bool isStockBought, int k) {
    if (index == stocks.size()) return 0;
    if (coolDown > 0) return getMaxProfit(stocks, index + 1, coolDown - 1, isStockBought, k);
    int ans = INT_MIN;
    if (!isStockBought) {
        int option1 = getMaxProfit(stocks, index + 1, coolDown, true, k) - stocks[index];
        int option2 = getMaxProfit(stocks, index + 1, coolDown, false, k);
        ans = max(ans, max(option1, option2));
    } else {
        int option1 = getMaxProfit(stocks, index + 1, k, false, k) + stocks[index];
        int option2 = getMaxProfit(stocks, index + 1, coolDown, true, k);
        ans = max(ans, max(option1, option2));
    }
    return ans;
}

int main() {
    vector<int> stocks = {1, 2, 3, 0, 2};
    getMaxProfit(stocks, 0, 0, false, 0, 1);
    cout << ans << endl;
    cout << getMaxProfit(stocks, 0, 0, false, 1);
}