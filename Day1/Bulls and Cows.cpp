#include<bits/stdc++.h>

using namespace std;

int isInBulls(vector<int> v, int i) {
    for (int k: v) {
        if (k == i) {
            return 1;
        }
    }
    return 0;
}

string getHint(string secret, string guess) {
    vector<char> s;
    vector<char> g;
    for (int i = 0; i < secret.length(); ++i) {
        s.push_back(secret[i]);
    }
    for (int i = 0; i < guess.length(); ++i) {
        g.push_back(guess[i]);
    }
    vector<int> bulls;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == g[i]) {
            bulls.push_back(i);
        }
    }
    int cows = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (!isInBulls(bulls, i)) {
            for (int j = 0; j < g.size(); ++j) {
                if (j != i && !isInBulls(bulls, j)) {
                    if (s[i] == g[j]) {
                        cows++;
                        break;
                    }
                }
            }
        }
    }
    cout << bulls.size() << endl;
    cout << cows << endl;
    string str = "";
    str += to_string(bulls.size());
    str += "A";
    str += to_string(cows);
    str += "B";
    return str;
}

int main() {
    string secret, guess;
    cin >> secret;
    cin >> guess;
    cout << getHint(secret, guess);
}
