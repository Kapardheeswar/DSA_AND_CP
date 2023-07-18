//
// Created by kapar on 14-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int countTriangles(vector<pair<int, int>> v) {
    map<int, int> xMap, yMap;
    for (auto p: v) {
        xMap[p.first]++;
        yMap[p.second]++;
    }
    int cnt = 0;
    for (auto p: v) {
        cnt += (xMap[p.first] - 1) * (yMap[p.second] - 1);
    }
    return cnt;
}

int main() {
    vector<pair<int, int>> v = {{1, 2},
                                {2, 0},
                                {2, 2},
                                {2, 3},
                                {4, 2}};
    cout << countTriangles(v);
}