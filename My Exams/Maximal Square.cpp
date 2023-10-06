//
// Created by kapar on 04-10-2023.
//
#include <bits/stdc++.h>

using namespace std;

int getMaxLength(vector<vector<char>> &matrix, int i, int j) {
    if (i >= matrix[0].size() or j >= matrix.size()) return 0;
    int right = getMaxLength(matrix, i + 1, j);
    int down = getMaxLength(matrix, i, j + 1);
    int cross = getMaxLength(matrix, i + 1, j + 1);
    if (matrix[i][j] == '0') return 0;
    int ans = INT_MIN;
    ans = max(ans, 1 + min(right, min(down, cross)));
    return ans;
}

int maximalSquare(vector<vector<char>> &matrix) {
    int ans = getMaxLength(matrix, 0, 0);
    return ans * ans;
}

int main() {
    vector<vector<char>> mat = {{'0', '1'},
                                {'1', '0'}};
    cout << maximalSquare(mat);
}