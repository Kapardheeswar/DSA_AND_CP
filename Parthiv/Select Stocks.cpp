//
// Created by kapar on 24-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

void
getMaxProfit(vector<int> currentPrices, vector<int> futurePrices, int index, int cost, int currProfit, int &maxProfit,
             int currSpending) {
    if (index == currentPrices.size()) {
        if (currProfit - currSpending > maxProfit) maxProfit = currProfit - currSpending;
        return;
    }
    if (cost >= currentPrices[index])
        getMaxProfit(currentPrices, futurePrices, index + 1, cost - currentPrices[index],
                     currProfit + futurePrices[index], maxProfit, currSpending + currentPrices[index]);
    getMaxProfit(currentPrices, futurePrices, index + 1, cost, currProfit, maxProfit, currSpending);
}

int main() {
    vector<int> cuuPrices = {175, 133, 109, 210, 97};
    vector<int> futPrices = {200, 125, 128, 228, 133};
    int maxProfit = INT_MIN;
    getMaxProfit(cuuPrices, futPrices, 0, 250, 0, maxProfit, 0);
    cout << maxProfit << endl;
}