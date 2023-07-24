//
// Created by kapar on 22-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

void getMinCost(vector<int> a, vector<int> b, vector<int> c, int index, int &maxElement, int currCost, int &minCost) {
    if (index == a.size()) {
        int currMin = INT_MAX;
        for (auto i: a) if (i < currMin) currMin = i;
        if (maxElement < currMin) {
            minCost = currCost;
            maxElement = currMin;
        }
        return;
    }
    for (int i = 0; i < index; i++) {
        if (a[index] > b[index] and a[index] - 1 >= 0) {
            a[i]++;
            a[index]--;
            getMinCost(a, b, c, index + 1, maxElement, c[index], minCost);
            a[i]--;
            a[index]++;
        } else {
            getMinCost(a, b, c, index + 1, maxElement, currCost, minCost);
        }
    }
    return;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 3};
    vector<int> b = {1, 2, 1, 2, 1};
    vector<int> c = {1, 2, 1, 4, 3};
    int maxElement = INT_MIN;
    int minCost = INT_MAX;
    getMinCost(a, b, c, 1, maxElement, 0, minCost);
    cout << maxElement << " " << minCost << endl;
}