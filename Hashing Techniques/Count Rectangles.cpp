//
// Created by kapar on 14-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int countRect(vector<pair<int, int>> v) {
    set<pair<int, int>> pointSet(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i].first != v[j].first and v[i].second != v[j].second)
                if (pointSet.find({v[i].first, v[j].second}) != pointSet.end() and
                    pointSet.find({v[j].first, v[i].second}) != pointSet.end()) {
                    cnt++;
                }
        }
    }
    return cnt / 2;
}

int main() {
    vector<pair<int, int>> points = {{0, 0},
                                     {0, 1},
                                     {1, 0},
                                     {1, 1},
                                     {2, 0},
                                     {2, 1},
                                     {4, 0},
                                     {4, 1}};
    cout << countRect(points);
}