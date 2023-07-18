//
// Created by kapar on 18-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

bool compare(const vector<int> &box1, const vector<int> &box2) {
    return box1[2] < box2[2];
}

int boxStacking(vector<vector<int>> boxes) {
    sort(boxes.begin(), boxes.end(), compare);
    vector<int> dp(boxes.size());
    for (int i = 0; i < boxes.size(); i++) {
        dp[i] = boxes[i][2];//Initialise with height of each box
    }
    for (int i = 0; i < boxes.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (boxes[j][0] < boxes[i][0] and boxes[j][1] < boxes[i][1] and boxes[j][2] < boxes[i][2]) {
                int currentHeight = boxes[i][2];
                if (dp[j] + currentHeight > dp[i]) {
                    dp[i] = dp[j] + currentHeight;
                }
            }
        }
    }
    int maxHeight = 0;
    for (int i: dp) maxHeight = max(maxHeight, i);
    return maxHeight;
}

int main() {
    vector<vector<int>> boxes = {{2, 2, 1},
                                 {2, 1, 2},
                                 {3, 2, 3},
                                 {2, 3, 4},
                                 {4, 4, 5},
                                 {2, 2, 8}};
    cout << boxStacking(boxes);
}