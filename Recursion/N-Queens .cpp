//
// Created by kapar on 05-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<string> board, int x, int y) {
    int length = board.size();
    for (int i = 0; i < x; i++) {
        if (board[i][y] == 'Q') {
            return false;
        }
    }
    int rowIndex = x;
    int colIndex = y;
    while (rowIndex >= 0 and colIndex >= 0) {
        if (board[rowIndex][colIndex] == 'Q') {
            return false;
        }
        rowIndex--;
        colIndex--;
    }
    rowIndex = x;
    colIndex = y;
    while (rowIndex >= 0 and colIndex < length) {
        if (board[rowIndex][colIndex] == 'Q') {
            return false;
        }
        rowIndex--;
        colIndex++;
    }
    return true;
}

void getQueensPositions(vector<string> &board, vector<vector<string>> &ans, int i) {
    if (i == board.size()) {
        ans.push_back(board);
        return;
    }
    for (int j = 0; j < board.size(); j++) {
        if (isSafe(board, i, j)) {
            board[i][j] = 'Q';
            getQueensPositions(board, ans, i + 1);
            board[i][j] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    getQueensPositions(board,ans,0);

    return ans;
}
int main(){
    vector<vector<string>>pos = solveNQueens(4);
    for (auto s:pos) {
        for (auto str:s) {
            cout<<str<<endl;
        }
        cout<<endl;
    }
}