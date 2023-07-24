#include <bits/stdc++.h>

using namespace std;

int minPeriod(string s) {
    int length = s.length();
    for (int i = 1; i <= length; i++) {
        if ((s.length() % i) == 0) {
            map<char, int> m1;
            for (int j = 0; j < i; j++) {
                m1[s[j]]++;
            }
            map<char, int> m2;
            int currIndex = i;
            int currLen = i;
            bool isPossible = true;
            while (currIndex < s.length()) {
                for (int k = currIndex; k < currIndex + currLen; k++) {
                    m2[s[k]]++;
                }
                if (m2 != m1) {
                    isPossible = false;
                    break;
                }
                m2.clear();
                currIndex += currLen;
            }
            if (!isPossible) {
                continue;
            }
            return currLen;
        }
    }
    return s.length();
}

int main() {
    cout << minPeriod("bbaaababababaabb") << endl;
    cout << minPeriod("abcbcacba") << endl;
}