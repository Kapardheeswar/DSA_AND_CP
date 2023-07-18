//
// Created by kapar on 17-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
struct trieNode {
    char ch;
    map<char, trieNode *> m;
    bool isTerminal = false;
    string s = "";
};
typedef trieNode *tptr;

tptr insert(tptr &t, string word) {
    tptr temp = t;
    for (char ch: word) {
        if (temp->m.count(ch) == 0) {
            tptr n = new trieNode;
            n->ch = ch;
            temp->m[ch] = n;
            temp = n;
        } else {
            temp = temp->m[ch];
        }
    }
    temp->isTerminal = true;
    temp->s = word;
    return t;
}

void getAllWordsInBoard(int m, int n, vector<vector<char>> graph, tptr t, int i, int j, vector<string> &output,
                        vector<vector<bool>> visited) {
    char ch = graph[i][j];
    if (t->m.count(ch) == 0) return;
    if (t->m[ch]->isTerminal) output.push_back(t->m[ch]->s);
    visited[i][j] = true;

    vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
    vector<int> dy = {1, -1, 0, 1, -1, 0, 1, -1};

    for (int k = 0; k < 8; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 and ny >= 0 and nx < m and ny < n and !visited[nx][ny]) {
            getAllWordsInBoard(m, n, graph, t->m[ch], nx, ny, output, visited);
        }
    }
    visited[i][j] = false;
}

int main() {
    vector<string> words = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO", "TUNES", "CAT"};
    vector<vector<char>> graph = {{'S', 'E', 'R', 'T'},
                                  {'U', 'N', 'K', 'S'},
                                  {'T', 'C', 'A', 'T'}};
    int m = 3;
    int n = 4;
    tptr t = new trieNode;
    t->ch = '\0';
    for (auto w: words) {
        t = insert(t, w);
    }
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<string> output;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            getAllWordsInBoard(m, n, graph, t, i, j, output, visited);
        }
    }
    for (auto word: output) {
        cout << word << endl;
    }
}
