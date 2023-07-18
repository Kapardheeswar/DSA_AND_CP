//
// Created by kapar on 05-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<char>> board, int i, int j, char ch) {
    for (int k = 0; k < 9; k++) {
        if (board[i][k] == ch or board[k][j] == ch) return false;
    }

    int startX = (i / 3) * 3;
    int startY = (j / 3) * 3;

    for (int k = startX; k < startX + 3; k++) {
        for (int l = startY; l < startY + 3; l++) {
            if (board[k][l] == ch) return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board, int i, int j) {
    if (i == board.size()) {
        return true;
    }
    if (j == board.size()) {
        return solveSudoku(board, i + 1, 0);
    }
    if (board[i][j] != '.') {
        return solveSudoku(board, i, j + 1);
    }
    for (char ch = '1'; ch <= '9'; ch++) {
        if (isSafe(board, i, j, ch)) {
            board[i][j] = ch;
            bool canBeSolved = solveSudoku(board, i, j + 1);
            if(canBeSolved) return true;
        }
    }
    board[i][j] = '.';
    return false;
}

int main() {
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board, 0, 0);
    for (auto k: board) {
        for (auto ch: k) {
            cout << ch << " ";
        }
        cout << endl;
    }
}