#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

bool is_valid_word(string word, unordered_set<string>& valid_words) {
    return valid_words.find(word) != valid_words.end();
}

void get_valid_words(vector<vector<char>>& matrix, int m, int n, unordered_set<string>& valid_words) {
    // Check horizontally left to right
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n-1; j++) {
            string word = "";
            word += matrix[i][j];
            word += matrix[i][j+1];
            if (is_valid_word(word, valid_words)) {
                valid_words.insert(word);
            }
        }
    }
    // Check vertically top to bottom
    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < n; j++) {
            string word = "";
            word += matrix[i][j];
            word += matrix[i+1][j];
            if (is_valid_word(word, valid_words)) {
                valid_words.insert(word);
            }
        }
    }
}

bool is_valid_carving(string carving, unordered_set<string>& valid_words) {
    int n = carving.length();
    for (int i = 0; i < n-1; i++) {
        string word = "";
        word += carving[i];
        word += carving[i+1];
        if (!is_valid_word(word, valid_words)) {
            return false;
        }
    }
    return true;
}

int main() {
    int m, n, q;
    cin >> m >> n >> q;
    vector<vector<char>> matrix(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    unordered_set<string> valid_words;
    get_valid_words(matrix, m, n, valid_words);
    for (int i = 0; i < q; i++) {
        string carving;
        cin >> carving;
        if (is_valid_carving(carving, valid_words)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}