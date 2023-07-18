//
// Created by kapar on 24-06-2023.
//
#include <bits/stdc++.h>

using namespace std;

string isPackingPossible(vector<pair<int, int>> &gifts, vector<pair<int, int>> &boxes) {
    int totalGifts = gifts.size();
    int totalBoxes = boxes.size();
    if (totalGifts > totalBoxes) return "NO";
    for (auto gift: gifts) {
        int index = -1;
        int m3 = INT_MAX;
        for (int i = 0; i < boxes.size(); i++) {
            auto box = boxes[i];
            if (gift.first <= box.first && gift.second <= box.second) {
                int diff1 = box.first - gift.first;
                int diff2 = box.second - gift.second;
                if (m3 > abs(diff1 - diff2)) {
                    m3 = abs(diff1 - diff2);
                    index = i;
                }
            }
        }
        if (index == -1) return "NO";
        else boxes.erase(boxes.begin() + index);
    }
    return "YES";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> gifts(n);
        vector<pair<int, int>> boxes(m);
        for (int i = 0; i < n; i++) {
            cin >> gifts[i].first >> gifts[i].second;
        }
        for (int i = 0; i < m; i++) {
            cin >> boxes[i].first >> boxes[i].second;
        }
        cout << isPackingPossible(gifts, boxes) << "\n";
    }
    return 0;
}