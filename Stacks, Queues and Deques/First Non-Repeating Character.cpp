//
// Created by kapar on 10-07-2023.
//
#include<bits/stdc++.h>

using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string s) {
    vector<char> ans;
    queue<char> queue;
    map<char, int> map;
    map[s[0]]++;
    queue.push(s[0]);
    ans.push_back(s[0]);
    for (int i = 1; i < s.length(); i++) {
        char ch = s[i];
        map[ch]++;
        char front = queue.front();
        if (map[front] > 1) {
            while (!queue.empty()) {
                if (map[queue.front()] > 1) {
                    queue.pop();
                    continue;
                } else {
                    ans.push_back(queue.front());
                    break;
                }
            }
            if (queue.empty()) ans.push_back('0');
        } else {
            if (queue.empty()) {
                queue.push(ch);
                ans.push_back(ch);
            } else {
                queue.push(ch);
                ans.push_back(front);
            }
        }
    }
    return ans;
}

int main() {
    vector<char> v = FindFirstNonRepeatingCharacter("aabcbcd");
    for (auto ch: v) {
        cout << ch << " ";
    }
}