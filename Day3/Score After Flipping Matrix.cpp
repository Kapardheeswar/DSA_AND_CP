//
// Created by kapar on 22-04-2023.
//
#include<bits/stdc++.h>

using namespace std;

int findMaxScore(vector<vector<int>> grid) {
    int score = 0;
    int rows = grid.size();
    int cols = grid.at(0).size();
    score += (1 << (cols - 1)) * rows;
    for (int j = 1; j < cols; ++j) {
        int value = (1 << (cols - 1 - j));
        int sets = 0;
        for (int i = 0; i < rows; ++i) {
            if (grid[i][j] == grid[i][0]) sets++;
        }
        int maxEleThatCanBeToggled = max(sets, rows - sets);
        score += maxEleThatCanBeToggled * value;
    }
    return score;
}

int main() {
    vector<vector<int>> grid = {{0, 0, 1, 1},
                                {1, 0, 1, 0},
                                {1, 1, 0, 0}};
    int score = findMaxScore(grid);
    cout << score;
}